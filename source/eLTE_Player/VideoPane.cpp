// VideoPane.cpp : implementation file
//
//lint -e766
#include "stdafx.h"
#include "eLTE_Player.h"
#include "VideoPane.h"
#include "afxdialogex.h"
#include "eLTE_Log.h"
#include "eLTE_Tool.h"
#include "eLTE_PlayerCtrl.h"


// CVideoPane dialog

IMPLEMENT_DYNAMIC(CVideoPane, CDialog)

CVideoPane::CVideoPane(CWnd* pParent /*=NULL*/)
	: CDialog(CVideoPane::IDD, pParent)
	, m_pImgCaption(NULL)
	, m_strCaptionText(_T(""))
	, m_bEnableAudio(FALSE)
	, m_bHaveSound(FALSE)
	, m_bShowToolBar(TRUE)
	, m_pCeLTE_PlayerCtrl(NULL)
{

}

CVideoPane::~CVideoPane()
{
	try
	{
		if (NULL != m_VideoStatic.GetSafeHwnd())
		{
			m_VideoStatic.DestroyWindow();
		}
		if (NULL != m_SnapshotBtn.GetSafeHwnd())
		{
			m_SnapshotBtn.DestroyWindow();
		}
		if (NULL != m_ReversePlayBtn.GetSafeHwnd())
		{
			m_ReversePlayBtn.DestroyWindow();
		}
		if (NULL != m_AudioBtn.GetSafeHwnd())
		{
			m_AudioBtn.DestroyWindow();
		}
		if (NULL != m_FullScreenBtn.GetSafeHwnd())
		{
			m_FullScreenBtn.DestroyWindow();
		}
		m_pCeLTE_PlayerCtrl = NULL;
		m_pImgCaption = NULL;
	}
	catch(...)
	{
		m_pCeLTE_PlayerCtrl = NULL;
		m_pImgCaption = NULL;
	}
}

void CVideoPane::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVideoPane, CDialog)
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_NCLBUTTONDBLCLK()
	ON_WM_NCHITTEST()
	ON_MESSAGE(WM_ELTE_IMG_BTN_CLICKED, OnMsgImgBtnClicked)
	ON_WM_NCLBUTTONDOWN()
	ON_WM_MOVE()
END_MESSAGE_MAP()


// CVideoPane message handlers


BOOL CVideoPane::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// ��ȡ����
	CRect rect;
	GetClientRect(rect);
	CString strOcxPath = eLTE_Tool::GetOcxPath();

	// ����ͼ��
	Gdiplus::Bitmap* pBitmap = Gdiplus::Bitmap::FromFile(strOcxPath + _T("Skin\\Icon.ico"));
	if (NULL != pBitmap && Gdiplus::Ok == pBitmap->GetLastStatus())
	{
		HICON hIcon = NULL;
		pBitmap->GetHICON(&hIcon);
		if (NULL != hIcon)
		{
			SetIcon(hIcon, FALSE);		// Set small icon
			SetIcon(hIcon, TRUE);		// Set big icon
		}
	}

	// ��ʾ�߿�
	ModifyStyle(0, WS_BORDER);
	SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_DRAWFRAME);

	// ����������
	CreateCaption(rect, strOcxPath);

	// ������Ƶ����
	CreateVideoStatic(rect, strOcxPath);

	// ����������
	CreateToolBar(rect, strOcxPath);

	// ���ð�ť
	EnableImageButton(FALSE);

	// ����������
	if (!m_bShowToolBar)
	{
		m_SnapshotBtn.ShowWindow(SW_HIDE);
		m_ReversePlayBtn.ShowWindow(SW_HIDE);
		m_FullScreenBtn.ShowWindow(SW_HIDE);
		m_AudioBtn.ShowWindow(SW_HIDE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CVideoPane::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		// ֹͣ������Ƶ
		m_pCeLTE_PlayerCtrl->PostMessage(WM_ELTE_VIDEO_EXIT, 0, NULL);

		// ���������������¼�
		m_pCeLTE_PlayerCtrl->PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_HIDE, NULL);
	}

	// ���ù�������ť
	EnableAudio(FALSE);
	EnableImageButton(FALSE);

	// ���ز��Ŵ���
	ShowWindow(SW_HIDE);

	//CDialog::OnClose();
}


