#include "StdAfx.h"
#include "MediaPlayer.h"
#include "eLTE_Log.h"
#include "eLTE_Tool.h"


#define IVS_MP_LOG_PATH (".\\ivs_mp_log\\")

// 初始化标志
BOOL MediaPlayer::m_bInit = FALSE;

MediaPlayer::MediaPlayer(void)
	: m_ulNetChannel(0)
	, m_ulPalyerChannel(0)	
	, m_bStartPlayer(FALSE)
	, m_snapshotFormat(0)
	, m_savePath("")
	, m_bAllowPlaySound(FALSE)
	, m_strResId("")
	, m_strLocalIP("")
	, m_strRemoteIP("")
	, m_uiLocalVideoPort(0)
	, m_uiLocalAudioPort(0)
	, m_uiRemoteVideoPort(0)
	, m_uiRemoteAudioPort(0)
{

}


MediaPlayer::~MediaPlayer(void)
{

}

int MediaPlayer::InitPlayerParam(IVS_CHAR* pLocalIP, IVS_UINT32 uiLocalVideoPort, IVS_UINT32 uiLocalAudioPort)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM3(pLocalIP, uiLocalVideoPort, uiLocalAudioPort);
	
	// 入参判断
	if (NULL == pLocalIP)
	{
		ERROR_LOG() << "pLocalIP is null.";
		return eLTE_INVALID_PARAM;
	}

	// 先停止播放
	(void)StopPlayer();

	// 保存IP参数
	m_strLocalIP = pLocalIP;

	// netsource init
	IVS_INT32 iRet = IVS_SUCCEED;
	if (!m_bInit)
	{
		iRet = IVS_NETSOURCE_Init(IVS_MP_LOG_PATH);
		if (IVS_SUCCEED != iRet)
		{
			ERROR_LOG() << "IVS_NETSOURCE_Init failed. (" << iRet << ")";
			return iRet;
		}
	}

	// 获取可用通道
	iRet = IVS_NETSOURCE_GetChannel(&m_ulNetChannel);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_NETSOURCE_GetChannel failed. (" << iRet << ")";
		m_ulNetChannel = 0;
		return iRet;
	}

	// player init
	if (!m_bInit)
	{
		iRet = IVS_PLAY_Init(IVS_MP_LOG_PATH);
		if (IVS_SUCCEED != iRet)
		{
			ERROR_LOG() << "IVS_PLAY_Init failed. (" << iRet << ")";
			return iRet;
		}
		m_bInit = TRUE;
	}

	// 获取可用的媒体通道号
	iRet = IVS_PLAY_GetChannel(&m_ulPalyerChannel);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_PLAY_GetChannel failed. (" << iRet << ")";
		m_ulPalyerChannel = 0;
		return iRet;
	}

	// 设置媒体流回调函数
	IVS_NETSOURCE_SetDataCallBack(m_ulNetChannel, NetDateCallBack, (IVS_VOID *)this);
	// 设置异常回调函数
	IVS_NETSOURCE_SetExceptionCallBack(NetExceptionCallBack, (IVS_VOID *)this);

	// 设置协议类型，1-UDP 2-TCP，默认为1
	iRet = IVS_NETSOURCE_SetProtocolType(m_ulNetChannel, PROTOCOL_RTP_OVER_UDP);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_PARAM2(m_ulNetChannel, PROTOCOL_RTP_OVER_UDP);
		ERROR_LOG() << "IVS_NETSOURCE_SetProtocolType failed. (" << iRet << ")";
		return iRet;
	}

	// 设置本地接收码流的Ip地址
	iRet = IVS_NETSOURCE_SetLocalRecvStreamIP(m_ulNetChannel, pLocalIP);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_PARAM2(m_ulNetChannel, pLocalIP);
		ERROR_LOG() << "IVS_NETSOURCE_SetLocalRecvStreamIP failed. (" << iRet << ")";
		return iRet;
	}

	// 设置本地接收码流的端口号
	iRet = IVS_NETSOURCE_SetLocalRecvStreamPort(m_ulNetChannel, uiLocalVideoPort, uiLocalAudioPort);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_PARAM3(m_ulNetChannel, uiLocalVideoPort, uiLocalAudioPort);
		ERROR_LOG() << "IVS_NETSOURCE_SetLocalRecvStreamPort failed. (" << iRet << ")";
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

