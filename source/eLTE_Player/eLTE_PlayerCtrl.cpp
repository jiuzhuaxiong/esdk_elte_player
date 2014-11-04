// eLTE_PlayerCtrl.cpp : Implementation of the CeLTE_PlayerCtrl ActiveX Control class.

#include "stdafx.h"
#include "eLTE_Player.h"
#include "eLTE_PlayerCtrl.h"
#include "eLTE_PlayerPropPage.h"
#include "afxdialogex.h"
#include "eLTE_Tool.h"
#include "eLTE_Log.h"
#include "XMLProcess.h"
#include "eLTE_Xml.h"
#include "mq/p2pvideocallstatus_indicator.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//lint -e1788
IMPLEMENT_DYNCREATE(CeLTE_PlayerCtrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CeLTE_PlayerCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_MOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_MESSAGE(WM_ELTE_EXIT_FULL_SCREEN, OnMsgExitFullScreen)
	ON_MESSAGE(WM_ELTE_POST_EVENT, OnMsgPostEvent)
	ON_MESSAGE(WM_ELTE_POST_PLAYER_EVENT, OnMsgPostPlayerEvent)
	ON_MESSAGE(WM_ELTE_VIDEO_EXIT, OnMsgStopVideoPlay)
END_MESSAGE_MAP()//lint -e786



// Dispatch map

BEGIN_DISPATCH_MAP(CeLTE_PlayerCtrl, COleControl)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_SetLogPath", dispidELTE_OCX_SetLogPath, ELTE_OCX_SetLogPath, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_SetLogLevel", dispidELTE_OCX_SetLogLevel, ELTE_OCX_SetLogLevel, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_UploadLogo", dispidELTE_OCX_UploadLogo, ELTE_OCX_UploadLogo, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_GetVersion", dispidELTE_OCX_GetVersion, ELTE_OCX_GetVersion, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_SetLanguage", dispidELTE_OCX_SetLanguage, ELTE_OCX_SetLanguage, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_ShowToolbar", dispidELTE_OCX_ShowToolbar, ELTE_OCX_ShowToolbar, VT_BSTR, VTS_I4)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_Load", dispidELTE_OCX_Load, ELTE_OCX_Load, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_UnLoad", dispidELTE_OCX_UnLoad, ELTE_OCX_UnLoad, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_Login", dispidELTE_OCX_Login, ELTE_OCX_Login, VT_BSTR, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_Logout", dispidELTE_OCX_Logout, ELTE_OCX_Logout, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_TriggerStatusReport", dispidELTE_OCX_TriggerStatusReport, ELTE_OCX_TriggerStatusReport, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_ProvisionManagerInit", dispidELTE_OCX_ProvisionManagerInit, ELTE_OCX_ProvisionManagerInit, VT_BSTR, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_ProvisionManagerExit", dispidELTE_OCX_ProvisionManagerExit, ELTE_OCX_ProvisionManagerExit, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_GetDcGroups", dispidELTE_OCX_GetDcGroups, ELTE_OCX_GetDcGroups, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_GetDcUsers", dispidELTE_OCX_GetDcUsers, ELTE_OCX_GetDcUsers, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_GetGroupUsers", dispidELTE_OCX_GetGroupUsers, ELTE_OCX_GetGroupUsers, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_GetGroupInfo", dispidELTE_OCX_GetGroupInfo, ELTE_OCX_GetGroupInfo, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_GetUserInfo", dispidELTE_OCX_GetUserInfo, ELTE_OCX_GetUserInfo, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_GetDcInfo", dispidELTE_OCX_GetDcInfo, ELTE_OCX_GetDcInfo, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_SubscribeGroup", dispidELTE_OCX_SubscribeGroup, ELTE_OCX_SubscribeGroup, VT_BSTR, VTS_BSTR VTS_UI4)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_GetUserRECFileInfoList", dispidELTE_OCX_GetUserRECFileInfoList, ELTE_OCX_GetUserRECFileInfoList, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_StartRealPlay", dispidELTE_OCX_StartRealPlay, ELTE_OCX_StartRealPlay, VT_BSTR, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_ReverseRealPlay", dispidELTE_OCX_ReverseRealPlay, ELTE_OCX_ReverseRealPlay, VT_BSTR, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_StopRealPlay", dispidELTE_OCX_StopRealPlay, ELTE_OCX_StopRealPlay, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_ShowRealPlay", dispidELTE_OCX_ShowRealPlay, ELTE_OCX_ShowRealPlay, VT_BSTR, VTS_BSTR VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_Snapshot", dispidELTE_OCX_Snapshot, ELTE_OCX_Snapshot, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_HideRealPlay", dispidELTE_OCX_HideRealPlay, ELTE_OCX_HideRealPlay, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_PlaySound", dispidELTE_OCX_PlaySound, ELTE_OCX_PlaySound, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_StopSound", dispidELTE_OCX_StopSound, ELTE_OCX_StopSound, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_SetVideoWindowPos", dispidELTE_OCX_SetVideoWindowPos, ELTE_OCX_SetVideoWindowPos, VT_BSTR, VTS_UI4 VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_FullScreenDisplay", dispidELTE_OCX_FullScreenDisplay, ELTE_OCX_FullScreenDisplay, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_NormalScreenDisplay", dispidELTE_OCX_NormalScreenDisplay, ELTE_OCX_NormalScreenDisplay, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CeLTE_PlayerCtrl, "ELTE_OCX_SetTitleText", dispidELTE_OCX_SetTitleText, ELTE_OCX_SetTitleText, VT_BSTR, VTS_BSTR)
END_DISPATCH_MAP()//lint -e786



// Event map

BEGIN_EVENT_MAP(CeLTE_PlayerCtrl, COleControl)
	EVENT_CUSTOM_ID("ELTE_OCX_Event", eventidELTE_OCX_Event, ELTE_OCX_Event, VTS_UI4 VTS_BSTR)
	EVENT_CUSTOM_ID("ELTE_OCX_PlayerEvent", eventidELTE_OCX_PlayerEvent, ELTE_OCX_PlayerEvent, VTS_UI4 VTS_BSTR)
END_EVENT_MAP()//lint -e786



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CeLTE_PlayerCtrl, 1)
	PROPPAGEID(CeLTE_PlayerPropPage::guid)
