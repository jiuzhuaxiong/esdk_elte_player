/********************************************************************
filename    :    eLTE_Tool.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    ���߹����ࡣ��ȡ�ڲ�ʹ�õĹ��÷���ͳһ����
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_TOOL_H__
#define __ELTE_OCX_TOOL_H__

#include <sstream>


class eLTE_Tool
{
	// �ļ�·��
public:	
	static CString GetOcxPath();
	static std::string GetOcxPathA();
	static CString GetAppPath();
	static std::string GetAppPathA();
	static BOOL IsExistPath(const CString& path);
	static BOOL IsExistPath(const std::string& path);
	static BOOL CreateMultipleDirectory(const CString& path);
	static BOOL CreateMultipleDirectory(const std::string& path);
	static void RelativePathToAbsolute(CString& path);
	static void RelativePathToAbsolute(std::string& path);
	static void RelativePathToAbsoluteOcx(CString& path);

	// ����ת��
public:	
	static std::string UnicodeToANSI(const std::wstring& str);
	static std::string UnicodeToUTF8(const std::wstring& str);
	static std::wstring ANSIToUnicode(const std::string& str);
	static std::wstring UTF8ToUnicode(const std::string& str);
	static std::string UTF8ToANSI(const std::string& str);
	static std::string ANSIToUTF8(const std::string& str);

	// ���в�������
public:
	static BOOL ChangeEnvironmentVariable();

	// ��ȡOCX�汾
public:
	static CString GetOcxVersion();

	// IP����
public:
	static std::string GetIPByUIntValue(unsigned long ulIP);

	// ����ת��
public:
	// int ת��Ϊ std::string
	static std::string Int2String(int iVar);
	// unsigned int ת��Ϊ std::string
	static std::string UInt2String(unsigned int iVar);
	// double װ��Ϊ std::string
	static std::string Double2String(double dVar);
	// std::string ת��Ϊ int
	static int String2Int(const std::string& str);
	// std::string ת��Ϊ unsigned int
	static unsigned int String2UInt(const std::string& str);
	// std::wstring ת��Ϊ int
	static int WString2Int(const std::wstring& wstr);
	// std::wstring ת��Ϊ unsigned int
	static unsigned int WString2UInt(const std::wstring& wstr);

private:
	eLTE_Tool(void);
	~eLTE_Tool(void);
};

#endif