void CVideoPane::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages

	// ���Ʊ�����
	if (NULL != m_pImgCaption)
	{
		// ��������
		CRect rect;
		GetClientRect(rect);
		Gdiplus::Rect gRect(rect.left, rect.top, rect.right, CAPTION_HEIGHT);
		Gdiplus::ImageAttributes ImgAtt;
		ImgAtt.SetWrapMode(Gdiplus::WrapModeTileFlipXY); 
		Gdiplus::Graphics graphics(dc);
		graphics.DrawImage(m_pImgCaption, gRect, 0, 0, (INT)m_pImgCaption->GetWidth(), (INT)m_pImgCaption->GetHeight(), Gdiplus::UnitPixel, &ImgAtt);
	}

	// �������ı�
	CRect rect;
	GetClientRect(rect);
	rect.left += BTN_CLOSE_SPACE;
	rect.bottom = CAPTION_HEIGHT;
	dc.SetBkMode(CAPTION_FONT_BKCLR);
	dc.SetTextColor(CAPTION_FONT_COLOR);
	CFont font;
	font.CreateFont(CAPTION_FONT_SIZE, 0, 0, 0, FW_NORMAL, FALSE,FALSE,FALSE,0,0,0,0,0,CAPTION_FONT_NAME);
	dc.SelectObject(font);
	dc.DrawText(m_strCaptionText, -1, &rect, DT_SINGLELINE | DT_VCENTER);
}


void CVideoPane::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (m_bShowToolBar)
	{
		if (NULL != m_CloseBtn.GetSafeHwnd())
		{
			m_CloseBtn.SetWindowPos(NULL, (cx - BTN_CLOSE_SPACE) - BTN_CLOSE_WIDTH, (CAPTION_HEIGHT - BTN_CLOSE_HEIGHT)/2, 0, 0, SWP_NOSIZE);
		}

		if (NULL != m_VideoStatic.GetSafeHwnd())
		{
			m_VideoStatic.SetWindowPos(NULL, 0, 0, cx, (cy - CAPTION_HEIGHT) - VIDEO_TOOLBAR_WIDTH, SWP_NOMOVE);
		}

		if (NULL != m_SnapshotBtn.GetSafeHwnd())
		{
			m_SnapshotBtn.SetWindowPos(NULL, VIDEO_IMG_BTN_SPACE, (cy - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2), 0, 0, SWP_NOSIZE);
		}
		if (NULL != m_ReversePlayBtn.GetSafeHwnd())
		{
			m_ReversePlayBtn.SetWindowPos(NULL, (2*VIDEO_IMG_BTN_SPACE) + VIDEO_IMG_BTN_WIDTH, (cy - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2), 0, 0, SWP_NOSIZE);
		}
		if (NULL != m_AudioBtn.GetSafeHwnd())
		{
			m_AudioBtn.SetWindowPos(NULL, (cx - (2*VIDEO_IMG_BTN_SPACE)) - (2*VIDEO_IMG_BTN_WIDTH), (cy - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2), 0, 0, SWP_NOSIZE);
		}
		if (NULL != m_FullScreenBtn.GetSafeHwnd())
		{
			m_FullScreenBtn.SetWindowPos(NULL, (cx - VIDEO_IMG_BTN_SPACE) - VIDEO_IMG_BTN_WIDTH, (cy - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2), 0, 0, SWP_NOSIZE);
		}
	}
	else
	{
		if (NULL != m_CloseBtn.GetSafeHwnd())
		{
			m_CloseBtn.SetWindowPos(NULL, (cx - BTN_CLOSE_SPACE) - BTN_CLOSE_WIDTH, (CAPTION_HEIGHT - BTN_CLOSE_HEIGHT)/2, 0, 0, SWP_NOSIZE);
		}

		if (NULL != m_VideoStatic.GetSafeHwnd())
		{
			m_VideoStatic.SetWindowPos(NULL, 0, 0, cx, cy - CAPTION_HEIGHT, SWP_NOMOVE);
		}
	}

	// ����������䶯�¼�
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		CRect rect;
		GetWindowRect(&rect);

		PlayerEventParamInfo* pInfo = new PlayerEventParamInfo;
		if (NULL != pInfo)
		{
			pInfo->iLeft = rect.left;
			pInfo->iTop = rect.top;
			pInfo->iWidth = rect.Width();
			pInfo->iHeight = rect.Height();

			m_pCeLTE_PlayerCtrl->PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_POSITION, (LPARAM)pInfo);
		}
	}
}


