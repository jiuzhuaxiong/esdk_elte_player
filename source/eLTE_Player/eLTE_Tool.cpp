#include "StdAfx.h"
#include "eLTE_Tool.h"
#include "Shlwapi.h"

#pragma comment(lib, "Shlwapi.lib")


#define STR_LENGTH_SIZE 20
#define INT_FORMAT_D	10
#define DOUBLE_STR_SIZE	64
#define DOUBLE_FORMAT	"%g"
#define UINT_FORMAT		"%u"

eLTE_Tool::eLTE_Tool(void)
{
}


eLTE_Tool::~eLTE_Tool(void)
{
}

CString eLTE_Tool::GetOcxPath()
{
	TCHAR path[MAX_PATH] = {0};
	GetModuleFileName(AfxGetInstanceHandle(), path, MAX_PATH);

	CString szPath(path);
	szPath = szPath.Left(szPath.ReverseFind(_T('\\'))+1);

	return szPath;
}

std::string eLTE_Tool::GetOcxPathA()
{
	char path[MAX_PATH] = {0};
	GetModuleFileNameA(AfxGetInstanceHandle(), path, MAX_PATH);

	std::string strPath(path);
	strPath = strPath.substr(0, strPath.rfind("\\")+1);

	return strPath;
}

CString eLTE_Tool::GetAppPath()
{
	TCHAR path[MAX_PATH] = {0};
	GetModuleFileName(NULL, path, MAX_PATH);

	CString szPath(path);
	szPath = szPath.Left(szPath.ReverseFind(_T('\\'))+1);

	return szPath;
}

std::string eLTE_Tool::GetAppPathA()
{
	char path[MAX_PATH] = {0};
	GetModuleFileNameA(NULL, path, MAX_PATH);

	std::string strPath(path);
	strPath = strPath.substr(0, strPath.rfind("\\")+1);

	return strPath;
}

BOOL eLTE_Tool::IsExistPath(const CString& path)
{
	return PathFileExists(path);
}

BOOL eLTE_Tool::IsExistPath(const std::string& path)
{
	return PathFileExistsA(path.c_str());
}

BOOL eLTE_Tool::CreateMultipleDirectory(const CString& path)
{
	// ����Ѿ������Ѿ����سɹ�
	if (IsExistPath(path))
	{
		return TRUE;
	}
	else
	{
		CString szPath(path);

		// �жϿ�
		if (szPath.IsEmpty())
		{
			return FALSE;
		}

		// ��ȥ��β��"\\"
		while (_T("\\") == szPath.Right(1))
		{
			szPath.Left(szPath.GetLength()-1);
		}

		// ��ȡ�ϼ�Ŀ¼
		CString prePath = szPath.Left(szPath.ReverseFind(_T('\\')));

		// �����ڵ�Ŀ¼
		if (prePath == szPath)
		{
			return FALSE;
		}
		
		if (IsExistPath(prePath))
		{
			return CreateDirectory(szPath, NULL);
		}
		else
		{
			// ���ǰ���Ŀ¼�����ڣ����ȴ���ǰ���Ŀ¼
			if (CreateMultipleDirectory(prePath))
			{
				// ǰ��Ŀ¼���������Ժ����ٴ��������Ŀ¼
				return CreateMultipleDirectory(szPath);
			}
			return FALSE;
		}
	}
}

BOOL eLTE_Tool::CreateMultipleDirectory(const std::string& path)
{
	// ����Ѿ������Ѿ����سɹ�
	if (IsExistPath(path))
	{
		return TRUE;
	}
	else
	{
		std::string strPath(path);

		// �жϿ�
		if (strPath.empty())
		{
			return FALSE;
		}

		// ��ȥ��β��"\\"
		while ('\\' == strPath.back())
		{
			strPath = strPath.substr(0, strPath.rfind("\\"));
		}

		// ��ȡ�ϼ�Ŀ¼
		std::string prePath = strPath.substr(0, strPath.rfind("\\"));

		// �����ڵ�Ŀ¼
		if (prePath == strPath)
		{
			return FALSE;
		}

		if (IsExistPath(prePath))
		{
			return CreateDirectoryA(strPath.c_str(), NULL);
		}
		else
		{
			// ���ǰ���Ŀ¼�����ڣ����ȴ���ǰ���Ŀ¼
			if (CreateMultipleDirectory(prePath))
			{
				// ǰ��Ŀ¼���������Ժ����ٴ��������Ŀ¼
				return CreateMultipleDirectory(strPath);
			}
			return FALSE;
		}
	}
}

void eLTE_Tool::RelativePathToAbsolute(CString& path)
{
	if (PathIsRelative(path))
	{
		CString szApp = GetAppPath();
		szApp.Append(path);
		path = szApp;
	}
}

