﻿#pragma once

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit
#define _ATL_NO_AUTOMATIC_NAMESPACE             // avoid class name conflicts

#include <afxctl.h>         // MFC support for ActiveX Controls
#include <afxext.h>         // MFC extensions
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Comon Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

// Delete the two includes below if you do not wish to use the MFC
//  database classes
#ifndef _WIN64

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#endif // _WIN64



#ifndef UNICODE
#define UNICODE
#endif


#include <string>
#include <set>

// CImage
#include <atlimage.h>

// GDI+
#include <GdiPlus.h>
#pragma comment(lib, "GdiPlus.lib")

//IVS_MP
#include "IVS_NetSource.h"
#include "IVS_Player.h"

// eLTE_SDK
#include "ace/ACE.h"
#include "log4cxx/logger.h"
#include "dc/dc_module_error.h"
#include "appcontext.h"
#include "operationmanager.h"
#include "provisionmanager.h"
#include "platform/modules/trace/ubp_trace.hpp"
#include "dcstate.h"
