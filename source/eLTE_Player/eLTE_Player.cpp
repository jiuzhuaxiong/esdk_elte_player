// eLTE_Player.cpp : Implementation of CeLTE_PlayerApp and DLL registration.

#include "stdafx.h"
#include "eLTE_Player.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CeLTE_PlayerApp theApp;

const GUID CDECL _tlid = { 0xEBB01215, 0xC409, 0x4D39, { 0xA1, 0x5D, 0x58, 0x16, 0xC3, 0x85, 0x2B, 0xB } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CeLTE_PlayerApp::InitInstance - DLL initialization

BOOL CeLTE_PlayerApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CeLTE_PlayerApp::ExitInstance - DLL termination

int CeLTE_PlayerApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);//lint !e835

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}//lint !e1788



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);//lint !e835

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}//lint !e1788