void CVideoPane::OnMove(int x, int y)
{
	CDialog::OnMove(x, y);

	// ����������䶯�¼�
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		CRect rect;
		GetWindowRect(&rect);

		PlayerEventParamInfo* pInfo = new PlayerEventParamInfo;
		if (NULL != pInfo)
		{
			pInfo->iLeft = rect.left;
			pInfo->iTop = rect.top;
			pInfo->iWidth = rect.Width();
			pInfo->iHeight = rect.Height();

			m_pCeLTE_PlayerCtrl->PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_POSITION, (LPARAM)pInfo);
		}
	}
	// TODO: Add your message handler code here
}


void CVideoPane::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (NULL != m_VideoStatic.GetSafeHwnd()
		&& !m_VideoStatic.IsFullScreen())
	{
		int iRet = m_VideoStatic.SetFullScreen();
		if (eLTE_SUCCESS == iRet)
		{
			// �������˳�ȫ���¼�
			if (NULL != m_pCeLTE_PlayerCtrl)
			{
				m_pCeLTE_PlayerCtrl->PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_FULLSCREEN, NULL);
			}
		}
	}

	CDialog::OnLButtonDblClk(nFlags, point);
}


void CVideoPane::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (NULL != m_VideoStatic.GetSafeHwnd()
		&& !m_VideoStatic.IsFullScreen())
	{
		int iRet = m_VideoStatic.SetFullScreen();
		if (eLTE_SUCCESS == iRet)
		{
			// �������˳�ȫ���¼�
			if (NULL != m_pCeLTE_PlayerCtrl)
			{
				m_pCeLTE_PlayerCtrl->PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_FULLSCREEN, NULL);
			}
		}
	}

	CDialog::OnNcLButtonDblClk(nHitTest, point);
}//lint !e1746


LRESULT CVideoPane::OnNcHitTest(CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(rect);
	ClientToScreen(rect);

	CRect htlRt;
	htlRt.left = rect.right - VIDEO_RESIZING_WIDTH;
	htlRt.top = rect.top + VIDEO_RESIZING_WIDTH;
	htlRt.right = rect.right;
	htlRt.bottom = rect.bottom - VIDEO_RESIZING_WIDTH;
	if (htlRt.PtInRect(point))
	{
		return HTRIGHT;
	}

	CRect htrRt;
	htrRt.left = rect.left;
	htrRt.top = rect.top + VIDEO_RESIZING_WIDTH;
	htrRt.right = rect.left + VIDEO_RESIZING_WIDTH;
	htrRt.bottom = rect.bottom - VIDEO_RESIZING_WIDTH;
	if (htrRt.PtInRect(point))
	{
		return HTLEFT;
	}

	CRect htbRt;
	htbRt.left = rect.left + VIDEO_RESIZING_WIDTH;
	htbRt.top = rect.bottom - VIDEO_RESIZING_WIDTH;
	htbRt.right = rect.right - VIDEO_RESIZING_WIDTH;
	htbRt.bottom = rect.bottom;
	if (htbRt.PtInRect(point))
	{
		return HTBOTTOM;
	}

	CRect htbLRt;
	htbLRt.left = rect.left;
	htbLRt.top = rect.bottom - (2*VIDEO_RESIZING_WIDTH);
	htbLRt.right = rect.left + (2*VIDEO_RESIZING_WIDTH);
	htbLRt.bottom = rect.bottom;
	if (htbLRt.PtInRect(point))
	{
		return HTBOTTOMLEFT;
	}

	CRect htbRRt;
	htbRRt.left = rect.right - (2*VIDEO_RESIZING_WIDTH);
	htbRRt.top = rect.bottom - (2*VIDEO_RESIZING_WIDTH);
	htbRRt.right = rect.right;
	htbRRt.bottom = rect.bottom;
	if (htbRRt.PtInRect(point))
	{
		return HTBOTTOMRIGHT;
	}
	
	if (rect.PtInRect(point))
	{
		return HTCAPTION;
	}

	return CDialog::OnNcHitTest(point);
}//lint !e1746


