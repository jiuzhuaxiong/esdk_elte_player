#include "StdAfx.h"
#include "ConfigMgr.h"
#include "MediaPlayer.h"
#include "VideoPane.h"
#include "OperationMgr.h"
#include "eLTE_Tool.h"
#include "eLTE_Log.h"


// 配置文件读取返回值检测
#define CHECK_READ_CONFIG_FILE(x) \
	if (0 >= (int)x) \
	{ \
		return eLTE_LOAD_CONFIG_FILE_FAILED; \
	}


ConfigMgr::ConfigMgr(void)
	: m_logLevel(0)
	, m_logSize(0)
	, m_logCount(0)
	, m_logPath("")
	, m_snapshotFormat(0)
	, m_savePath("")
	, m_skinType(0)
	, m_strLogoPath(_T(""))
	, m_ulVolume(0)
	, m_strFrontFormat("")
	, m_strBackFormat("")
{
}


ConfigMgr::~ConfigMgr(void)
{
}

eLTE_RET ConfigMgr::Start(MediaPlayer& mediaPlayer, CVideoPane& videoPane, OperationMgr& operationMgr)
{
	// 相对路径转绝对路径
	eLTE_Tool::RelativePathToAbsolute(m_savePath);
	eLTE_Tool::RelativePathToAbsoluteOcx(m_strLogoPath);

	// 设置MediaPlayer抓图参数
	mediaPlayer.InitParam(m_snapshotFormat, m_savePath);

	// 设置音频播放音量
	mediaPlayer.InitParam(m_ulVolume);

	// 设置CVideoPane皮肤
	videoPane.SetParam(m_skinType, m_strLogoPath);

	// 设置OperationMgr参数
	operationMgr.SetParam(m_strFrontFormat, m_strBackFormat);

	return eLTE_SUCCESS;
}

eLTE_RET ConfigMgr::Init()
{
	// 读取配置文件
	eLTE_RET iRet = LoadConfigFile();
	if (eLTE_SUCCESS != iRet)
	{
		return iRet;
	}

	// 相对路径转绝对路径
	eLTE_Tool::RelativePathToAbsolute(m_logPath);

	// 设置日志参数
	eLTE_Log::InitParam(m_logLevel, m_logSize, m_logCount, m_logPath);

	return eLTE_SUCCESS;
}

eLTE_RET ConfigMgr::Exit()
{
	m_logLevel = 0;
	m_logSize = 0;
	m_logCount = 0;
	m_logPath = "";
	m_snapshotFormat = 0;
	m_savePath = "";
	m_skinType = 0;

	return eLTE_SUCCESS;
}

std::string ConfigMgr::GetDefaultLogPath() const
{
	return m_logPath;
}

eLTE_RET ConfigMgr::LoadConfigFile()
{
	CString szPath = eLTE_Tool::GetOcxPath();
	if (!eLTE_Tool::IsExistPath(szPath))
	{
		return eLTE_LOAD_CONFIG_FILE_FAILED;
	}	
	szPath.Append(CONFIG_FILE_NAME);

	TCHAR tchValue[LENGTH_LONG] = {0};

	// log_config
	DWORD dwRet = GetPrivateProfileString(SECTION_LOG_CONFIG, _T("logLevel"), _T(""), tchValue, LENGTH_SHORT, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_logLevel = eLTE_Tool::WString2Int(tchValue);
	
	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_LOG_CONFIG, _T("logSize"), _T(""), tchValue, LENGTH_SHORT, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_logSize = eLTE_Tool::WString2UInt(tchValue);

	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_LOG_CONFIG, _T("logCount"), _T(""), tchValue, LENGTH_SHORT, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_logCount = eLTE_Tool::WString2UInt(tchValue);

	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_LOG_CONFIG, _T("logPath"), _T(""), tchValue, LENGTH_LONG, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_logPath = eLTE_Tool::UnicodeToANSI(tchValue);

	// snapshot_config
	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_SNAPSHOT_CONFIG, _T("snapshotFormat"), _T(""), tchValue, LENGTH_SHORT, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_snapshotFormat = eLTE_Tool::WString2Int(tchValue);

	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_SNAPSHOT_CONFIG, _T("savePath"), _T(""), tchValue, LENGTH_LONG, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_savePath = eLTE_Tool::UnicodeToANSI(tchValue);

	// skin_config
	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_SKIN_CONFIG, _T("skinType"), _T(""), tchValue, LENGTH_SHORT, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_skinType = eLTE_Tool::WString2Int(tchValue);

	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_SKIN_CONFIG, _T("logoPath"), _T(""), tchValue, LENGTH_LONG, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_strLogoPath = tchValue;

	// audio_config
	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_AUDIO_CONFIG, _T("volume"), _T(""), tchValue, LENGTH_SHORT, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_ulVolume = eLTE_Tool::WString2UInt(tchValue);

	// video_param
	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_VIDEO_PARAM, _T("frontFormat"), _T(""), tchValue, LENGTH_SHORT, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_strFrontFormat = eLTE_Tool::UnicodeToANSI(tchValue);

	memset(tchValue, 0, sizeof(TCHAR)*LENGTH_LONG);
	dwRet = GetPrivateProfileString(SECTION_VIDEO_PARAM, _T("backFormat"), _T(""), tchValue, LENGTH_SHORT, szPath);
	CHECK_READ_CONFIG_FILE(dwRet);
	m_strBackFormat = eLTE_Tool::UnicodeToANSI(tchValue);

	return eLTE_SUCCESS;
}
