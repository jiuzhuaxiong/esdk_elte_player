#include "StdAfx.h"
#include "OperationMgr.h"
#include "eLTE_Log.h"
#include "eLTE_Tool.h"


OperationMgr::OperationMgr(void)
	: m_userId("")
	, m_passwd("")
	, m_localIP("")
	, m_serverIP("")
	, m_sipPort("")
	, m_strFrontFormat("")
	, m_strBackFormat("")
{
	m_mapResource.clear();
}


OperationMgr::~OperationMgr(void)
{
	try
	{
		m_mapResource.clear();
	}
	catch (...)
	{

	}
}


OperationMgr& OperationMgr::Instance()
{
	static OperationMgr s_OperationMgr;
	return s_OperationMgr;
}

// 调度台注册
int OperationMgr::DcLogin(const std::string& userId, const std::string& passwd, 
	const std::string& serverIP, const std::string& localIP, const std::string& sipPort, bool bEnableStatusReport)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM4(userId, serverIP, localIP, sipPort);

	// 入参校验
	if (!m_userId.empty())
	{
		ERROR_LOG() << "Please logout first.";
		return eLTE_FAILED;
	}

	// 获取SDK实例指针
	ApplicationContext* pAC = ApplicationContext::getInstance();
	if (NULL == pAC)
	{
		ERROR_LOG() << "ApplicationContext get instance failed.";
		return eLTE_FAILED;
	}
	OperationManager* pOM = OperationManager_T::instance();
	if (NULL == pOM)
	{
		ERROR_LOG() << "OperationManager_T get instance failed.";
		return eLTE_FAILED;
	}

	// 设置调度台状态
	DcState* pDC = pAC->getConsoleState();
	if (NULL == pDC)
	{
		ERROR_LOG() << "getConsoleState failed.";
		return eLTE_FAILED;
	}
	int iDcId = eLTE_Tool::String2Int(userId);
	pDC->setDCID(iDcId);
	pDC->setUser(userId.c_str());
	pDC->setPwd(passwd.c_str());
	pDC->setServerIP(serverIP.c_str());
	pDC->setLocalIP(localIP.c_str());
	pDC->setSipPort(sipPort.c_str());

	// 设置登录资源
	ResourceInfo* pResInfo = new ResourceInfo(iDcId);
	if (NULL == pResInfo)//lint !e774
	{
		ERROR_LOG() << "new ResourceInfo failed.";
		return eLTE_FAILED;
	}
	pResInfo->setUserName(userId.c_str());
	pResInfo->setPassWord(passwd.c_str());
	pResInfo->setServerIp(serverIP.c_str());
	pResInfo->setLocalIp(localIP.c_str());
	pResInfo->setSipPort(sipPort.c_str());

	// 调度台注册
	Op_Return_t iRet = pOM->invokeOp(pResInfo, DC_LOGIN);
	if (OP_OK_ACCEPTED != iRet)
	{
		// 释放登陆资源
		delete pResInfo;
		ERROR_LOG() << "invokeOp DC_LOGIN failed. (" << iRet << ")";
		return eLTE_FAILED;
	}

	// 释放登陆资源
	delete pResInfo;

	// 启动SDK处理业务
	int sRet = pAC->startRunning(serverIP.c_str());
	if (0 != sRet)
	{
		ERROR_LOG() << "startRunning failed. (" << sRet << ")";
		return sRet;
	}

	Sleep(2000);

	// 触发上报状态
	pAC->triggerStatusReport(bEnableStatusReport);

	// 保存本地数据
	m_userId = userId;
	m_passwd = passwd;
	m_localIP = localIP;
	m_serverIP = serverIP;
	m_sipPort = sipPort;

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 调度台注销
int OperationMgr::DcLogout(const std::string& userId)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(userId);

	// 入参校验
	if (m_userId != userId)
	{
		ERROR_PARAM2(userId, m_userId);
		ERROR_LOG() << "Please login first.";
		return eLTE_FAILED;
	}

	// 获取SDK实例指针
	ApplicationContext * pAC = ApplicationContext::getInstance();
	if (NULL == pAC)
	{
		ERROR_LOG() << "ApplicationContext get instance failed.";
		return eLTE_FAILED;
	}
	OperationManager * pOM = OperationManager_T::instance();
	if (NULL == pOM)
	{
		ERROR_LOG() << "OperationManager_T get instance failed.";
		return eLTE_FAILED;
	}

	// 停止SDK处理业务
	int sRet = pAC->stopRunning();
	if (0 != sRet)
	{
		ERROR_LOG() << "stopRunning failed. (" << sRet << ")";
		return sRet;
	}

	// 设置登出资源
	ResourceInfo* pResInfo = new ResourceInfo(eLTE_Tool::String2Int(userId));
	if (NULL == pResInfo)//lint !e774
	{
		ERROR_LOG() << "new ResourceInfo failed.";
		return eLTE_FAILED;
	}
	pResInfo->setUserName(userId.c_str());
	pResInfo->setPassWord(m_passwd.c_str());
	pResInfo->setServerIp(m_serverIP.c_str());
	pResInfo->setLocalIp(m_localIP.c_str());
	pResInfo->setSipPort(m_sipPort.c_str());

	// 调度台注销
	Op_Return_t iRet = pOM->invokeOp(pResInfo, DC_LOGOUT);
	if (OP_OK_ACCEPTED != iRet)
	{
		ERROR_LOG() << "invokeOp DC_LOGOUT failed. (" << iRet << ")";
	}

	// 释放登出资源
	delete pResInfo;

	// 清理本地变量
	m_userId.clear();
	m_passwd.clear();
	m_localIP.clear();
	m_serverIP.clear();
	m_sipPort.clear();

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