LRESULT CVideoPane::OnMsgImgBtnClicked(WPARAM wParam, LPARAM /*lParam*/)
{
	int iImgBtnID = (int)wParam;
	CeLTE_PlayerCtrl* pCeLTE_PlayerCtrl = dynamic_cast<CeLTE_PlayerCtrl*>(m_pCeLTE_PlayerCtrl);
	if (NULL == pCeLTE_PlayerCtrl)
	{
		ERROR_LOG() << "pCeLTE_PlayerCtrl is null.";
		return -1L;
	}

	switch (iImgBtnID)
	{
		// ץͼ
	case IDC_BTN_SNAPSHOT:
		{
			(void)pCeLTE_PlayerCtrl->ToolBarSnapshot();
		}
		break;
		// ����ͷ�л�
	case IDC_BTN_REVERSEPLAY:
		{
			(void)pCeLTE_PlayerCtrl->ToolBarReversePlayer();
		}
		break;
		// ����
	case IDC_BTN_VOLUME:
		{
			m_bHaveSound = !m_bHaveSound;
			CString strOcxPath = eLTE_Tool::GetOcxPath();
			strOcxPath.Append(IMG_RESOURCE_PATH);
			if (m_bHaveSound)
			{
				m_AudioBtn.LoadImages(strOcxPath + IMG_UNMUTE_NORMAL, strOcxPath + IMG_UNMUTE_SELECT,
					strOcxPath + IMG_UNMUTE_FOCUS, strOcxPath + IMG_UNMUTE_DISABLE);
				m_AudioBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_MUTE)));

				// ���Ű���
				(void)pCeLTE_PlayerCtrl->ToolBarPlayAudio(TRUE);
			}
			else
			{
				m_AudioBtn.LoadImages(strOcxPath + IMG_MUTE_NORMAL, strOcxPath + IMG_MUTE_SELECT,
					strOcxPath + IMG_MUTE_FOCUS, strOcxPath + IMG_MUTE_DISABLE);
				m_AudioBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_UNMUTE)));

				// �رհ���
				(void)pCeLTE_PlayerCtrl->ToolBarPlayAudio(FALSE);
			}
		}
		break;
		// ȫ��
	case IDC_BTN_FULLSCREEN:
		{
			if (NULL == m_VideoStatic.GetSafeHwnd())
			{
				ERROR_LOG() << "VideoStatic had been destory.";
				return eLTE_FAILED;
			}
			int iRet = m_VideoStatic.SetFullScreen();
			if (eLTE_SUCCESS == iRet)
			{
				// ������ȫ���¼�
				pCeLTE_PlayerCtrl->PostMessage(WM_ELTE_POST_PLAYER_EVENT, (WPARAM)eLTE_PLAYER_FULLSCREEN, NULL);
			}
		}
		break;
		// �ر�
	case IDC_BTN_CLOSEVIDEO:
		{
			PostMessage(WM_CLOSE);
		}
		break;
	default:
		{
			ERROR_LOG() << "Invalid btn ID.";
		}
		break;
	}

	return 0L;
}


void CVideoPane::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	switch (nHitTest)
	{
	case HTTOP:
		{
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, FALSE, NULL, 0);
			SendMessage( WM_SYSCOMMAND, SC_SIZE | WMSZ_TOP, MAKELPARAM(point.x, point.y));
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
			Invalidate(TRUE);
		}
		break;
	case HTBOTTOM:
		{
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, FALSE, NULL, 0);
			SendMessage( WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOM, MAKELPARAM(point.x, point.y));
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
			Invalidate(TRUE);
		}
		break;
	case HTLEFT:
		{
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, FALSE, NULL, 0);
			SendMessage( WM_SYSCOMMAND, SC_SIZE | WMSZ_LEFT, MAKELPARAM(point.x, point.y));
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
			Invalidate(TRUE);
		}
		break;
	case HTRIGHT:
		{
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, FALSE, NULL, 0);
			SendMessage( WM_SYSCOMMAND, SC_SIZE | WMSZ_RIGHT, MAKELPARAM(point.x, point.y));
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
			Invalidate(TRUE);
		}
		break;
	case HTTOPLEFT:
		{
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, FALSE, NULL, 0);
			SendMessage( WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPLEFT, MAKELPARAM(point.x, point.y));
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
			Invalidate(TRUE);
		}
		break;
	case HTTOPRIGHT:
		{
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, FALSE, NULL, 0);
			SendMessage( WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPRIGHT, MAKELPARAM(point.x, point.y));
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
			Invalidate(TRUE);
		}
		break;
	case HTBOTTOMLEFT:
		{
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, FALSE, NULL, 0);
			SendMessage( WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMLEFT, MAKELPARAM(point.x, point.y));
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
			Invalidate(TRUE);
		}
		break;
	case HTBOTTOMRIGHT:
		{
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, FALSE, NULL, 0);
			SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMRIGHT, MAKELPARAM(point.x, point.y));
			SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, TRUE, NULL, 0);
			Invalidate(TRUE);
		}
		break;
	default:
		{

		}
		break;
	}

	CDialog::OnNcLButtonDown(nHitTest, point);
}//lint !e1746


