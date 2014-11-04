#include "StdAfx.h"
#include "XMLProcess.h"
#include "eLTE_Log.h"
#include "eLTE_Tool.h"
#include "eLTE_Xml.h"
#include "mq/provchange_indicator.h"


XMLProcess::XMLProcess(void)
{
}


XMLProcess::~XMLProcess(void)
{
}


// 解析入参Video_UL_parameter
eLTE_RET XMLProcess::XmlParseVideoULParameter(const std::string& xmlStr,	// 入参
		std::string& strVideoFormat, std::string& strCameraType,			// 出参
		std::string& strUserConfirmType, std::string& strMuteType)			// 出参
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<VideoParam>
			<VideoFormat>D1、CIF、QCIF、720P或1080P</VideoFormat>
			<CameraType>“0”表示前置，“1”表示后置。</CameraType>
			<UserConfirmType>“0”表示不需要用户确认，“1”表示需要用户确认。</UserConfirmType>
			<MuteType>“0”表示需要伴音；“1”表示不需要伴音</MuteType>
		</VideoParam>
	</Content>
	************************************************************************/ 
	
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM1(xmlStr);

	CXml xmlParse;
	if (!xmlParse.Parse(xmlStr.c_str()))
	{
		ERROR_LOG() << "parse xml failed.";
		return eLTE_FAILED;
	}
	if (!xmlParse.FindElem("Content"))
	{
		ERROR_LOG() << "FindElem Content failed.";
		return eLTE_FAILED;
	}
	(void)xmlParse.IntoElem();
	if (!xmlParse.FindElem("VideoParam"))
	{
		ERROR_LOG() << "FindElem VideoParam failed.";
		return eLTE_FAILED;
	}
	(void)xmlParse.IntoElem();

	const unsigned int XML_VAR_LENGTH = 16;
	char elemValue[XML_VAR_LENGTH] = {0};
	const char* srcValue;
	unsigned int uiMaxLen = XML_VAR_LENGTH;

	GET_XML_ELEM_VALUE_CHAR(xmlParse, "VideoFormat", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	strVideoFormat = elemValue;

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);	
	GET_XML_ELEM_VALUE_CHAR(xmlParse, "CameraType", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	strCameraType = elemValue;

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);	
	GET_XML_ELEM_VALUE_CHAR(xmlParse, "UserConfirmType", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	strUserConfirmType = elemValue;

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlParse, "MuteType", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	strMuteType = elemValue;

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 解析入参视频播放参数
eLTE_RET XMLProcess::XmlParsePlayVideoParam(const std::string& xmlStrLocal, const std::string& xmlStrRemote,	// 入参
		std::string& strLocalIP, unsigned int& uiLocalVideoPort, unsigned int& uiLocalAudioPort,				// 出参
		std::string& strRemoteIP, unsigned int& uiRemoteVideoPort, unsigned int& uiRemoteAudioPort)				// 出参
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<LocalMediaAddr>
			<LocalIP></LocalIP>
			<VideoPort></VideoPort>
			<AudioPort></AudioPort>
		</LocalMediaAddr>
	</Content>
	<Content>
		<RemoteMediaAddr>
			<RemoteIP></RemoteIP>
			<VideoPort></VideoPort>
			<AudioPort></AudioPort>
		</RemoteMediaAddr>
	</Content>
	************************************************************************/ 
	
	DEBUG_LOG() << "--- ENTRY";
	INFO_PARAM2(xmlStrLocal, xmlStrRemote);

	// 解析本地视频参数
	CXml xmlLocal;
	if (!xmlLocal.Parse(xmlStrLocal.c_str()))
	{
		ERROR_LOG() << "parse xmlStrLocal failed.";
		return eLTE_FAILED;
	}
	if (!xmlLocal.FindElem("Content"))
	{
		ERROR_LOG() << "FindElem Content failed.";
		return eLTE_FAILED;
	}
	(void)xmlLocal.IntoElem();
	if (!xmlLocal.FindElem("LocalMediaAddr"))
	{
		ERROR_LOG() << "FindElem LocalMediaAddr failed.";
		return eLTE_FAILED;
	}
	(void)xmlLocal.IntoElem();

	const unsigned int XML_VAR_LENGTH = 16;
	char elemValue[XML_VAR_LENGTH] = {0};
	const char* srcValue;
	unsigned int uiMaxLen = XML_VAR_LENGTH;

	GET_XML_ELEM_VALUE_CHAR(xmlLocal, "LocalIP", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	strLocalIP = elemValue;

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlLocal, "VideoPort", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	uiLocalVideoPort = eLTE_Tool::String2UInt(elemValue);

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlLocal, "AudioPort", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	uiLocalAudioPort = eLTE_Tool::String2UInt(elemValue);

	// 解析远端视频参数
	CXml xmlRemote;
	if (!xmlRemote.Parse(xmlStrRemote.c_str()))
	{
		ERROR_LOG() << "parse xmlStrRemote failed.";
		return eLTE_FAILED;
	}
	if (!xmlRemote.FindElem("Content"))
	{
		ERROR_LOG() << "FindElem Content failed.";
		return eLTE_FAILED;
	}
	(void)xmlRemote.IntoElem();
	if (!xmlRemote.FindElem("RemoteMediaAddr"))
	{
		ERROR_LOG() << "FindElem RemoteMediaAddr failed.";
		return eLTE_FAILED;
	}
	(void)xmlRemote.IntoElem();

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlRemote, "RemoteIP", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	strRemoteIP = elemValue;

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlRemote, "VideoPort", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	uiRemoteVideoPort = eLTE_Tool::String2UInt(elemValue);

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlRemote, "AudioPort", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	uiRemoteAudioPort = eLTE_Tool::String2UInt(elemValue);

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 解析查询录音文件信息的查询条件
eLTE_RET XMLProcess::XmlParseRECQueryInfo(const std::string& xmlStr,
	RECQueryInfo& queryInfo)
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<RECQueryInfo>
			<CallType></CallType>
			<Caller></Caller>
			<Callee></Callee>
			<ResourceID></ResourceID>
			<StartSec></StartSec>
			<EndSec></EndSec>
		</RECQueryInfo>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	CXml xmlParse;
	if (!xmlParse.Parse(xmlStr.c_str()))
	{
		ERROR_LOG() << "parse xml failed.";
		return eLTE_FAILED;
	}
	if (!xmlParse.FindElem("Content"))
	{
		ERROR_LOG() << "FindElem Content failed.";
		return eLTE_FAILED;
	}
	(void)xmlParse.IntoElem();
	if (!xmlParse.FindElem("RECQueryInfo"))
	{
		ERROR_LOG() << "FindElem RECQueryInfo failed.";
		return eLTE_FAILED;
	}
	(void)xmlParse.IntoElem();

	const unsigned int XML_VAR_LENGTH = 16;
	char elemValue[XML_VAR_LENGTH] = {0};
	const char* srcValue;
	unsigned int uiMaxLen = XML_VAR_LENGTH;

	GET_XML_ELEM_VALUE_CHAR(xmlParse, "CallType", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	int iType = eLTE_Tool::String2Int(elemValue);
	switch (iType)
	{
	case ENUM_REC_UNKNOW_CALL_TYPE:
		{
			queryInfo.call_type = ENUM_REC_UNKNOW_CALL_TYPE;
		}
		break;
	case ENUM_REC_P2P_AUDIO:
		{
			queryInfo.call_type = ENUM_REC_P2P_AUDIO;
		}
		break;
	case ENUM_REC_P2P_VIDEO:
		{
			queryInfo.call_type = ENUM_REC_P2P_VIDEO;
		}
		break;
	case ENUM_REC_VIDEO_UPLOAD:
		{
			queryInfo.call_type = ENUM_REC_VIDEO_UPLOAD;
		}
		break;
	case ENUM_REC_PTT:
		{
			queryInfo.call_type = ENUM_REC_PTT;
		}
		break;
	default:
		{
			ERROR_LOG() << "Invalid call_type. (" << queryInfo.call_type << ")";
			return eLTE_FAILED;
		}
	}

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);	
	GET_XML_ELEM_VALUE_CHAR(xmlParse, "Caller", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	queryInfo.caller = eLTE_Tool::String2Int(elemValue);

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);	
	GET_XML_ELEM_VALUE_CHAR(xmlParse, "Callee", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	queryInfo.callee = eLTE_Tool::String2Int(elemValue);

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlParse, "ResourceID", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	queryInfo.resourceid = eLTE_Tool::String2Int(elemValue);

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlParse, "StartSec", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	queryInfo.start_sec = elemValue;

	uiMaxLen = XML_VAR_LENGTH;
	memset(elemValue, 0, sizeof(char)*XML_VAR_LENGTH);
	GET_XML_ELEM_VALUE_CHAR(xmlParse, "EndSec", srcValue, elemValue, uiMaxLen, eLTE_FAILED);
	queryInfo.end_sec = elemValue;

	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 设置DcGroups XML出参
eLTE_RET XMLProcess::SetXmlStringDcGroups(const DcGroups* pDcGroups,			// 入参
	CString& xmlStr)															// 出参
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ResultCode></ResultCode>
		<GroupInfoList>
			<GroupInfo>
				<GroupID></GroupID>
				<GroupCategory></GroupCategory>
				<GroupPriority></GroupPriority>
				<GroupName></GroupName>
			</GroupInfo>
		</GroupInfoList>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pDcGroups)
	{
		ERROR_LOG() << "pDcGroups is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ResultCode");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(eLTE_SUCCESS).c_str());
	(void)xml.AddElem("GroupInfoList");

	DcGroups::const_iterator it_b = pDcGroups->begin();
	DcGroups::const_iterator it_e = pDcGroups->end();
	for (DcGroups::const_iterator itor = it_b; it_e != itor; itor++)
	{
		if (it_b == itor)
		{
			(void)xml.AddChildElem("GroupInfo");
			(void)xml.IntoElem();
		}
		else
		{
			(void)xml.AddElem("GroupInfo");
		}

		GroupInfo* const &pGroupInfo = *itor;

		(void)xml.AddChildElem("GroupID");
		(void)xml.IntoElem();
		(void)xml.SetElemValue(eLTE_Tool::Int2String(pGroupInfo->grpid).c_str());
		(void)xml.AddElem("GroupCategory");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(pGroupInfo->grpcategory).c_str());
		(void)xml.AddElem("GroupPriority");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(pGroupInfo->grppriority).c_str());
		(void)xml.AddElem("GroupName");
		(void)xml.SetElemValue(eLTE_Tool::UTF8ToANSI(pGroupInfo->grpname.c_str()).c_str());

		xml.OutOfElem();
	}
	xml.OutOfElem();
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 设置DcUsers XML出参
eLTE_RET XMLProcess::SetXmlStringDcUsers(const DcUsers* pDcUsers,				// 入参
	CString& xmlStr)															// 出参
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ResultCode></ResultCode>
		<UserInfoList>
			<UserInfo>
				<UserID></UserID>
				<UserCategory></UserCategory>
				<UserPriority></UserPriority>
				<UserName></UserName>
			</UserInfo>
		</UserInfoList>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pDcUsers)
	{
		ERROR_LOG() << "pDcUsers is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ResultCode");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(eLTE_SUCCESS).c_str());
	(void)xml.AddElem("UserInfoList");

	DcUsers::const_iterator it_b = pDcUsers->begin();
	DcUsers::const_iterator it_e = pDcUsers->end();
	for (DcUsers::const_iterator itor = it_b; it_e != itor; itor++)
	{
		if (it_b == itor)
		{
			(void)xml.AddChildElem("UserInfo");
			(void)xml.IntoElem();
		}
		else
		{
			(void)xml.AddElem("UserInfo");
		}

		UserInfo* const &pUserInfo = *itor;

		(void)xml.AddChildElem("UserID");
		(void)xml.IntoElem();
		(void)xml.SetElemValue(eLTE_Tool::Int2String(pUserInfo->userid).c_str());
		(void)xml.AddElem("UserCategory");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(pUserInfo->usercategory).c_str());
		(void)xml.AddElem("UserPriority");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(pUserInfo->userpriority).c_str());
		(void)xml.AddElem("UserName");
		(void)xml.SetElemValue(eLTE_Tool::UTF8ToANSI(pUserInfo->username.c_str()).c_str());

		xml.OutOfElem();
	}
	xml.OutOfElem();
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 设置GrpUserList XML出参
eLTE_RET XMLProcess::SetXmlStringGrpUserList(const GrpUserList* pGrpUserList,	// 入参
	CString& xmlStr)															// 出参
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ResultCode></ResultCode>
		<GroupUserInfoList>
			<GroupUserInfo>
				<UserID></UserID>
				<GroupID></GroupID>
				<UserPriorityInGroup></UserPriorityInGroup>
				<MemberType></MemberType>
			</GroupUserInfo>
		</GroupUserInfoList>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pGrpUserList)
	{
		ERROR_LOG() << "pGrpUserList is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ResultCode");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(eLTE_SUCCESS).c_str());
	(void)xml.AddElem("GroupUserInfoList");

	GrpUserList::const_iterator it_b = pGrpUserList->begin();
	GrpUserList::const_iterator it_e = pGrpUserList->end();
	for (GrpUserList::const_iterator itor = it_b; it_e != itor; itor++)
	{
		if (it_b == itor)
		{
			(void)xml.AddChildElem("GroupUserInfo");
			(void)xml.IntoElem();
		}
		else
		{
			(void)xml.AddElem("GroupUserInfo");
		}

		GrpUserInfo* const &grpUserInfo = *itor;

		(void)xml.AddChildElem("UserID");
		(void)xml.IntoElem();
		(void)xml.SetElemValue(eLTE_Tool::Int2String(grpUserInfo->userid).c_str());
		(void)xml.AddElem("GroupID");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(grpUserInfo->grpid).c_str());
		(void)xml.AddElem("UserPriorityInGroup");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(grpUserInfo->userpriorityInGrp).c_str());
		(void)xml.AddElem("MemberType");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(grpUserInfo->memberType).c_str());

		xml.OutOfElem();
	}
	xml.OutOfElem();
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 设置GroupInfo XML出参
eLTE_RET XMLProcess::SetXmlStringGroupInfo(const GroupInfo* pGroupInfo,			// 入参
	CString& xmlStr)															// 出参
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ResultCode></ResultCode>
		<GroupInfo>
			<GroupID></GroupID>
			<GroupCategory></GroupCategory>
			<GroupPriority></GroupPriority>
			<GroupName></GroupName>
		</GroupInfo>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pGroupInfo)
	{
		ERROR_LOG() << "pGroupInfo is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ResultCode");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(eLTE_SUCCESS).c_str());
	(void)xml.AddElem("GroupInfo");
	(void)xml.AddChildElem("GroupID");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pGroupInfo->grpid).c_str());
	(void)xml.AddElem("GroupCategory");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pGroupInfo->grpcategory).c_str());
	(void)xml.AddElem("GroupPriority");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pGroupInfo->grppriority).c_str());
	(void)xml.AddElem("GroupName");
	(void)xml.SetElemValue(eLTE_Tool::UTF8ToANSI(pGroupInfo->grpname.c_str()).c_str());
	xml.OutOfElem();
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 设置UserInfo XML出参
eLTE_RET XMLProcess::SetXmlStringUserInfo(const UserInfo* pUserInfo,			// 入参
	CString& xmlStr)															// 出参
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ResultCode></ResultCode>
		<UserInfo>
			<UserID></UserID>
			<UserCategory></UserCategory>
			<UserPriority></UserPriority>
			<UserName></UserName>
		</UserInfo>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pUserInfo)
	{
		ERROR_LOG() << "pUserInfo is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ResultCode");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(eLTE_SUCCESS).c_str());
	(void)xml.AddElem("UserInfo");
	(void)xml.AddChildElem("UserID");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pUserInfo->userid).c_str());
	(void)xml.AddElem("UserCategory");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pUserInfo->usercategory).c_str());
	(void)xml.AddElem("UserPriority");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pUserInfo->userpriority).c_str());
	(void)xml.AddElem("UserName");
	(void)xml.SetElemValue(eLTE_Tool::UTF8ToANSI(pUserInfo->username.c_str()).c_str());
	xml.OutOfElem();
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 设置DcProperty XML出参
eLTE_RET XMLProcess::SetXmlStringDcProperty(const DcProperty* pDcProperty,		// 入参
	CString& xmlStr)															// 出参
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ResultCode></ResultCode>
		<DcInfo>
			<DcID></DcID>
			<Priviledge></Priviledge>
			<Role></Role>
			<Alias></Alias>
		</DcInfo>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pDcProperty)
	{
		ERROR_LOG() << "pDcProperty is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ResultCode");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(eLTE_SUCCESS).c_str());
	(void)xml.AddElem("DcInfo");
	(void)xml.AddChildElem("DcID");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pDcProperty->dcid).c_str());
	(void)xml.AddElem("Priviledge");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pDcProperty->priviledge).c_str());
	(void)xml.AddElem("Role");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pDcProperty->role).c_str());
	(void)xml.AddElem("Alias");
	(void)xml.SetElemValue(eLTE_Tool::UTF8ToANSI(pDcProperty->Alias.c_str()).c_str());
	xml.OutOfElem();
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