// 触发状态上报
int OperationMgr::DcTriggerStatusReport(bool bEnableStatusReport) const
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(bEnableStatusReport);

	ApplicationContext* pAC = ApplicationContext::getInstance();
	if (NULL == pAC)
	{
		ERROR_LOG() << "ApplicationContext get instance failed.";
		return eLTE_FAILED;
	}

	// 触发上报状态
	pAC->triggerStatusReport(bEnableStatusReport);

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 调度台发起视频回传
int OperationMgr::DcVideoMonitor(int iResId, Video_UL_parameter& param, bool bNeedSave)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM5(iResId, param.fmtvalue, param.cameratype, param.mutetype, param.user_confirm_type);

	// 获取SDK实例指针
	OperationManager* pOM = OperationManager_T::instance();
	if (NULL == pOM)
	{
		ERROR_LOG() << "OperationManager_T get instance failed.";
		return eLTE_FAILED;
	}

	// 构造视频资源
	ResourceInfo* pResInfo = new ResourceInfo(iResId);
	if (NULL == pResInfo)//lint !e774
	{
		ERROR_LOG() << "new ResourceInfo failed.";
		return eLTE_FAILED;
	}

	// 发起视频回传
	Op_Return_t iRet = pOM->invokeOp_multipara(pResInfo, (void*)&param, P2P_VIDEO_MONITOR);
	if (OP_OK_ACCEPTED != iRet)
	{
		ERROR_LOG() << "invokeOp_multipara P2P_VIDEO_MONITOR failed. (" << iRet << ")";
	}

	// 释放视频资源
	delete pResInfo;

	// 保存视频回传资源列表
	if (OP_OK_ACCEPTED == iRet && bNeedSave)
	{
		std::map<int, STVideoParam>::iterator itor = m_mapResource.find(iResId);
		if (m_mapResource.end() != itor)
		{
			STVideoParam& videoParam = itor->second;
			videoParam.strFmtValue = param.fmtvalue;
			videoParam.strCameraType = param.cameratype;
			videoParam.strUserCfmType = param.user_confirm_type;
			videoParam.strMuteType = param.mutetype;
		}
		else
		{
			STVideoParam videoParam;
			videoParam.strFmtValue = param.fmtvalue;
			videoParam.strCameraType = param.cameratype;
			videoParam.strUserCfmType = param.user_confirm_type;
			videoParam.strMuteType = param.mutetype;
			(void)m_mapResource.insert(std::make_pair(iResId, videoParam));
		}
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

// 调度台挂断视频回传
int OperationMgr::DcVideoHangup(int iResId, bool bNeedSave)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iResId);

	// 获取SDK实例指针
	OperationManager* pOM = OperationManager_T::instance();
	if (NULL == pOM)
	{
		ERROR_LOG() << "OperationManager_T get instance failed.";
		return eLTE_FAILED;
	}

	// 构造视频资源
	ResourceInfo* pResInfo = new ResourceInfo(iResId);
	if (NULL == pResInfo)//lint !e774
	{
		ERROR_LOG() << "new ResourceInfo failed.";
		return eLTE_FAILED;
	}

	// 挂断视频回传
	Op_Return_t iRet = pOM->invokeOp(pResInfo, P2P_VIDEO_HANGUP);
	if (OP_OK_ACCEPTED != iRet)
	{
		ERROR_LOG() << "invokeOp P2P_VIDEO_HANGUP failed. (" << iRet << ")";	
	}

	// 释放视频资源
	delete pResInfo;

	// 从视频回传资源列表中删除
	if (OP_OK_ACCEPTED == iRet && bNeedSave)
	{
		std::map<int, STVideoParam>::iterator itor = m_mapResource.find(iResId);
		if (m_mapResource.end() != itor)
		{
			m_mapResource.erase(itor);
		}
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

// 切换摄像头
int OperationMgr::DcVideoReverse(int iResId, STVideoParam& vParam)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iResId);

	// 查找视频回传资源
	std::map<int, STVideoParam>::iterator itor = m_mapResource.find(iResId);
	if (m_mapResource.end() == itor)
	{
		ERROR_LOG() << "Not found the resourceID in m_mapResource.";
		DEBUG_LOG() << "--- LEAVE";
		return eLTE_FAILED;
	}

	// 挂断视频回传
	int iRet = DcVideoHangup(itor->first, false);
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "DcVideoHangup failed.";
		return iRet;
	}

	// 构建视频回传参数
	STVideoParam& videoParam = itor->second;
	videoParam.strCameraType = ("0" == videoParam.strCameraType) ? "1" : "0";//切换摄像头
	videoParam.strUserCfmType = "0";//默认不需要确认
	std::string strFormat = ("0" == videoParam.strCameraType) ? m_strFrontFormat : m_strBackFormat;//使用配置文件中的视频格式
	if (strFormat.empty())
	{
		strFormat = videoParam.strFmtValue;
	}
	videoParam.strFmtValue = strFormat;

	Video_UL_parameter param;
	param.fmtvalue = (char *)strFormat.c_str();//lint !e1773
	param.cameratype = (char *)videoParam.strCameraType.c_str();//lint !e1773
	param.user_confirm_type = (char *)videoParam.strUserCfmType.c_str();//lint !e1773
	param.mutetype = (char *)videoParam.strMuteType.c_str();//lint !e1773

	// 发起视频回传
	iRet = DcVideoMonitor(itor->first, param, false);
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "DcVideoMonitor failed.";
	}
	else
	{
		vParam = videoParam;
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

// 获取是否开启伴音
std::string OperationMgr::GetMuteType(int iResId)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iResId);

	std::string strMuteType = "-1";

	// 查找视频回传资源
	std::map<int, STVideoParam>::iterator itor = m_mapResource.find(iResId);
	if (m_mapResource.end() != itor)
	{
		strMuteType = itor->second.strMuteType;
	}

	DEBUG_LOG() << "--- LEAVE";
	return strMuteType;
}

