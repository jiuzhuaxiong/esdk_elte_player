/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    appcontext.h
Author:      Wu yu wei
Created:     2012/07/07 10:00
Description:
*********************************************************************/
#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H
#include <memory>
#include <string>
#include "sdk_export.h"


class DcState;

class DisplayManager;

class LicenseControl;

class ConnectionControl;

class MediaManager;

class GISReportManager;

class Peripheral_report_manager;

class DcMqContext;

struct eXosip_t;

class KeepAliveTimeoutHandler;

/**
   定义APP的工作模式,APP可用工作在如下的几种模式
**/
typedef enum {

    APPMODE_DISPATCH_CONSOLE,	//调度台		
    APPMODE_VIDEO_GATEWAY,		//视频网关
    APPMODE_LOGGING_SERVER,		//录音录像服务器
    APPMODE_LISTEN_SERVER,		//监听服务器
    APPMODE_DEC_GATEWAY		//视频网关
} App_Mode_t;


/**
  定义业务类型
**/
typedef enum {

   MMS,  //短消息
   GIS,  //GIS
   REC,  //录音录像
   SUB   //资源订阅
} Biz_t;

class SDK_IMPORT_EXPORT ApplicationContext
{

public:   

    /* 取调度台状态对象 */
    virtual DcState * getConsoleState();

    /* 单例模式的访问函数，在非本DLL中只用使用此函数！！！ */
    static ApplicationContext* getInstance();
    
    /* 初始化与退出 */
    virtual int initApp();
    virtual int exitApp();


    /* 获得DisplayManager接口 */
    virtual DisplayManager * getDisplayManager();
    /* 设置DisplayManager接口的实现类 */
    virtual void setDisplayManager(DisplayManager*);

    /* 获得LicenseControl接口 */
    virtual LicenseControl * getLicenseControl();
    /* 设置LicenseControl接口的实现类 */
    virtual void setLicenseControl(LicenseControl* );

    /* 获得ConnectionControl接口 */
    virtual ConnectionControl * getConnectionControl();
    /* 设置ConnectionControl接口的实现类 */
    virtual void setConnectionControl(ConnectionControl* );

    /* 获取MediaManager接口 */
    virtual MediaManager * getMediaManager();
    /* 设置MediaManager接口的实现类 */
    virtual void setMediaManager(MediaManager* );

    /* 获取ReportManager接口 */
    virtual GISReportManager * getReportManager();
    /* 设置ReportManager接口实现类 */
    virtual void setReportManager(GISReportManager * );

    /* 获取Peripheral_report_manager接口 */
    virtual Peripheral_report_manager * getPeripheralManager();
    /* 设置Peripheral_report_manager接口实现类 */
    virtual void setPeripheralManager(Peripheral_report_manager * );

    /* 获取是否跳过媒体面的开关 */
    virtual bool bypassBuildMedia();
    /* 设置是否跳过媒体面的开关 */
    virtual void setBypassBuildMedia(bool );

    /* 设置工作模式 */
    virtual void setWorkMode(App_Mode_t );
    virtual App_Mode_t getWorkMode();


     /* 触发app进行状态上报 */
    virtual void triggerStatusReport(bool );
    virtual bool isStatusReportTriggered();


    /*  APP启动,只有DC工作模式需要调用，只做DC相关的工作
    */
    virtual int startRunning(std::string & );

    /*
      停止DC，与start对应,退出和注销时需要调用
    */
    virtual int stopRunning();

    /* Exosip 上下文 */
    virtual eXosip_t *getExContext();
    virtual void setExContext(eXosip_t *);

    /* MRS 调用 */
    virtual int GetLocalSipPort() ;
    virtual void SetLocalSipPort(int );

    /* ZMQ上下文对象 */
    virtual DcMqContext * getDcMqContext();

    //added from TTR2.1

    //APP启动,使用const char*参数
    virtual int startRunning(const char* serverip);
    //设置是否跳过视频媒体面的开关，只控制视频业务
    virtual void setBypassBuildVideo(bool );
    virtual bool bypassBuildVideo();
};

//typedef ACE_Singleton<ApplicationContext, ACE_Null_Mutex> ApplicationContext_T;

class SDK_IMPORT_EXPORT ApplicationContext_T
{
public:
  /// Global access point to the Singleton.
  static ApplicationContext *instance (void);
};

#endif // APPLICATIONCONTEXT_H
