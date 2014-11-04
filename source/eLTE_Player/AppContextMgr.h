/********************************************************************
filename    :    AppContextMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    调度台初始化、退出、登陆、登出逻辑实现类。对应于eLTE SDK内的ApplicationContext类
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 初始版本
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
	// 初始化SDK
	int Init();
	// 退出SDK
	int Exit() const;
	// 设置eLTE_PlayerCtrl句柄
	void SetCeLTE_PlayerCtrl(COleControl* pCeLTE_PlayerCtrl);

private:
	// 注册的DisplayManager回调类实例
	DisplayMgr* m_pDisplayMgr;
};

#endif