// 设置UserRecFileInfoList XML出参
eLTE_RET XMLProcess::SetXmlStringRecFileInfoList(const UserRecFileInfoList* pInfoList,
	CString& xmlStr)	
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ResultCode></ResultCode>
		<RECFileInfoList>
			<RECFileInfo>
				<CallType></CallType>
				<Caller></Caller>
				<Callee></Callee>
				<ResourceID></ResourceID>
				<StartSec></StartSec>
				<EndSec></EndSec>
				<UrlFTP></UrlFTP>
				<UrlRTSP></UrlRTSP>
			</RECFileInfo>
		<RECFileInfoList>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pInfoList)
	{
		ERROR_LOG() << "pInfoList is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ResultCode");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(eLTE_SUCCESS).c_str());
	(void)xml.AddElem("RECFileInfoList");

	UserRecFileInfoList::const_iterator it_b = pInfoList->begin();
	UserRecFileInfoList::const_iterator it_e = pInfoList->end();
	for (UserRecFileInfoList::const_iterator itor = it_b; it_e != itor; itor++)
	{
		if (it_b == itor)
		{
			(void)xml.AddChildElem("RECFileInfo");
			(void)xml.IntoElem();
		}
		else
		{
			(void)xml.AddElem("RECFileInfo");
		}

		UserRecFileInfo* const &recFileInfo = *itor;

		(void)xml.AddChildElem("CallType");
		(void)xml.IntoElem();
		(void)xml.SetElemValue(eLTE_Tool::Int2String(recFileInfo->call_type).c_str());
		(void)xml.AddElem("Caller");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(recFileInfo->caller).c_str());
		(void)xml.AddElem("Callee");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(recFileInfo->callee).c_str());
		(void)xml.AddElem("ResourceID");
		(void)xml.SetElemValue(eLTE_Tool::Int2String(recFileInfo->resourceid).c_str());
		(void)xml.AddElem("StartSec");
		(void)xml.SetElemValue(recFileInfo->start_sec.c_str());
		(void)xml.AddElem("EndSec");
		(void)xml.SetElemValue(recFileInfo->end_sec.c_str());
		(void)xml.AddElem("UrlFTP");
		(void)xml.SetElemValue(recFileInfo->urlFTP.c_str());
		(void)xml.AddElem("UrlRTSP");
		(void)xml.SetElemValue(recFileInfo->urlRTSP.c_str());

		xml.OutOfElem();
	}
	xml.OutOfElem();
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

