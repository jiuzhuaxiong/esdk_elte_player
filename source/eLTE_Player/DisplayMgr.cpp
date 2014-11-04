#include "StdAfx.h"
#include "DisplayMgr.h"
#include "DataType.h"
#include "AppContextMgr.h"
#include "eLTE_Log.h"
#include "eLTE_Tool.h"

#include "mq/resourcestatus_indicator.h"
#include "mq/p2pvideocallstatus_indicator.h"
#include "mq/sds_message_indicator.h"
#include "mq/provchange_indicator.h"
#include "mq/grpcallstatus_indicator.h"
#include "mq/p2pcallstatus_indicator.h"


DisplayMgr::DisplayMgr(void)
	: m_pCeLTE_PlayerCtrl(NULL)
{
}


DisplayMgr::~DisplayMgr(void)
{
	m_pCeLTE_PlayerCtrl = NULL;
}

//通知组呼的状态变更信息
void DisplayMgr::notifyGroupStatus(GrpDspInfo* pGrpInfo)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pGrpInfo)
	{
		ERROR_LOG() << "pGrpInfo is null.";
		return;
	}

	int iGroupID = pGrpInfo->getGrpId();
	int iGroupCallStatus = pGrpInfo->getSpStatus();
	int iSpeaker = pGrpInfo->getSpeaker();
	INFO_PARAM3(iGroupID, iGroupCallStatus, iSpeaker);

	// 发送事件消息
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		NotifyGroupStatusInfo* pNotifyGroupStatusInfo = new NotifyGroupStatusInfo;
		if (NULL == pNotifyGroupStatusInfo)//lint !e774
		{
			ERROR_LOG() << "pNotifyGroupStatusInfo is null.";
			return;
		}

		pNotifyGroupStatusInfo->iGroupID = iGroupID;
		pNotifyGroupStatusInfo->iGroupCallStatus = iGroupCallStatus;
		pNotifyGroupStatusInfo->iSpeaker = iSpeaker;

		::PostMessage(m_pCeLTE_PlayerCtrl->GetSafeHwnd(), WM_ELTE_POST_EVENT,
			(WPARAM)EVENT_NOTIFY_GROUP_STATUS, (LPARAM)pNotifyGroupStatusInfo);
	}

	DEBUG_LOG() << "--- LEAVE";
}

//通知用户和群组资源的状态变更信息
void DisplayMgr::notifyResourceStatus(ResourceStatusIndicator* pResourceStatus)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pResourceStatus)
	{
		ERROR_LOG() << "pResourceStatus is null.";
		return;
	}

	int iResId = pResourceStatus->getResId();
	int iStatusType = pResourceStatus->getStatusType();
	int iStatusValue = pResourceStatus->getStatusValue();
	int iAttachingGrp = pResourceStatus->getAttachingGrp();
	INFO_PARAM4(iResId, iStatusType, iStatusValue, iAttachingGrp);

	// 发送事件消息
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		NotifyResourceStatusInfo* pNotifyResourceStatusInfo = new NotifyResourceStatusInfo;
		if (NULL == pNotifyResourceStatusInfo)//lint !e774
		{
			ERROR_LOG() << "pNotifyResourceStatusInfo is null.";
			return;
		}
		pNotifyResourceStatusInfo->iResourceID = iResId;
		pNotifyResourceStatusInfo->iStatusType = iStatusType;
		pNotifyResourceStatusInfo->iStatusValue = iStatusValue;
		pNotifyResourceStatusInfo->iAttachingGroup = iAttachingGrp;

		::PostMessage(m_pCeLTE_PlayerCtrl->GetSafeHwnd(), WM_ELTE_POST_EVENT,
			(WPARAM)EVENT_NOTIFY_RESOURCE_STATUS, (LPARAM)pNotifyResourceStatusInfo);
	}

	DEBUG_LOG() << "--- LEAVE";
}

