#include "StdAfx.h"
#include "ProvisionMgr.h"
#include "eLTE_Log.h"


ProvisionMgr::ProvisionMgr(void)
	: m_pProvMgr(NULL)
{
}


ProvisionMgr::~ProvisionMgr(void)
{
	m_pProvMgr = NULL;
}


ProvisionMgr& ProvisionMgr::Instance()
{
	static ProvisionMgr s_ProvisionMgr;
	return s_ProvisionMgr;
}

// 配置管理接口初始化
int ProvisionMgr::Init(const std::string& strSrvIp, int iUserId)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(strSrvIp, iUserId);

	m_pProvMgr = ProvisionManager_T::instance();
	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "ProvisionManager_T instance failed.";
		return eLTE_FAILED;
	}

	m_pProvMgr->init(strSrvIp.c_str(), iUserId);
	m_pProvMgr->initMRS(strSrvIp.c_str());

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 退出配置管理接口
int ProvisionMgr::Exit()
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "m_pProvMgr is null.";
		return eLTE_FAILED;
	}

	m_pProvMgr->exit();
	m_pProvMgr = NULL;

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 获取调度台的群组列表
int ProvisionMgr::GetDcGroups(int iUserId, DcGroups* &pDcGroups)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iUserId);

	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "m_pProvMgr is null.";
		return eLTE_FAILED;
	}

	pDcGroups = m_pProvMgr->getDcGroupsClone(iUserId);
	if (NULL == pDcGroups)
	{
		ERROR_LOG() << "getDcGroupsClone failed.";
		return eLTE_FAILED;
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 获取调度台的用户列表
int ProvisionMgr::GetDcUsers(int iUserId, DcUsers* &pDcUsers)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iUserId);

	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "m_pProvMgr is null.";
		return eLTE_FAILED;
	}

	pDcUsers = m_pProvMgr->getDcUsersClone(iUserId);
	if (NULL == pDcUsers)
	{
		ERROR_LOG() << "getDcUsersClone failed.";
		return eLTE_FAILED;
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 获取一个群组的成员列表
int ProvisionMgr::GetGroupUsers(int iGroupId, GrpUserList* &pGrpUserList)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iGroupId);

	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "m_pProvMgr is null.";
		return eLTE_FAILED;
	}

	pGrpUserList = m_pProvMgr->getGroupUsersClone(iGroupId);
	if (NULL == pGrpUserList)
	{
		ERROR_LOG() << "getGroupUsersClone failed.";
		return eLTE_FAILED;
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 获取一个群组的详细配置信息
int ProvisionMgr::GetGroupInfo(int iGroupId, GroupInfo* &pGroupInfo)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iGroupId);

	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "m_pProvMgr is null.";
		return eLTE_FAILED;
	}

	pGroupInfo = m_pProvMgr->getGroupInfoClone(iGroupId);
	if (NULL == pGroupInfo)
	{
		ERROR_LOG() << "getGroupInfoClone failed.";
		return eLTE_FAILED;
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 获取一个用户的详细信息
eLTE_RET ProvisionMgr::GetUserInfo(int iUserId, UserInfo* &pUserInfo)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iUserId);

	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "m_pProvMgr is null.";
		return eLTE_FAILED;
	}

	pUserInfo = m_pProvMgr->getUserInfoClone(iUserId);
	if (NULL == pUserInfo)
	{
		ERROR_LOG() << "getUserInfoClone failed.";
		return eLTE_FAILED;
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 获取DC详细信息
int ProvisionMgr::GetDcInfo(int iUserId, DcProperty* &pDcProperty)
{
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(iUserId);

	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "m_pProvMgr is null.";
		return eLTE_FAILED;
	}

	pDcProperty = m_pProvMgr->getDcProperty(iUserId);
	if (NULL == pDcProperty)
	{
		ERROR_LOG() << "getDcProperty failed.";
		return eLTE_FAILED;
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 查询录音文件信息
int ProvisionMgr::GetUserRECFileInfoList(RECQueryInfo* pCondition, UserRecFileInfoList* &pInfoList)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == m_pProvMgr)
	{
		ERROR_LOG() << "m_pProvMgr is null.";
		return eLTE_FAILED;
	}

	if (NULL == pCondition)
	{
		ERROR_LOG() << "pCondition is null.";
		return eLTE_INVALID_PARAM;
	}

	pInfoList = m_pProvMgr->getUserRecFileInfoList(pCondition);
	if (NULL == pInfoList)
	{
		ERROR_LOG() << "getUserRecFileInfoList failed.";
		return eLTE_FAILED;
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}