eLTE_RET XMLProcess::SetXmlStringEventNotifyUserStatus(const NotifyUserStatusInfo* pInfo,
	CString& xmlStr)
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<UserID></UserID>
		<StatusType>USERSTATUS</StatusType>
		<StatusValue></StatusValue>
		<PeerID></PeerID>
		<Direction></Direction>
		<CallType></CallType>
	</Content>
	************************************************************************/
	
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pInfo)
	{
		ERROR_LOG() << "pInfo is null.";
		return eLTE_FAILED;
	}
	
	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("UserID");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iUserID).c_str());
	(void)xml.AddElem("StatusType");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iStatusType).c_str());
	(void)xml.AddElem("StatusValue");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iStatusValue).c_str());
	(void)xml.AddElem("PeerID");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iPeerID).c_str());
	(void)xml.AddElem("Direction");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iDirection).c_str());
	(void)xml.AddElem("CallType");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iCallType).c_str());
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

eLTE_RET XMLProcess::SetXmlStringEventNotifyP2pvideocallStatus(const NotifyP2pvideocallStatusInfo* pInfo,
	CString& xmlStr)
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<CallStatus></CallStatus>
		<LocalAudioPort></LocalAudioPort>
		<LocalVideoPort></LocalVideoPort>
		<RemoteAudioPort></RemoteAudioPort>
		<RemoteVideoPort></RemoteVideoPort>
		<RemoteIp></RemoteIp>
		<Callee></Callee>
		<Caller></Caller>
		<SoundMute></SoundMute>
		<Channel></Channel>
		<UserConfirm></UserConfirm>
		<Camera></Camera>
		<SoundPtype></SoundPtype>
		<VideoFormatType></VideoFormatType>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pInfo)
	{
		ERROR_LOG() << "pInfo is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("CallStatus");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iCallStatus).c_str());
	(void)xml.AddElem("LocalAudioPort");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iLocalAudioPort).c_str());
	(void)xml.AddElem("LocalVideoPort");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iLocalVideoPort).c_str());
	(void)xml.AddElem("RemoteAudioPort");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iRemoteAudioPort).c_str());
	(void)xml.AddElem("RemoteVideoPort");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iRemoteVideoPort).c_str());
	(void)xml.AddElem("RemoteIp");
	(void)xml.SetElemValue(pInfo->strRemoteIp.c_str());
	(void)xml.AddElem("Callee");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iCallee).c_str());
	(void)xml.AddElem("Caller");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iCaller).c_str());
	(void)xml.AddElem("SoundMute");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iSoundMute).c_str());
	(void)xml.AddElem("Channel");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iChannel).c_str());
	(void)xml.AddElem("UserConfirm");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iUserConfirm).c_str());
	(void)xml.AddElem("Camera");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iCamera).c_str());
	(void)xml.AddElem("SoundPtype");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iSoundPtype).c_str());
	(void)xml.AddElem("VideoFormatType");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iVideoFormatType).c_str());
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

