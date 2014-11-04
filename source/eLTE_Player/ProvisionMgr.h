/********************************************************************
filename    :    ProvisionMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    调度台配置管理类。负责群组和用户逻辑处理。对应eLTE SDK内的ProvisionManager类
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 初始版本
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
	// 配置管理接口初始化
	int Init(const std::string& strSrvIp, int iUserId);
	// 退出配置管理接口
	int Exit();
	// 获取调度台的群组列表
	int GetDcGroups(int iUserId, DcGroups* &pDcGroups);
	// 获取调度台的用户列表
	int GetDcUsers(int iUserId, DcUsers* &pDcUsers);
	// 获取一个群组的成员列表
	int GetGroupUsers(int iGroupId, GrpUserList* &pGrpUserList);
	// 获取一个群组的详细配置信息
	int GetGroupInfo(int iGroupId, GroupInfo* &pGroupInfo);
	// 获取一个用户的详细信息
	int GetUserInfo(int iUserId, UserInfo* &pUserInfo);
	// 获取DC详细信息
	int GetDcInfo(int iUserId, DcProperty* &pDcProperty);
	// 查询录音文件信息
	int GetUserRECFileInfoList(RECQueryInfo* pCondition, UserRecFileInfoList* &pInfoList);

private:
	ProvisionManager* m_pProvMgr;
};

#endif
