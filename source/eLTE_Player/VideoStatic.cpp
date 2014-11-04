// VideoStatic.cpp : implementation file
//

#include "stdafx.h"
#include "VideoStatic.h"
#include "eLTE_PlayerCtrl.h"
#include "eLTE_Log.h"


// CVideoStatic

IMPLEMENT_DYNAMIC(CVideoStatic, CStatic)

CVideoStatic::CVideoStatic()
	: m_bIsFullScreen(FALSE)
	, m_pParentWnd(NULL)
	, m_skinType(0)
	, m_pImage(NULL)
{
	memset(&m_struOldWndpl, 0, sizeof(m_struOldWndpl));
}

CVideoStatic::~CVideoStatic()
{
	m_pParentWnd = NULL;
	m_pImage = NULL;
}


BEGIN_MESSAGE_MAP(CVideoStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CVideoStatic message handlers




void CVideoStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CStatic::OnPaint() for painting messages

	if (eLTE_SKIN_BLACK == m_skinType)
	{
		CRect rect;
		GetClientRect(rect);
		dc.FillSolidRect(rect, BLACK_COLOR);
		SetBackGroudImage(dc);
	}
	else if (eLTE_SKIN_WHITE == m_skinType)
	{
		CRect rect;
		GetClientRect(rect);
		dc.FillSolidRect(rect, WHITE_COLOR);
		SetBackGroudImage(dc);
	}
}

void CVideoStatic::SetParam(int skinType, const CString& strLogoPath)
{
	m_skinType = skinType;
	m_strLogoPath = strLogoPath;
}

void CVideoStatic::SetParam(const CString& strLogoPath)
{
	m_strLogoPath = strLogoPath;
}