eLTE_RET XMLProcess::SetXmlStringEventNotifyResourceStatus(const NotifyResourceStatusInfo* pInfo,
	CString& xmlStr)
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ResourceID></ResourceID>
		<StatusType></StatusType>
		<StatusValue></StatusValue>
		<AttachingGroup></AttachingGroup>
	</Content>
	************************************************************************/
	
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pInfo)
	{
		ERROR_LOG() << "pInfo is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ResourceID");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iResourceID).c_str());
	(void)xml.AddElem("StatusType");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iStatusType).c_str());
	(void)xml.AddElem("StatusValue");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iStatusValue).c_str());
	(void)xml.AddElem("AttachingGroup");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iAttachingGroup).c_str());
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

eLTE_RET XMLProcess::SetXmlStringEventNotifyProvisionChange(const NotifyProvisionChangeInfo* pInfo,
	CString& xmlStr)
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<ChangeType></ChangeType>
		<ChangeMO></ChangeMO>
		<xxxInfo>
		....
		</xxxInfo>
	</Content>
	************************************************************************/
	
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pInfo)
	{
		ERROR_LOG() << "pInfo is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("ChangeType");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iChangeType).c_str());
	(void)xml.AddElem("ChangeMO");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iChangeMO).c_str());

	INFO_PARAM1(pInfo->iChangeMO);
	switch (pInfo->iChangeMO)
	{
	case MO_PTTUser:
		{
			MO_PTTUser_Info* pIf = (MO_PTTUser_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("PTTUserInfo");
			(void)xml.AddChildElem("UserID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserID).c_str());
			(void)xml.AddElem("UserCategory");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserCategory).c_str());
			(void)xml.AddElem("UserPriority");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserPriority).c_str());
			(void)xml.AddElem("UserName");
			(void)xml.SetElemValue(pIf->strUserName.c_str());
			(void)xml.AddElem("VpnID");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iVpnID).c_str());
			(void)xml.AddElem("VpnOut");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iVpnOut).c_str());
			(void)xml.AddElem("VpnIn");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iVpnIn).c_str());
			(void)xml.AddElem("Location");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iLocation).c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_FixedUser:
		{
			MO_FixedUser_Info* pIf = (MO_FixedUser_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("FixedUserInfo");
			(void)xml.AddChildElem("UserID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserID).c_str());
			(void)xml.AddElem("UserCategory");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserCategory).c_str());
			(void)xml.AddElem("UserPriority");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserPriority).c_str());
			(void)xml.AddElem("UserName");
			(void)xml.SetElemValue(pIf->strUserName.c_str());
			(void)xml.AddElem("VpnID");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iVpnID).c_str());
			(void)xml.AddElem("VpnOut");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iVpnOut).c_str());
			(void)xml.AddElem("VpnIn");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iVpnIn).c_str());
			(void)xml.AddElem("Location");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iLocation).c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_DCAttribute:
		{
			MO_DCAttribute_Info* pIf = (MO_DCAttribute_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("DCAttributeInfo");
			(void)xml.AddChildElem("DcID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iDcID).c_str());
			(void)xml.AddElem("Priviledge");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iPriviledge).c_str());
			(void)xml.AddElem("Role");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iRole).c_str());
			(void)xml.AddElem("Alias");
			(void)xml.SetElemValue(pIf->strAlias.c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_Group:
		{
			MO_Group_Info* pIf = (MO_Group_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("GroupInfo");
			(void)xml.AddChildElem("GroupID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iGroupID).c_str());
			(void)xml.AddElem("GroupCategory");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iGroupCategory).c_str());
			(void)xml.AddElem("GroupPriority");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iGroupPriority).c_str());
			(void)xml.AddElem("GroupName");
			(void)xml.SetElemValue(pIf->strGroupName.c_str());
			(void)xml.AddElem("GroupState");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iGroupState).c_str());
			(void)xml.AddElem("VpnID");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iVpnID).c_str());
			(void)xml.AddElem("SetupDcID");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iSetupDcID).c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_GroupPTTUser:
	case MO_GroupFixedUser:
		{
			MO_GroupUser_Info* pIf = (MO_GroupUser_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("GroupUserInfo");
			(void)xml.AddChildElem("UserID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserID).c_str());
			(void)xml.AddElem("GroupID");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iGroupID).c_str());
			(void)xml.AddElem("UserPriorityInGroup");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserPriorityInGroup).c_str());
			(void)xml.AddElem("MemberType");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iMemberType).c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_RangeList:
		{
			MO_RangeList_Info* pIf = (MO_RangeList_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("RangeListInfo");
			(void)xml.AddChildElem("RangeID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iRangeID).c_str());
			(void)xml.AddElem("RangeCategory");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iRangeCategory).c_str());
			(void)xml.AddElem("From");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iFrom).c_str());
			(void)xml.AddElem("To");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iTo).c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_DCRanges:
		{
			MO_DCRanges_Info* pIf = (MO_DCRanges_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("DCRangesInfo");
			(void)xml.AddChildElem("RangeID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iRangeID).c_str());
			(void)xml.AddElem("DcID");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iDcID).c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_HOTLINECFG:
		{
			MO_HotlineCfg_Info* pIf = (MO_HotlineCfg_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("HotlineCfgInfo");
			(void)xml.AddChildElem("DcID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iDcID).c_str());
			(void)xml.AddElem("HotIndex");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iHotIndex).c_str());
			(void)xml.AddElem("Number");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iNumber).c_str());
			(void)xml.AddElem("Alias");
			(void)xml.SetElemValue(pIf->strAlias.c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_STMSGCFG:
		{
			MO_StMsgCfg_Info* pIf = (MO_StMsgCfg_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("StMsgCfgInfo");
			(void)xml.AddChildElem("ID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iID).c_str());
			(void)xml.AddElem("StMsg");
			(void)xml.SetElemValue(pIf->strStMsg.c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	//case MO_DECUSER:
	//	{
	//		// 没有找到对应类
	//	}
	//	break;
	case MO_GISCFG:
		{
			MO_GisCfg_Info* pIf = (MO_GisCfg_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("GisCfgInfo");
			(void)xml.AddChildElem("UserID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserID).c_str());
			(void)xml.AddElem("ReportSwitch");
			(void)xml.SetElemValue(eLTE_Tool::UInt2String(pIf->uiReportSwitch).c_str());
			(void)xml.AddElem("ReportPeriod");
			(void)xml.SetElemValue(eLTE_Tool::UInt2String(pIf->uiReportPeriod).c_str());
			(void)xml.AddElem("ReportCapability");
			(void)xml.SetElemValue(eLTE_Tool::UInt2String(pIf->uiReportCapability).c_str());
			(void)xml.AddElem("ReportDistance");
			(void)xml.SetElemValue(eLTE_Tool::UInt2String(pIf->uiReportDistance).c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	case MO_GISIPC:
		{
			MO_GisIpc_Info* pIf = (MO_GisIpc_Info*)pInfo->pInfo;
			if (NULL == pIf)
			{
				ERROR_LOG() << "pIf is null.";
				return eLTE_FAILED;
			}

			(void)xml.AddElem("GisIpcInfo");
			(void)xml.AddChildElem("UserID");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pIf->iUserID).c_str());
			(void)xml.AddElem("Latitude");
			(void)xml.SetElemValue(eLTE_Tool::Double2String(pIf->dLatitude).c_str());
			(void)xml.AddElem("Longitude");
			(void)xml.SetElemValue(eLTE_Tool::Double2String(pIf->dLongitude).c_str());
			(void)xml.AddElem("Altitude");
			(void)xml.SetElemValue(eLTE_Tool::Double2String(pIf->dAltitude).c_str());
			(void)xml.AddElem("Address");
			(void)xml.SetElemValue(pIf->strAddress.c_str());
			xml.OutOfElem();

			delete pIf;
		}
		break;
	default:
		{
			// 其他不做事件回调
			// 没有找到对应类
			ERROR_LOG() << "Invalid ChangeMO.";
			return eLTE_FAILED;
		}
	}

	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

eLTE_RET XMLProcess::SetXmlStringEventNotifyP2pcallStatus(const NotifyP2pcallStatusInfo* pInfo,
	CString& xmlStr)
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<P2pcallStatus></P2pcallStatus>
		<Caller></Caller>
		<Callee></Callee>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pInfo)
	{
		ERROR_LOG() << "pInfo is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("P2pcallStatus");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iCallStatus).c_str());
	(void)xml.AddElem("Caller");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iCaller).c_str());
	(void)xml.AddElem("Callee");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iCallee).c_str());
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

eLTE_RET XMLProcess::SetXmlStringEventNotifyGroupStatus(const NotifyGroupStatusInfo* pInfo,
	CString& xmlStr)
{
	/************************************************************************
	--- XML 格式 ---
	<Content>
		<GroupID></GroupID>
		<GroupCallStatus></GroupCallStatus>
		<Speaker></Speaker>
	</Content>
	************************************************************************/

	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pInfo)
	{
		ERROR_LOG() << "pInfo is null.";
		return eLTE_FAILED;
	}

	CXml xml;
	(void)xml.AddElem("Content");
	(void)xml.AddChildElem("GroupID");
	(void)xml.IntoElem();
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iGroupID).c_str());
	(void)xml.AddElem("GroupCallStatus");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iGroupCallStatus).c_str());
	(void)xml.AddElem("Speaker");
	(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iSpeaker).c_str());
	xml.OutOfElem();

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}