// ����Ƥ������
void CVideoPane::SetParam(int skinType, const CString& strLogoPath)
{
	m_VideoStatic.SetParam(skinType, strLogoPath);
}


// ����ͼƬ·��
void CVideoPane::SetParam(const CString& strLogoPath)
{
	m_VideoStatic.SetParam(strLogoPath);
}


// ȫ��
eLTE_RET CVideoPane::SetFullScreen()
{
	if (NULL == m_VideoStatic.GetSafeHwnd())
	{
		ERROR_LOG() << "VideoStatic had been destory.";
		return eLTE_FAILED;
	}
	return m_VideoStatic.SetFullScreen();
}


// �˳�ȫ��
eLTE_RET CVideoPane::ResetFullScreen()
{
	if (NULL == m_VideoStatic.GetSafeHwnd())
	{
		ERROR_LOG() << "VideoStatic had been destory.";
		return eLTE_FAILED;
	}
	return m_VideoStatic.ResetFullScreen();
}


// �Ƿ�ȫ��
BOOL CVideoPane::IsFullScreen() const
{
	return m_VideoStatic.IsFullScreen();
}


// ��ȡ���Ŵ�����
HWND CVideoPane::GetVideoStaticSafeHwnd() const
{
	return m_VideoStatic.GetSafeHwnd();
}


// ����رհ�ť
void CVideoPane::EnableImageButton(BOOL bEnable)
{
	if (bEnable)
	{
		if (NULL != m_SnapshotBtn.GetSafeHwnd())
		{
			m_SnapshotBtn.EnableWindow(TRUE);
			m_SnapshotBtn.SetCurImgState(ImgState_Normal);
		}
		if (NULL != m_ReversePlayBtn.GetSafeHwnd())
		{
			m_ReversePlayBtn.EnableWindow(TRUE);
			m_ReversePlayBtn.SetCurImgState(ImgState_Normal);
		}
		if (NULL != m_AudioBtn.GetSafeHwnd() && m_bEnableAudio)
		{
			m_AudioBtn.EnableWindow(TRUE);
			m_AudioBtn.SetCurImgState(ImgState_Normal);
		}
		if (NULL != m_FullScreenBtn.GetSafeHwnd())
		{
			m_FullScreenBtn.EnableWindow(TRUE);
			m_FullScreenBtn.SetCurImgState(ImgState_Normal);
		}
	}
	else
	{
		if (NULL != m_SnapshotBtn.GetSafeHwnd())
		{
			m_SnapshotBtn.EnableWindow(FALSE);
			m_SnapshotBtn.SetCurImgState(ImgState_Disable);
		}
		if (NULL != m_ReversePlayBtn.GetSafeHwnd())
		{
			m_ReversePlayBtn.EnableWindow(FALSE);
			m_ReversePlayBtn.SetCurImgState(ImgState_Disable);
		}
		if (NULL != m_AudioBtn.GetSafeHwnd())
		{
			m_AudioBtn.EnableWindow(FALSE);
			m_AudioBtn.SetCurImgState(ImgState_Disable);
		}
		if (NULL != m_FullScreenBtn.GetSafeHwnd())
		{
			m_FullScreenBtn.EnableWindow(FALSE);
			m_FullScreenBtn.SetCurImgState(ImgState_Disable);
		}
	}

	// ˢ�¹�����
	if (NULL != m_hWnd)
	{
		CRect rt;
		GetClientRect(rt);
		rt.top = rt.bottom - VIDEO_TOOLBAR_WIDTH;
		InvalidateRect(rt, TRUE);
	}
}


// ����رհ���
void CVideoPane::EnableAudio(BOOL bEnable)
{
	m_bEnableAudio = bEnable;

	if (NULL != m_AudioBtn.GetSafeHwnd())
	{
		CString strOcxPath = eLTE_Tool::GetOcxPath();
		strOcxPath.Append(IMG_RESOURCE_PATH);
		m_AudioBtn.LoadImages(strOcxPath + IMG_MUTE_NORMAL, strOcxPath + IMG_MUTE_SELECT,
			strOcxPath + IMG_MUTE_FOCUS, strOcxPath + IMG_MUTE_DISABLE, ImgState_Disable);
		m_AudioBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_UNMUTE)));
		m_AudioBtn.Invalidate(TRUE);
	}
}


