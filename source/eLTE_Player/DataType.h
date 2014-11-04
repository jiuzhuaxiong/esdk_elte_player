/********************************************************************
filename    :    DataType.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    �������Ͷ����ࡣ�����ڲ�ʹ�õ�ö�ٺͽṹ��
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_DATA_TYPE_H__
#define __ELTE_OCX_DATA_TYPE_H__


//////////////////////////////////////////////////////////////////////////
typedef int eLTE_RET;

// eLTE_Player �����붨��
// 213��eSDK��ʶ, 5101��eLTE_Player��ʶ�� 51xx���Ժ�eLTE SDK
typedef enum
{
	eLTE_SUCCESS = 0,				// �ɹ�
	eLTE_FAILED = 2135101001,		// ʧ��
	eLTE_INVALID_PARAM,				// �Ƿ����
	eLTE_ERROR_LOAD_TYPE,			// ocx load���Ͳ�֧��
	eLTE_LOAD_CONFIG_FILE_FAILED	// ���������ļ�ʧ��

} eLTE_RET_CODE_E;

//////////////////////////////////////////////////////////////////////////
// �汾����
typedef enum
{
	eLTE_VERSION_INVALID = 0,		// �Ƿ��汾
	eLTE_VERSION_OCX,				// OCX �汾
	eLTE_VERSION_SDK				// SDK �汾
} eLTE_VERSION_TYPE_E;

//////////////////////////////////////////////////////////////////////////
// ��������
typedef enum
{
	eLTE_LANG_INVALID = 0,			// �Ƿ�����
	eLTE_LANG_zh_CN,				// ����
	eLTE_LANG_en_US,				// Ӣ��
	eLTE_LANG_es_ES					// ��������
} eLTE_LANG_CATEGORY_E;

//////////////////////////////////////////////////////////////////////////
// eLTE_Player ����ģʽ
typedef enum
{
	eLTE_LOAD_INVALID = 0,
	eLTE_LOAD_OPERATE_MGR,			// ����Ҫ���ز��ִ�й������ʱʹ��1
	eLTE_LOAD_MEDIA_PLAYER			// ����Ϊ������ģʽʹ��ʱʹ��2
} eLTE_LOAD_TYPE_E;

//////////////////////////////////////////////////////////////////////////
// ץͼ����
typedef enum
{
	eLTE_SNAPSHOT_INVALID = 0,
	eLTE_SNAPSHOT_JPG,				// JPG ��ʽ
	eLTE_SNAPSHOT_BMP				// BMP ��ʽ
} eLTE_SNAPSHOT_FORMAT_E;

//////////////////////////////////////////////////////////////////////////
// eLTE_Player��ϢID����
#define WM_ELTE_CUSTOM_MSG_BEGIN	(WM_USER+100)
#define WM_ELTE_POST_EVENT			(WM_ELTE_CUSTOM_MSG_BEGIN+1)	// �¼���ϢID
#define WM_ELTE_POST_PLAYER_EVENT	(WM_ELTE_CUSTOM_MSG_BEGIN+2)	// �����������¼���ϢID
#define WM_ELTE_EXIT_FULL_SCREEN	(WM_ELTE_CUSTOM_MSG_BEGIN+3)	// �˳�ȫ����ϢID
#define WM_ELTE_INVALID_PARENTWND	(WM_ELTE_CUSTOM_MSG_BEGIN+4)	// �ػ游����CImageButton��ʹ��
#define WM_ELTE_IMG_BTN_CLICKED		(WM_ELTE_CUSTOM_MSG_BEGIN+5)	// CImageButton Clicked��Ϣ
#define WM_ELTE_VIDEO_EXIT			(WM_ELTE_CUSTOM_MSG_BEGIN+6)	// CVideoPane �ر���Ϣ
#define WM_ELTE_CUSTOM_MSG_END		(WM_ELTE_CUSTOM_MSG_BEGIN+100)

//////////////////////////////////////////////////////////////////////////
// �����������¼�
typedef enum
{
	eLTE_PLAYER_HIDE = 0,					// OCX ��������������
	eLTE_PLAYER_SHOW,						// OCX ������������ʾ
	eLTE_PLAYER_FULLSCREEN,					// OCX ������ȫ��
	eLTE_PLAYER_NORMALSCREEN,				// OCX �������˳�ȫ��
	eLTE_PLAYER_MUTE,						// OCX ����������
	eLTE_PLAYER_UNMUTE,						// OCX ������ȡ������
	eLTE_PLAYER_REVERSE,					// OCX �������л���ͷ(XML����Ϊ��Ƶ����)
	eLTE_PLAYER_SNAPSHOT,					// OCX ������ץͼ(XML����ΪͼƬ����·��)
	eLTE_PLAYER_POSITION,					// OCX ����������䶯(XML����Ϊ����)
	eLTE_PLAYER_TITLE						// OCX ���������ڱ���(XML����Ϊ���ڱ���)
} eLTE_PLAYER_EVENT_ID_E;

typedef struct
{
	// videoparam
	std::string strFmtValue;
	std::string strCameraType;
	std::string strUserCfmType;
	std::string strMuteType;

	// snapshot
	std::string strSnapshotPath;

	// position
	int iLeft;
	int iTop;
	int iWidth;
	int iHeight;

	// title
	CString strTitle;
} PlayerEventParamInfo;

//////////////////////////////////////////////////////////////////////////
// �¼�����
typedef enum
{
	EVENT_NOTIFY_USER_STATUS = 0,			// �豸״̬�仯�¼�֪ͨ
	EVENT_NOTIFY_P2P_VIDEO_CALL_STATUS,		// ��ʼʵ���¼�֪ͨ
	EVENT_NOTIFY_RESOURCE_STATUS,			// Ⱥ���ϵ״̬�仯�¼�֪ͨ
	EVENT_NOTIFY_PROVISION_CHANGE,			// �豸�������ñ��֪ͨ�¼�
	EVENT_NOTIFY_PROVISION_ALLRESYNC,		// �Զ�������������֪ͨ�¼�
	EVENT_NOTIFY_P2P_CALL_STATUS,			// ���״̬�仯�¼�
	EVENT_NOTIFY_GROUP_STATUS				// ���״̬�仯�¼�
} eLTE_EVENT_ID_E;

// �¼��ṹ��
typedef struct  
{
	int iUserID;				// ��ԴID
	int iStatusType;			// ״̬���ͣ��̶�ΪUSERSTATUS
	int iStatusValue;			// ״̬ȡֵ
	int iPeerID;				// �¼�����
	int iDirection;				// ��1����ʾ���У���2����ʾ����
	int iCallType;				// ��Դ����
} NotifyUserStatusInfo;			// �豸״̬�仯�¼�֪ͨ��Ϣ�ṹ��

typedef struct
{
	int iCallStatus;			// �¼�����
	int iLocalAudioPort;		// ��������RTP�˿�
	int iLocalVideoPort;		// ������Ƶ�˿�
	int iRemoteAudioPort;		// Զ������RTP�˿�
	int iRemoteVideoPort;		// Զ����Ƶ�˿�
	std::string strRemoteIp;	// �Զ�IP��ַ
	int iCallee;				// ����
	int iCaller;				// ����
	int iSoundMute;				// ����
	int iChannel;				// ����Channel
	int iUserConfirm;			// �û�ȷ��
	int iCamera;				// ��ԴID
	int iSoundPtype;			//
	int iVideoFormatType;		// ��Ƶ��ʽ
} NotifyP2pvideocallStatusInfo;	// ��ʼʵ���¼�֪ͨ��Ϣ�ṹ

typedef struct  
{
	int iCallStatus;			// �¼�����
	int iCaller;				// ����
	int iCallee;				// ����
} NotifyP2pcallStatusInfo;		// ���״̬�仯�¼�

typedef struct  
{
	int iGroupID;				// ���
	int iGroupCallStatus;		// �¼�����
	int iSpeaker;				// �����ˣ�����Ϊ�գ�
} NotifyGroupStatusInfo;		// ���״̬�仯�¼�

typedef struct  
{
	int iResourceID;			// ��ԴID
	int iStatusType;			// ��Դ״̬����
	int iStatusValue;			// ��Դ״ֵ̬
	int iAttachingGroup;		// �û���ǰ��������
} NotifyResourceStatusInfo;		// Ⱥ���ϵ״̬�仯�¼�֪ͨ��Ϣ�ṹ��

typedef struct
{
	int iChangeType;			// ����
	int iChangeMO;				// ȡֵ
	void* pInfo;				// ����MO_xxx_Info�ṹ��
} NotifyProvisionChangeInfo;	// �豸�������ñ��֪ͨ�¼��ṹ��

// ProvChangeIndicator_PTTUser
typedef struct
{
	int iUserID;
	int iUserCategory;			// ����PTTuser�� Camera, FixedLine, etc
	int iUserPriority;
	std::string strUserName;
	int iVpnID;
	int iVpnOut;
	int iVpnIn;
	int iLocation;
} MO_PTTUser_Info;

// ProvChangeIndicator_FixedUser
typedef MO_PTTUser_Info MO_FixedUser_Info;

// ProvChangeIndicator_DCAttribute
typedef struct
{
	int iDcID;
	int iPriviledge;
	int iRole;					// supervisor, operator
	std::string strAlias;
} MO_DCAttribute_Info;

// ProvChangeIndicator_Group
typedef struct 
{
	int iGroupID;
	int iGroupCategory;			// ȫ���� ���� ��̬�� ��̬�� etc
	int iGroupPriority;
	std::string strGroupName;
	int iGroupState;			// 0=disable, 1=enable
	int iVpnID;
	int iSetupDcID;				// creator, valid if it's dynamic or temp group
} MO_Group_Info;

// ProvChangeIndicator_GrpUserInfo
typedef struct  
{
	int iUserID;				// ����membertype������Ϊ��̬�û����� ID
	int iGroupID;				// ����Ϊ��̬���̬��
	int iUserPriorityInGroup;
	int iMemberType;			// 1=��ͨ�û���Ա�� 0=��̬�����е����Ա
} MO_GroupUser_Info;

// ProvChangeIndicator_RangeList
typedef struct
{
	int iRangeID;
	int iRangeCategory;			// group range, user range,
	int iFrom;
	int iTo;
	std::string strAlias;
} MO_RangeList_Info;

// ProvChangeIndicator_DCRange
typedef struct 
{
	int iRangeID;
	int iDcID;
} MO_DCRanges_Info;

// ProvChangeIndicator_HotlineCfg
typedef struct  
{
	int iDcID;
	int iHotIndex;
	int iNumber;
	std::string strAlias;
} MO_HotlineCfg_Info;

// ProvChangeIndicator_StMsgCfg
typedef struct  
{
	int iID;
	std::string strStMsg;
} MO_StMsgCfg_Info;

	//MO_DECUSER

// ProvChangeIndicator_GisCfg
typedef struct  
{
	int iUserID;
	unsigned int uiReportSwitch;// �ϱ�����, 0=�رգ� 1=����
	unsigned int uiReportPeriod;
	unsigned int uiReportCapability;
	unsigned int uiReportDistance;// ֧��GIS�ն��ϱ�
} MO_GisCfg_Info;

// ProvChangeIndicator_GisIpc
typedef struct
{
	int iUserID;
	double dLatitude;
	double dLongitude;
	double dAltitude;
	std::string strAddress;
} MO_GisIpc_Info;

#endif
