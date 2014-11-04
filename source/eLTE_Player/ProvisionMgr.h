/********************************************************************
filename    :    ProvisionMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    ����̨���ù����ࡣ����Ⱥ����û��߼�������ӦeLTE SDK�ڵ�ProvisionManager��
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_PROVISION_MGR_H__
#define __ELTE_OCX_PROVISION_MGR_H__

#include "DataType.h"


class ProvisionMgr
{
public:
	static ProvisionMgr& Instance();

private:
	ProvisionMgr(void);
	~ProvisionMgr(void);

public:
	// ���ù���ӿڳ�ʼ��
	int Init(const std::string& strSrvIp, int iUserId);
	// �˳����ù���ӿ�
	int Exit();
	// ��ȡ����̨��Ⱥ���б�
	int GetDcGroups(int iUserId, DcGroups* &pDcGroups);
	// ��ȡ����̨���û��б�
	int GetDcUsers(int iUserId, DcUsers* &pDcUsers);
	// ��ȡһ��Ⱥ��ĳ�Ա�б�
	int GetGroupUsers(int iGroupId, GrpUserList* &pGrpUserList);
	// ��ȡһ��Ⱥ�����ϸ������Ϣ
	int GetGroupInfo(int iGroupId, GroupInfo* &pGroupInfo);
	// ��ȡһ���û�����ϸ��Ϣ
	int GetUserInfo(int iUserId, UserInfo* &pUserInfo);
	// ��ȡDC��ϸ��Ϣ
	int GetDcInfo(int iUserId, DcProperty* &pDcProperty);
	// ��ѯ¼���ļ���Ϣ
	int GetUserRECFileInfoList(RECQueryInfo* pCondition, UserRecFileInfoList* &pInfoList);

private:
	ProvisionManager* m_pProvMgr;
};

#endif
