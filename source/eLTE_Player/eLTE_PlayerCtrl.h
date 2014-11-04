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
	 *设置日志文件生成路径
	 * 
	 *该函数用于设置日志文件生成路径
	 *
	 *@param[in] 	pLogFilePath	日志生成路径，包括文件名*.log
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	ELTE_OCX_Load前调用。请使用绝对路径(不建议使用相对路径，相对路径以不能'\'开头)
	 *@par 			无
	**/
	BSTR ELTE_OCX_SetLogPath(LPCTSTR pLogFilePath);

	/**
	 *设置日志级别
	 * 
	 *该函数用于设置日志级别
	 *
	 *@param[in] 	ulLogLevel		日志级别
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	ELTE_OCX_Load前调用。四个级别0 debug、1 info、2 warn、3 error
	 *@par 			无
	**/
	BSTR ELTE_OCX_SetLogLevel(ULONG ulLogLevel);

	/**
	 *设置背景图片
	 * 
	 *该函数用于设置背景图片
	 *
	 *@param[in] 	pLogoFilePath	图片路径
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	ELTE_OCX_Load前调用。会拷贝设置的图片到ocx所在目录/Skin下面，并设置其为默认的背景图片
	 *@par 			无
	**/
	BSTR ELTE_OCX_UploadLogo(LPCTSTR pLogoFilePath);

	/**
	 *获取版本
	 * 
	 *该函数用于获取版本
	 *
	 *@param[in] 	ulVersion		版本ID。1-获取ocx插件版本号，2-获取sdk版本号(暂不支持)
	 *@return 		XML格式，ResultCode=0成功(Version=版本字符串)，其他失败(Version=空字符串)参考错误码
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_GetVersion(ULONG ulVersion);

	/**
	 *设置OCX语言
	 * 
	 *该函数用于设置OCX语言
	 *
	 *@param[in] 	ulLanguage		语言ID。1-中文 2-英语 3-西班牙语
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	用于工具栏界面显示
	 *@par 			无
	**/
	BSTR ELTE_OCX_SetLanguage(ULONG ulLanguage);

	/**
	 *显示/隐藏工具栏
	 * 
	 *该函数用于显示/隐藏工具栏
	 *
	 *@param[in] 	ulToolbar		1-显示，0-隐藏
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_ShowToolbar(LONG ulToolbar);

	/**
	 *加载OCX插件
	 * 
	 *该函数用于加载OCX插件
	 *
	 *@param[in] 	ulType			1-加载播放器和业务，2-只加载播放器
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	只能调用一次
	 *@par 			无
	**/
	BSTR ELTE_OCX_Load(ULONG ulType);

	/**
	 *退出OCX插件
	 * 
	 *该函数用于退出OCX插件
	 *
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	只能调用一次
	 *@par 			无
	**/
	BSTR ELTE_OCX_UnLoad(void);

	/**
	 *登陆eLTE调度机
	 * 
	 *该函数用于登陆eLTE调度机
	 *
	 *@param[in] 	pUserID			调度员账号
	 *@param[in] 	pPWD			密码
	 *@param[in] 	pServerIP		服务器IP
	 *@param[in] 	pLocalIP		本地IP
	 *@param[in] 	pServerSIPPort	服务器端口
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	ELTE_OCX_Load type为1时才能使用eLTE功能
	 *@par 			无
	**/
	BSTR ELTE_OCX_Login(LPCTSTR pUserID, LPCTSTR pPWD, LPCTSTR pServerIP, LPCTSTR pLocalIP, LPCTSTR pServerSIPPort);

	/**
	 *登出eLTE调度机
	 * 
	 *该函数用于登出eLTE调度机
	 *
	 *@param[in] 	pUserID			调度员账号
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	ELTE_OCX_Load type为1时才能使用eLTE功能
	 *@par 			无
	**/
	BSTR ELTE_OCX_Logout(LPCTSTR pUserID);

	/**
	 *触发状态上报
	 * 
	 *该函数用于触发状态上报
	 *
	 *@param[in] 	ulEnableStatusReport	1-开始状态上报，0-关闭状态上报
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_TriggerStatusReport(ULONG ulEnableStatusReport);

	/**
	 *配置管理初始化
	 * 
	 *该函数用于配置管理初始化
	 *
	 *@param[in] 	pServerIP		服务器IP
	 *@param[in] 	pUserID			调度员账号
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_ProvisionManagerInit(LPCTSTR pServerIP, LPCTSTR pUserID);

	/**
	 *退出配置管理
	 * 
	 *该函数用于退出配置管理
	 *
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码
	 *@attention	先调用ELTE_OCX_ProvisionManagerInit接口
	 *@par 			无
	**/
	BSTR ELTE_OCX_ProvisionManagerExit(void);

	/**
	 *获取调度台群组列表
	 * 
	 *该函数用于获取调度台群组列表
	 *
	 *@param[in] 	pUserID			调度员账号
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。列表按XML格式解析
	 *@attention	先调用ELTE_OCX_ProvisionManagerInit接口
	 *@par 			无
	**/
	BSTR ELTE_OCX_GetDcGroups(LPCTSTR pUserID);

	/**
	 *获取调度台用户列表
	 * 
	 *该函数用于获取调度台用户列表
	 *
	 *@param[in] 	pUserID			调度员账号
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。列表按XML格式解析
	 *@attention	先调用ELTE_OCX_ProvisionManagerInit接口
	 *@par 			无
	**/
	BSTR ELTE_OCX_GetDcUsers(LPCTSTR pUserID);

	/**
	 *获取一个群组成员列表
	 * 
	 *该函数用于获取一个群组成员列表
	 *
	 *@param[in] 	pGroupID		群组ID
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。列表按XML格式解析
	 *@attention	先调用ELTE_OCX_ProvisionManagerInit接口
	 *@par 			无
	**/
	BSTR ELTE_OCX_GetGroupUsers(LPCTSTR pGroupID);

	/**
	 *获取一个群组详细信息
	 * 
	 *该函数用于获取一个群组详细信息
	 *
	 *@param[in] 	pGroupID		群组ID
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。详细信息按XML格式解析
	 *@attention	先调用ELTE_OCX_ProvisionManagerInit接口
	 *@par 			无
	**/
	BSTR ELTE_OCX_GetGroupInfo(LPCTSTR pGroupID);

	/**
	 *获取一个用户详细信息
	 * 
	 *该函数用于获取一个用户详细信息
	 *
	 *@param[in] 	pUserID			用户账号
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。详细信息按XML格式解析
	 *@attention	先调用ELTE_OCX_ProvisionManagerInit接口
	 *@par 			无
	**/
	BSTR ELTE_OCX_GetUserInfo(LPCTSTR pUserID);

	/**
	 *获取一个调度台详细信息
	 * 
	 *该函数用于获取一个调度台详细信息
	 *
	 *@param[in] 	pUserID			调度台账号
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。详细信息按XML格式解析
	 *@attention	先调用ELTE_OCX_ProvisionManagerInit接口
	 *@par 			无
	**/
	BSTR ELTE_OCX_GetDcInfo(LPCTSTR pUserID);

	/**
	 *订阅/取消订阅群组
	 * 
	 *该函数用于订阅/取消订阅群组
	 *
	 *@param[in] 	pGroupID				群组ID
	 *@param[in] 	ulEnableSubscribeGroup	1-订阅，0-取消订阅
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_SubscribeGroup(LPCTSTR pGroupID, ULONG ulEnableSubscribeGroup);

	/**
	 *获取录像文件列表
	 * 
	 *该函数用于获取录像文件列表
	 *
	 *@param[in] 	pQueryXml		查询条件，按XML格式定义
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。列表信息按XML格式解析
	 *@attention	先调用ELTE_OCX_ProvisionManagerInit接口
	 *@par 			无
	**/
	BSTR ELTE_OCX_GetUserRECFileInfoList(LPCTSTR pQueryXml);

	/**
	 *开启视频回传
	 * 
	 *该函数用于开启视频回传
	 *
	 *@param[in] 	pResourceID		资源ID
	 *@param[in] 	pVideoParam		媒体参数，按XML格式定义
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	从视频回调事件中获取音视频端口信息，然后使用ELTE_OCX_ShowRealPlay显示视频，ELTE_OCX_PlaySound播放伴音
	 *@par 			无
	**/
	BSTR ELTE_OCX_StartRealPlay(LPCTSTR pResourceID, LPCTSTR pVideoParam);

	/**
	 *切换前后置摄像头
	 * 
	 *该函数用于切换前后置摄像头
	 *
	 *@param[in] 	pResourceID		资源ID
	 *@param[in] 	pVideoParam		媒体参数，按XML格式定义
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	从视频回调事件中获取音视频端口信息，然后使用ELTE_OCX_ShowRealPlay显示视频，ELTE_OCX_PlaySound播放伴音
	 *@par 			无
	**/
	BSTR ELTE_OCX_ReverseRealPlay(LPCTSTR pResourceID, LPCTSTR pVideoParam);

	/**
	 *停止播放实时视频
	 * 
	 *该函数用于停止播放实时视频
	 *
	 *@param[in] 	pResourceID		资源ID
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_StopRealPlay(LPCTSTR pResourceID);

	/**
	 *播放器开始播放视频
	 * 
	 *该函数用于播放器开始播放视频
	 *
	 *@param[in] 	pResourceID		资源ID
	 *@param[in] 	pLocalMediaAddr	本地流媒体参数，按XML格式定义
	 *@param[in] 	pRemoteMediaAddr远端流媒体参数，按XML格式定义
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	流媒体参数从视频回调事件中获取
	 *@par 			无
	**/
	BSTR ELTE_OCX_ShowRealPlay(LPCTSTR pResourceID, LPCTSTR pLocalMediaAddr, LPCTSTR pRemoteMediaAddr);

	/**
	 *抓拍视频画面
	 * 
	 *该函数用于抓拍视频画面
	 *
	 *@param[in] 	pResourceID		资源ID
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	截图保存格式和路径在eLTE_Player.ini配置文件中。文件名“pResourceID_实时时间字符串”
	 *@par 			无
	**/
	BSTR ELTE_OCX_Snapshot(LPCTSTR pResourceID);

	/**
	 *播放器停止播放视频
	 * 
	 *该函数用于播放器停止播放视频
	 *
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_HideRealPlay(void);

	/**
	 *播放器开始播放音频
	 * 
	 *该函数用于播放器开始播放音频
	 *
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	ELTE_OCX_StartRealPlay媒体参数需要设置“有伴音”
	 *@par 			无
	**/
	BSTR ELTE_OCX_PlaySound(void);

	/**
	 *播放器停止播放音频
	 * 
	 *该函数用于播放器停止播放音频
	 *
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_StopSound(void);

	/**
	 *设置播放器窗体坐标
	 * 
	 *该函数用于设置播放器窗体坐标
	 *
	 *@param[in] 	ulLeft			左坐标
	 *@param[in] 	ulTop			上坐标
	 *@param[in] 	ulWidth			宽度
	 *@param[in] 	ulHeight		高度
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_SetVideoWindowPos(ULONG ulLeft, ULONG ulTop, ULONG ulWidth, ULONG ulHeight);

	/**
	 *全屏幕显示播放画面
	 * 
	 *该函数用于全屏幕显示播放画面
	 *
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_FullScreenDisplay(void);

	/**
	 *退出全屏幕播放
	 * 
	 *该函数用于退出全屏幕播放
	 *
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_NormalScreenDisplay(void);

	/**
	 *设置播放窗体标题文本
	 * 
	 *该函数用于设置播放窗体文本
	 *
	 *@param[in] 	pTitleText		标题文本
	 *@return 		XML格式，ResultCode=0成功，其他失败参考错误码。
	 *@attention	无
	 *@par 			无
	**/
	BSTR ELTE_OCX_SetTitleText(LPCTSTR pTitleText);

	/**
	 *OCX消息事件
	 * 
	 *该函数用于OCX消息事件
	 *
	 *@param[in] 	ulEventType		事件类型。参考eLTE_EVENT_ID_E枚举定义
	 *@param[in] 	pEventDataXml	事件数据。按XML格式解析
	 *@attention	无
	 *@par 			无
	**/
	void ELTE_OCX_Event(ULONG ulEventType, LPCTSTR pEventDataXml)
	{
		FireEvent(eventidELTE_OCX_Event, EVENT_PARAM(VTS_UI4 VTS_BSTR), ulEventType, pEventDataXml);//lint !e1773
	}

	/**
	 *OCX播放器消息事件
	 * 
	 *该函数用于OCX播放器消息事件，播放窗体显示/隐藏。
	 *
	 *@param[in] 	ulEventType		事件类型。参考eLTE_PLAYER_EVENT_ID_E枚举定义
	 *@param[in] 	pEventDataXml	事件数据。按XML格式解析
	 *@attention	无
	 *@par 			无
	**/
	void ELTE_OCX_PlayerEvent(ULONG ulEventType, LPCTSTR pEventDataXml)
	{
		FireEvent(eventidELTE_OCX_PlayerEvent, EVENT_PARAM(VTS_UI4 VTS_BSTR), ulEventType, pEventDataXml);
	}
	//lint !e1762

	// 工具栏操作接口
public:
	// 抓图
	int ToolBarSnapshot();
	// 切换前后置摄像头
	int ToolBarReversePlayer();
	// 开启关闭伴音
	int ToolBarPlayAudio(BOOL bEnable);
	// 异步播放视频
	static std::map<int, CeLTE_PlayerCtrl*> m_WaitPlayVideoList;

public:
	// 键盘钩子
	static HHOOK s_KeyboardHook;
	// 键盘钩子处理函数
	static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
	// 鼠标钩子
	static HHOOK s_MouseHook;
	// 鼠标钩子处理函数
	static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);

	// GDI+
private:
	Gdiplus::GdiplusStartupInput m_GdiplusStartupInput;
	ULONG_PTR m_GdiplusToken;

private:
	// Load OCX类型
	ULONG m_ulType;
	// Load OCX标识
	BOOL m_bHaveLoaded;
	// 登陆标识
	BOOL m_bIsLogin;
	// 是否触发状态上报
	bool m_bEnableStatusReport;

private:
	ConfigMgr m_ConfigMgr;
	MediaPlayer m_MediaPlayer;
	CVideoPane m_VideoPane;

private:
	// 控件列表
	static std::set<CeLTE_PlayerCtrl*> m_eLTE_PlayerList;
};//lint !e1712 !e1773 !e1768
