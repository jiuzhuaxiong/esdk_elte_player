/********************************************************************
filename    :    VideoStatic.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    �ؼ���Ƶ���Ŵ��塣����Ƶ�ش��Ĳ��Ŵ���
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#pragma once

#include "DataType.h"

typedef enum
{
	eLTE_SKIN_INVALID = 0,
	eLTE_SKIN_BLACK,
	eLTE_SKIN_WHITE
} eLTE_SKIN_TYPE_E;

#define BLACK_COLOR RGB(88, 88, 88)
#define WHITE_COLOR RGB(255,255,255)

// CVideoStatic

class CVideoStatic : public CStatic
{
	DECLARE_DYNAMIC(CVideoStatic)

public:
	CVideoStatic();
	virtual ~CVideoStatic();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);

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
	// ���ø�����
	void SetParentWnd(CWnd* pParentWnd);

private:
	// ���ñ���ͼƬ
	void SetBackGroudImage(const CPaintDC& dc);

private:
	// ȫ��ǰ����Ļ��С
	WINDOWPLACEMENT m_struOldWndpl;
	// ȫ����־
	BOOL m_bIsFullScreen;
	// ������
	CWnd* m_pParentWnd;
	// ���λ��
	CPoint m_OldCursorPoint;

private:
	// Ƥ������
	int m_skinType;
	// ����ͼƬ·��
	CString m_strLogoPath;
	// ����logoͼƬ
	Gdiplus::Image* m_pImage;
};