//通知点对点呼叫的状态变更信息
void DisplayMgr::notifyP2pcallStatus(P2pcallStatusIndicator* pCallStatus)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pCallStatus)
	{
		ERROR_LOG() << "pCallStatus is null.";
		return;
	}

	int iCallStatus = pCallStatus->getStatus();
	int iCaller = pCallStatus->getCaller();
	int iCallee = pCallStatus->getCallee();
	INFO_PARAM3(iCallStatus, iCaller, iCallee);

	// 发送事件消息
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		NotifyP2pcallStatusInfo* pNotifyP2pcallStatusInfo = new NotifyP2pcallStatusInfo;
		if (NULL == pNotifyP2pcallStatusInfo)//lint !e774
		{
			ERROR_LOG() << "pNotifyP2pcallStatusInfo is null.";
			return;
		}
		pNotifyP2pcallStatusInfo->iCallStatus = iCallStatus;
		pNotifyP2pcallStatusInfo->iCaller = iCaller;
		pNotifyP2pcallStatusInfo->iCallee = iCallee;

		::PostMessage(m_pCeLTE_PlayerCtrl->GetSafeHwnd(), WM_ELTE_POST_EVENT,
			(WPARAM)EVENT_NOTIFY_P2P_CALL_STATUS, (LPARAM)pNotifyP2pcallStatusInfo);
	}

	DEBUG_LOG() << "--- LEAVE";
}

//通知视频呼叫的状态变更信息（包括视频回传），需要YC实现
void DisplayMgr::notifyP2pvideocallStatus(P2pvideocallStatusIndicator* pCallStatus)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pCallStatus)
	{
		ERROR_LOG() << "pCallStatus is null.";
		return;
	}

	int iCallStatus = pCallStatus->getStatus();
	int iLocalAudioPort = pCallStatus->getlocalaudioport();
	int iLocalVideoPort = pCallStatus->getlocalvideoport();
	int iRemoteAudioPort = pCallStatus->getremoteaudioport();
	int iRemoteVideoPort = pCallStatus->getremotevideoport();
	unsigned long iRemoteIp = pCallStatus->getRemoteIp();
	int iCallee = pCallStatus->getCallee();
	int iCaller = pCallStatus->getCaller();
	int iSoundMute = pCallStatus->getSoundMute();
	int iChannel = pCallStatus->getChannel();
	int iUserConfirm = pCallStatus->getUserCfm();
	int iCamera = pCallStatus->getCamera();
	int iSoundPtype = pCallStatus->getSoundPtype();
	int iVideoFormatType = pCallStatus->getFmt();

	INFO_PARAM3(iCallStatus, iCaller, iCallee);
	INFO_PARAM6(iRemoteIp, iChannel, iLocalAudioPort, iLocalVideoPort, iRemoteAudioPort, iRemoteVideoPort);
	INFO_PARAM5(iSoundMute, iUserConfirm, iCamera, iVideoFormatType, iSoundPtype);

	// 发送事件消息
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		NotifyP2pvideocallStatusInfo* pNotifyP2pvideocallStatusInfo = new NotifyP2pvideocallStatusInfo;
		if (NULL == pNotifyP2pvideocallStatusInfo)//lint !e774
		{
			ERROR_LOG() << "pNotifyP2pvideocallStatusInfo is null.";
			return;
		}
		pNotifyP2pvideocallStatusInfo->iCallStatus = iCallStatus;
		pNotifyP2pvideocallStatusInfo->iLocalAudioPort = iLocalAudioPort;
		pNotifyP2pvideocallStatusInfo->iLocalVideoPort = iLocalVideoPort;
		pNotifyP2pvideocallStatusInfo->iRemoteAudioPort = iRemoteAudioPort;
		pNotifyP2pvideocallStatusInfo->iRemoteVideoPort = iRemoteVideoPort;
		pNotifyP2pvideocallStatusInfo->strRemoteIp = eLTE_Tool::GetIPByUIntValue(iRemoteIp);
		pNotifyP2pvideocallStatusInfo->iCallee = iCallee;
		pNotifyP2pvideocallStatusInfo->iCaller = iCaller;
		pNotifyP2pvideocallStatusInfo->iSoundMute = iSoundMute;
		pNotifyP2pvideocallStatusInfo->iChannel = iChannel;
		pNotifyP2pvideocallStatusInfo->iUserConfirm = iUserConfirm;
		pNotifyP2pvideocallStatusInfo->iCamera = iCamera;
		pNotifyP2pvideocallStatusInfo->iSoundPtype = iSoundPtype;
		pNotifyP2pvideocallStatusInfo->iVideoFormatType = iVideoFormatType;

		::PostMessage(m_pCeLTE_PlayerCtrl->GetSafeHwnd(), WM_ELTE_POST_EVENT,
			(WPARAM)EVENT_NOTIFY_P2P_VIDEO_CALL_STATUS, (LPARAM)pNotifyP2pvideocallStatusInfo);
	}

	DEBUG_LOG() << "--- LEAVE";
}

