#include "StdAfx.h"
#include "AudioPlayer.h"
#include "eLTE_Log.h"


AudioPlayer::AudioPlayer(void)
	: m_hWaveOut(NULL)
	, m_uIdxToWrite(0)
	, m_uIdxToRead(0)
	, m_dwVolume(0)
{
	memset(&m_waveformat, 0, sizeof(m_waveformat));
	memset(m_WaveOutBuf, 0, sizeof(WAVE_OUT_BUF)*WAVE_RING_SZ);
}


AudioPlayer::~AudioPlayer(void)
{
	if (NULL != m_hWaveOut)
	{
		(void)waveOutClose(m_hWaveOut);
		m_hWaveOut = NULL;
	}
}


// 初始化播放
int AudioPlayer::WaveOutInit()
{
	DEBUG_LOG() << "--- ENTRY";

	// 初始化opencore-amr音频转码
	int iRet = m_OpencoreAmrnb.Init();
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "OpencoreAmrnb init failed.";
		return iRet;
	}

	if (NULL == m_hWaveOut)
	{
		// 设置音频参数
		memset(&m_waveformat, 0, sizeof(m_waveformat));
		m_waveformat.wFormatTag = WAVE_FORMAT_PCM;	// 音频格式
		m_waveformat.nChannels = 1;					// 1单声道，2立体声
		m_waveformat.nSamplesPerSec = 8000;			// 样本频率8.0 KHz
		m_waveformat.nAvgBytesPerSec = 16000;		// 平均数据传输率,PCM nAvgBytesPerSec = nSamplesPerSec
		m_waveformat.nBlockAlign = 2;				// 以字节为单位设置块对齐, (nChannels*wBitsPerSample)/8
		m_waveformat.wBitsPerSample = 16;			// 样本的位深
		m_waveformat.cbSize = 0;					// 额外信息的大小, PCM忽略此值

		// 打开音频设备
		MMRESULT mRet = waveOutOpen(&m_hWaveOut, WAVE_MAPPER, &m_waveformat, (DWORD_PTR)WaveOutProc, (DWORD_PTR)this, CALLBACK_FUNCTION);//lint !e620
		if (MMSYSERR_NOERROR != mRet)  
		{
			ERROR_LOG() << "waveOutOpen failed. (" << mRet << ")";
			return eLTE_FAILED;  
		}

		// 设置音量
		(void)WaveOutSetVolume(m_dwVolume);
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 退出播放
int AudioPlayer::WaveOutExit()
{
	DEBUG_LOG() << "--- ENTRY";

	// 关闭音频设备
	if (NULL != m_hWaveOut)
	{
		MMRESULT mRet = waveOutReset(m_hWaveOut);
		if (MMSYSERR_NOERROR != mRet)  
		{
			ERROR_LOG() << "waveOutReset failed. (" << mRet << ")";
			return eLTE_FAILED;  
		}

		// 等待播放结束
		while (m_uIdxToRead != m_uIdxToWrite)
		{
			mRet = waveOutUnprepareHeader(m_hWaveOut, &m_WaveOutBuf[m_uIdxToRead].Hdr, sizeof(WAVEHDR));
			if (MMSYSERR_NOERROR != mRet)  
			{
				ERROR_LOG() << "waveOutUnprepareHeader failed. (" << mRet << ")";
				return eLTE_FAILED;  
			}

			m_WaveOutBuf[m_uIdxToRead].bInUse = FALSE;
			m_uIdxToRead++;
			m_uIdxToRead = m_uIdxToRead % WAVE_RING_SZ;
		}

		mRet = waveOutClose(m_hWaveOut);
		if (MMSYSERR_NOERROR != mRet)  
		{
			ERROR_LOG() << "waveOutClose failed. (" << mRet << ")";
			return eLTE_FAILED;
		}
		m_hWaveOut = NULL;
	}

	// 退出opencore-amr音频转码
	int iRet = m_OpencoreAmrnb.Exit();
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "OpencoreAmrnb Exit failed. (" << iRet << ")";
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

// 播放PCM
int AudioPlayer::WaveOutPlay(char* pAmr, unsigned int len)
{
	// 入参判断
	if (NULL == pAmr)
	{
		ERROR_LOG() << "pAmr is null.";
		return eLTE_INVALID_PARAM;
	}
	if (AUDIO_FRAME_DATA_SZ < len)
	{
		ERROR_LOG() << "len is overlong.";
		return eLTE_INVALID_PARAM;
	}

	// 状态校验
	if (NULL == m_hWaveOut)
	{
		ERROR_LOG() << "Please WaveOutInit first.";
		return eLTE_FAILED;
	}

	// 缓存满了
	if (m_WaveOutBuf[m_uIdxToWrite].bInUse)
	{
		ERROR_LOG() << "RingBuffer is full.";
		return eLTE_FAILED;
	}

	// AMR 转换为 WAV
	char* pWav = (char*)m_OpencoreAmrnb.DecodeAmrToWav((unsigned char*)pAmr);
	if (NULL == pWav)
	{
		ERROR_LOG() << "DecodeAmrToWav failed.";
		return eLTE_FAILED;
	}

	// 播放
	WAVE_OUT_BUF* pWaveOutBuf = &m_WaveOutBuf[m_uIdxToWrite];
	if (pWaveOutBuf->Hdr.dwFlags & WHDR_PREPARED)
	{
		(void)waveOutUnprepareHeader(m_hWaveOut, &pWaveOutBuf->Hdr, sizeof(WAVEHDR));
	}

	pWaveOutBuf->Hdr.lpData = pWaveOutBuf->WaveData;
	pWaveOutBuf->Hdr.dwBufferLength = WAV_BUFFER_SIZE;
	pWaveOutBuf->Hdr.dwBytesRecorded = 0;
	pWaveOutBuf->Hdr.dwUser =  0;
	pWaveOutBuf->Hdr.dwFlags = 0; 
	pWaveOutBuf->Hdr.dwLoops = 0; 
	pWaveOutBuf->Hdr.lpNext = NULL;
	pWaveOutBuf->Hdr.reserved = 0;
	memcpy(pWaveOutBuf->Hdr.lpData, pWav, WAV_BUFFER_SIZE);

	int iRet = eLTE_SUCCESS;
	MMRESULT mRet = waveOutPrepareHeader(m_hWaveOut, &pWaveOutBuf->Hdr, sizeof(WAVEHDR));
	if (MMSYSERR_NOERROR != mRet)
	{
		ERROR_LOG() << "waveOutPrepareHeader failed. (" << mRet << ")";
		iRet = eLTE_FAILED;
	}

	pWaveOutBuf->bInUse = TRUE;
	mRet = waveOutWrite(m_hWaveOut, &pWaveOutBuf->Hdr, sizeof(WAVEHDR));
	if (MMSYSERR_NOERROR != mRet)
	{              
		ERROR_LOG() << "waveOutWrite failed. (" << mRet << ")";
		iRet = eLTE_FAILED;
	}

	m_uIdxToWrite++;
	m_uIdxToWrite = m_uIdxToWrite % WAVE_RING_SZ;

	return iRet;
}

// 设置播放音量
int AudioPlayer::WaveOutSetVolume(DWORD dwVolume)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(dwVolume);
	if (NULL == m_hWaveOut)
	{
		ERROR_LOG() << "Please WaveOutInit first.";
		return eLTE_FAILED;
	}

	dwVolume = (ULONG)(((float)0xFFFF / 100) * (float)dwVolume);
	dwVolume = (dwVolume << 16) + dwVolume;

	MMRESULT mRet = waveOutSetVolume(m_hWaveOut, dwVolume);
	if (MMSYSERR_NOERROR != mRet)
	{              
		ERROR_LOG() << "waveOutSetVolume failed. (" << mRet << ")";
		return eLTE_FAILED;
	}

	m_dwVolume = dwVolume;
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 获取播放音量
int AudioPlayer::WaveOutGetVolume(DWORD& dwVolume)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == m_hWaveOut)
	{
		ERROR_LOG() << "Please WaveOutInit first.";
		return eLTE_FAILED;
	}

	MMRESULT mRet = waveOutGetVolume(m_hWaveOut, &dwVolume);
	if (MMSYSERR_NOERROR != mRet)
	{              
		ERROR_LOG() << "waveOutGetVolume failed. (" << mRet << ")";
		return eLTE_FAILED;
	}

	dwVolume = (dwVolume >> 16) * 100 / 0xFFFF;

	INFO_PARAM1(dwVolume);
	m_dwVolume = dwVolume;
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 初始化音量
int AudioPlayer::WaveOutInitVolume(DWORD dwVolume)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(dwVolume);

	m_dwVolume = dwVolume;

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// waveOut回调函数
void CALLBACK AudioPlayer::WaveOutProc(HWAVEOUT /*hwo*/, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR /*dwParam1*/, DWORD_PTR /*dwParam2*/)
{
	if (WOM_DONE != uMsg)
	{
		return;
	}

	AudioPlayer* pAudioPlayer = (AudioPlayer*)dwInstance;
	if (NULL == pAudioPlayer)
	{
		ERROR_LOG() << "pAudioPlayer is null.";
		return;
	}

	WAVE_OUT_BUF* pWaveOutBuf = &pAudioPlayer->m_WaveOutBuf[pAudioPlayer->m_uIdxToRead];
	if (!(pWaveOutBuf->Hdr.dwFlags & WHDR_DONE))
	{
		ERROR_LOG() << "WAVEHDR.dwFlags is not WHDR_DONE.";
	}

	pWaveOutBuf->bInUse = FALSE;
	pAudioPlayer->m_uIdxToRead++;
	pAudioPlayer->m_uIdxToRead = pAudioPlayer->m_uIdxToRead % WAVE_RING_SZ;
}
