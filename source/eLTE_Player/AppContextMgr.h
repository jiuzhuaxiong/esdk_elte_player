/********************************************************************
filename    :    AppContextMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    ����̨��ʼ�����˳�����½���ǳ��߼�ʵ���ࡣ��Ӧ��eLTE SDK�ڵ�ApplicationContext��
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_APPCONTEXT_MGR_H__
#define __ELTE_OCX_APPCONTEXT_MGR_H__

#include "DataType.h"
#include "DisplayMgr.h"


class AppContextMgr
{
public:
	static AppContextMgr& Instance();

private:
	AppContextMgr(void);
	~AppContextMgr(void);

public:
	// ��ʼ��SDK
	int Init();
	// �˳�SDK
	int Exit() const;
	// ����eLTE_PlayerCtrl���
	void SetCeLTE_PlayerCtrl(COleControl* pCeLTE_PlayerCtrl);

private:
	// ע���DisplayManager�ص���ʵ��
	DisplayMgr* m_pDisplayMgr;
};

#endif