//通知用户和群组资源的状态变更信息,需要YC实现
void DisplayMgr::notifyUserStatus(ResourceStatusIndicator* pResourceStatus)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pResourceStatus)
	{
		ERROR_LOG() << "pResourceStatus is null.";
		return;
	}

	int iStatusType = pResourceStatus->getStatusType();
	int iStatusValue = pResourceStatus->getStatusValue();
	int iResId = pResourceStatus->getResId();
	INFO_PARAM3(iResId, iStatusType, iStatusValue);
	int iPeerID = 0;
	int iDirection = 0;
	int iCallType = 0;

	if (USERSTATUS == iStatusType)
	{
		UserStatusIndicator* pUserStatus = dynamic_cast<UserStatusIndicator*>(pResourceStatus);
		if (NULL == pUserStatus)
		{
			ERROR_LOG() << "pUserStatus is null.";
			return;
		}
		else
		{
			iPeerID = pUserStatus->getPeerUser();
			iDirection = pUserStatus->getDirection();
			iCallType = pUserStatus->getCallType();
		}
	}
	
	// 发送事件消息
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		NotifyUserStatusInfo* pNotifyUserStatusInfo = new NotifyUserStatusInfo;
		if (NULL == pNotifyUserStatusInfo)//lint !e774
		{
			ERROR_LOG() << "pNotifyUserStatusInfo is null.";
			return;
		}
		pNotifyUserStatusInfo->iUserID = iResId;
		pNotifyUserStatusInfo->iStatusType = iStatusType;
		pNotifyUserStatusInfo->iStatusValue = iStatusValue;
		pNotifyUserStatusInfo->iPeerID = iPeerID;
		pNotifyUserStatusInfo->iDirection = iDirection;
		pNotifyUserStatusInfo->iCallType = iCallType;

		::PostMessage(m_pCeLTE_PlayerCtrl->GetSafeHwnd(), WM_ELTE_POST_EVENT,
			(WPARAM)EVENT_NOTIFY_USER_STATUS, (LPARAM)pNotifyUserStatusInfo);
	}

	DEBUG_LOG() << "--- LEAVE";
}

//通知用户状态短消息的服务接收实现
void DisplayMgr::notifyUserSdsStatus(SdsMessageIndicator* )
{

}

void DisplayMgr::notifyModuleStatus(DCModuleStatusIndicator* )
{

}

//短数据信息上报给GUI
void DisplayMgr::notifySMS(SdsMessageIndicator* )
{

}

