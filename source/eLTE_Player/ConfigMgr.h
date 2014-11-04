/********************************************************************
filename    :    ConfigMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    配置文件读取，并初始化OCX参数类
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 初始版本
*********************************************************************/

#ifndef __ELTE_OCX_CONFIG_MGR_H__
#define __ELTE_OCX_CONFIG_MGR_H__

#include "DataType.h"


#define CONFIG_FILE_NAME			_T("eLTE_Player.ini")

#define SECTION_LOG_CONFIG			_T("log_config")
#define SECTION_SNAPSHOT_CONFIG		_T("snapshot_config")
#define SECTION_SKIN_CONFIG			_T("skin_config")
#define SECTION_AUDIO_CONFIG		_T("audio_config")
#define SECTION_VIDEO_PARAM			_T("video_param")

#define LENGTH_SHORT				16
#define LENGTH_LONG					256


class CVideoPane;
class MediaPlayer;
class OperationMgr;
class ConfigMgr
{
public:
	ConfigMgr(void);
	~ConfigMgr(void);

public:
	eLTE_RET Init();
	eLTE_RET Start(MediaPlayer& mediaPlayer, CVideoPane& videoPane, OperationMgr& operationMgr);
	eLTE_RET Exit();
	std::string GetDefaultLogPath() const;

private:
	eLTE_RET LoadConfigFile();

private:
	// log_config
	int m_logLevel;
	size_t m_logSize;
	unsigned int m_logCount;
	std::string m_logPath;

	// snapshot_config
	int m_snapshotFormat;
	std::string m_savePath;

	// skin_config
	int m_skinType;
	CString m_strLogoPath;

	// audio_config
	unsigned long m_ulVolume;

	// video_param
	std::string m_strFrontFormat;
	std::string m_strBackFormat;
};

#endif