END_PROPPAGEIDS(CeLTE_PlayerCtrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CeLTE_PlayerCtrl, "ELTE_PLAYER.eLTE_PlayerCtrl.1",
	0x6ab35b6f, 0xd5d4, 0x4da3, 0x95, 0x3, 0x1a, 0xd4, 0xe5, 0xe1, 0xe5, 0x89)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CeLTE_PlayerCtrl, _tlid, _wVerMajor, _wVerMinor)



// Interface IDs

const IID IID_DeLTE_Player = { 0x76935AE5, 0xA248, 0x4C3E, { 0x87, 0x59, 0x0, 0xB6, 0x16, 0xF9, 0x7F, 0x41 } };
const IID IID_DeLTE_PlayerEvents = { 0x241C1E26, 0xBFDE, 0x49BC, { 0xA4, 0x40, 0xE6, 0xC2, 0x8D, 0xF3, 0xA7, 0xEE } };


// Control type information

static const DWORD _dweLTE_PlayerOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CeLTE_PlayerCtrl, IDS_ELTE_PLAYER, _dweLTE_PlayerOleMisc)



// CeLTE_PlayerCtrl::CeLTE_PlayerCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CeLTE_PlayerCtrl

BOOL CeLTE_PlayerCtrl::CeLTE_PlayerCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_ELTE_PLAYER,
			IDB_ELTE_PLAYER,
			afxRegApartmentThreading,
			_dweLTE_PlayerOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


HHOOK CeLTE_PlayerCtrl::s_KeyboardHook = NULL;
HHOOK CeLTE_PlayerCtrl::s_MouseHook = NULL;
std::set<CeLTE_PlayerCtrl*> CeLTE_PlayerCtrl::m_eLTE_PlayerList;
std::map<int, CeLTE_PlayerCtrl*> CeLTE_PlayerCtrl::m_WaitPlayVideoList;

// CeLTE_PlayerCtrl::CeLTE_PlayerCtrl - Constructor

CeLTE_PlayerCtrl::CeLTE_PlayerCtrl()
	: m_GdiplusToken(0)
	, m_ulType(0)
	, m_bHaveLoaded(FALSE)
	, m_bIsLogin(FALSE)
	, m_bEnableStatusReport(true)
{
	InitializeIIDs(&IID_DeLTE_Player, &IID_DeLTE_PlayerEvents);
	// TODO: Initialize your control's instance data here.
}



// CeLTE_PlayerCtrl::~CeLTE_PlayerCtrl - Destructor

CeLTE_PlayerCtrl::~CeLTE_PlayerCtrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CeLTE_PlayerCtrl::OnDraw - Drawing function

void CeLTE_PlayerCtrl::OnDraw(
			CDC* pdc, const CRect& /*rcBounds*/, const CRect& /*rcInvalid*/)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
}//lint -e715



// CeLTE_PlayerCtrl::DoPropExchange - Persistence support

void CeLTE_PlayerCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CeLTE_PlayerCtrl::OnResetState - Reset control to default state

void CeLTE_PlayerCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}



// CeLTE_PlayerCtrl::AboutBox - Display an "About" box to the user

void CeLTE_PlayerCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_ELTE_PLAYER);
	dlgAbout.DoModal();
}//lint !e1762



// CeLTE_PlayerCtrl message handlers

LRESULT CALLBACK CeLTE_PlayerCtrl::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (HC_ACTION == nCode)
	{
		KBDLLHOOKSTRUCT *pkbh = (KBDLLHOOKSTRUCT *)lParam;
		if (NULL != pkbh)
		{
			if (VK_ESCAPE == pkbh->vkCode)
			{
				std::set<CeLTE_PlayerCtrl*>::iterator itor = m_eLTE_PlayerList.begin();
				for (; m_eLTE_PlayerList.end() != itor; itor++)
				{
					CeLTE_PlayerCtrl* pOcx = *itor;
					if (NULL != pOcx)
					{
						pOcx->PostMessage(WM_ELTE_EXIT_FULL_SCREEN);
					}
				}
				return 1L;
			}
		}
	}

	return CallNextHookEx(s_KeyboardHook, nCode, wParam, lParam);
}

LRESULT CALLBACK CeLTE_PlayerCtrl::MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (HC_ACTION == nCode)
	{
		// 全屏时忽略鼠标事件
		return 1L;
	}

	return CallNextHookEx(s_KeyboardHook, nCode, wParam, lParam);
}

int CeLTE_PlayerCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	(void)m_ConfigMgr.Init();

	return 0;
}

void CeLTE_PlayerCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (NULL != m_VideoPane.GetSafeHwnd())
	{
		m_VideoPane.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOMOVE);
	}
}

void CeLTE_PlayerCtrl::OnMove(int x, int y)
{
	COleControl::OnMove(x, y);

	// TODO: Add your message handler code here
	if (NULL != m_VideoPane.GetSafeHwnd())
	{
		m_VideoPane.SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE);
	}
}

void CeLTE_PlayerCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (NULL != m_VideoPane.GetSafeHwnd() && !m_VideoPane.IsFullScreen())
	{
		int iRet = m_VideoPane.SetFullScreen();
		if (eLTE_SUCCESS == iRet)
		{
			// 播放器全屏事件
			PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_FULLSCREEN, NULL);
		}
	}

	COleControl::OnLButtonDblClk(nFlags, point);
}

LRESULT CeLTE_PlayerCtrl::OnMsgExitFullScreen(WPARAM wparam, LPARAM lparam)
{
	if (NULL != m_VideoPane.GetSafeHwnd() && m_VideoPane.IsFullScreen())
	{
		int iRet = m_VideoPane.ResetFullScreen();
		if (eLTE_SUCCESS == iRet)
		{
			// 播放器退出全屏事件
			PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_NORMALSCREEN, NULL);
		}
	}

	return 0L;
}

