/********************************************************************
filename    :    DisplayMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    eLTE SDK业务消息回调类。通过注册该类来接收调度台状态指示事件
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 初始版本
*********************************************************************/

#ifndef __ELTE_OCX_DISPLAY_MGR_H__
#define __ELTE_OCX_DISPLAY_MGR_H__


class DisplayMgr : public DisplayManager
{
public:
	DisplayMgr(void);
	virtual ~DisplayMgr(void); //lint !e1510

	//通知组呼的状态变更信息
	virtual void notifyGroupStatus(GrpDspInfo * grpInfo);

	//通知用户和群组资源的状态变更信息
	virtual void notifyResourceStatus(ResourceStatusIndicator * resourceStatus);

	//通知点对点呼叫的状态变更信息
	virtual void notifyP2pcallStatus(P2pcallStatusIndicator * callStatus);

	//通知视频呼叫的状态变更信息（包括视频回传），需要YC实现
	virtual void notifyP2pvideocallStatus(P2pvideocallStatusIndicator * callStatus);

	//通知用户和群组资源的状态变更信息,需要YC实现
	virtual void notifyUserStatus(ResourceStatusIndicator * resourceStatus);

	//通知用户状态短消息的服务接收实现
	virtual void notifyUserSdsStatus(SdsMessageIndicator * sdsmsg);

	virtual void notifyModuleStatus(DCModuleStatusIndicator * moduleStatus);

	//短数据信息上报给GUI
	virtual void notifySMS(SdsMessageIndicator * sdsmsg);

	//通知配置对象的变更信息， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
	virtual void notifyProvisionChange(ProvChangeIndicator* pProvChange);

	//通知配置对象的全同步， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
	virtual void notifyProvisionAllResync(ProvChangeIndicator* );

	//通知状态对象的全同步， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
	virtual void notifyStatusAllResync(ResourceStatusIndicator* );

public:
	// 设置eLTE_PlayerCtrl句柄
	void SetCeLTE_PlayerCtrl(COleControl* pCeLTE_PlayerCtrl);

private:
	COleControl* m_pCeLTE_PlayerCtrl;
};

#endif