// ���ð���
void CVideoPane::PlayAudio(BOOL bPlay)
{
	if (m_bEnableAudio)
	{
		m_bHaveSound = bPlay;
		CString strOcxPath = eLTE_Tool::GetOcxPath();
		strOcxPath.Append(IMG_RESOURCE_PATH);
		if (bPlay)
		{
			m_AudioBtn.LoadImages(strOcxPath + IMG_UNMUTE_NORMAL, strOcxPath + IMG_UNMUTE_SELECT,
				strOcxPath + IMG_UNMUTE_FOCUS, strOcxPath + IMG_UNMUTE_DISABLE, ImgState_Normal);
			m_AudioBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_MUTE)));
		}
		else
		{
			m_AudioBtn.LoadImages(strOcxPath + IMG_MUTE_NORMAL, strOcxPath + IMG_MUTE_SELECT,
				strOcxPath + IMG_MUTE_FOCUS, strOcxPath + IMG_MUTE_DISABLE, ImgState_Normal);
			m_AudioBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_UNMUTE)));
		}
		// ˢ�¹�����
		if (NULL != m_hWnd)
		{
			CRect rt;
			GetClientRect(rt);
			rt.top = rt.bottom - VIDEO_TOOLBAR_WIDTH;
			InvalidateRect(rt, TRUE);
		}
	}
}


// ��ʾ������
void CVideoPane::ShowToolBar(BOOL bShow)
{
	m_bShowToolBar = bShow;
	
	// �ػ����
	if (!m_bShowToolBar && NULL != m_SnapshotBtn.GetSafeHwnd() 
		&& NULL != m_ReversePlayBtn.GetSafeHwnd() 
		&& NULL != m_FullScreenBtn.GetSafeHwnd() 
		&& NULL != m_AudioBtn.GetSafeHwnd())
	{
		m_SnapshotBtn.ShowWindow(SW_HIDE);
		m_ReversePlayBtn.ShowWindow(SW_HIDE);
		m_FullScreenBtn.ShowWindow(SW_HIDE);
		m_AudioBtn.ShowWindow(SW_HIDE);
	}
	if (m_bShowToolBar && NULL != m_SnapshotBtn.GetSafeHwnd() 
		&& NULL != m_ReversePlayBtn.GetSafeHwnd() 
		&& NULL != m_FullScreenBtn.GetSafeHwnd() 
		&& NULL != m_AudioBtn.GetSafeHwnd())
	{
		m_SnapshotBtn.ShowWindow(SW_SHOW);
		m_ReversePlayBtn.ShowWindow(SW_SHOW);
		m_FullScreenBtn.ShowWindow(SW_SHOW);
		m_AudioBtn.ShowWindow(SW_SHOW);

		CRect rt;
		GetClientRect(rt);
		m_SnapshotBtn.SetWindowPos(NULL, VIDEO_IMG_BTN_SPACE, (rt.Height() - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2), 0, 0, SWP_NOSIZE);
		m_ReversePlayBtn.SetWindowPos(NULL, (2*VIDEO_IMG_BTN_SPACE) + VIDEO_IMG_BTN_WIDTH, (rt.Height() - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2), 0, 0, SWP_NOSIZE);
		m_AudioBtn.SetWindowPos(NULL, (rt.Width() - (2*VIDEO_IMG_BTN_SPACE)) - (2*VIDEO_IMG_BTN_WIDTH), (rt.Height() - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2), 0, 0, SWP_NOSIZE);
		m_FullScreenBtn.SetWindowPos(NULL, (rt.Width() - VIDEO_IMG_BTN_SPACE) - VIDEO_IMG_BTN_WIDTH, (rt.Height() - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2), 0, 0, SWP_NOSIZE);
	}
	if (!m_bShowToolBar && NULL != m_VideoStatic.GetSafeHwnd())
	{
		CRect rt;
		GetClientRect(rt);
		m_VideoStatic.SetWindowPos(NULL, 0, 0, rt.Width(), rt.Height() - CAPTION_HEIGHT, SWP_NOMOVE);
	}
	if (m_bShowToolBar && NULL != m_VideoStatic.GetSafeHwnd())
	{
		CRect rt;
		GetClientRect(rt);
		m_VideoStatic.SetWindowPos(NULL, 0, 0, rt.Width(), (rt.Height() - CAPTION_HEIGHT) - VIDEO_TOOLBAR_WIDTH, SWP_NOMOVE);
	}
	// ˢ�¹�����
	if (NULL != m_hWnd)
	{
		Invalidate(TRUE);
	}
}