void eLTE_Tool::RelativePathToAbsolute(std::string& path)
{
	if (PathIsRelativeA(path.c_str()))
	{
		std::string strApp = GetAppPathA();
		strApp.append(path);
		path = strApp;
	}
}

void eLTE_Tool::RelativePathToAbsoluteOcx(CString& path)
{
	if (PathIsRelative(path))
	{
		CString szApp = GetOcxPath();
		szApp.Append(path);
		path = szApp;
	}
}

BOOL eLTE_Tool::ChangeEnvironmentVariable()
{
	// Get the eLTE SDK directory
	CString szPath = GetOcxPath();

	const int BUFSIZE = 4096;
	const TCHAR* VARNAME = _T("EASY_INSTALL");

	DWORD dwRet, dwErr;
	LPTSTR pszOldVal; 

	// Retrieves the current value of the variable if it exists.
	// Sets the variable to a new value, creates a child process,
	// then uses SetEnvironmentVariable to restore the original
	// value or delete it if it did not exist previously. 

	pszOldVal = (LPTSTR) malloc(BUFSIZE*sizeof(TCHAR));
	memset(pszOldVal, 0, BUFSIZE*sizeof(TCHAR));
	if(NULL == pszOldVal)
	{
		return FALSE;
	}

	dwRet = GetEnvironmentVariable(VARNAME, pszOldVal, BUFSIZE);

	if(0 == dwRet)
	{
		dwErr = GetLastError();
		if( ERROR_ENVVAR_NOT_FOUND == dwErr )
		{
			//ERROR_LOG() << "Environment variable does not exist.";
			memset(pszOldVal, 0, BUFSIZE*sizeof(TCHAR));
		}
		else
		{
			free(pszOldVal);
			return FALSE;
		}
	}
	else if(BUFSIZE < dwRet)
	{
		pszOldVal = (LPTSTR) realloc(pszOldVal, dwRet*sizeof(TCHAR));   
		if(NULL == pszOldVal)
		{
			//ERROR_LOG() << "Out of memory.";
			return FALSE;
		}
		dwRet = GetEnvironmentVariable(VARNAME, pszOldVal, dwRet);
		if(!dwRet)
		{
			//ERROR_LOG() << "GetEnvironmentVariable failed (" << GetLastError() << ")";
			free(pszOldVal);
			return FALSE;
		}
	}

	// Set a value for the child process to inherit. 
	CString szOldVal(pszOldVal);
	if (szOldVal != szPath)
	{
		if (!SetEnvironmentVariable(VARNAME, szPath)) 
		{
			//ERROR_LOG() << "SetEnvironmentVariable failed (" << GetLastError() << ")"; 
			free(pszOldVal);
			return FALSE;
		}
	}

	free(pszOldVal);
	return TRUE;
}

CString eLTE_Tool::GetOcxVersion()
{
	CString strVersion(_T(""));
	HRSRC hRsrc = FindResource(AfxGetInstanceHandle(), (LPCTSTR)VS_VERSION_INFO, RT_VERSION);
	if (NULL == hRsrc)
	{
		return strVersion;
	}
	HGLOBAL hGlobal = LoadResource(AfxGetInstanceHandle(), hRsrc);
	if (NULL == hGlobal)
	{
		return strVersion;
	}

	struct VS_VERSIONINFO
	{ 
		WORD  wLength; //lint -e754
		WORD  wValueLength; //lint -e754
		WORD  wType; //lint -e754

		WCHAR szKey[16]; //lint -e754
		WORD  Padding1[1]; //lint -e754
		VS_FIXEDFILEINFO Value;
		//  WORD  Padding2[];
		//  WORD  Children[];
	} *pData;
	DWORD ver1, ver2, ver3, ver4;

	pData = (VS_VERSIONINFO*)LockResource(hGlobal);
	if (NULL == pData)
	{
		return strVersion;
	}
	ver1 = pData->Value.dwFileVersionMS>>16;
	ver2 = pData->Value.dwFileVersionMS&0xffff;
	ver3 = pData->Value.dwFileVersionLS>>16;
	ver4 = pData->Value.dwFileVersionLS&0xffff;

	strVersion.Format(_T("%d.%d.%d.%d"), ver1, ver2, ver3, ver4);

	return strVersion;
}

std::string eLTE_Tool::GetIPByUIntValue(unsigned long ulIP)
{
	int val1 = (ulIP & 0xFF000000) >> 24;
	int val2 = (ulIP & 0x00FF0000) >> 16;
	int val3 = (ulIP & 0x0000FF00) >> 8;
	int val4 = (ulIP & 0x000000FF);

	std::string str = ".";
	std::string strIP
		= Int2String(val1)
		+ str
		+ Int2String(val2)
		+ str
		+ Int2String(val3)
		+ str
		+ Int2String(val4);

	return strIP;
}