// 订阅群组
int OperationMgr::DcSubscribeGroup(const std::string& groupId, unsigned long ulEableSubscribeGroup) const
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(groupId, ulEableSubscribeGroup);

	// 获取SDK实例指针
	OperationManager* pOM = OperationManager_T::instance();
	if (NULL == pOM)
	{
		ERROR_LOG() << "OperationManager_T get instance failed.";
		return eLTE_FAILED;
	}

	// 构造群组资源
	ResourceInfo* pResInfo = new ResourceInfo(eLTE_Tool::String2Int(groupId));
	if (NULL == pResInfo)//lint !e774
	{
		ERROR_LOG() << "pResInfo is null.";
		return eLTE_FAILED;
	}

	// 去订阅群组
	Op_Return_t iRet;
	if (0 == ulEableSubscribeGroup)
	{
		iRet = pOM->invokeOp(pResInfo, GRP_UNSUB);
		if (OP_OK_ACCEPTED != iRet)
		{
			ERROR_LOG() << "invokeOp GRP_UNSUB failed. (" << iRet << ")";
		}
	}
	// 订阅群组
	else
	{
		iRet = pOM->invokeOp(pResInfo, GRP_SUB);
		if (OP_OK_ACCEPTED != iRet)
		{
			ERROR_LOG() << "invokeOp GRP_SUB failed. (" << iRet << ")";
		}
	}

	// 释放群组资源
	delete pResInfo;

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

void OperationMgr::SetParam(const std::string& strFrontFormat, const std::string& strBackFormat)
{
	m_strFrontFormat = strFrontFormat;
	m_strBackFormat = strBackFormat;
}