LRESULT CeLTE_PlayerCtrl::OnMsgPostEvent(WPARAM wparam, LPARAM lparam)
{
	DEBUG_LOG() << "--- ENTRY";

	int iEventId = (int)wparam;
	INFO_PARAM1(iEventId);

	CString xmlStr("");
	switch (iEventId)
	{
	case EVENT_NOTIFY_USER_STATUS:				// 设备状态变化事件通知
		{
			NotifyUserStatusInfo* pInfo = (NotifyUserStatusInfo*)lparam;
			if (NULL == pInfo)
			{
				ERROR_LOG() << "pInfo is null.";
				DEBUG_LOG() << "--- LEAVE";
				return -1L;
			}			
			eLTE_RET iRet = XMLProcess::SetXmlStringEventNotifyUserStatus(pInfo, xmlStr);
			if (eLTE_SUCCESS != iRet)
			{
				delete pInfo;
				ERROR_LOG() << "SetXmlStringEventNotifyUserStatus failed.";
				DEBUG_LOG() << "--- LEAVE";				
				return -1L;
			}
			delete pInfo;
		}
		break;
	case EVENT_NOTIFY_P2P_VIDEO_CALL_STATUS:	// 开始实况事件通知
		{
			NotifyP2pvideocallStatusInfo* pInfo = (NotifyP2pvideocallStatusInfo*)lparam;
			if (NULL == pInfo)
			{
				ERROR_LOG() << "pInfo is null.";
				DEBUG_LOG() << "--- LEAVE";
				return -1L;
			}			
			eLTE_RET iRet = XMLProcess::SetXmlStringEventNotifyP2pvideocallStatus(pInfo, xmlStr);
			if (eLTE_SUCCESS != iRet)
			{
				delete pInfo;
				ERROR_LOG() << "SetXmlStringEventNotifyP2pvideocallStatus failed.";
				DEBUG_LOG() << "--- LEAVE";				
				return -1L;
			}

			// 设置视频参数，用于工具栏操作
			if (P2Pvideocall_IND_STATUS_ANSWERED == pInfo->iCallStatus
				|| P2Pvideocall_IND_STATUS_ACKED == pInfo->iCallStatus
				|| P2Pvideocall_IND_STATUS_REMOTE_NOTSUPPORTED == pInfo->iCallStatus)
			{
				// 正在等待播放视频，用于工具栏播放视频
				std::map<int, CeLTE_PlayerCtrl*>::iterator itor = m_WaitPlayVideoList.find(pInfo->iCallee);
				if (m_WaitPlayVideoList.end() == itor)
				{
					itor = m_WaitPlayVideoList.find(pInfo->iCaller);
				}
				if (m_WaitPlayVideoList.end() != itor)
				{
					CeLTE_PlayerCtrl* &pOCX = itor->second;
					if (NULL != pOCX)
					{
						MediaPlayer& mediaPlayer = pOCX->m_MediaPlayer;
						CVideoPane& videoPane = pOCX->m_VideoPane;

						if (P2Pvideocall_IND_STATUS_ANSWERED == pInfo->iCallStatus
							|| P2Pvideocall_IND_STATUS_ACKED == pInfo->iCallStatus)
						{
							// 设置播放参数
							mediaPlayer.SetPlayerParam((unsigned int)pInfo->iLocalVideoPort, (unsigned int)pInfo->iLocalAudioPort, (unsigned int)pInfo->iRemoteVideoPort, (unsigned int)pInfo->iRemoteAudioPort);

							// 播放视频
							(void)mediaPlayer.StartPlayer(videoPane.GetVideoStaticSafeHwnd());
						}

						// 激活工具栏按钮
						videoPane.EnableImageButton(TRUE);
					}

					m_WaitPlayVideoList.erase(itor);
				}
			}			

			delete pInfo;
		}
		break;
	case EVENT_NOTIFY_RESOURCE_STATUS:			// 群组关系状态变化事件通知
		{
			NotifyResourceStatusInfo* pInfo = (NotifyResourceStatusInfo*)lparam;
			if (NULL == pInfo)
			{
				ERROR_LOG() << "pInfo is null.";
				DEBUG_LOG() << "--- LEAVE";
				return -1L;
			}			
			eLTE_RET iRet = XMLProcess::SetXmlStringEventNotifyResourceStatus(pInfo, xmlStr);
			if (eLTE_SUCCESS != iRet)
			{
				delete pInfo;
				ERROR_LOG() << "SetXmlStringEventNotifyResourceStatus failed.";
				DEBUG_LOG() << "--- LEAVE";				
				return -1L;
			}
			delete pInfo;
		}
		break;
	case EVENT_NOTIFY_PROVISION_CHANGE:			// 设备属性配置变更通知事件
		{
			NotifyProvisionChangeInfo* pInfo = (NotifyProvisionChangeInfo*)lparam;
			if (NULL == pInfo)
			{
				ERROR_LOG() << "pInfo is null.";
				DEBUG_LOG() << "--- LEAVE";
				return -1L;
			}			
			eLTE_RET iRet = XMLProcess::SetXmlStringEventNotifyProvisionChange(pInfo, xmlStr);
			if (eLTE_SUCCESS != iRet)
			{
				delete pInfo;
				ERROR_LOG() << "SetXmlStringEventNotifyProvisionChange failed.";
				DEBUG_LOG() << "--- LEAVE";				
				return -1L;
			}
			delete pInfo;
		}
		break;
	case EVENT_NOTIFY_PROVISION_ALLRESYNC:		// 自动下载配置数据通知事件
		{
			// 不用做处理
		}
		break;
	case EVENT_NOTIFY_P2P_CALL_STATUS:			// 点呼状态变化事件
		{
			NotifyP2pcallStatusInfo* pInfo = (NotifyP2pcallStatusInfo*)lparam;
			if (NULL == pInfo)
			{
				ERROR_LOG() << "pInfo is null.";
				DEBUG_LOG() << "--- LEAVE";
				return -1L;
			}
			eLTE_RET iRet = XMLProcess::SetXmlStringEventNotifyP2pcallStatus(pInfo, xmlStr);
			if (eLTE_SUCCESS != iRet)
			{
				delete pInfo;
				ERROR_LOG() << "SetXmlStringEventNotifyP2pcallStatus failed.";
				DEBUG_LOG() << "--- LEAVE";				
				return -1L;
			}
			delete pInfo;
		}
		break;
	case EVENT_NOTIFY_GROUP_STATUS:				// 组呼状态变化事件
		{
			NotifyGroupStatusInfo* pInfo = (NotifyGroupStatusInfo*)lparam;
			if (NULL == pInfo)
			{
				ERROR_LOG() << "pInfo is null.";
				DEBUG_LOG() << "--- LEAVE";
				return -1L;
			}
			eLTE_RET iRet = XMLProcess::SetXmlStringEventNotifyGroupStatus(pInfo, xmlStr);
			if (eLTE_SUCCESS != iRet)
			{
				delete pInfo;
				ERROR_LOG() << "SetXmlStringEventNotifyGroupStatus failed.";
				DEBUG_LOG() << "--- LEAVE";				
				return -1L;
			}
			delete pInfo;
		}
		break;
	default:
		{
			ERROR_LOG() << "Invalid eventId.";
			return -1L;
		}
	}	
	
	// fireEvent
	DEBUG_LOG() << "Enter ELTE_OCX_Event";
	ELTE_OCX_Event((ULONG)iEventId, xmlStr);
	DEBUG_LOG() << "Leave ELTE_OCX_Event";

	DEBUG_LOG() << "--- LEAVE";
	return 0L;
}

