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

// ����̨ע��
int OperationMgr::DcLogin(const std::string& userId, const std::string& passwd, 
	const std::string& serverIP, const std::string& localIP, const std::string& sipPort, bool bEnableStatusReport)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM4(userId, serverIP, localIP, sipPort);

	// ���У��
	if (!m_userId.empty())
	{
		ERROR_LOG() << "Please logout first.";
		return eLTE_FAILED;
	}

	// ��ȡSDKʵ��ָ��
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

	// ���õ���̨״̬
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

	// ���õ�¼��Դ
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

	// ����̨ע��
	Op_Return_t iRet = pOM->invokeOp(pResInfo, DC_LOGIN);
	if (OP_OK_ACCEPTED != iRet)
	{
		// �ͷŵ�½��Դ
		delete pResInfo;
		ERROR_LOG() << "invokeOp DC_LOGIN failed. (" << iRet << ")";
		return eLTE_FAILED;
	}

	// �ͷŵ�½��Դ
	delete pResInfo;

	// ����SDK����ҵ��
	int sRet = pAC->startRunning(serverIP.c_str());
	if (0 != sRet)
	{
		ERROR_LOG() << "startRunning failed. (" << sRet << ")";
		return sRet;
	}

	Sleep(2000);

	// �����ϱ�״̬
	pAC->triggerStatusReport(bEnableStatusReport);

	// ���汾������
	m_userId = userId;
	m_passwd = passwd;
	m_localIP = localIP;
	m_serverIP = serverIP;
	m_sipPort = sipPort;

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// ����̨ע��
int OperationMgr::DcLogout(const std::string& userId)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(userId);

	// ���У��
	if (m_userId != userId)
	{
		ERROR_PARAM2(userId, m_userId);
		ERROR_LOG() << "Please login first.";
		return eLTE_FAILED;
	}

	// ��ȡSDKʵ��ָ��
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

	// ֹͣSDK����ҵ��
	int sRet = pAC->stopRunning();
	if (0 != sRet)
	{
		ERROR_LOG() << "stopRunning failed. (" << sRet << ")";
		return sRet;
	}

	// ���õǳ���Դ
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

	// ����̨ע��
	Op_Return_t iRet = pOM->invokeOp(pResInfo, DC_LOGOUT);
	if (OP_OK_ACCEPTED != iRet)
	{
		ERROR_LOG() << "invokeOp DC_LOGOUT failed. (" << iRet << ")";
	}

	// �ͷŵǳ���Դ
	delete pResInfo;

	// �����ر���
	m_userId.clear();
	m_passwd.clear();
	m_localIP.clear();
	m_serverIP.clear();
	m_sipPort.clear();

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

// ����״̬�ϱ�
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

	// �����ϱ�״̬
	pAC->triggerStatusReport(bEnableStatusReport);

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// ����̨������Ƶ�ش�
int OperationMgr::DcVideoMonitor(int iResId, Video_UL_parameter& param, bool bNeedSave)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM5(iResId, param.fmtvalue, param.cameratype, param.mutetype, param.user_confirm_type);

	// ��ȡSDKʵ��ָ��
	OperationManager* pOM = OperationManager_T::instance();
	if (NULL == pOM)
	{
		ERROR_LOG() << "OperationManager_T get instance failed.";
		return eLTE_FAILED;
	}

	// ������Ƶ��Դ
	ResourceInfo* pResInfo = new ResourceInfo(iResId);
	if (NULL == pResInfo)//lint !e774
	{
		ERROR_LOG() << "new ResourceInfo failed.";
		return eLTE_FAILED;
	}

	// ������Ƶ�ش�
	Op_Return_t iRet = pOM->invokeOp_multipara(pResInfo, (void*)&param, P2P_VIDEO_MONITOR);
	if (OP_OK_ACCEPTED != iRet)
	{
		ERROR_LOG() << "invokeOp_multipara P2P_VIDEO_MONITOR failed. (" << iRet << ")";
	}

	// �ͷ���Ƶ��Դ
	delete pResInfo;

	// ������Ƶ�ش���Դ�б�
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

