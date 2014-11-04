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

// ���ù���ӿڳ�ʼ��
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

// �˳����ù���ӿ�
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

// ��ȡ����̨��Ⱥ���б�
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

// ��ȡ����̨���û��б�
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

// ��ȡһ��Ⱥ��ĳ�Ա�б�
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

// ��ȡһ��Ⱥ�����ϸ������Ϣ
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

// ��ȡһ���û�����ϸ��Ϣ
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

// ��ȡDC��ϸ��Ϣ
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

// ��ѯ¼���ļ���Ϣ
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
