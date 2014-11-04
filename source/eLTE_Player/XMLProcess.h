/********************************************************************
filename    :    XMLProcess.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    XML��ν�����XML���θ�ֵ
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_XML_PROCESS_H__
#define __ELTE_OCX_XML_PROCESS_H__

#include "DataType.h"


// XML����ֵ��ֵ
#define GET_RETURN_CODE_XML(xml, iRet, strResult)								\
	(void)xml.AddElem("Content");												\
	(void)xml.AddChildElem("ResultCode");										\
	(void)xml.IntoElem();														\
	(void)xml.SetElemValue(eLTE_Tool::Int2String(iRet).c_str());				\
	IVS_UINT32 uiLen = 0;														\
	strResult = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

// XML��ȡ�汾
#define GET_VERSION_XML(xml, pVersion, strResult)								\
	(void)xml.AddElem("Content");												\
	(void)xml.AddChildElem("Version");											\
	(void)xml.IntoElem();														\
	(void)xml.SetElemValue(pVersion);											\
	IVS_UINT32 uiLen = 0;														\
	strResult = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

// XML�ڵ����
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

// ���OCX Loadģʽ�Ƿ���ȷ
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
	// �������Video_UL_parameter
	static eLTE_RET XmlParseVideoULParameter(const std::string& xmlStr,			// ���
		std::string& strVideoFormat, std::string& strCameraType,				// ����
		std::string& strUserConfirmType, std::string& strMuteType);				// ����

	// ���������Ƶ���Ų���
	static eLTE_RET XmlParsePlayVideoParam(const std::string& xmlStrLocal, const std::string& xmlStrRemote,	// ���
		std::string& strLocalIP, unsigned int& uiLocalVideoPort, unsigned int& uiLocalAudioPort,			// ����
		std::string& strRemoteIP, unsigned int& uiRemoteVideoPort, unsigned int& uiRemoteAudioPort);		// ����

	// ������ѯ¼���ļ���Ϣ�Ĳ�ѯ����
	static eLTE_RET XmlParseRECQueryInfo(const std::string& xmlStr,
		RECQueryInfo& queryInfo);

public:
	// ����DcGroups XML����
	static eLTE_RET SetXmlStringDcGroups(const DcGroups* pDcGroups,			// ���
		CString& xmlStr);													// ����

	// ����DcUsers XML����
	static eLTE_RET SetXmlStringDcUsers(const DcUsers* pDcUsers,			// ���
		CString& xmlStr);													// ����

	// ����GrpUserList XML����
	static eLTE_RET SetXmlStringGrpUserList(const GrpUserList* pGrpUserList,// ���
		CString& xmlStr);													// ����

	// ����GroupInfo XML����
	static eLTE_RET SetXmlStringGroupInfo(const GroupInfo* pGroupInfo,		// ���
		CString& xmlStr);													// ����

	// ����UserInfo XML����
	static eLTE_RET SetXmlStringUserInfo(const UserInfo* pUserInfo,			// ���
		CString& xmlStr);													// ����

	// ����DcProperty XML����
	static eLTE_RET SetXmlStringDcProperty(const DcProperty* pDcProperty,	// ���
		CString& xmlStr);													// ����

	// ����UserRecFileInfoList XML����
	static eLTE_RET SetXmlStringRecFileInfoList(const UserRecFileInfoList* pInfoList,
		CString& xmlStr);

	// Event�¼�XML����
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

	// PlayerEvent�¼�XML����
public:
	static eLTE_RET SetXmlStringPlayerEvent(int iEventId, const PlayerEventParamInfo* pInfo,
		CString& xmlStr);

private:
	XMLProcess(void);
	~XMLProcess(void);
};

#endif
