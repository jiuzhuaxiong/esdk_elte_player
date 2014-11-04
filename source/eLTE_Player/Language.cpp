#include "StdAfx.h"
#include "Language.h"
#include "eLTE_Tool.h"


#define LANGUAGE_MAX_LENGTH	128

Language::Language(void)
	: m_strFileName(_T(""))
{
	m_langMap.clear();
}

Language::~Language(void)
{
	try
	{
		m_strFileName = _T("");
		m_langMap.clear();
	}
	catch(...)
	{

	}
}

void Language::LoadLanguage(int iLangId)
{
	// 清除原来的语言
	m_langMap.clear();

	CString strPath = eLTE_Tool::GetOcxPath();
	CString strCfgFileName;
	strCfgFileName.Format(_T("Lang\\%d.ini"), iLangId);
	strPath.Append(strCfgFileName);

	m_strFileName = strPath;
	(void)GetAllValueMap(m_langMap);
}

CString Language::GetString(UINT uiID, const CString& strKey)
{
	CString strValue = _T("");

	// 使用系统语言
	if (m_strFileName.IsEmpty())
	{
		LoadLanguage(GetUserDefaultLangID());
	}

	// 使用配置文件数据
	LANG_MAP::iterator iter = m_langMap.find(strKey);
	if(m_langMap.end() != iter)
	{
		strValue = iter->second;
	}

	if(strValue.IsEmpty())
	{
		// 使用默认配置
		TCHAR tchValue[LANGUAGE_MAX_LENGTH] = {0};
		(void)::LoadString(AfxGetInstanceHandle(), uiID, tchValue, /*sizeof(TCHAR)**/LANGUAGE_MAX_LENGTH);
		strValue = tchValue;
	}

	return strValue;
}

BOOL Language::GetAllValueMap(VALUE_MAP &valueMap) const
{
	STRING_LIST nameList;
	if(GetSectionNames(nameList))
	{
		for(STRING_LIST::iterator ite=nameList.begin();ite!=nameList.end();ite++)
		{
			CString strSection = *ite;
			VALUE_MAP tmpMap;
			if(GetSectionValueMap(strSection, tmpMap))
			{
				VALUE_MAP::iterator itor_b = tmpMap.begin();
				VALUE_MAP::iterator itor_e = tmpMap.end();
				for (; itor_b != itor_e; itor_b++)
				{
					(void)valueMap.insert(std::make_pair(itor_b->first, itor_b->second));
				}
			}
		}
	}
	return TRUE;
}

BOOL Language::GetSectionNames(STRING_LIST &nameList) const
{
	const int BUF_MAX_SIZE = 1024*2;
	TCHAR *pSectionBuf = new TCHAR[BUF_MAX_SIZE];
	DWORD dwNamesLen = GetPrivateProfileSectionNames((LPTSTR)pSectionBuf, BUF_MAX_SIZE, m_strFileName);
	if(0 == dwNamesLen)
	{
		delete[] pSectionBuf;
		return FALSE;
	}
	TCHAR *pBuf = pSectionBuf;
	size_t nLen = 0;
	do 
	{
		nameList.push_back((LPTSTR)pBuf);
		nLen = std::wcslen(pBuf) + 1;
		pBuf += nLen;
		dwNamesLen -= nLen;
	} while (dwNamesLen > 0);
	delete[] pSectionBuf;
	return TRUE;
}

BOOL Language::GetSectionValueMap(LPCTSTR strSection, VALUE_MAP& valueMap) const
{
	const int BUF_MAX_SIZE = 1024*8;
	TCHAR *pValuesBuf = new TCHAR[BUF_MAX_SIZE];
	DWORD dwValuesLen = GetPrivateProfileSection(strSection, pValuesBuf, BUF_MAX_SIZE, m_strFileName);
	if(0 == dwValuesLen)
	{
		delete[] pValuesBuf;
		return FALSE;
	}
	TCHAR *pBuf = pValuesBuf;
	size_t nLen = 0;
	do 
	{
		CString key_value = pBuf;
		int pos = key_value.Find(_T("="));
		CString strKey;
		CString strValue;
		if(pos>0)
		{
			strKey = key_value.Left(pos);
			strValue = key_value.Right((key_value.GetLength() - key_value.Find(_T("="))) - 1);
		}
		else if(pos<0)
		{
			strKey = key_value;
		}
		if(!strKey.IsEmpty())
		{
			VALUE_MAP::iterator ite = valueMap.find(strKey);
			if(ite==valueMap.end())
			{
				valueMap.insert(VALUE_MAP::value_type(strKey, strValue));
			}
			else
			{
				ite->second = strValue;
			}
		}
		nLen = std::wcslen(pBuf);
		pBuf += nLen + 1;
		dwValuesLen -= nLen + 1;
	} while (dwValuesLen > 0);
	delete[] pValuesBuf;
	return TRUE;
}
