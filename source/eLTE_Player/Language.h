/********************************************************************
filename    :    Language.h
author      :    yubinbin wx200189
created     :    2014/08/12
description :    国际化文件
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/08/12 初始版本
*********************************************************************/

#ifndef __ELTE_OCX_LANGUAGE_H__
#define __ELTE_OCX_LANGUAGE_H__

#include <map>
#include <vector>


#define GET_STRING_PARAM(ID) ID, _T(#ID)
typedef std::map<CString, CString> VALUE_MAP;
typedef std::vector<CString> STRING_LIST;
typedef VALUE_MAP LANG_MAP;

class Language
{
public:
	Language(void);
	~Language(void);

public:
	void LoadLanguage(int iLangId);
	CString GetString(UINT uiID, const CString& strKey);

	// ini 文件操作
private:
	BOOL GetAllValueMap(VALUE_MAP &valueMap) const;
	BOOL GetSectionNames(STRING_LIST &nameList) const;
	BOOL GetSectionValueMap(LPCTSTR strSection, VALUE_MAP& valueMap) const;

private:
	CString m_strFileName;
	LANG_MAP m_langMap;
};

#endif