void CVideoPane::SetLanguage(int ilang)
{
	int iLangId = GetUserDefaultLangID();
	
	switch (ilang)
	{
	case eLTE_LANG_zh_CN:
		{
			iLangId = 2052;	// ����
		}
		break;
	case eLTE_LANG_en_US:
		{
			iLangId = 1033;	// Ӣ��
		}
		break;
	case eLTE_LANG_es_ES:
		{
			iLangId = 1034;	// ������
		}
		break;
	default:
		{

		}
		break;
	}
	m_Language.LoadLanguage(iLangId);

	// ˢ����ʾ�ı�
	if (NULL != m_hWnd)
	{
		m_SnapshotBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_SNAPSHOT)));
		m_ReversePlayBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_REVERSEPLAY)));
		m_AudioBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_UNMUTE)));
		m_FullScreenBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_FULLSCREEN)));
		m_CloseBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_CLOSEVIDEO)));
		if (m_bHaveSound)
		{
			m_AudioBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_MUTE)));
		}
		else
		{
			m_AudioBtn.UpdateToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_UNMUTE)));
		}
	}
}


// ���ñ������ı�
void CVideoPane::SetCaptionText(const CString& strText)
{
	DEBUG_LOG() << "--- ENTRY";
	DEBUG_PARAM1(strText);
	
	m_strCaptionText = strText;
	SetWindowText(m_strCaptionText);

	CRect rect;
	GetClientRect(rect);
	rect.bottom = CAPTION_HEIGHT;
	InvalidateRect(rect, TRUE);
	DEBUG_LOG() << "--- LEAVE";
}


void CVideoPane::SetCeLTE_PlayerCtrl(COleControl* pCeLTE_PlayerCtrl)
{
	DEBUG_LOG() << "--- ENTRY";
	DEBUG_PARAM1(pCeLTE_PlayerCtrl);

	m_pCeLTE_PlayerCtrl = pCeLTE_PlayerCtrl;

	DEBUG_LOG() << "--- LEAVE";
}


void CVideoPane::CreateCaption(const CRect& rect, const CString& strOcxPath)
{
	// ������Դ·��
	CString strCaptionPath(strOcxPath);
	strCaptionPath.Append(IMG_CAPTION_PATH);

	// ��������
	CRect rtCaption(rect);
	rtCaption.bottom = CAPTION_HEIGHT;

	// ������ԴͼƬ
	m_pImgCaption = Gdiplus::Image::FromFile(strCaptionPath + IMG_CAPTION);
	if (NULL == m_pImgCaption)
	{
		ERROR_LOG() << "m_pImgCaption is null.";
	}
	else
	{
		if (Gdiplus::Ok != m_pImgCaption->GetLastStatus())
		{
			ERROR_LOG() << "Gdiplus::Image::FromFile failed.";
			m_pImgCaption = NULL;
		}
	}

	// �������رհ�ť
	CRect rtClose;
	rtClose.left = (rect.right - BTN_CLOSE_SPACE) - BTN_CLOSE_WIDTH;
	rtClose.top = (CAPTION_HEIGHT - BTN_CLOSE_HEIGHT)/2;
	rtClose.right = rtClose.left + BTN_CLOSE_WIDTH;
	rtClose.bottom = rtClose.top + BTN_CLOSE_HEIGHT;
	m_CloseBtn.Create(_T(""), WS_CHILD | WS_VISIBLE, rtClose, this, IDC_BTN_CLOSEVIDEO);
	m_CloseBtn.LoadImages(strCaptionPath + IMG_CLOSE_NORMAL, strCaptionPath + IMG_CLOSE_SELECT,
		strCaptionPath + IMG_CLOSE_FOCUS, strCaptionPath + IMG_CLOSE_DISABLE);
	m_CloseBtn.AddToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_CLOSEVIDEO)));
}


