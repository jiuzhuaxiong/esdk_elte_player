#include "StdAfx.h"
#include "AppContextMgr.h"
#include "eLTE_Log.h"


AppContextMgr::AppContextMgr(void)
	: m_pDisplayMgr(NULL)
{
}


AppContextMgr::~AppContextMgr(void)
{
	if (NULL != m_pDisplayMgr)
	{
		try
		{
			delete m_pDisplayMgr;
			m_pDisplayMgr = NULL;
		}
		catch ( ... )
		{
			m_pDisplayMgr = NULL;
		}
	}
}


AppContextMgr& AppContextMgr::Instance()
{
	static AppContextMgr s_AppContextMgr;
	return s_AppContextMgr;
}

int AppContextMgr::Init()
{
	DEBUG_LOG() << "--- ENTRY";

	// ��ʼ��ACE
	ACE::init();

	ApplicationContext* pAC = ApplicationContext::getInstance();
	if (NULL == pAC)
	{
		ERROR_LOG() << "ApplicationContext get instance failed.";
		return eLTE_FAILED;
	}
	pAC->setWorkMode(APPMODE_DISPATCH_CONSOLE);
	pAC->setBypassBuildMedia(true);

	if (NULL == m_pDisplayMgr)
	{
		m_pDisplayMgr = new DisplayMgr();
		if (NULL == m_pDisplayMgr)//lint !e774
		{
			ERROR_LOG() << "m_pDisplayMgr is null.";
			return eLTE_FAILED;
		}
	}
	DisplayManager* pDisplayManager = dynamic_cast<DisplayManager*>(m_pDisplayMgr);
	if (NULL == pDisplayManager)
	{
		ERROR_LOG() << "pDisplayManager is null.";
		return eLTE_FAILED;
	}
	pAC->setDisplayManager(pDisplayManager);

	// ��ʼ��SDK�������־������SDK����ʱ�������־
	ubp::platform::trace::UBPTrace* pUBP = ubp::platform::trace::UBPTrace_T::instance();
	if (NULL != pUBP)
	{
		pUBP->Init("DC");
	}	

	// ��ʼ��SDK
	int iRet = pAC->initApp();
	if (0 != iRet)
	{
		ERROR_LOG() << "initApp failed. (" << iRet << ")";
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

int AppContextMgr::Exit() const
{
	DEBUG_LOG() << "--- ENTRY";

	ApplicationContext* pAC = ApplicationContext::getInstance();
	if (NULL == pAC)
	{
		ERROR_LOG() << "ApplicationContext get instance failed.";
		return eLTE_FAILED;
	}

	// �˳�SDK
	int iRet = pAC->exitApp();
	if (0 != iRet)
	{
		ERROR_LOG() << "exitApp failed. (" << iRet << ")";
	}

	// ȥ��ʼ��ACE
	ACE::fini();

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}

void AppContextMgr::SetCeLTE_PlayerCtrl(COleControl* pCeLTE_PlayerCtrl)
{
	if (NULL != m_pDisplayMgr)
	{
		m_pDisplayMgr->SetCeLTE_PlayerCtrl(pCeLTE_PlayerCtrl);
	}
}