std::string eLTE_Tool::UnicodeToANSI(const std::wstring& str)
{
	std::string strResult("");

	int textlen = WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	if (0 >= textlen)
	{
		// WideCharToMultiByte failed.
		return strResult;
	}

	size_t bufsize = (size_t)(textlen+1);
	char* pBuf = new char[bufsize];
	memset(pBuf, 0, sizeof(char)*bufsize);
	WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, pBuf, textlen, NULL, NULL);//lint !e713

	strResult = pBuf;
	delete[] pBuf;

	return strResult;
}

std::string eLTE_Tool::UnicodeToUTF8(const std::wstring& str)
{
	std::string strResult("");

	int textlen = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	if (0 >= textlen)
	{
		// WideCharToMultiByte failed.
		return strResult;
	}

	size_t bufsize = (size_t)(textlen+1);
	char* pBuf = new char[bufsize];
	memset(pBuf, 0, sizeof(char)*bufsize);
	WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, pBuf, textlen, NULL, NULL);//lint !e713

	strResult = pBuf;
	delete[] pBuf;

	return strResult;
}

std::wstring eLTE_Tool::ANSIToUnicode(const std::string& str)
{
	std::wstring strResult(L"");

	int textlen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	if (0 >= textlen)
	{
		// MultiByteToWideChar failed.
		return strResult;
	}

	size_t bufsize = (size_t)(textlen+1);
	wchar_t* pBuf = new wchar_t[bufsize];
	memset(pBuf, 0, sizeof(wchar_t)*bufsize);
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, (LPWSTR)pBuf, textlen);//lint !e713

	strResult = pBuf;
	delete[] pBuf;

	return strResult;
}

std::wstring eLTE_Tool::UTF8ToUnicode(const std::string& str)
{
	std::wstring strResult(L"");
	int textlen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	if (0 >= textlen)
	{
		// MultiByteToWideChar failed.
		return strResult;
	}

	size_t bufsize = (size_t)(textlen+1);
	wchar_t* pBuf = new wchar_t[bufsize];
	memset(pBuf, 0, sizeof(wchar_t)*bufsize);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, (LPWSTR)pBuf, textlen);//lint !e713

	strResult = pBuf;
	delete[] pBuf;

	return strResult;
}

std::string eLTE_Tool::UTF8ToANSI(const std::string& str)
{
	std::wstring strUnicode = UTF8ToUnicode(str);
	std::string strAnsi = UnicodeToANSI(strUnicode);
	return strAnsi;
}

std::string eLTE_Tool::ANSIToUTF8(const std::string& str)
{
	std::wstring strUnicode = ANSIToUnicode(str);
	std::string strUtf8 = UnicodeToUTF8(strUnicode);
	return strUtf8;
}

// int ת��Ϊ std::string
std::string eLTE_Tool::Int2String(int iVar)
{
	char buf[STR_LENGTH_SIZE] = {0};
	(void)_itoa_s(iVar, buf, INT_FORMAT_D);
	return std::string(buf);
}
// unsigned int ת��Ϊ std::string
std::string eLTE_Tool::UInt2String(unsigned int iVar)
{
	char _Buf[STR_LENGTH_SIZE];
	(void)sprintf_s(_Buf, sizeof(_Buf), UINT_FORMAT, iVar);
	return std::string(_Buf);
}
// double װ��Ϊ std::string
std::string eLTE_Tool::Double2String(double dVar)
{
	char _Buf[DOUBLE_STR_SIZE];
	(void)sprintf_s(_Buf, sizeof(_Buf), DOUBLE_FORMAT, dVar);
	return std::string(_Buf);
}
// std::string ת��Ϊ int
int eLTE_Tool::String2Int(const std::string& str)
{
	int iRet = 0;

	try
	{
		iRet = std::stoi(str);
	}
	catch (...)
	{
		iRet = 0;
	}

	return iRet;
}
// std::string ת��Ϊ unsigned int
unsigned int eLTE_Tool::String2UInt(const std::string& str)
{
	unsigned int uiRet = 0;

	try
	{
		uiRet = std::stoul(str);
	}
	catch (...)
	{
		uiRet = 0;
	}

	return uiRet;
}
// std::wstring ת��Ϊ int
int eLTE_Tool::WString2Int(const std::wstring& wstr)
{
	int iRet = 0;

	try
	{
		iRet = std::stoi(wstr);
	}
	catch (...)
	{
		iRet = 0;
	}

	return iRet;
}
// std::wstring ת��Ϊ unsigned int
unsigned int eLTE_Tool::WString2UInt(const std::wstring& wstr)
{
	unsigned int uiRet = 0;

	try
	{
		uiRet = std::stoul(wstr);
	}
	catch (...)
	{
		uiRet = 0;
	}

	return uiRet;
}
