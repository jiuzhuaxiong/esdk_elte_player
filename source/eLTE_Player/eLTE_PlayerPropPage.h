#pragma once

// eLTE_PlayerPropPage.h : Declaration of the CeLTE_PlayerPropPage property page class.


// CeLTE_PlayerPropPage : See eLTE_PlayerPropPage.cpp for implementation.

class CeLTE_PlayerPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CeLTE_PlayerPropPage)
	DECLARE_OLECREATE_EX(CeLTE_PlayerPropPage)//lint !e1768

// Constructor
public:
	CeLTE_PlayerPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_ELTE_PLAYER };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};//lint !e1712