int MediaPlayer::UninitPlayer()
{
	DEBUG_LOG() << "--- ENTRY";
	
	(void)StopPlayer();

	if (m_bInit)
	{
		IVS_PLAY_UnInit();
		IVS_NETSOURCE_UnInit();
		m_bInit = FALSE;
	}

	if (m_bAllowPlaySound)
	{
		(void)StopAudio();
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

int MediaPlayer::StartPlayer(IVS_CHAR* pRemoteIP, IVS_UINT32 uiRemoteVideoPort, IVS_UINT32 uiRemoteAudioPort, HWND hVideoPlayer)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM4(pRemoteIP, uiRemoteVideoPort, uiRemoteAudioPort, hVideoPlayer);
	
	// 入参判断
	if (NULL == pRemoteIP)
	{
		ERROR_LOG() << "pRemoteIP is null.";
		return eLTE_INVALID_PARAM;
	}
	if (NULL == hVideoPlayer)
	{
		ERROR_LOG() << "hVideoPlayer is null.";
		return eLTE_FAILED;
	}

	// 是否已经播放
	if (m_bStartPlayer)
	{
		DEBUG_LOG() << "Is playing. please stop player first.";
		return eLTE_FAILED;
	}

	// 保存IP参数
	m_strRemoteIP = pRemoteIP;

	// 打开流、启动收流线程;
	IVS_INT32 iRet = IVS_NETSOURCE_OpenNetStream(m_ulNetChannel, pRemoteIP, uiRemoteVideoPort, uiRemoteAudioPort);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_NETSOURCE_OpenNetStream failed. (" << iRet << ")";
		(void)IVS_NETSOURCE_FreeChannel(m_ulNetChannel);
		(void)IVS_PLAY_FreeChannel(m_ulPalyerChannel);
		m_ulPalyerChannel = 0;
		m_ulNetChannel = 0;
		return iRet;
	}

	// 启动收流
	iRet = IVS_NETSOURCE_StartRecvStream(m_ulNetChannel);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_NETSOURCE_StartRecvStream failed. (" << iRet << ")";
		(void)IVS_NETSOURCE_CloseNetStream(m_ulNetChannel);
		(void)IVS_NETSOURCE_FreeChannel(m_ulNetChannel);
		(void)IVS_PLAY_FreeChannel(m_ulPalyerChannel);
		m_ulPalyerChannel = 0;
		m_ulNetChannel = 0;
		return iRet;
	}

	MEDIA_ATTR AttrAudio = {0};
	AttrAudio.rtpmap = PAY_LOAD_TYPE_PCMA;
	AttrAudio.type   = AUDIO_DEC_G711U;
	AttrAudio.samplerate = 8000;
	MEDIA_ATTR AttrVideo = {0};
	AttrVideo.rtpmap = PAY_LOAD_TYPE_H264;
	AttrVideo.type   = VIDEO_DEC_H264;
	AttrVideo.samplerate = 90000;
	// 设置媒体信息
	iRet = IVS_PLAY_SetMediaAttribute(m_ulPalyerChannel, &AttrVideo, &AttrAudio);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_PLAY_SetMediaAttribute failed. (" << iRet << ")";
		(void)IVS_NETSOURCE_CloseNetStream(m_ulNetChannel);
		(void)IVS_NETSOURCE_FreeChannel(m_ulNetChannel);
		(void)IVS_PLAY_FreeChannel(m_ulPalyerChannel);
		m_ulPalyerChannel = 0;
		m_ulNetChannel = 0;
		return iRet;
	}

	// 打开流通道
	iRet = IVS_PLAY_OpenStream(m_ulPalyerChannel, SERVICE_TYPE_REALVIDEO, SOURCE_RTP);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_PLAY_OpenStream failed. (" << iRet << ")";
		(void)IVS_NETSOURCE_CloseNetStream(m_ulNetChannel);
		(void)IVS_NETSOURCE_FreeChannel(m_ulNetChannel);
		(void)IVS_PLAY_FreeChannel(m_ulPalyerChannel);
		m_ulPalyerChannel = 0;
		m_ulNetChannel = 0;
		return iRet;
	}

	// 启动播放
	iRet = IVS_PLAY_StartPlay(m_ulPalyerChannel);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_PLAY_StartPlay failed. (" << iRet << ")";
		(void)IVS_NETSOURCE_CloseNetStream(m_ulNetChannel);
		(void)IVS_NETSOURCE_FreeChannel(m_ulNetChannel);
		(void)IVS_PLAY_CloseStream(m_ulPalyerChannel);
		(void)IVS_PLAY_FreeChannel(m_ulPalyerChannel);
		m_ulPalyerChannel = 0;
		m_ulNetChannel = 0;
		return iRet;
	}
	// 设置播放窗口句柄
	iRet = IVS_PLAY_SetPlayWindow(m_ulPalyerChannel, hVideoPlayer);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_PLAY_SetPlayWindow failed. (" << iRet << ")";
		(void)IVS_NETSOURCE_CloseNetStream(m_ulNetChannel);
		(void)IVS_NETSOURCE_FreeChannel(m_ulNetChannel);
		(void)IVS_PLAY_CloseStream(m_ulPalyerChannel);
		(void)IVS_PLAY_StopPlay(m_ulPalyerChannel);
		(void)IVS_PLAY_FreeChannel(m_ulPalyerChannel);
		m_ulPalyerChannel = 0;
		m_ulNetChannel = 0;
		return iRet;
	}
	// 按通道和窗口设置视频显示比例，1为原始尺寸，2为全屏
	iRet = IVS_PLAY_SetDisplayAspectRatio(m_ulPalyerChannel, 1);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_PLAY_SetDisplayAspectRatio failed. (" << iRet << ")";
		(void)IVS_NETSOURCE_CloseNetStream(m_ulNetChannel);
		(void)IVS_NETSOURCE_FreeChannel(m_ulNetChannel);
		(void)IVS_PLAY_CloseStream(m_ulPalyerChannel);
		(void)IVS_PLAY_StopPlay(m_ulPalyerChannel);
		(void)IVS_PLAY_FreeChannel(m_ulPalyerChannel);
		m_ulPalyerChannel = 0;
		m_ulNetChannel = 0;
		return iRet;
	}

	m_bStartPlayer = TRUE;

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

