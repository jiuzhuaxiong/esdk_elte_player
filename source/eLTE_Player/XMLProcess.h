/********************************************************************
filename    :    XMLProcess.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    XML入参解析，XML出参赋值
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 初始版本
*********************************************************************/

#ifndef __ELTE_OCX_XML_PROCESS_H__
#define __ELTE_OCX_XML_PROCESS_H__

#include "DataType.h"


// XML返回值赋值
#define GET_RETURN_CODE_XML(xml, iRet, strResult)								\
	(void)xml.AddElem("Content");												\
	(void)xml.AddChildElem("ResultCode");										\
	(void)xml.IntoElem();														\
	(void)xml.SetElemValue(eLTE_Tool::Int2String(iRet).c_str());				\
	IVS_UINT32 uiLen = 0;														\
	strResult = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

// XML获取版本
#define GET_VERSION_XML(xml, pVersion, strResult)								\
	(void)xml.AddElem("Content");												\
	(void)xml.AddChildElem("Version");											\
	(void)xml.IntoElem();														\
	(void)xml.SetElemValue(pVersion);											\
	IVS_UINT32 uiLen = 0;														\
	strResult = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

// XML节点解析
#define GET_XML_ELEM_VALUE_CHAR(xml, elem, srcValue, retValue, maxLen, errCode)	\
	if (!xml.FindElem(elem))													\
	{																			\
		ERROR_LOG() << "FindElem " << #elem << " failed.";						\
		return errCode;															\
	}																			\
	srcValue = xml.GetElemValue();												\
	if (NULL == srcValue)														\
	{																			\
		ERROR_LOG() << "GetElemValue " << #elem << " failed.";					\
		return errCode;															\
	}																			\
	maxLen = (strlen(srcValue) < (maxLen)) ? strlen(srcValue) : ((maxLen)-1);	\
	memcpy(retValue, srcValue, maxLen);

// 检查OCX Load模式是否正确
#define CHECK_ELTE_OCX_LOAD_TYPE(type, xml, strResult)							\
	if (eLTE_LOAD_OPERATE_MGR != type)											\
	{																			\
		GET_RETURN_CODE_XML(xml, eLTE_ERROR_LOAD_TYPE, strResult);				\
		return strResult.AllocSysString();										\
	}


//////////////////////////////////////////////////////////////////////////
class XMLProcess
{
public:
	// 解析入参Video_UL_parameter
	static eLTE_RET XmlParseVideoULParameter(const std::string& xmlStr,			// 入参
		std::string& strVideoFormat, std::string& strCameraType,				// 出参
		std::string& strUserConfirmType, std::string& strMuteType);				// 出参

	// 解析入参视频播放参数
	static eLTE_RET XmlParsePlayVideoParam(const std::string& xmlStrLocal, const std::string& xmlStrRemote,	// 入参
		std::string& strLocalIP, unsigned int& uiLocalVideoPort, unsigned int& uiLocalAudioPort,			// 出参
		std::string& strRemoteIP, unsigned int& uiRemoteVideoPort, unsigned int& uiRemoteAudioPort);		// 出参

	// 解析查询录音文件信息的查询条件
	static eLTE_RET XmlParseRECQueryInfo(const std::string& xmlStr,
		RECQueryInfo& queryInfo);

public:
	// 设置DcGroups XML出参
	static eLTE_RET SetXmlStringDcGroups(const DcGroups* pDcGroups,			// 入参
		CString& xmlStr);													// 出参

	// 设置DcUsers XML出参
	static eLTE_RET SetXmlStringDcUsers(const DcUsers* pDcUsers,			// 入参
		CString& xmlStr);													// 出参

	// 设置GrpUserList XML出参
	static eLTE_RET SetXmlStringGrpUserList(const GrpUserList* pGrpUserList,// 入参
		CString& xmlStr);													// 出参

	// 设置GroupInfo XML出参
	static eLTE_RET SetXmlStringGroupInfo(const GroupInfo* pGroupInfo,		// 入参
		CString& xmlStr);													// 出参

	// 设置UserInfo XML出参
	static eLTE_RET SetXmlStringUserInfo(const UserInfo* pUserInfo,			// 入参
		CString& xmlStr);													// 出参

	// 设置DcProperty XML出参
	static eLTE_RET SetXmlStringDcProperty(const DcProperty* pDcProperty,	// 入参
		CString& xmlStr);													// 出参

	// 设置UserRecFileInfoList XML出参
	static eLTE_RET SetXmlStringRecFileInfoList(const UserRecFileInfoList* pInfoList,
		CString& xmlStr);

	// Event事件XML出参
public:
	static eLTE_RET SetXmlStringEventNotifyUserStatus(const NotifyUserStatusInfo* pInfo,
		CString& xmlStr);
	static eLTE_RET SetXmlStringEventNotifyP2pvideocallStatus(const NotifyP2pvideocallStatusInfo* pInfo,
		CString& xmlStr);
	static eLTE_RET SetXmlStringEventNotifyResourceStatus(const NotifyResourceStatusInfo* pInfo,
		CString& xmlStr);
	static eLTE_RET SetXmlStringEventNotifyProvisionChange(const NotifyProvisionChangeInfo* pInfo,
		CString& xmlStr);
	static eLTE_RET SetXmlStringEventNotifyP2pcallStatus(const NotifyP2pcallStatusInfo* pInfo,
		CString& xmlStr);
	static eLTE_RET SetXmlStringEventNotifyGroupStatus(const NotifyGroupStatusInfo* pInfo,
		CString& xmlStr);

	// PlayerEvent事件XML出参
public:
	static eLTE_RET SetXmlStringPlayerEvent(int iEventId, const PlayerEventParamInfo* pInfo,
		CString& xmlStr);

private:
	XMLProcess(void);
	~XMLProcess(void);
};

#endif