// ����̨�Ҷ���Ƶ�ش�
int OperationMgr::DcVideoHangup(int iResId, bool bNeedSave)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iResId);

	// ��ȡSDKʵ��ָ��
	OperationManager* pOM = OperationManager_T::instance();
	if (NULL == pOM)
	{
		ERROR_LOG() << "OperationManager_T get instance failed.";
		return eLTE_FAILED;
	}

	// ������Ƶ��Դ
	ResourceInfo* pResInfo = new ResourceInfo(iResId);
	if (NULL == pResInfo)//lint !e774
	{
		ERROR_LOG() << "new ResourceInfo failed.";
		return eLTE_FAILED;
	}

	// �Ҷ���Ƶ�ش�
	Op_Return_t iRet = pOM->invokeOp(pResInfo, P2P_VIDEO_HANGUP);
	if (OP_OK_ACCEPTED != iRet)
	{
		ERROR_LOG() << "invokeOp P2P_VIDEO_HANGUP failed. (" << iRet << ")";	
	}

	// �ͷ���Ƶ��Դ
	delete pResInfo;

	// ����Ƶ�ش���Դ�б���ɾ��
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

// �л�����ͷ
int OperationMgr::DcVideoReverse(int iResId, STVideoParam& vParam)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iResId);

	// ������Ƶ�ش���Դ
	std::map<int, STVideoParam>::iterator itor = m_mapResource.find(iResId);
	if (m_mapResource.end() == itor)
	{
		ERROR_LOG() << "Not found the resourceID in m_mapResource.";
		DEBUG_LOG() << "--- LEAVE";
		return eLTE_FAILED;
	}

	// �Ҷ���Ƶ�ش�
	int iRet = DcVideoHangup(itor->first, false);
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "DcVideoHangup failed.";
		return iRet;
	}

	// ������Ƶ�ش�����
	STVideoParam& videoParam = itor->second;
	videoParam.strCameraType = ("0" == videoParam.strCameraType) ? "1" : "0";//�л�����ͷ
	videoParam.strUserCfmType = "0";//Ĭ�ϲ���Ҫȷ��
	std::string strFormat = ("0" == videoParam.strCameraType) ? m_strFrontFormat : m_strBackFormat;//ʹ�������ļ��е���Ƶ��ʽ
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

	// ������Ƶ�ش�
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

// ��ȡ�Ƿ�������
std::string OperationMgr::GetMuteType(int iResId)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iResId);

	std::string strMuteType = "-1";

	// ������Ƶ�ش���Դ
	std::map<int, STVideoParam>::iterator itor = m_mapResource.find(iResId);
	if (m_mapResource.end() != itor)
	{
		strMuteType = itor->second.strMuteType;
	}

	DEBUG_LOG() << "--- LEAVE";
	return strMuteType;
}

// ����Ⱥ��
int OperationMgr::DcSubscribeGroup(const std::string& groupId, unsigned long ulEableSubscribeGroup) const
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(groupId, ulEableSubscribeGroup);

	// ��ȡSDKʵ��ָ��
	OperationManager* pOM = OperationManager_T::instance();
	if (NULL == pOM)
	{
		ERROR_LOG() << "OperationManager_T get instance failed.";
		return eLTE_FAILED;
	}

	// ����Ⱥ����Դ
	ResourceInfo* pResInfo = new ResourceInfo(eLTE_Tool::String2Int(groupId));
	if (NULL == pResInfo)//lint !e774
	{
		ERROR_LOG() << "pResInfo is null.";
		return eLTE_FAILED;
	}

	// ȥ����Ⱥ��
	Op_Return_t iRet;
	if (0 == ulEableSubscribeGroup)
	{
		iRet = pOM->invokeOp(pResInfo, GRP_UNSUB);
		if (OP_OK_ACCEPTED != iRet)
		{
			ERROR_LOG() << "invokeOp GRP_UNSUB failed. (" << iRet << ")";
		}
	}
	// ����Ⱥ��
	else
	{
		iRet = pOM->invokeOp(pResInfo, GRP_SUB);
		if (OP_OK_ACCEPTED != iRet)
		{
			ERROR_LOG() << "invokeOp GRP_SUB failed. (" << iRet << ")";
		}
	}

	// �ͷ�Ⱥ����Դ
	delete pResInfo;

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

void OperationMgr::SetParam(const std::string& strFrontFormat, const std::string& strBackFormat)
{
	m_strFrontFormat = strFrontFormat;
	m_strBackFormat = strBackFormat;
}