LRESULT CeLTE_PlayerCtrl::OnMsgPostPlayerEvent(WPARAM wparam, LPARAM lparam)
{
	DEBUG_LOG() << "--- ENTRY";

	int iEventId = (int)wparam;
	INFO_PARAM1(iEventId);
	CString xmlStr(_T(""));
	switch (iEventId)
	{
	case eLTE_PLAYER_HIDE:
	case eLTE_PLAYER_SHOW:
	case eLTE_PLAYER_FULLSCREEN:
	case eLTE_PLAYER_NORMALSCREEN:
	case eLTE_PLAYER_MUTE:
	case eLTE_PLAYER_UNMUTE:
		break;
	case eLTE_PLAYER_REVERSE:
	case eLTE_PLAYER_SNAPSHOT:
	case eLTE_PLAYER_POSITION:
	case eLTE_PLAYER_TITLE:
		{
			PlayerEventParamInfo* pInfo = (PlayerEventParamInfo*)lparam;
			if (NULL == pInfo)
			{
				ERROR_LOG() << "pInfo is null.";
				return -1L;
			}

			eLTE_RET iRet = XMLProcess::SetXmlStringPlayerEvent(iEventId, pInfo, xmlStr);
			if (eLTE_SUCCESS != iRet)
			{
				delete pInfo;
				ERROR_LOG() << "SetXmlStringPlayerEvent failed.";
				DEBUG_LOG() << "--- LEAVE";				
				return -1L;
			}

			delete pInfo;
		}
		break;
	default:
		{
			ERROR_LOG() << "Invalid eventId.";
			return -1L;
		}
	}

	DEBUG_LOG() << "Enter ELTE_OCX_PlayerEvent";
	ELTE_OCX_PlayerEvent((ULONG)iEventId, xmlStr);
	DEBUG_LOG() << "Leave ELTE_OCX_PlayerEvent";

	DEBUG_LOG() << "--- LEAVE";
	return 0L;
}

LRESULT CeLTE_PlayerCtrl::OnMsgStopVideoPlay(WPARAM /*wparam*/, LPARAM /*lparam*/)
{
	DEBUG_LOG() << "--- ENTRY";

	// 获取资源ID
	int iResId = m_MediaPlayer.GetMediaPlayerResID();

	// 关闭视频回传
	int iRet = OperationMgr::Instance().DcVideoHangup(iResId);
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "VideoHangup failed.";
		DEBUG_LOG() << "--- LEAVE";
	}

	// 停止播放视频
	iRet = m_MediaPlayer.StopAudio();
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "StopAudio failed.";
		DEBUG_LOG() << "--- LEAVE";
	}

	iRet = m_MediaPlayer.StopPlayer();
	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "StopPlayer failed.";
		DEBUG_LOG() << "--- LEAVE";
	}

	// 重置界面
	m_VideoPane.Invalidate(TRUE);
	
	if (eLTE_SUCCESS == iRet)
	{
		// 禁用工具栏按钮
		m_VideoPane.EnableAudio(FALSE);
		m_VideoPane.EnableImageButton(FALSE);

		// 隐藏播放窗口
		m_VideoPane.ShowWindow(SW_HIDE);
	}

	DEBUG_LOG() << "--- LEAVE";
	return 0L;
}