eLTE_RET CVideoStatic::SetFullScreen()
{
	DEBUG_LOG() << "--- ENTRY";

	if (m_bIsFullScreen)
	{
		INFO_LOG() << "Is already a full-screen.";
		return eLTE_SUCCESS;
	}
	
	if (NULL == m_pParentWnd || NULL == m_pParentWnd->GetSafeHwnd())
	{
		ERROR_LOG() << "m_pParentWnd is null or parentwnd had been destory.";
		return eLTE_FAILED;
	}

	m_pParentWnd->ShowWindow(SW_HIDE);
	SetParent(NULL);
	ModifyStyle(WS_CHILD, WS_POPUP, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();
	SetFocus();
	GetCursorPos(&m_OldCursorPoint);
	ShowCursor(FALSE);

	HMONITOR hMonitor = MonitorFromWindow(m_pParentWnd->GetSafeHwnd(),MONITOR_DEFAULTTONEAREST);
	MONITORINFO info;
	info.cbSize = sizeof(MONITORINFO);
	GetMonitorInfo(hMonitor,&info);

	long top = info.rcMonitor.top;
	long left = info.rcMonitor.left;
	long bottom = info.rcMonitor.bottom;
	long right = info.rcMonitor.right;

	GetWindowPlacement(&m_struOldWndpl);

	CRect rectFullScreen;
	rectFullScreen.left = left;
	rectFullScreen.top    = top;
	rectFullScreen.right  = right;
	rectFullScreen.bottom = bottom;

	//enter into full screen;
	WINDOWPLACEMENT struWndpl;
	struWndpl.length = sizeof(WINDOWPLACEMENT);
	struWndpl.flags   = 0;
	struWndpl.showCmd = SW_SHOWNORMAL;
	struWndpl.rcNormalPosition = rectFullScreen;
	SetWindowPlacement(&struWndpl);
	// ÖÃ¶¥´°¿Ú
	SetWindowPos(&CWnd::wndNoTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

	m_bIsFullScreen = TRUE;

	// ¼üÅÌ¹³×Ó
	if (NULL == CeLTE_PlayerCtrl::s_KeyboardHook)
	{
		CeLTE_PlayerCtrl::s_KeyboardHook = ::SetWindowsHookEx(WH_KEYBOARD_LL, CeLTE_PlayerCtrl::KeyboardProc, AfxGetInstanceHandle(), 0);
	}
	// Êó±ê¹³×Ó
	if (NULL == CeLTE_PlayerCtrl::s_MouseHook)
	{
		CeLTE_PlayerCtrl::s_MouseHook = ::SetWindowsHookEx(WH_MOUSE_LL, CeLTE_PlayerCtrl::MouseProc, AfxGetInstanceHandle(), 0);
	}

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

eLTE_RET CVideoStatic::ResetFullScreen()
{
	DEBUG_LOG() << "--- ENTRY";

	if (!m_bIsFullScreen)
	{
		INFO_LOG() << "Is already not full-screen.";
		return eLTE_SUCCESS;
	}

	if (NULL == m_pParentWnd || NULL == m_pParentWnd->GetSafeHwnd())
	{
		ERROR_LOG() << "m_pParentWnd is null or parentwnd had been destory.";
		return eLTE_FAILED;
	}
	m_pParentWnd->ShowWindow(SW_HIDE);
	// »Ö¸´¸¸´°¿ÚÖ¸Õë£¬²¢ÏÔÊ¾
	ModifyStyle(WS_POPUP, WS_CHILD, 0);
	SetParent(m_pParentWnd);
	m_pParentWnd->Invalidate(TRUE);

	m_pParentWnd->ShowWindow(SW_SHOW);

	m_pParentWnd->SetForegroundWindow();
	SetForegroundWindow();

	m_pParentWnd->SetFocus();
	SetWindowPlacement(&m_struOldWndpl);

	m_bIsFullScreen = FALSE;

	// ¼üÅÌ¹³×Ó
	if (NULL != CeLTE_PlayerCtrl::s_KeyboardHook)
	{
		::UnhookWindowsHookEx(CeLTE_PlayerCtrl::s_KeyboardHook);
		CeLTE_PlayerCtrl::s_KeyboardHook = NULL;
	}
	// Êó±ê¹³×Ó
	if (NULL != CeLTE_PlayerCtrl::s_MouseHook)
	{
		::UnhookWindowsHookEx(CeLTE_PlayerCtrl::s_MouseHook);
		CeLTE_PlayerCtrl::s_MouseHook = NULL;
	}

	ShowCursor(TRUE);
	SetCursorPos(m_OldCursorPoint.x, m_OldCursorPoint.y);

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}


BOOL CVideoStatic::IsFullScreen() const
{
	return m_bIsFullScreen;
}


void CVideoStatic::SetBackGroudImage(const CPaintDC& dc)
{
	// ¼ÓÔØ±³¾°logoÍ¼Æ¬
	if (NULL == m_pImage)
	{
		m_pImage = Gdiplus::Image::FromFile(m_strLogoPath);
		if (NULL == m_pImage)
		{
			ERROR_LOG() << "m_pImage is null.";
			return;
		}
		else
		{
			if (Gdiplus::Ok != m_pImage->GetLastStatus())
			{
				ERROR_LOG() << "Gdiplus::Image::FromFile failed. (" << m_strLogoPath << ")";
				m_pImage = NULL;
				return;
			}
		}
	}

	// ¾ÓÖÐÎ»ÖÃ¼ÆËã
	CRect rect;
	GetClientRect(&rect);
	int iWidth = (int)m_pImage->GetWidth();
	int iHeight = (int)m_pImage->GetHeight();
	if ((double)rect.right/rect.bottom > (double)iWidth/iHeight)
	{
		iHeight = rect.bottom / 3;
		iWidth = iHeight * (int)m_pImage->GetWidth() / (int)m_pImage->GetHeight();
	}
	else
	{
		iWidth = rect.right / 3;
		iHeight = iWidth * (int)m_pImage->GetHeight() / (int)m_pImage->GetWidth();
	}

	int iLeft = (rect.right - iWidth) / 2;
	int iTop = (rect.bottom - iHeight) / 2;

	// »æÖÆÍ¼Æ¬
	Gdiplus::Graphics graphics(dc);
	Gdiplus::Rect gRect(iLeft, iTop, iWidth, iHeight);
	Gdiplus::ImageAttributes ImgAtt;
	ImgAtt.SetWrapMode(Gdiplus::WrapModeTileFlipXY);
	graphics.DrawImage(m_pImage, gRect, 0, 0, (INT)m_pImage->GetWidth(), (INT)m_pImage->GetHeight(), Gdiplus::UnitPixel, &ImgAtt);
}


// ÉèÖÃ¸¸´°Ìå
void CVideoStatic::SetParentWnd(CWnd* pParentWnd)
{
	m_pParentWnd = pParentWnd;
}