int MediaPlayer::StopPlayer()
{
	DEBUG_LOG() << "--- ENTRY";
	if (m_bStartPlayer)
	{
		(void)IVS_NETSOURCE_CloseNetStream(m_ulNetChannel);
		(void)IVS_NETSOURCE_FreeChannel(m_ulNetChannel);
		(void)IVS_PLAY_CloseStream(m_ulPalyerChannel);
		(void)IVS_PLAY_StopPlay(m_ulPalyerChannel);
		(void)IVS_PLAY_FreeChannel(m_ulPalyerChannel);
		m_ulPalyerChannel = 0;
		m_ulNetChannel = 0;
		m_bStartPlayer = FALSE;
	}

	if (m_bAllowPlaySound)
	{
		(void)StopAudio();
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 播放音频
int MediaPlayer::PlayAudio()
{
	DEBUG_LOG() << "--- ENTRY";

	// 音频播放器初始化
	int iRet = m_AudioPlayer.WaveOutInit();
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "WaveOutInit failed.";
		return iRet;
	}

	m_bAllowPlaySound = TRUE;

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 停止音频
int MediaPlayer::StopAudio()
{
	DEBUG_LOG() << "--- ENTRY";

	// 先禁止waveOutWrite音频
	m_bAllowPlaySound = FALSE;

	// 音频播放器退出
	int iRet = m_AudioPlayer.WaveOutExit();
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "WaveOutInit failed.";
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

int MediaPlayer::LocalSnapshot(const std::string& strResId, std::string& strSnapshotPath)
{
	DEBUG_LOG() << "--- ENTRY";	

	strSnapshotPath = GetSnapshotPath(strResId);
	INFO_PARAM2(m_snapshotFormat, strSnapshotPath);

	IVS_INT32 iRet = IVS_PLAY_LocalSnapshot(m_ulPalyerChannel, strSnapshotPath.c_str(), (IVS_ULONG)m_snapshotFormat);
	if (IVS_SUCCEED != iRet)
	{
		ERROR_LOG() << "IVS_PLAY_LocalSnapshot failed. (" << iRet << ")";
		strSnapshotPath = "";
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

// 获取资源ID
int MediaPlayer::GetMediaPlayerResID() const
{
	DEBUG_LOG() << "--- ENTRY";

	int iResId = 0;
	if (!m_strResId.empty())
	{
		iResId = eLTE_Tool::String2Int(m_strResId);
	}

	DEBUG_LOG() << "--- LEAVE";
	return iResId;
}

void MediaPlayer::InitParam(int snapshotFormat, const std::string& savePath)
{
	DEBUG_LOG() << "--- ENTRY";
	DEBUG_PARAM2(snapshotFormat, savePath);

	m_snapshotFormat = snapshotFormat;
	m_savePath = savePath;

	DEBUG_LOG() << "--- LEAVE";
}

void MediaPlayer::InitParam(DWORD dwVolume)
{
	DEBUG_LOG() << "--- ENTRY";
	DEBUG_PARAM1(dwVolume);

	(void)m_AudioPlayer.WaveOutInitVolume(dwVolume);

	DEBUG_LOG() << "--- LEAVE";
}

// 设置抓图参数
void MediaPlayer::SetMediaPlayerResID(const std::string& strResId)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(strResId);
	
	m_strResId = strResId;

	DEBUG_LOG() << "--- LEAVE";
}

// 设置播放参数（这里是工具栏切换视频操作，因此IP使用上次开启视频时使用的IP）
void MediaPlayer::SetPlayerParam(IVS_UINT32 uiLocalVideoPort, IVS_UINT32 uiLocalAudioPort,
	IVS_UINT32 uiRemoteVideoPort, IVS_UINT32 uiRemoteAudioPort)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM4(uiLocalVideoPort, uiLocalAudioPort, uiRemoteVideoPort, uiRemoteAudioPort);

	m_uiLocalVideoPort = uiLocalVideoPort;
	m_uiLocalAudioPort = uiLocalAudioPort;
	m_uiRemoteVideoPort = uiRemoteVideoPort;
	m_uiRemoteAudioPort = uiRemoteAudioPort;

	DEBUG_LOG() << "--- LEAVE";
}

// 初始化播放器
int MediaPlayer::StartPlayer(HWND hVideoPlayer)
{
	DEBUG_LOG() << "--- ENTRY";

	// 初始化播放参数
	int iRet = InitPlayerParam((IVS_CHAR*)m_strLocalIP.c_str(), m_uiLocalVideoPort, m_uiLocalAudioPort);//lint !e1773
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "InitPlayerParam failed.";
		DEBUG_LOG() << "--- LEAVE";
		return iRet;
	}

	// 开始播放
	iRet = StartPlayer((IVS_CHAR*)m_strRemoteIP.c_str(), m_uiRemoteVideoPort, m_uiRemoteAudioPort, hVideoPlayer);//lint !e1773
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "StartPlayer failed.";
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

// 本地抓拍单张图片
int MediaPlayer::LocalSnapshot(std::string& strSnapshotPath)
{
	DEBUG_LOG() << "--- ENTRY";

	int iRet = LocalSnapshot(m_strResId, strSnapshotPath);
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "LocalSnapshot failed.";
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

std::string MediaPlayer::GetSnapshotPath(const std::string& strResId) const
{
	CTime time = CTime::GetCurrentTime();;
	CString szTime = time.Format(_T("%Y%m%d%H%M%S"));
	std::string strSnapshotName = strResId;
	strSnapshotName.append("_");
	strSnapshotName.append(eLTE_Tool::UnicodeToANSI(szTime.GetBuffer()));

	std::string strSnapshotPath = m_savePath;
	strSnapshotPath.append(strSnapshotName);
	if (eLTE_SNAPSHOT_JPG == m_snapshotFormat)
	{
		strSnapshotPath.append(".jpg");
	}
	else if (eLTE_SNAPSHOT_BMP == m_snapshotFormat)
	{
		strSnapshotPath.append(".bmp");
	}
	else
	{
		ERROR_LOG() << "Invalid snapshot format.";
		ERROR_PARAM1(m_snapshotFormat);
	}

	return strSnapshotPath;
}

// 音频判断
BOOL MediaPlayer::IsNetDateAudio(char* pBuf, size_t bufSize, char* &pAmr, size_t& amrSize) const
{
	if (NULL == pBuf)
	{
		ERROR_LOG() << "pBuf is null.";
		return FALSE;
	}

	if (sizeof(FIXED_HEADER) > bufSize)
	{
		ERROR_LOG() << "bufSize is too small.";
		return FALSE;
	}

	FIXED_HEADER *phdr = (FIXED_HEADER *)pBuf;//lint !e826
	if (NULL == phdr)//lint !e774
	{
		ERROR_LOG() << "phdr is null.";
		return FALSE;
	}

	// amr
	if (PAY_LOAD_TYPE_ELTE_AMR == phdr->payload)
	{
		// 减去AMR帧中的RTP头大小，12B
		size_t headerLen = sizeof(FIXED_HEADER) + phdr->csrc_len*4;
		if (headerLen >= bufSize)
		{
			return FALSE;
		}
		amrSize = bufSize - headerLen;
		pAmr = pBuf + headerLen;

		// 再减去AMR中的Payload header大小，1B
		amrSize -= 1;
		pAmr += 1;

		return TRUE;
	}

	return FALSE;
}

IVS_VOID CALLBACK MediaPlayer::NetDateCallBack(IVS_CHAR* pBuf, IVS_UINT32 uiSize, IVS_VOID* pUser)
{
	// 获取回调出来的类对象;
	MediaPlayer* pMediaPlayer = (MediaPlayer*)pUser;
	if (NULL == pMediaPlayer)
	{
		ERROR_LOG() << "MediaPlayer is null.";
		return;
	}

	// 音频处理
	size_t amrSize;
	char* pAmr;
	if (pMediaPlayer->IsNetDateAudio(pBuf, uiSize, pAmr, amrSize))
	{
		if (pMediaPlayer->m_bAllowPlaySound)
		{
			// 播放音频
			int iRet = pMediaPlayer->m_AudioPlayer.WaveOutPlay(pAmr, amrSize);
			if (eLTE_SUCCESS != iRet)
			{
				ERROR_LOG() << "WaveOutPlay failed.";
			}
		}
	}
	// 视频处理
	else
	{
		// 向播放库输入RTP流;
		IVS_INT32 iRet = IVS_PLAY_InputRtpData(pMediaPlayer->m_ulPalyerChannel, pBuf, uiSize);
		if (IVS_SUCCEED != iRet)
		{
			ERROR_LOG() << "IVS_PLAY_InputRtpData failed. (" << iRet << ")";
		}
	}
}

IVS_VOID CALLBACK MediaPlayer::NetExceptionCallBack(IVS_ULONG ulChannel, IVS_INT32 iMsgType, IVS_VOID* /*pParam*/, IVS_VOID* /*pUser*/)
{
	// 设计没有添加异常事件上报，暂时先把异常写入到日志中。
	WARN_LOG() << "Net exception: Type = " << iMsgType << ", Channel = " << ulChannel;
}