BSTR CeLTE_PlayerCtrl::ELTE_OCX_SetLogPath(LPCTSTR pLogFilePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	CXml xml;
	
	// 日志模块还没有启动，不能输出日志
	// 入参检测
	if (NULL == pLogFilePath)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	eLTE_RET iRet = eLTE_Log::SetLogPath(eLTE_Tool::UnicodeToANSI(pLogFilePath));
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	return strResult.AllocSysString();
}//lint !e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_SetLogLevel(ULONG ulLogLevel)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	CXml xml;

	eLTE_RET iRet = eLTE_Log::SetLogLevel((int)ulLogLevel);
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	return strResult.AllocSysString();
}//lint !e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_UploadLogo(LPCTSTR pLogoFilePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	CXml xml;

	// 入参检测
	if (NULL == pLogoFilePath)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 判断文件是否存在
	if (!eLTE_Tool::IsExistPath(pLogoFilePath))
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 图片格式是否支持, 这里GDI+没有启动，使用CImage
	ATL::CImage Image;
	HRESULT hResult = Image.Load(pLogoFilePath);
	if(FAILED(hResult))
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}
	if (!Image.IsNull())
	{
		Image.Destroy();
	}	

	// 拷贝文件到Skin目录, 覆盖拷贝
	CString szImageName(pLogoFilePath);
	int iIndex = (szImageName.GetLength() - szImageName.ReverseFind(_T('\\'))) - 1;
	szImageName = szImageName.Right(iIndex);
	CString szPath = eLTE_Tool::GetOcxPath();
	szPath.Append(_T("Skin\\"));
	szPath.Append(szImageName);
	if (!CopyFile(pLogoFilePath, szPath, FALSE))
	{
		// 拷贝失败. 日志模块还没有启动，无法打印
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		return strResult.AllocSysString();
	}

	// 修改配置文件eLTE_Player.ini
	szPath = eLTE_Tool::GetOcxPath();
	szPath.Append(CONFIG_FILE_NAME);
	CString strValue = _T(".\\Skin\\");
	strValue.Append(szImageName);
	if (!WritePrivateProfileString(SECTION_SKIN_CONFIG, _T("logoPath"), strValue, szPath))
	{
		// 修改配置文件失败
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		return strResult.AllocSysString();
	}

	// 修改内存变量
	m_VideoPane.SetParam(pLogoFilePath);

	GET_RETURN_CODE_XML(xml, eLTE_SUCCESS, strResult);
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_GetVersion(ULONG ulVersion)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	CXml xml;

	// 获取eLTE_Player.ocx 版本
	if (eLTE_VERSION_OCX == ulVersion)
	{
		CString strVersion = eLTE_Tool::GetOcxVersion();
		GET_VERSION_XML(xml, eLTE_Tool::UnicodeToANSI(strVersion.GetBuffer()).c_str(), strResult);
	}
	// 获取eLTE SDK 版本
	else if (eLTE_VERSION_SDK == ulVersion)
	{
		GET_VERSION_XML(xml, "", strResult);
	}
	// 非法版本
	else
	{
		GET_VERSION_XML(xml, "", strResult);
	}

	return strResult.AllocSysString();
}//lint !e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_SetLanguage(ULONG ulLanguage)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	CXml xml;

	m_VideoPane.SetLanguage((int)ulLanguage);
	GET_RETURN_CODE_XML(xml, eLTE_SUCCESS, strResult);

	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_ShowToolbar(LONG ulToolbar)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	CXml xml;

	if (0 == ulToolbar)
	{
		m_VideoPane.ShowToolBar(FALSE);
	}
	else
	{
		m_VideoPane.ShowToolBar(TRUE);
	}
	
	GET_RETURN_CODE_XML(xml, eLTE_SUCCESS, strResult);
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_Load(ULONG ulType)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here

	// 日志开始
	(void)eLTE_Log::GetCategoryInstance();

	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(ulType);

	CXml xml;
	// 不能重复加载
	if (m_bHaveLoaded)
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Can't load eLTE_Player.ocx multiple.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	//入参校验
	if (eLTE_LOAD_OPERATE_MGR != ulType
		&& eLTE_LOAD_MEDIA_PLAYER != ulType)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		ERROR_LOG() << "Invalid param.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// GDI+
	Gdiplus::GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartupInput, NULL);

	// 修改eLTE SDK 环境变量EASY_INSTALL
	(void)eLTE_Tool::ChangeEnvironmentVariable();

	// 初始化配置参数
	int iRet = m_ConfigMgr.Start(m_MediaPlayer, m_VideoPane, OperationMgr::Instance());
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "ConfigMgr start failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 创建视频窗口
	if (NULL != m_VideoPane.GetSafeHwnd())
	{
		m_VideoPane.DestroyWindow();
	}
	CRect rect;
	GetClientRect(rect);
	m_VideoPane.SetCeLTE_PlayerCtrl(this);
	m_VideoPane.Create(CVideoPane::IDD, CWnd::GetDesktopWindow());
	m_VideoPane.ShowWindow(SW_HIDE);

	// 需要加载插件执行管理操作
	if (eLTE_LOAD_OPERATE_MGR == ulType)
	{
		// 初始化eLTE SDK		
		iRet = AppContextMgr::Instance().Init();
		if (eLTE_SUCCESS != iRet)
		{
			GET_RETURN_CODE_XML(xml, iRet, strResult);
			ERROR_LOG() << "AppContextMgr Init failed.";
			DEBUG_LOG() << "--- LEAVE";
			return strResult.AllocSysString();
		}
		AppContextMgr::Instance().SetCeLTE_PlayerCtrl(this);
		m_ulType = ulType;
	}

	// eLTE_Player 列表
	m_eLTE_PlayerList.insert(this);
	m_bHaveLoaded = TRUE;

	GET_RETURN_CODE_XML(xml, iRet, strResult);
	DEBUG_LOG() << "--- LEAVE";	
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_UnLoad(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here	
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// 需要加载插件执行管理操作
	if (eLTE_LOAD_OPERATE_MGR == m_ulType)
	{
		// 退出eLTE SDK
		int iRet = AppContextMgr::Instance().Exit();
		if (eLTE_SUCCESS != iRet)
		{
			GET_RETURN_CODE_XML(xml, iRet, strResult);
			ERROR_LOG() << "AppContextMgr Exit failed.";
			DEBUG_LOG() << "--- LEAVE";
			return strResult.AllocSysString();
		}
		m_ulType = 0;
	}

	// 销毁播放窗口
	if (NULL != m_VideoPane.GetSafeHwnd())
	{
		m_VideoPane.DestroyWindow();
	}
	CWnd* pParentWnd = GetParentOwner();
	if (NULL != pParentWnd)
	{
		pParentWnd->Invalidate(TRUE);
	}

	// 去初始化配置参数
	eLTE_RET iRet = m_ConfigMgr.Exit();
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "ConfigMgr Exit failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 键盘钩子
	if (NULL != CeLTE_PlayerCtrl::s_KeyboardHook)
	{
		::UnhookWindowsHookEx(CeLTE_PlayerCtrl::s_KeyboardHook);
		CeLTE_PlayerCtrl::s_KeyboardHook = NULL;
	}
	// 鼠标钩子
	if (NULL != CeLTE_PlayerCtrl::s_MouseHook)
	{
		::UnhookWindowsHookEx(CeLTE_PlayerCtrl::s_MouseHook);
		CeLTE_PlayerCtrl::s_MouseHook = NULL;
	}

	// GDI+
	Gdiplus::GdiplusShutdown(m_GdiplusToken);

	// 移除eLTE_Player 列表
	std::set<CeLTE_PlayerCtrl*>::iterator itor = m_eLTE_PlayerList.find(this);
	if (m_eLTE_PlayerList.end() != itor)
	{
		m_eLTE_PlayerList.erase(itor);
	}

	GET_RETURN_CODE_XML(xml, iRet, strResult);
	DEBUG_LOG() << "--- LEAVE";

	if (m_eLTE_PlayerList.empty())
	{
		// 媒体去初始化
		(void)m_MediaPlayer.UninitPlayer();
		// 日志结束
		eLTE_Log::DestroyInstance();
	}

	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_Login(LPCTSTR pUserID, LPCTSTR pPWD, LPCTSTR pServerIP, LPCTSTR pLocalIP, LPCTSTR pServerSIPPort)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM4(pUserID, pServerIP, pLocalIP, pServerSIPPort);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pUserID || NULL == pPWD || NULL == pServerIP || NULL == pLocalIP || NULL == pServerSIPPort)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	int iRet = OperationMgr::Instance().DcLogin(eLTE_Tool::UnicodeToANSI(pUserID), eLTE_Tool::UnicodeToANSI(pPWD), 
		eLTE_Tool::UnicodeToANSI(pServerIP), eLTE_Tool::UnicodeToANSI(pLocalIP), eLTE_Tool::UnicodeToANSI(pServerSIPPort), m_bEnableStatusReport);
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "DcLogin failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	m_bIsLogin = TRUE;

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_Logout(LPCTSTR pUserID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pUserID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pUserID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	int iRet = OperationMgr::Instance().DcLogout(eLTE_Tool::UnicodeToANSI(pUserID));
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	if (eLTE_SUCCESS != iRet)
	{
		ERROR_LOG() << "DcLogout failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	m_bIsLogin = FALSE;

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_TriggerStatusReport(ULONG ulEnableStatusReport)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(ulEnableStatusReport);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 保存到本地内存
	m_bEnableStatusReport = (0 == ulEnableStatusReport) ? false : true;

	// 如果已经登陆
	int iRet = eLTE_SUCCESS;
	if (m_bIsLogin)
	{
		iRet = OperationMgr::Instance().DcTriggerStatusReport(m_bEnableStatusReport);
	}

	GET_RETURN_CODE_XML(xml, iRet, strResult);
	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_ProvisionManagerInit(LPCTSTR pServerIP, LPCTSTR pUserID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(pServerIP, pUserID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pServerIP || NULL == pUserID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	int iRet = ProvisionMgr::Instance().Init(eLTE_Tool::UnicodeToANSI(pServerIP), eLTE_Tool::WString2Int(pUserID));
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_ProvisionManagerExit(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	int iRet = ProvisionMgr::Instance().Exit();
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_GetDcGroups(LPCTSTR pUserID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pUserID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pUserID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 获取群组列表
	DcGroups* pDcGroups = NULL;
	int iRet = ProvisionMgr::Instance().GetDcGroups(eLTE_Tool::WString2Int(pUserID), pDcGroups);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "GetDcGroups failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 获取返回XML
	iRet = XMLProcess::SetXmlStringDcGroups(pDcGroups, strResult);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "SetXmlStringDcGroups failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_GetDcUsers(LPCTSTR pUserID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pUserID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pUserID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 获取用户列表
	DcUsers* pDcUsers = NULL;
	int iRet = ProvisionMgr::Instance().GetDcUsers(eLTE_Tool::WString2Int(pUserID), pDcUsers);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "GetDcUsers failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 获取返回XML
	iRet = XMLProcess::SetXmlStringDcUsers(pDcUsers, strResult);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "SetXmlStringDcUsers failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_GetGroupUsers(LPCTSTR pGroupID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pGroupID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pGroupID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 获取一个群组的成员列表
	GrpUserList* pGrpUserList = NULL;
	int iRet = ProvisionMgr::Instance().GetGroupUsers(eLTE_Tool::WString2Int(pGroupID), pGrpUserList);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "GetGroupUsers failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 获取返回XML
	iRet = XMLProcess::SetXmlStringGrpUserList(pGrpUserList, strResult);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "SetXmlStringGrpUserList failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_GetGroupInfo(LPCTSTR pGroupID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pGroupID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pGroupID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 获取群组详细配置信息
	GroupInfo* pGroupInfo = NULL;
	int iRet = ProvisionMgr::Instance().GetGroupInfo(eLTE_Tool::WString2Int(pGroupID), pGroupInfo);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "GetGroupInfo failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 获取返回XML
	iRet = XMLProcess::SetXmlStringGroupInfo(pGroupInfo, strResult);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "SetXmlStringGroupInfo failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_GetUserInfo(LPCTSTR pUserID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pUserID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pUserID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 获取用户详细信息
	UserInfo* pUserInfo = NULL;
	int iRet = ProvisionMgr::Instance().GetUserInfo(eLTE_Tool::WString2Int(pUserID), pUserInfo);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "GetUserInfo failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 获取返回XML
	iRet = XMLProcess::SetXmlStringUserInfo(pUserInfo, strResult);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "SetXmlStringUserInfo failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_GetDcInfo(LPCTSTR pUserID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pUserID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pUserID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 获取DC详细信息
	DcProperty* pDcProperty = NULL;
	int iRet = ProvisionMgr::Instance().GetDcInfo(eLTE_Tool::WString2Int(pUserID), pDcProperty);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "GetDcInfo failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 获取返回XML
	iRet = XMLProcess::SetXmlStringDcProperty(pDcProperty, strResult);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "SetXmlStringDcProperty failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_SubscribeGroup(LPCTSTR pGroupID, ULONG ulEnableSubscribeGroup)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(pGroupID, ulEnableSubscribeGroup);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pGroupID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 订阅群组\去订阅群组
	int iRet = OperationMgr::Instance().DcSubscribeGroup(eLTE_Tool::UnicodeToANSI(pGroupID), ulEnableSubscribeGroup);
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_GetUserRECFileInfoList(LPCTSTR pQueryXml)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pQueryXml);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pQueryXml)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 解析入参
	RECQueryInfo condition;
	int iRet = XMLProcess::XmlParseRECQueryInfo(eLTE_Tool::UnicodeToANSI(pQueryXml), condition);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "XmlParseRECQueryInfo failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 查询录音文件信息
	UserRecFileInfoList* pInfoList = NULL;
	iRet = ProvisionMgr::Instance().GetUserRECFileInfoList(&condition, pInfoList);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "GetUserRECFileInfoList failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 获取返回XML
	iRet = XMLProcess::SetXmlStringRecFileInfoList(pInfoList, strResult);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "SetXmlStringDcProperty failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_StartRealPlay(LPCTSTR pResourceID, LPCTSTR pVideoParam)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(pResourceID, pVideoParam);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pResourceID || NULL == pVideoParam)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 解析视频参数
	std::string strVideoFormat("");
	std::string strCameraType("");
	std::string strUserConfirmType("");
	std::string strMuteType("");
	int iRet = XMLProcess::XmlParseVideoULParameter(eLTE_Tool::UnicodeToANSI(pVideoParam),
		strVideoFormat, strCameraType, strUserConfirmType, strMuteType);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "XmlParseVideoULParameter failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 构建视频参数
	Video_UL_parameter param;
	param.fmtvalue = (char*)strVideoFormat.c_str();//lint !e1773
	param.cameratype = (char*)strCameraType.c_str();//lint !e1773
	param.user_confirm_type = (char*)strUserConfirmType.c_str();//lint !e1773
	param.mutetype = (char*)strMuteType.c_str();//lint !e1773

	// 开启视频回传
	iRet = OperationMgr::Instance().DcVideoMonitor(eLTE_Tool::WString2Int(pResourceID), param);

	GET_RETURN_CODE_XML(xml, iRet, strResult);
	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_ReverseRealPlay(LPCTSTR pResourceID, LPCTSTR pVideoParam)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(pResourceID, pVideoParam);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pResourceID || NULL == pVideoParam)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 解析视频参数
	std::string strVideoFormat("");
	std::string strCameraType("");
	std::string strUserConfirmType("");
	std::string strMuteType("");
	int iRet = XMLProcess::XmlParseVideoULParameter(eLTE_Tool::UnicodeToANSI(pVideoParam),
		strVideoFormat, strCameraType, strUserConfirmType, strMuteType);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "XmlParseVideoULParameter failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 构建视频参数
	Video_UL_parameter param;
	param.fmtvalue = (char*)strVideoFormat.c_str();//lint !e1773
	param.cameratype = (char*)strCameraType.c_str();//lint !e1773
	param.user_confirm_type = (char*)strUserConfirmType.c_str();//lint !e1773
	param.mutetype = (char*)strMuteType.c_str();//lint !e1773

	// 关闭视频回传
	iRet = OperationMgr::Instance().DcVideoHangup(eLTE_Tool::WString2Int(pResourceID));
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "DcVideoHangup failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 停止视频播放
	(void)m_MediaPlayer.StopPlayer();
	m_VideoPane.PlayAudio(FALSE);
	m_VideoPane.EnableImageButton(FALSE);
	m_VideoPane.Invalidate(TRUE);

	// 开启视频回传
	iRet = OperationMgr::Instance().DcVideoMonitor(eLTE_Tool::WString2Int(pResourceID), param);

	GET_RETURN_CODE_XML(xml, iRet, strResult);
	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_StopRealPlay(LPCTSTR pResourceID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pResourceID);
	CXml xml;

	// load类型是否支持
	CHECK_ELTE_OCX_LOAD_TYPE(m_ulType, xml, strResult);

	// 入参检测
	if (NULL == pResourceID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 关闭视频回传
	int iRet = OperationMgr::Instance().DcVideoHangup(eLTE_Tool::WString2Int(pResourceID));
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "DcVideoHangup failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}	

	// 停止播放视频
	(void)m_MediaPlayer.StopAudio();
	iRet = m_MediaPlayer.StopPlayer();
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	// 关闭播放器窗口
	std::set<CeLTE_PlayerCtrl*>::iterator itor_b = m_eLTE_PlayerList.begin();
	std::set<CeLTE_PlayerCtrl*>::iterator itor_e = m_eLTE_PlayerList.end();
	for (; itor_e != itor_b; itor_b++)
	{
		CeLTE_PlayerCtrl* pOCX = *itor_b;
		int iResId = pOCX->m_MediaPlayer.GetMediaPlayerResID();
		if (eLTE_Tool::WString2Int(pResourceID) == iResId)
		{
			pOCX->m_VideoPane.PostMessage(WM_CLOSE);
			break;
		}
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_ShowRealPlay(LPCTSTR pResourceID, LPCTSTR pLocalMediaAddr, LPCTSTR pRemoteMediaAddr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(pLocalMediaAddr, pRemoteMediaAddr);
	CXml xml;

	// 入参检测
	if (NULL == pLocalMediaAddr || NULL == pRemoteMediaAddr)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 解析XML入参
	std::string strLocalIP("");
	unsigned int uiLocalVideoPort = 0;
	unsigned int uiLocalAudioPort = 0;
	std::string strRemoteIP("");
	unsigned int uiRemoteVideoPort = 0;
	unsigned int uiRemoteAudioPort = 0;
	int iRet = XMLProcess::XmlParsePlayVideoParam(
		eLTE_Tool::UnicodeToANSI(pLocalMediaAddr),
		eLTE_Tool::UnicodeToANSI(pRemoteMediaAddr),
		strLocalIP, uiLocalVideoPort, uiLocalAudioPort,
		strRemoteIP, uiRemoteVideoPort, uiRemoteAudioPort);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "XmlParsePlayVideoParam failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 设置资源ID
	m_MediaPlayer.SetMediaPlayerResID(eLTE_Tool::UnicodeToANSI(pResourceID));

	// 初始化播放器
	iRet = m_MediaPlayer.InitPlayerParam((IVS_CHAR*)strLocalIP.c_str(),//lint !e1773
		uiLocalVideoPort, uiLocalAudioPort);
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "MediaPlayer InitPlayerParam failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 播放视频
	iRet = m_MediaPlayer.StartPlayer((IVS_CHAR*)strRemoteIP.c_str(),//lint !e1773
		uiRemoteVideoPort, uiRemoteAudioPort, m_VideoPane.GetVideoStaticSafeHwnd());
	if (eLTE_SUCCESS != iRet)
	{
		GET_RETURN_CODE_XML(xml, iRet, strResult);
		ERROR_LOG() << "MediaPlayer StartPlayer failed.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 伴音判断
	std::string strMuteType = OperationMgr::Instance().GetMuteType(eLTE_Tool::WString2Int(pResourceID));
	if ("0" == strMuteType)
	{
		// 有伴音
		m_VideoPane.EnableAudio(TRUE);
	}
	else if ("1" == strMuteType)
	{
		// 无伴音
		m_VideoPane.EnableAudio(FALSE);
	}

	// 显示播放窗口
	m_VideoPane.ShowWindow(SW_SHOW);

	// 激活工具栏按钮
	m_VideoPane.EnableImageButton(TRUE);

	// 播放器窗体显示事件
	PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_SHOW, NULL);

	GET_RETURN_CODE_XML(xml, iRet, strResult);
	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_Snapshot(LPCTSTR pResourceID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// 入参检测
	if (NULL == pResourceID)
	{
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 本地抓图
	std::string strSnapshotPath = "";
	int iRet = m_MediaPlayer.LocalSnapshot(eLTE_Tool::UnicodeToANSI(pResourceID), strSnapshotPath);
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	if (eLTE_SUCCESS == iRet)
	{
		PlayerEventParamInfo* pInfo = new PlayerEventParamInfo;
		if (NULL != pInfo)
		{
			pInfo->strSnapshotPath = strSnapshotPath;
			// 播放器抓图事件
			PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_SNAPSHOT, (LPARAM)pInfo);
		}
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_HideRealPlay(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 停止播放视频
	int iRet = m_MediaPlayer.StopPlayer();
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	m_VideoPane.PlayAudio(FALSE);

	// 隐藏播放窗口
	m_VideoPane.ShowWindow(SW_HIDE);

	// 播放器窗体隐藏事件
	//PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_HIDE, NULL);

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_PlaySound(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 开始播放音频
	int iRet = m_MediaPlayer.PlayAudio();
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	// 设置静音按钮
	if (eLTE_SUCCESS == iRet)
	{
		m_VideoPane.PlayAudio(TRUE);

		// 播放器取消静音事件
		PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_UNMUTE, NULL);
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_StopSound(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	// 停止播放音频
	int iRet = m_MediaPlayer.StopAudio();
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	// 设置静音按钮
	if (eLTE_SUCCESS == iRet)
	{
		m_VideoPane.PlayAudio(FALSE);

		// 播放器静音事件
		PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_MUTE, NULL);
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}//lint -e1762


BSTR CeLTE_PlayerCtrl::ELTE_OCX_SetVideoWindowPos(ULONG ulLeft, ULONG ulTop, ULONG ulWidth, ULONG ulHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	m_VideoPane.SetWindowPos(NULL, (int)ulLeft, (int)ulTop, (int)ulWidth, (int)ulHeight, SWP_DRAWFRAME);
	m_VideoPane.Invalidate(TRUE);

	DEBUG_LOG() << "--- LEAVE";

	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_FullScreenDisplay(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	eLTE_RET iRet = m_VideoPane.SetFullScreen();
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	if (eLTE_SUCCESS == iRet)
	{
		// 播放器全屏事件
		PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_FULLSCREEN, NULL);
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_NormalScreenDisplay(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	CXml xml;

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	eLTE_RET iRet = m_VideoPane.ResetFullScreen();
	GET_RETURN_CODE_XML(xml, iRet, strResult);

	if (eLTE_SUCCESS == iRet)
	{
		// 播放器退出全屏事件
		PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_NORMALSCREEN, NULL);
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


BSTR CeLTE_PlayerCtrl::ELTE_OCX_SetTitleText(LPCTSTR pTitleText)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(pTitleText);
	CXml xml;

	// 入参校验
	if (NULL == pTitleText)
	{
		ERROR_LOG() << "pTitleText is null.";
		GET_RETURN_CODE_XML(xml, eLTE_INVALID_PARAM, strResult);
		return strResult.AllocSysString();
	}

	// 状态校验
	if (NULL == m_VideoPane.GetSafeHwnd())
	{
		GET_RETURN_CODE_XML(xml, eLTE_FAILED, strResult);
		ERROR_LOG() << "Please load ocx first.";
		DEBUG_LOG() << "--- LEAVE";
		return strResult.AllocSysString();
	}

	m_VideoPane.SetCaptionText(pTitleText);
	GET_RETURN_CODE_XML(xml, eLTE_SUCCESS, strResult);

	// 播放器取消静音事件
	PlayerEventParamInfo* pInfo = new PlayerEventParamInfo;
	if (NULL != pInfo)
	{
		pInfo->strTitle = pTitleText;
		PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_TITLE, (LPARAM)pInfo);
	}

	DEBUG_LOG() << "--- LEAVE";
	return strResult.AllocSysString();
}


// 抓图
int CeLTE_PlayerCtrl::ToolBarSnapshot()
{
	DEBUG_LOG() << "--- ENTRY";
	std::string strSnapshotPath = "";
	int iRet = m_MediaPlayer.LocalSnapshot(strSnapshotPath);

	if (eLTE_SUCCESS == iRet)
	{
		PlayerEventParamInfo* pInfo = new PlayerEventParamInfo;
		if (NULL != pInfo)
		{
			pInfo->strSnapshotPath = strSnapshotPath;
			// 播放器抓图事件
			PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_SNAPSHOT, (LPARAM)pInfo);
		}
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}


// 切换前后置摄像头
int CeLTE_PlayerCtrl::ToolBarReversePlayer()
{
	DEBUG_LOG() << "--- ENTRY";

	// 关闭视频播放
	(void)m_MediaPlayer.StopAudio();
	(void)m_MediaPlayer.StopPlayer();

	// 重置界面
	m_VideoPane.Invalidate(TRUE);

	// 修改界面
	m_VideoPane.PlayAudio(FALSE);
	m_VideoPane.EnableImageButton(FALSE);

	// 切换镜头
	int iResId = m_MediaPlayer.GetMediaPlayerResID();
	STVideoParam vParam;
	int iRet = OperationMgr::Instance().DcVideoReverse(iResId, vParam);
	if (eLTE_SUCCESS == iRet)
	{
		PlayerEventParamInfo* pInfo = new PlayerEventParamInfo;
		if (NULL != pInfo)
		{
			pInfo->strFmtValue = vParam.strFmtValue;
			pInfo->strCameraType = vParam.strCameraType;
			pInfo->strUserCfmType = vParam.strUserCfmType;
			pInfo->strMuteType = vParam.strMuteType;
			// 播放器切换镜头事件
			PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_REVERSE, (LPARAM)pInfo);
		}
	}

	//----------------异步播放
	std::map<int, CeLTE_PlayerCtrl*>::iterator itor = m_WaitPlayVideoList.find(iResId);
	if (m_WaitPlayVideoList.end() == itor)
	{
		(void)m_WaitPlayVideoList.insert(std::make_pair(iResId, this));
	}

	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}


// 开启关闭伴音
int CeLTE_PlayerCtrl::ToolBarPlayAudio(BOOL bEnable)
{
	DEBUG_LOG() << "--- ENTRY";
	int iRet;
	if (bEnable)
	{
		iRet = m_MediaPlayer.PlayAudio();
		if (eLTE_SUCCESS == iRet)
		{
			// 播放器取消静音事件
			PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_UNMUTE, NULL);
		}
	}
	else
	{
		iRet = m_MediaPlayer.StopAudio();
		if (eLTE_SUCCESS == iRet)
		{
			// 播放器取消静音事件
			PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_MUTE, NULL);
		}
	}
	DEBUG_LOG() << "--- LEAVE";
	return iRet;
}
