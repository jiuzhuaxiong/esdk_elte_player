#pragma once

#include "ConfigMgr.h"
#include "AppContextMgr.h"
#include "OperationMgr.h"
#include "ProvisionMgr.h"
#include "MediaPlayer.h"
#include "VideoPane.h"

// eLTE_PlayerCtrl.h : Declaration of the CeLTE_PlayerCtrl ActiveX Control class.


// CeLTE_PlayerCtrl : See eLTE_PlayerCtrl.cpp for implementation.

class CeLTE_PlayerCtrl : public COleControl
{
	DECLARE_DYNCREATE(CeLTE_PlayerCtrl)

// Constructor
public:
	CeLTE_PlayerCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CeLTE_PlayerCtrl();

	//lint -e1768
	DECLARE_OLECREATE_EX(CeLTE_PlayerCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CeLTE_PlayerCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CeLTE_PlayerCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CeLTE_PlayerCtrl)		// Type name and misc status
	//lint -e1768
// Message maps
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMsgExitFullScreen(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnMsgPostEvent(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnMsgPostPlayerEvent(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnMsgStopVideoPlay(WPARAM wparam, LPARAM lparam);

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		eventidELTE_OCX_PlayerEvent = 51L,
		dispidELTE_OCX_SetTitleText = 38L,
		dispidELTE_OCX_NormalScreenDisplay = 37L,
		dispidELTE_OCX_FullScreenDisplay = 36L,
		dispidELTE_OCX_SetVideoWindowPos = 35L,
		dispidELTE_OCX_StopSound = 34L,
		dispidELTE_OCX_PlaySound = 33L,
		dispidELTE_OCX_HideRealPlay = 31L,
		dispidELTE_OCX_Snapshot = 30L,
		dispidELTE_OCX_ShowRealPlay = 29L,
		dispidELTE_OCX_StopRealPlay = 25L,
		dispidELTE_OCX_ReverseRealPlay = 24L,
		dispidELTE_OCX_StartRealPlay = 23L,
		dispidELTE_OCX_GetUserRECFileInfoList = 22L,
		dispidELTE_OCX_SubscribeGroup = 21L,
		dispidELTE_OCX_GetDcInfo = 20L,
		dispidELTE_OCX_GetUserInfo = 19L,
		dispidELTE_OCX_GetGroupInfo = 18L,
		dispidELTE_OCX_GetGroupUsers = 17L,
		dispidELTE_OCX_GetDcUsers = 16L,
		dispidELTE_OCX_GetDcGroups = 15L,
		dispidELTE_OCX_ProvisionManagerExit = 14L,
		dispidELTE_OCX_ProvisionManagerInit = 13L,
		dispidELTE_OCX_TriggerStatusReport = 12L,
		dispidELTE_OCX_Logout = 11L,
		dispidELTE_OCX_Login = 10L,
		dispidELTE_OCX_UnLoad = 8L,
		dispidELTE_OCX_Load = 7L,
		dispidELTE_OCX_ShowToolbar = 6L,
		dispidELTE_OCX_SetLanguage = 5L,
		dispidELTE_OCX_GetVersion = 4L,
		dispidELTE_OCX_UploadLogo = 3L,
		dispidELTE_OCX_SetLogLevel = 2L,
		dispidELTE_OCX_SetLogPath = 1L
	};//lint -e726

	enum {
		eventidELTE_OCX_Event = 50L,
	};//lint -e726

protected:

	/**
	 *������־�ļ�����·��
	 * 
	 *�ú�������������־�ļ�����·��
	 *
	 *@param[in] 	pLogFilePath	��־����·���������ļ���*.log
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	ELTE_OCX_Loadǰ���á���ʹ�þ���·��(������ʹ�����·�������·���Բ���'\'��ͷ)
	 *@par 			��
	**/
	BSTR ELTE_OCX_SetLogPath(LPCTSTR pLogFilePath);

	/**
	 *������־����
	 * 
	 *�ú�������������־����
	 *
	 *@param[in] 	ulLogLevel		��־����
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	ELTE_OCX_Loadǰ���á��ĸ�����0 debug��1 info��2 warn��3 error
	 *@par 			��
	**/
	BSTR ELTE_OCX_SetLogLevel(ULONG ulLogLevel);

	/**
	 *���ñ���ͼƬ
	 * 
	 *�ú����������ñ���ͼƬ
	 *
	 *@param[in] 	pLogoFilePath	ͼƬ·��
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	ELTE_OCX_Loadǰ���á��´�����õ�ͼƬ��ocx����Ŀ¼/Skin���棬��������ΪĬ�ϵı���ͼƬ
	 *@par 			��
	**/
	BSTR ELTE_OCX_UploadLogo(LPCTSTR pLogoFilePath);

	/**
	 *��ȡ�汾
	 * 
	 *�ú������ڻ�ȡ�汾
	 *
	 *@param[in] 	ulVersion		�汾ID��1-��ȡocx����汾�ţ�2-��ȡsdk�汾��(�ݲ�֧��)
	 *@return 		XML��ʽ��ResultCode=0�ɹ�(Version=�汾�ַ���)������ʧ��(Version=���ַ���)�ο�������
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_GetVersion(ULONG ulVersion);

	/**
	 *����OCX����
	 * 
	 *�ú�����������OCX����
	 *
	 *@param[in] 	ulLanguage		����ID��1-���� 2-Ӣ�� 3-��������
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	���ڹ�����������ʾ
	 *@par 			��
	**/
	BSTR ELTE_OCX_SetLanguage(ULONG ulLanguage);

	/**
	 *��ʾ/���ع�����
	 * 
	 *�ú���������ʾ/���ع�����
	 *
	 *@param[in] 	ulToolbar		1-��ʾ��0-����
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_ShowToolbar(LONG ulToolbar);

	/**
	 *����OCX���
	 * 
	 *�ú������ڼ���OCX���
	 *
	 *@param[in] 	ulType			1-���ز�������ҵ��2-ֻ���ز�����
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	ֻ�ܵ���һ��
	 *@par 			��
	**/
	BSTR ELTE_OCX_Load(ULONG ulType);

	/**
	 *�˳�OCX���
	 * 
	 *�ú��������˳�OCX���
	 *
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	ֻ�ܵ���һ��
	 *@par 			��
	**/
	BSTR ELTE_OCX_UnLoad(void);

	/**
	 *��½eLTE���Ȼ�
	 * 
	 *�ú������ڵ�½eLTE���Ȼ�
	 *
	 *@param[in] 	pUserID			����Ա�˺�
	 *@param[in] 	pPWD			����
	 *@param[in] 	pServerIP		������IP
	 *@param[in] 	pLocalIP		����IP
	 *@param[in] 	pServerSIPPort	�������˿�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	ELTE_OCX_Load typeΪ1ʱ����ʹ��eLTE����
	 *@par 			��
	**/
	BSTR ELTE_OCX_Login(LPCTSTR pUserID, LPCTSTR pPWD, LPCTSTR pServerIP, LPCTSTR pLocalIP, LPCTSTR pServerSIPPort);

	/**
	 *�ǳ�eLTE���Ȼ�
	 * 
	 *�ú������ڵǳ�eLTE���Ȼ�
	 *
	 *@param[in] 	pUserID			����Ա�˺�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	ELTE_OCX_Load typeΪ1ʱ����ʹ��eLTE����
	 *@par 			��
	**/
	BSTR ELTE_OCX_Logout(LPCTSTR pUserID);

	/**
	 *����״̬�ϱ�
	 * 
	 *�ú������ڴ���״̬�ϱ�
	 *
	 *@param[in] 	ulEnableStatusReport	1-��ʼ״̬�ϱ���0-�ر�״̬�ϱ�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_TriggerStatusReport(ULONG ulEnableStatusReport);

	/**
	 *���ù����ʼ��
	 * 
	 *�ú����������ù����ʼ��
	 *
	 *@param[in] 	pServerIP		������IP
	 *@param[in] 	pUserID			����Ա�˺�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_ProvisionManagerInit(LPCTSTR pServerIP, LPCTSTR pUserID);

	/**
	 *�˳����ù���
	 * 
	 *�ú��������˳����ù���
	 *
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο�������
	 *@attention	�ȵ���ELTE_OCX_ProvisionManagerInit�ӿ�
	 *@par 			��
	**/
	BSTR ELTE_OCX_ProvisionManagerExit(void);

	/**
	 *��ȡ����̨Ⱥ���б�
	 * 
	 *�ú������ڻ�ȡ����̨Ⱥ���б�
	 *
	 *@param[in] 	pUserID			����Ա�˺�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣�б�XML��ʽ����
	 *@attention	�ȵ���ELTE_OCX_ProvisionManagerInit�ӿ�
	 *@par 			��
	**/
	BSTR ELTE_OCX_GetDcGroups(LPCTSTR pUserID);

	/**
	 *��ȡ����̨�û��б�
	 * 
	 *�ú������ڻ�ȡ����̨�û��б�
	 *
	 *@param[in] 	pUserID			����Ա�˺�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣�б�XML��ʽ����
	 *@attention	�ȵ���ELTE_OCX_ProvisionManagerInit�ӿ�
	 *@par 			��
	**/
	BSTR ELTE_OCX_GetDcUsers(LPCTSTR pUserID);

	/**
	 *��ȡһ��Ⱥ���Ա�б�
	 * 
	 *�ú������ڻ�ȡһ��Ⱥ���Ա�б�
	 *
	 *@param[in] 	pGroupID		Ⱥ��ID
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣�б�XML��ʽ����
	 *@attention	�ȵ���ELTE_OCX_ProvisionManagerInit�ӿ�
	 *@par 			��
	**/
	BSTR ELTE_OCX_GetGroupUsers(LPCTSTR pGroupID);

	/**
	 *��ȡһ��Ⱥ����ϸ��Ϣ
	 * 
	 *�ú������ڻ�ȡһ��Ⱥ����ϸ��Ϣ
	 *
	 *@param[in] 	pGroupID		Ⱥ��ID
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣��ϸ��Ϣ��XML��ʽ����
	 *@attention	�ȵ���ELTE_OCX_ProvisionManagerInit�ӿ�
	 *@par 			��
	**/
	BSTR ELTE_OCX_GetGroupInfo(LPCTSTR pGroupID);

	/**
	 *��ȡһ���û���ϸ��Ϣ
	 * 
	 *�ú������ڻ�ȡһ���û���ϸ��Ϣ
	 *
	 *@param[in] 	pUserID			�û��˺�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣��ϸ��Ϣ��XML��ʽ����
	 *@attention	�ȵ���ELTE_OCX_ProvisionManagerInit�ӿ�
	 *@par 			��
	**/
	BSTR ELTE_OCX_GetUserInfo(LPCTSTR pUserID);

	/**
	 *��ȡһ������̨��ϸ��Ϣ
	 * 
	 *�ú������ڻ�ȡһ������̨��ϸ��Ϣ
	 *
	 *@param[in] 	pUserID			����̨�˺�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣��ϸ��Ϣ��XML��ʽ����
	 *@attention	�ȵ���ELTE_OCX_ProvisionManagerInit�ӿ�
	 *@par 			��
	**/
	BSTR ELTE_OCX_GetDcInfo(LPCTSTR pUserID);

	/**
	 *����/ȡ������Ⱥ��
	 * 
	 *�ú������ڶ���/ȡ������Ⱥ��
	 *
	 *@param[in] 	pGroupID				Ⱥ��ID
	 *@param[in] 	ulEnableSubscribeGroup	1-���ģ�0-ȡ������
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_SubscribeGroup(LPCTSTR pGroupID, ULONG ulEnableSubscribeGroup);

	/**
	 *��ȡ¼���ļ��б�
	 * 
	 *�ú������ڻ�ȡ¼���ļ��б�
	 *
	 *@param[in] 	pQueryXml		��ѯ��������XML��ʽ����
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣�б���Ϣ��XML��ʽ����
	 *@attention	�ȵ���ELTE_OCX_ProvisionManagerInit�ӿ�
	 *@par 			��
	**/
	BSTR ELTE_OCX_GetUserRECFileInfoList(LPCTSTR pQueryXml);

	/**
	 *������Ƶ�ش�
	 * 
	 *�ú������ڿ�����Ƶ�ش�
	 *
	 *@param[in] 	pResourceID		��ԴID
	 *@param[in] 	pVideoParam		ý���������XML��ʽ����
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	����Ƶ�ص��¼��л�ȡ����Ƶ�˿���Ϣ��Ȼ��ʹ��ELTE_OCX_ShowRealPlay��ʾ��Ƶ��ELTE_OCX_PlaySound���Ű���
	 *@par 			��
	**/
	BSTR ELTE_OCX_StartRealPlay(LPCTSTR pResourceID, LPCTSTR pVideoParam);

	/**
	 *�л�ǰ��������ͷ
	 * 
	 *�ú��������л�ǰ��������ͷ
	 *
	 *@param[in] 	pResourceID		��ԴID
	 *@param[in] 	pVideoParam		ý���������XML��ʽ����
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	����Ƶ�ص��¼��л�ȡ����Ƶ�˿���Ϣ��Ȼ��ʹ��ELTE_OCX_ShowRealPlay��ʾ��Ƶ��ELTE_OCX_PlaySound���Ű���
	 *@par 			��
	**/
	BSTR ELTE_OCX_ReverseRealPlay(LPCTSTR pResourceID, LPCTSTR pVideoParam);

	/**
	 *ֹͣ����ʵʱ��Ƶ
	 * 
	 *�ú�������ֹͣ����ʵʱ��Ƶ
	 *
	 *@param[in] 	pResourceID		��ԴID
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_StopRealPlay(LPCTSTR pResourceID);

	/**
	 *��������ʼ������Ƶ
	 * 
	 *�ú������ڲ�������ʼ������Ƶ
	 *
	 *@param[in] 	pResourceID		��ԴID
	 *@param[in] 	pLocalMediaAddr	������ý���������XML��ʽ����
	 *@param[in] 	pRemoteMediaAddrԶ����ý���������XML��ʽ����
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��ý���������Ƶ�ص��¼��л�ȡ
	 *@par 			��
	**/
	BSTR ELTE_OCX_ShowRealPlay(LPCTSTR pResourceID, LPCTSTR pLocalMediaAddr, LPCTSTR pRemoteMediaAddr);

	/**
	 *ץ����Ƶ����
	 * 
	 *�ú�������ץ����Ƶ����
	 *
	 *@param[in] 	pResourceID		��ԴID
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��ͼ�����ʽ��·����eLTE_Player.ini�����ļ��С��ļ�����pResourceID_ʵʱʱ���ַ�����
	 *@par 			��
	**/
	BSTR ELTE_OCX_Snapshot(LPCTSTR pResourceID);

	/**
	 *������ֹͣ������Ƶ
	 * 
	 *�ú������ڲ�����ֹͣ������Ƶ
	 *
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_HideRealPlay(void);

	/**
	 *��������ʼ������Ƶ
	 * 
	 *�ú������ڲ�������ʼ������Ƶ
	 *
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	ELTE_OCX_StartRealPlayý�������Ҫ���á��а�����
	 *@par 			��
	**/
	BSTR ELTE_OCX_PlaySound(void);

	/**
	 *������ֹͣ������Ƶ
	 * 
	 *�ú������ڲ�����ֹͣ������Ƶ
	 *
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_StopSound(void);

	/**
	 *���ò�������������
	 * 
	 *�ú����������ò�������������
	 *
	 *@param[in] 	ulLeft			������
	 *@param[in] 	ulTop			������
	 *@param[in] 	ulWidth			���
	 *@param[in] 	ulHeight		�߶�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_SetVideoWindowPos(ULONG ulLeft, ULONG ulTop, ULONG ulWidth, ULONG ulHeight);

	/**
	 *ȫ��Ļ��ʾ���Ż���
	 * 
	 *�ú�������ȫ��Ļ��ʾ���Ż���
	 *
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_FullScreenDisplay(void);

	/**
	 *�˳�ȫ��Ļ����
	 * 
	 *�ú��������˳�ȫ��Ļ����
	 *
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_NormalScreenDisplay(void);

	/**
	 *���ò��Ŵ�������ı�
	 * 
	 *�ú����������ò��Ŵ����ı�
	 *
	 *@param[in] 	pTitleText		�����ı�
	 *@return 		XML��ʽ��ResultCode=0�ɹ�������ʧ�ܲο������롣
	 *@attention	��
	 *@par 			��
	**/
	BSTR ELTE_OCX_SetTitleText(LPCTSTR pTitleText);

	/**
	 *OCX��Ϣ�¼�
	 * 
	 *�ú�������OCX��Ϣ�¼�
	 *
	 *@param[in] 	ulEventType		�¼����͡��ο�eLTE_EVENT_ID_Eö�ٶ���
	 *@param[in] 	pEventDataXml	�¼����ݡ���XML��ʽ����
	 *@attention	��
	 *@par 			��
	**/
	void ELTE_OCX_Event(ULONG ulEventType, LPCTSTR pEventDataXml)
	{
		FireEvent(eventidELTE_OCX_Event, EVENT_PARAM(VTS_UI4 VTS_BSTR), ulEventType, pEventDataXml);//lint !e1773
	}

	/**
	 *OCX��������Ϣ�¼�
	 * 
	 *�ú�������OCX��������Ϣ�¼������Ŵ�����ʾ/���ء�
	 *
	 *@param[in] 	ulEventType		�¼����͡��ο�eLTE_PLAYER_EVENT_ID_Eö�ٶ���
	 *@param[in] 	pEventDataXml	�¼����ݡ���XML��ʽ����
	 *@attention	��
	 *@par 			��
	**/
	void ELTE_OCX_PlayerEvent(ULONG ulEventType, LPCTSTR pEventDataXml)
	{
		FireEvent(eventidELTE_OCX_PlayerEvent, EVENT_PARAM(VTS_UI4 VTS_BSTR), ulEventType, pEventDataXml);
	}
	//lint !e1762

	// �����������ӿ�
public:
	// ץͼ
	int ToolBarSnapshot();
	// �л�ǰ��������ͷ
	int ToolBarReversePlayer();
	// �����رհ���
	int ToolBarPlayAudio(BOOL bEnable);
	// �첽������Ƶ
	static std::map<int, CeLTE_PlayerCtrl*> m_WaitPlayVideoList;

public:
	// ���̹���
	static HHOOK s_KeyboardHook;
	// ���̹��Ӵ�����
	static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
	// ��깳��
	static HHOOK s_MouseHook;
	// ��깳�Ӵ�����
	static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);

	// GDI+
private:
	Gdiplus::GdiplusStartupInput m_GdiplusStartupInput;
	ULONG_PTR m_GdiplusToken;

private:
	// Load OCX����
	ULONG m_ulType;
	// Load OCX��ʶ
	BOOL m_bHaveLoaded;
	// ��½��ʶ
	BOOL m_bIsLogin;
	// �Ƿ񴥷�״̬�ϱ�
	bool m_bEnableStatusReport;

private:
	ConfigMgr m_ConfigMgr;
	MediaPlayer m_MediaPlayer;
	CVideoPane m_VideoPane;

private:
	// �ؼ��б�
	static std::set<CeLTE_PlayerCtrl*> m_eLTE_PlayerList;
};//lint !e1712 !e1773 !e1768
