/********************************************************************
filename    :    VideoPane.h
author      :    yubinbin wx200189
created     :    2014/07/30
description :    �ؼ���Ƶ���Ŵ��塣����Ƶ�ش��Ĳ��Ŵ���
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/30 ��ʼ�汾
*********************************************************************/

#pragma once

#include "eLTE_Player.h"
#include "VideoStatic.h"
#include "ImageButton.h"
#include "Language.h"
// CVideoPane dialog

#define VIDEO_TOOLBAR_WIDTH		30	// ���������
#define VIDEO_IMG_BTN_WIDTH		25	// ͼƬ��ť���
#define VIDEO_IMG_BTN_SPACE		10	// ͼƬ��ť���
#define VIDEO_RESIZING_WIDTH	5	// �����߿���

#define BTN_CLOSE_WIDTH			25	// �رհ�ť���
#define BTN_CLOSE_HEIGHT		25	// �رհ�ť�߶�
#define BTN_CLOSE_SPACE			10	// �رհ�ť���

#define CAPTION_HEIGHT			30	// �������߶�

//�������ı�����
#define CAPTION_FONT_SIZE		20					// �����С
#define CAPTION_FONT_COLOR		RGB(84, 84, 84)		// ������ɫ
#define CAPTION_FONT_BKCLR		TRANSPARENT			// ���屳����ɫ
#define CAPTION_FONT_NAME		_T("΢���ź�")		// ��������

// ͼƬ���ֶ���
#define IMG_RESOURCE_PATH		_T("Skin\\ToolBar\\")		// ͼƬ��ԴĿ¼
#define IMG_CAPTION_PATH		_T("Skin\\Caption\\")		// ��������ԴĿ¼

#define IMG_CAPTION				_T("caption.png")			// ����������ͼƬ����ȡ����
#define IMG_CAPTION_FOCUS		_T("caption_focus.png")		// ����������ͼƬ����ȡ����
#define IMG_CAPTION_DEFOCUS		_T("caption_defocus.png")	// ����������ͼƬ���޽���

#define IMG_CLOSE_NORMAL		_T("close_normal.png")		// �رհ�ť������
#define IMG_CLOSE_SELECT		_T("close_select.png")		// �رհ�ť��ѡ��
#define IMG_CLOSE_FOCUS			_T("close_focus.png")		// �رհ�ť����ȡ����
#define IMG_CLOSE_DISABLE		_T("close_disable.png")		// �رհ�ť����ֹʹ��

#define IMG_SNAPSHOT_NORMAL		_T("snapshot_normal.png")	// ץͼ������
#define IMG_SNAPSHOT_SELECT		_T("snapshot_select.png")	// ץͼ��ѡ��
#define IMG_SNAPSHOT_FOCUS		_T("snapshot_focus.png")	// ץͼ����ȡ����
#define IMG_SNAPSHOT_DISABLE	_T("snapshot_disable.png")	// ץͼ����ֹʹ��

#define IMG_REVERSEPLAY_NORMAL	_T("reverseplay_normal.png")	// �л�������
#define IMG_REVERSEPLAY_SELECT	_T("reverseplay_select.png")	// �л���ѡ��
#define IMG_REVERSEPLAY_FOCUS	_T("reverseplay_focus.png")	// �л�����ȡ����
#define IMG_REVERSEPLAY_DISABLE	_T("reverseplay_disable.png")// �л�����ֹʹ��

#define IMG_UNMUTE_NORMAL		_T("unmute_normal.png")		// ����������
#define IMG_UNMUTE_SELECT		_T("unmute_select.png")		// ������ѡ��
#define IMG_UNMUTE_FOCUS		_T("unmute_focus.png")		// ��������ȡ����
#define IMG_UNMUTE_DISABLE		_T("unmute_disable.png")	// ��������ֹʹ��

#define IMG_MUTE_NORMAL			_T("mute_normal.png")		// ����������
#define IMG_MUTE_SELECT			_T("mute_select.png")		// ������ѡ��
#define IMG_MUTE_FOCUS			_T("mute_focus.png")		// ��������ȡ����
#define IMG_MUTE_DISABLE		_T("mute_disable.png")		// ��������ֹʹ��

#define IMG_FULLSCREEN_NORMAL	_T("fullscreen_normal.png")	// ȫ��������
#define IMG_FULLSCREEN_SELECT	_T("fullscreen_select.png")	// ȫ����ѡ��
#define IMG_FULLSCREEN_FOCUS	_T("fullscreen_focus.png")	// ȫ������ȡ����
#define IMG_FULLSCREEN_DISABLE	_T("fullscreen_disable.png")// ȫ������ֹʹ��


class CVideoPane : public CDialog
{
	DECLARE_DYNAMIC(CVideoPane)

public:
	CVideoPane(CWnd* pParent = NULL);   // standard constructor
	virtual ~CVideoPane();

// Dialog Data
	enum { IDD = IDD_DIALOG_VIDEOPANE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg LRESULT OnMsgImgBtnClicked(WPARAM wParam, LPARAM lParam);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);

public:
	// ����Ƥ������
	void SetParam(int skinType, const CString& strLogoPath);
	// ����ͼƬ·��
	void SetParam(const CString& strLogoPath);
	// ȫ��
	eLTE_RET SetFullScreen();
	// �˳�ȫ��
	eLTE_RET ResetFullScreen();
	// �Ƿ�ȫ��
	BOOL IsFullScreen() const;
	// ��ȡ���Ŵ�����
	HWND GetVideoStaticSafeHwnd() const;
	// ����رհ�ť
	void EnableImageButton(BOOL bEnable);
	// ����رհ���
	void EnableAudio(BOOL bEnable);
	// ���ð���
	void PlayAudio(BOOL bPlay);
	// ��ʾ������
	void ShowToolBar(BOOL bShow);
	// ��������
	void SetLanguage(int ilang);
	// ���ñ������ı�
	void SetCaptionText(const CString& strText);
	// ����OCX�ؼ�ָ��
	void SetCeLTE_PlayerCtrl(COleControl* pCeLTE_PlayerCtrl);

private:
	void CreateCaption(const CRect& rect, const CString& strOcxPath);
	void CreateToolBar(const CRect& rect, const CString& strOcxPath);
	void CreateVideoStatic(const CRect& rect, const CString& strOcxPath);

private:
	CVideoStatic m_VideoStatic;
	Language m_Language;

	CImageButton m_SnapshotBtn;
	CImageButton m_ReversePlayBtn;
	CImageButton m_AudioBtn;
	CImageButton m_FullScreenBtn;
	CImageButton m_CloseBtn;

	Gdiplus::Image* m_pImgCaption;
	CString m_strCaptionText;

	BOOL m_bEnableAudio;
	BOOL m_bHaveSound;
	BOOL m_bShowToolBar;

private:
	COleControl* m_pCeLTE_PlayerCtrl;
};