void CVideoPane::CreateToolBar(const CRect& rect, const CString& strOcxPath)
{
	// ���ð�ť����
	CRect rtSnapshot,rtChangePlay,rtAudio,rtFullScreen;
	rtSnapshot.left = rect.left + VIDEO_IMG_BTN_SPACE;
	rtSnapshot.top = (rect.bottom - VIDEO_TOOLBAR_WIDTH) + ((VIDEO_TOOLBAR_WIDTH - VIDEO_IMG_BTN_WIDTH)/2);
	rtSnapshot.right = rtSnapshot.left + VIDEO_IMG_BTN_WIDTH;
	rtSnapshot.bottom = rtSnapshot.top + VIDEO_IMG_BTN_WIDTH;

	rtChangePlay.left = rtSnapshot.right + VIDEO_IMG_BTN_SPACE;
	rtChangePlay.top = rtSnapshot.top;
	rtChangePlay.right = rtChangePlay.left + VIDEO_IMG_BTN_WIDTH;
	rtChangePlay.bottom = rtChangePlay.top + VIDEO_IMG_BTN_WIDTH;

	rtAudio.left = rect.right - ((2*VIDEO_IMG_BTN_SPACE) + (2*VIDEO_IMG_BTN_WIDTH));
	rtAudio.top = rtSnapshot.top;
	rtAudio.right = rtAudio.left + VIDEO_IMG_BTN_WIDTH;
	rtAudio.bottom = rtAudio.top + VIDEO_IMG_BTN_WIDTH;

	rtFullScreen.left = rect.right - (VIDEO_IMG_BTN_SPACE + VIDEO_IMG_BTN_WIDTH);
	rtFullScreen.top = rtSnapshot.top;
	rtFullScreen.right = rtFullScreen.left + VIDEO_IMG_BTN_WIDTH;
	rtFullScreen.bottom = rtFullScreen.top + VIDEO_IMG_BTN_WIDTH;

	// ������ť
	m_SnapshotBtn.Create(_T(""), WS_CHILD | WS_VISIBLE, rtSnapshot, this, IDC_BTN_SNAPSHOT);
	m_ReversePlayBtn.Create(_T(""), WS_CHILD | WS_VISIBLE, rtChangePlay, this, IDC_BTN_REVERSEPLAY);
	m_AudioBtn.Create(_T(""), WS_CHILD | WS_VISIBLE, rtAudio, this, IDC_BTN_VOLUME);
	m_FullScreenBtn.Create(_T(""), WS_CHILD | WS_VISIBLE, rtFullScreen, this, IDC_BTN_FULLSCREEN);

	// ����״̬ͼƬ
	CString strToolBar(strOcxPath);
	strToolBar.Append(IMG_RESOURCE_PATH);
	m_SnapshotBtn.LoadImages(strToolBar + IMG_SNAPSHOT_NORMAL, strToolBar + IMG_SNAPSHOT_SELECT,
		strToolBar + IMG_SNAPSHOT_FOCUS, strToolBar + IMG_SNAPSHOT_DISABLE);
	m_ReversePlayBtn.LoadImages(strToolBar + IMG_REVERSEPLAY_NORMAL, strToolBar + IMG_REVERSEPLAY_SELECT,
		strToolBar + IMG_REVERSEPLAY_FOCUS, strToolBar + IMG_REVERSEPLAY_DISABLE);
	m_AudioBtn.LoadImages(strToolBar + IMG_UNMUTE_NORMAL, strToolBar + IMG_UNMUTE_SELECT,
		strToolBar + IMG_UNMUTE_FOCUS, strToolBar + IMG_UNMUTE_DISABLE);
	m_FullScreenBtn.LoadImages(strToolBar + IMG_FULLSCREEN_NORMAL, strToolBar + IMG_FULLSCREEN_SELECT,
		strToolBar + IMG_FULLSCREEN_FOCUS, strToolBar + IMG_FULLSCREEN_DISABLE);

	// ����������ʾ
	m_SnapshotBtn.AddToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_SNAPSHOT)));
	m_ReversePlayBtn.AddToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_REVERSEPLAY)));
	m_AudioBtn.AddToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_MUTE)));
	m_FullScreenBtn.AddToolTip(m_Language.GetString(GET_STRING_PARAM(IDS_FULLSCREEN)));
}


void CVideoPane::CreateVideoStatic(const CRect& rect, const CString& /*strOcxPath*/)
{
	CRect rtVideo(rect);
	rtVideo.top = CAPTION_HEIGHT;
	if (m_bShowToolBar)
	{
		rtVideo.bottom -= VIDEO_TOOLBAR_WIDTH;	
	}
	m_VideoStatic.Create(NULL, WS_CHILD | WS_VISIBLE, rtVideo, this);
	m_VideoStatic.SetParentWnd(this);
}
//lint -e766