//通知配置对象的变更信息， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
void DisplayMgr::notifyProvisionChange(ProvChangeIndicator* pProvChange)
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL == pProvChange)
	{
		ERROR_LOG() << "pProvChange is null.";
		return;
	}

	// 发送事件消息
	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		NotifyProvisionChangeInfo* pNotifyProvisionChangeInfo = new NotifyProvisionChangeInfo;
		if (NULL == pNotifyProvisionChangeInfo)//lint !e774
		{
			ERROR_LOG() << "pNotifyProvisionChangeInfo is null.";
			return;
		}
		pNotifyProvisionChangeInfo->iChangeType = pProvChange->getChangeType();
		pNotifyProvisionChangeInfo->iChangeMO = pProvChange->getChangeMO();
		pNotifyProvisionChangeInfo->pInfo = NULL;

		switch (pNotifyProvisionChangeInfo->iChangeMO)
		{
		case MO_PTTUser:
			{
				ProvChangeIndicator_PTTUser* pPTTUser = dynamic_cast<ProvChangeIndicator_PTTUser*>(pProvChange);
				if (NULL == pPTTUser)
				{
					ERROR_LOG() << "pPTTUser is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}

				MO_PTTUser_Info* pInfo = new MO_PTTUser_Info; //PClint Info:No.774, new 后指针必不为空 
				pInfo->iUserID = pPTTUser->userid;
				pInfo->iUserCategory = pPTTUser->usercategory;
				pInfo->iUserPriority = pPTTUser->userpriority;
				pInfo->strUserName = pPTTUser->username;
				pInfo->iVpnID = pPTTUser->vpnid;
				pInfo->iVpnOut = pPTTUser->vpnout;
				pInfo->iVpnIn = pPTTUser->vpnin;
				pInfo->iLocation = pPTTUser->location;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_FixedUser:
			{
				ProvChangeIndicator_FixedUser* pFixedUser = dynamic_cast<ProvChangeIndicator_FixedUser*>(pProvChange);
				if (NULL == pFixedUser)
				{
					ERROR_LOG() << "pFixedUser is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}

				MO_FixedUser_Info* pInfo = new MO_FixedUser_Info;
				pInfo->iUserID = pFixedUser->userid;
				pInfo->iUserCategory = pFixedUser->usercategory;
				pInfo->iUserPriority = pFixedUser->userpriority;
				pInfo->strUserName = pFixedUser->username;
				pInfo->iVpnID = pFixedUser->vpnid;
				pInfo->iVpnOut = pFixedUser->vpnout;
				pInfo->iVpnIn = pFixedUser->vpnin;
				pInfo->iLocation = pFixedUser->location;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_DCAttribute:
			{
				ProvChangeIndicator_DCAttribute* pDCAttribute = dynamic_cast<ProvChangeIndicator_DCAttribute*>(pProvChange);
				if (NULL == pDCAttribute)
				{
					ERROR_LOG() << "pDCAttribute is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}
				
				MO_DCAttribute_Info* pInfo = new MO_DCAttribute_Info;
				pInfo->iDcID = pDCAttribute->dcid;
				pInfo->iPriviledge = pDCAttribute->priviledge;
				pInfo->iRole = pDCAttribute->role;
				pInfo->strAlias = pDCAttribute->Alias;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_Group:
			{
				ProvChangeIndicator_Group* pGroup = dynamic_cast<ProvChangeIndicator_Group*>(pProvChange);
				if (NULL == pGroup)
				{
					ERROR_LOG() << "pGroup is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}

				MO_Group_Info* pInfo = new MO_Group_Info;
				pInfo->iGroupID = pGroup->grpid;
				pInfo->iGroupCategory = pGroup->grpcategory;
				pInfo->iGroupPriority = pGroup->grppriority;
				pInfo->strGroupName = pGroup->grpname;
				pInfo->iGroupState = pGroup->grpstate;
				pInfo->iVpnID = pGroup->vpnid;
				pInfo->iSetupDcID = pGroup->setupDcId;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_GroupPTTUser:
		case MO_GroupFixedUser:
			{
				ProvChangeIndicator_GrpUserInfo* pGroupUserInfo = dynamic_cast<ProvChangeIndicator_GrpUserInfo*>(pProvChange);
				if (NULL == pGroupUserInfo)
				{
					ERROR_LOG() << "pGroupUserInfo is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}

				MO_GroupUser_Info* pInfo = new MO_GroupUser_Info;
				pInfo->iUserID = pGroupUserInfo->userid;
				pInfo->iGroupID = pGroupUserInfo->grpid;
				pInfo->iUserPriorityInGroup = pGroupUserInfo->userpriorityInGrp;
				pInfo->iMemberType = pGroupUserInfo->memberType;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_RangeList:
			{
				ProvChangeIndicator_RangeList* pRangeList = dynamic_cast<ProvChangeIndicator_RangeList*>(pProvChange);
				if (NULL == pRangeList)
				{
					ERROR_LOG() << "pRangeList is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}
				
				MO_RangeList_Info* pInfo = new MO_RangeList_Info;
				pInfo->iRangeID = pRangeList->rangid;
				pInfo->iRangeCategory = pRangeList->Rangecategory;
				pInfo->iFrom = pRangeList->From;
				pInfo->iTo = pRangeList->To;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_DCRanges:
			{
				ProvChangeIndicator_DCRange* pDCRange = dynamic_cast<ProvChangeIndicator_DCRange*>(pProvChange);
				if (NULL == pDCRange)
				{
					ERROR_LOG() << "pDCRange is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}
			
				MO_DCRanges_Info* pInfo = new MO_DCRanges_Info;
				pInfo->iRangeID = pDCRange->rangid;
				pInfo->iDcID = pDCRange->dcid;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_HOTLINECFG:
			{
				ProvChangeIndicator_HotlineCfg* pHotlineCfg = dynamic_cast<ProvChangeIndicator_HotlineCfg*>(pProvChange);
				if (NULL == pHotlineCfg)
				{
					ERROR_LOG() << "pHotlineCfg is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}

				MO_HotlineCfg_Info* pInfo = new MO_HotlineCfg_Info;
				pInfo->iDcID = pHotlineCfg->DcId;
				pInfo->iHotIndex = pHotlineCfg->HotIndex;
				pInfo->iNumber = pHotlineCfg->Number;
				pInfo->strAlias = pHotlineCfg->Alias;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_STMSGCFG:
			{
				ProvChangeIndicator_StMsgCfg* pStMsgCfg = dynamic_cast<ProvChangeIndicator_StMsgCfg*>(pProvChange);
				if (NULL == pStMsgCfg)
				{
					ERROR_LOG() << "pStMsgCfg is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}
				
				MO_StMsgCfg_Info* pInfo = new MO_StMsgCfg_Info;
				pInfo->iID = pStMsgCfg->id;
				pInfo->strStMsg = pStMsgCfg->stmsg;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_DECUSER:
			{
				// 没有找到对应类
				//ERROR_LOG() << "not found MO_DECUSER.";
				delete pNotifyProvisionChangeInfo;
				return;
			}
			//break;//lint -e527
		case MO_GISCFG:
			{
				ProvChangeIndicator_GisCfg* pGisCfg = dynamic_cast<ProvChangeIndicator_GisCfg*>(pProvChange);
				if (NULL == pGisCfg)
				{
					ERROR_LOG() << "pGisCfg is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}

				MO_GisCfg_Info* pInfo = new MO_GisCfg_Info;
				pInfo->iUserID = pGisCfg->userid;
				pInfo->uiReportSwitch = pGisCfg->reportSwitch;
				pInfo->uiReportPeriod = pGisCfg->reportPeriod;
				pInfo->uiReportCapability = pGisCfg->reportCapability;
				pInfo->uiReportDistance = pGisCfg->reportDistance;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		case MO_GISIPC:
			{
				ProvChangeIndicator_GisIpc* pGisIpc = dynamic_cast<ProvChangeIndicator_GisIpc*>(pProvChange);
				if (NULL == pGisIpc)
				{
					ERROR_LOG() << "pGisIpc is null.";
					delete pNotifyProvisionChangeInfo;
					return;
				}
			
				MO_GisIpc_Info* pInfo = new MO_GisIpc_Info;
				pInfo->iUserID = pGisIpc->userid;
				pInfo->dLatitude = pGisIpc->latitude;
				pInfo->dLongitude = pGisIpc->longitude;
				pInfo->dAltitude = pGisIpc->altitude;
				pInfo->strAddress = pGisIpc->address;

				pNotifyProvisionChangeInfo->pInfo = pInfo;
			}
			break;
		default:
			{
				// 其他不做事件回调
				// 没有找到对应类
				delete pNotifyProvisionChangeInfo;
				return;
			}
		}

		::PostMessage(m_pCeLTE_PlayerCtrl->GetSafeHwnd(), WM_ELTE_POST_EVENT,
			(WPARAM)EVENT_NOTIFY_PROVISION_CHANGE, (LPARAM)pNotifyProvisionChangeInfo);
	}

	DEBUG_LOG() << "--- LEAVE";
}

//通知配置对象的全同步， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
void DisplayMgr::notifyProvisionAllResync(ProvChangeIndicator* )
{
	DEBUG_LOG() << "--- ENTRY";

	if (NULL != m_pCeLTE_PlayerCtrl)
	{
		::PostMessage(m_pCeLTE_PlayerCtrl->GetSafeHwnd(), WM_ELTE_POST_EVENT,
			(WPARAM)EVENT_NOTIFY_PROVISION_ALLRESYNC, 0);
	}

	DEBUG_LOG() << "--- LEAVE";
}

//通知状态对象的全同步， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
void DisplayMgr::notifyStatusAllResync(ResourceStatusIndicator* )
{

}

// 设置eLTE_PlayerCtrl句柄
void DisplayMgr::SetCeLTE_PlayerCtrl(COleControl* pCeLTE_PlayerCtrl)
{
	m_pCeLTE_PlayerCtrl = pCeLTE_PlayerCtrl;
}
