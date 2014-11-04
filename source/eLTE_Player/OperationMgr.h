/********************************************************************
filename    :    OperationMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    调度台操作管理类。包括注册、注销、视频回传业务逻辑处理。对应eLTE SDK内的OperationManager类
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 初始版本
*********************************************************************/

#ifndef __ELTE_OCX_OPERATION_MGR_H__
#define __ELTE_OCX_OPERATION_MGR_H__

#include "DataType.h"


//////////////////////////////////////////////////////////////////////////
// 视频回传参数
struct STVideoParam
{
	std::string strFmtValue;
	std::string strCameraType;
	std::string strUserCfmType;
	std::string strMuteType;

	STVideoParam& operator = (const STVideoParam& v)
	{
		strFmtValue = v.strFmtValue;
		strCameraType = v.strCameraType;
		strUserCfmType = v.strUserCfmType;
		strMuteType = v.strMuteType;
		return *this;
	}
};

//////////////////////////////////////////////////////////////////////////
class OperationMgr
{
public:
	static OperationMgr& Instance();

private:
	OperationMgr(void);
	~OperationMgr(void);

public:
	// 调度台注册
	int DcLogin(const std::string& userId, const std::string& passwd, 
		const std::string& serverIP, const std::string& localIP, const std::string& sipPort, bool bEnableStatusReport);
	// 调度台注销
	int DcLogout(const std::string& userId);
	// 触发状态上报
	int DcTriggerStatusReport(bool bEnableStatusReport) const;
	// 调度台发起视频回传
	int DcVideoMonitor(int iResId, Video_UL_parameter& param, bool bNeedSave = true);
	// 调度台挂断视频回传
	int DcVideoHangup(int iResId, bool bNeedSave = true);
	// 订阅群组
	int DcSubscribeGroup(const std::string& groupId, unsigned long ulEableSubscribeGroup) const;
	// 设置配置文件参数
	void SetParam(const std::string& strFrontFormat, const std::string& strBackFormat);

	// 用于工具栏操作
public:
	// 切换摄像头
	int DcVideoReverse(int iResId, STVideoParam& vParam);
	// 获取是否开启伴音
	std::string GetMuteType(int iResId);

	// 登陆登出参数
private:
	// 用户ID
	std::string m_userId;
	// 用户密码
	std::string m_passwd;
	// 本地IP
	std::string m_localIP;
	// 服务器IP
	std::string m_serverIP;
	// SIP端口
	std::string m_sipPort;

	// 用于工具栏操作
private:
	// 默认前置摄像头视频格式
	std::string m_strFrontFormat;
	// 默认后置摄像头视频格式
	std::string m_strBackFormat;

	// 视频回传资源列表
public:
	std::map<int, STVideoParam> m_mapResource;
};

#endif
