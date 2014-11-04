// ImageButton.cpp : implementation file
//
//lint -e766
#include "stdafx.h"
#include "eLTE_Player.h"
#include "ImageButton.h"
#include "VideoPane.h"
#include "eLTE_Log.h"


// CImageButton

IMPLEMENT_DYNAMIC(CImageButton, CButton)

CImageButton::CImageButton()
	: m_CurImageState(ImgState_Normal)
{
	for (int i = 0; i < IMGAGE_STATE_COUNT; i++)
	{
		m_ImageList[i] = NULL;
	}
}

CImageButton::~CImageButton()
{
	for (int i = 0; i < IMGAGE_STATE_COUNT; i++)
	{
		m_ImageList[i] = NULL;
	}
}


BEGIN_MESSAGE_MAP(CImageButton, CButton)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_CONTROL_REFLECT(BN_CLICKED, &CImageButton::OnBnClicked)
	ON_MESSAGE(WM_ELTE_INVALID_PARENTWND, OnMsgInvalidParent)
END_MESSAGE_MAP()



// CImageButton message handlers

void CImageButton::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CButton::OnPaint() for painting messages

	UpdateImage(dc);
}


void CImageButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	TRACKMOUSEEVENT csTME;
	csTME.cbSize = sizeof (csTME);
	csTME.dwFlags = TME_LEAVE | TME_HOVER;
	csTME.hwndTrack = m_hWnd ;// ָ��Ҫ ׷�� �Ĵ��� 
	csTME.dwHoverTime = 10;  // ����ڰ�ť��ͣ������ 100ms ������Ϊ״̬Ϊ HOVER
	::_TrackMouseEvent(&csTME); // ���� Windows �� WM_MOUSELEAVE �� WM_MOUSEHOVER �¼�֧�� 

	CButton::OnMouseMove(nFlags, point);
}


void CImageButton::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_CurImageState = ImgState_Focus;
	Invalidate(TRUE);

	RelayToolTipEvent(point);

	CButton::OnMouseHover(nFlags, point);
}//lint !e1746


void CImageButton::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default

	m_CurImageState = ImgState_Normal;
	PostMessage(WM_ELTE_INVALID_PARENTWND);

	CButton::OnMouseLeave();
}


void CImageButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_CurImageState = ImgState_Select;

	CButton::OnLButtonDown(nFlags, point);
}


void CImageButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_CurImageState = ImgState_Normal;

	CButton::OnLButtonUp(nFlags, point);
}


void CImageButton::OnBnClicked()
{
	// TODO: Add your control notification handler code here

	// ���͵���¼�
	CWnd* pParentWnd = GetParent();
	if (NULL != pParentWnd)
	{
		pParentWnd->PostMessage(WM_ELTE_IMG_BTN_CLICKED, (WPARAM)GetDlgCtrlID(), NULL);
	}
}//lint !e1762


LRESULT CImageButton::OnMsgInvalidParent(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	CWnd* pParentWnd = GetParent();
	if (NULL != pParentWnd)
	{
		CRect rect;
		pParentWnd->GetClientRect(rect);
		rect.top = rect.bottom - VIDEO_TOOLBAR_WIDTH;
		pParentWnd->InvalidateRect(rect, TRUE);
	}

	return 0L;
}//lint !e1762


void CImageButton::LoadImages(const CString& strNormal, const CString& strSelect,
	const CString& strFocus, const CString& strDisable, IMAGE_STATE_E eCurImageState)
{
	// ��ɾ��ԭ�е�Image��Դ��ʵ�ֿ��Ը���Image��Դ
	for (int i = 0; i < IMGAGE_STATE_COUNT; i++)
	{
		CString strFilePath;
		if (ImgState_Normal == i)
		{
			strFilePath = strNormal;
		}
		else if (ImgState_Select == i)
		{
			strFilePath = strSelect;
		}
		else if (ImgState_Focus == i)
		{
			strFilePath = strFocus;
		}
		else if (ImgState_Disable == i)
		{
			strFilePath = strDisable;
		}

		m_ImageList[i] = Gdiplus::Image::FromFile(strFilePath);
		if (NULL == m_ImageList[i])
		{
			ERROR_LOG() << "m_ImageList[" << i << "] is null. (" << strFilePath << ")";
		}
		else
		{
			if (Gdiplus::Ok != m_ImageList[i]->GetLastStatus())
			{
				ERROR_LOG() << "Gdiplus::Image::FromFile failed. (" << strFilePath << ")";
				m_ImageList[i] = NULL;
			}
		}
	}

	m_CurImageState = eCurImageState;
}


void CImageButton::SetCurImgState(IMAGE_STATE_E eCurImageState)
{
	m_CurImageState = eCurImageState;
	Invalidate(TRUE);
}


void CImageButton::AddToolTip(LPCTSTR lpszText)
{
	if (NULL == m_ToolTipCtrl.GetSafeHwnd())
	{
		m_ToolTipCtrl.Create(this);
		m_ToolTipCtrl.SetTipBkColor(RGB(70, 70, 70));
		m_ToolTipCtrl.SetTipTextColor(RGB(255, 255, 255));
		m_ToolTipCtrl.AddTool(this, lpszText);
		m_ToolTipCtrl.Activate(TRUE);
	}
}


void CImageButton::UpdateToolTip(LPCTSTR lpszText)
{
	if (NULL == m_ToolTipCtrl.GetSafeHwnd())
	{
		m_ToolTipCtrl.Create(this);
		m_ToolTipCtrl.SetTipBkColor(RGB(70, 70, 70));
		m_ToolTipCtrl.SetTipTextColor(RGB(255, 255, 255));
		m_ToolTipCtrl.AddTool(this, lpszText);
		m_ToolTipCtrl.Activate(TRUE);
	}
	else
	{
		m_ToolTipCtrl.UpdateTipText(lpszText, this);
	}
}


void CImageButton::UpdateImage(const CPaintDC& dc)
{
	if (NULL != m_ImageList[m_CurImageState])
	{
		Gdiplus::Image *pImg = m_ImageList[m_CurImageState];
		if (NULL != pImg)
		{
			Gdiplus::Graphics graphics(dc);
			graphics.DrawImage(pImg, 0, 0, (INT)pImg->GetWidth(), (INT)pImg->GetHeight());
		}
	}
}//lint !e1762


void CImageButton::RelayToolTipEvent(const CPoint &point)
{
	if (NULL != m_ToolTipCtrl.GetSafeHwnd())
	{
		MSG msg;
		msg.hwnd = m_hWnd;
		msg.message = WM_MOUSEMOVE;
		msg.time = 0;
		msg.pt.x = LOWORD(point.y);
		msg.pt.y = HIWORD(point.y);
		msg.wParam = LOWORD(point.x);
		msg.lParam = LOWORD(point.y);

		m_ToolTipCtrl.RelayEvent(&msg);
	}
}
//lint -e766
