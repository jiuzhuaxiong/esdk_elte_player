// eLTE_PlayerPropPage.cpp : Implementation of the CeLTE_PlayerPropPage property page class.

#include "stdafx.h"
#include "eLTE_Player.h"
#include "eLTE_PlayerPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CeLTE_PlayerPropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CeLTE_PlayerPropPage, COlePropertyPage)//lint !e830
END_MESSAGE_MAP()//lint !e751



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CeLTE_PlayerPropPage, "ELTE_PLAYER.eLTE_PlayerPropPage.1",
	0x702cc239, 0xc8ef, 0x4095, 0xab, 0x9, 0x23, 0xa4, 0xad, 0xe9, 0x3a, 0x1d)



// CeLTE_PlayerPropPage::CeLTE_PlayerPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CeLTE_PlayerPropPage

BOOL CeLTE_PlayerPropPage::CeLTE_PlayerPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ELTE_PLAYER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CeLTE_PlayerPropPage::CeLTE_PlayerPropPage - Constructor

CeLTE_PlayerPropPage::CeLTE_PlayerPropPage() :
	COlePropertyPage(IDD, IDS_ELTE_PLAYER_PPG_CAPTION)
{
}



// CeLTE_PlayerPropPage::DoDataExchange - Moves data between page and properties

void CeLTE_PlayerPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CeLTE_PlayerPropPage message handlers
