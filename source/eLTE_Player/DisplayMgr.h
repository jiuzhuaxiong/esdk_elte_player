/********************************************************************
filename    :    DisplayMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    eLTE SDKҵ����Ϣ�ص��ࡣͨ��ע����������յ���̨״ָ̬ʾ�¼�
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_DISPLAY_MGR_H__
#define __ELTE_OCX_DISPLAY_MGR_H__


class DisplayMgr : public DisplayManager
{
public:
	DisplayMgr(void);
	virtual ~DisplayMgr(void); //lint !e1510

	//֪ͨ�����״̬�����Ϣ
	virtual void notifyGroupStatus(GrpDspInfo * grpInfo);

	//֪ͨ�û���Ⱥ����Դ��״̬�����Ϣ
	virtual void notifyResourceStatus(ResourceStatusIndicator * resourceStatus);

	//֪ͨ��Ե���е�״̬�����Ϣ
	virtual void notifyP2pcallStatus(P2pcallStatusIndicator * callStatus);

	//֪ͨ��Ƶ���е�״̬�����Ϣ��������Ƶ�ش�������ҪYCʵ��
	virtual void notifyP2pvideocallStatus(P2pvideocallStatusIndicator * callStatus);

	//֪ͨ�û���Ⱥ����Դ��״̬�����Ϣ,��ҪYCʵ��
	virtual void notifyUserStatus(ResourceStatusIndicator * resourceStatus);

	//֪ͨ�û�״̬����Ϣ�ķ������ʵ��
	virtual void notifyUserSdsStatus(SdsMessageIndicator * sdsmsg);

	virtual void notifyModuleStatus(DCModuleStatusIndicator * moduleStatus);

	//��������Ϣ�ϱ���GUI
	virtual void notifySMS(SdsMessageIndicator * sdsmsg);

	//֪ͨ���ö���ı����Ϣ�� ����Ϊһ����ָ̬�룬 ʹ������Ҫdowncast Ϊ��Ӧ�ı������
	virtual void notifyProvisionChange(ProvChangeIndicator* pProvChange);

	//֪ͨ���ö����ȫͬ���� ����Ϊһ����ָ̬�룬 ʹ������Ҫdowncast Ϊ��Ӧ�ı������
	virtual void notifyProvisionAllResync(ProvChangeIndicator* );

	//֪ͨ״̬�����ȫͬ���� ����Ϊһ����ָ̬�룬 ʹ������Ҫdowncast Ϊ��Ӧ�ı������
	virtual void notifyStatusAllResync(ResourceStatusIndicator* );

public:
	// ����eLTE_PlayerCtrl���
	void SetCeLTE_PlayerCtrl(COleControl* pCeLTE_PlayerCtrl);

private:
	COleControl* m_pCeLTE_PlayerCtrl;
};

#endif