eLTE_RET XMLProcess::SetXmlStringPlayerEvent(int iEventId, const PlayerEventParamInfo* pInfo,
	CString& xmlStr)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pInfo)
	{
		ERROR_LOG() << "pInfo is null.";
		return eLTE_FAILED;
	}

	CXml xml;

	switch (iEventId)
	{
	case eLTE_PLAYER_REVERSE:		// OCX 播放器切换镜头
		{
			/************************************************************************
			--- XML 格式 ---
			<Content>
				<VideoFormat></VideoFormat>
				<CameraType></CameraType>
				<UserConfirmType></UserConfirmType>
				<MuteType></MuteType>
			</Content>
			************************************************************************/

			(void)xml.AddElem("Content");
			(void)xml.AddChildElem("VideoFormat");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(pInfo->strFmtValue.c_str());
			(void)xml.AddElem("CameraType");
			(void)xml.SetElemValue(pInfo->strCameraType.c_str());
			(void)xml.AddElem("UserConfirmType");
			(void)xml.SetElemValue(pInfo->strUserCfmType.c_str());
			(void)xml.AddElem("MuteType");
			(void)xml.SetElemValue(pInfo->strMuteType.c_str());
			xml.OutOfElem();
		}
		break;
	case eLTE_PLAYER_SNAPSHOT:		// OCX 播放器抓图
		{
			/************************************************************************
			--- XML 格式 ---
			<Content>
				<SnapshotPath></SnapshotPath>
			</Content>
			************************************************************************/

			(void)xml.AddElem("Content");
			(void)xml.AddChildElem("SnapshotPath");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(pInfo->strSnapshotPath.c_str());
			xml.OutOfElem();
		}
		break;
	case eLTE_PLAYER_POSITION:		// OCX 播放器坐标变动
		{
			/************************************************************************
			--- XML 格式 ---
			<Content>
				<Left></Left>
				<Top></Top>
				<Width></Width>
				<Height></Height>
			</Content>
			************************************************************************/

			(void)xml.AddElem("Content");
			(void)xml.AddChildElem("Left");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iLeft).c_str());
			(void)xml.AddElem("Top");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iTop).c_str());
			(void)xml.AddElem("Width");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iWidth).c_str());
			(void)xml.AddElem("Height");
			(void)xml.SetElemValue(eLTE_Tool::Int2String(pInfo->iHeight).c_str());
			xml.OutOfElem();
		}
		break;
	case eLTE_PLAYER_TITLE:			// OCX 播放器窗口标题
		{
			/************************************************************************
			--- XML 格式 ---
			<Content>
				<TitleText></TitleText>
			</Content>
			************************************************************************/

			(void)xml.AddElem("Content");
			(void)xml.AddChildElem("TitleText");
			(void)xml.IntoElem();
			(void)xml.SetElemValue(eLTE_Tool::UnicodeToANSI(pInfo->strTitle.GetString()).c_str());
			xml.OutOfElem();
		}
		break;
	default:
		{
			ERROR_LOG() << "Invalid eventId.";
			return eLTE_FAILED;
		}
		break;
	}

	IVS_UINT32 uiLen = 0;
	xmlStr = eLTE_Tool::ANSIToUnicode(xml.GetXMLStream(uiLen)).c_str();

	//INFO_PARAM1(xmlStr);
	DEBUG_LOG() << "--- LEAVE";
	return eLTE_SUCCESS;
}
