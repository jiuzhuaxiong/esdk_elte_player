/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    modulestatus_indicator.h
Author:      zhangjiansheng
Created:     2013/03/21 10:36
Description: 本对象负责处理各模块组件状态变更时从SDK到GUI等上层的指示
*********************************************************************/

#ifndef MODULESTATUS_INDICATOR_H
#define MODULESTATUS_INDICATOR_H

#include <string>

#include "sdk_export.h"


typedef enum {
    SDS_MODULE = 1,   //短信业务模块
    SMS_MODULE,       //彩信业务模块
    AUDIO_MODULE,    //语音业务模块
    VIDEO_MODULE,  //视频业务模块
    GIS_MODULE,  //GIS业务模块
    SIP_MODULE,  //信令通道模块
    RTP_MODULE   //媒体通道模块
} dc_module_t;

typedef enum {
    RESOURCE_STATUS_NORMAL = 0, //状态正常
    SDS_OVERFLOW,    //短信满
    SDS_DISCONNECT,  //DC和短信服务器断链
    SDS_CONNECT,     //DC和短信服务器连接
    SDS_SEND_SUCCESS, //短信发送成功
    SDS_SEND_FAIL, //短信发送失败
    FOLDER_IS_EMPTY,  //导出文件夹为空
    GIS_LICESNCE_UPDATE,  //GIS License变更
    GIS_LICENSCE_EXPIREDAY, //license 即将过期提醒，只剩7天时通知，正数为还剩n天，负数为已经过期n天
    SIP_DISCONNECT,       //DC和BCC断链
    SIP_RECONNECT,       //DC和BCC恢复
    SIP_KEEPALIVE_REJECT, //BCC拒绝DC的心跳请求
    ATTACH_UPLOAD_FAIL,   //附件上传失败
    ATTACH_DOWNLOAD_FAIL,  //附件下载失败
    SIP_START_RUNNING,     //BCC 启动
    KICK_OFF,      //BCC 踢出调度台通知,因为有相同账号登录
    ASYN_CALLBACK_RETURN,   //异步调用返回值
    PASSWORD_CHANGE   //BCC 踢出调度台，因为调度台密码错误
} module_status_t;

class SDK_IMPORT_EXPORT DCModuleStatusIndicator
{
public:
    DCModuleStatusIndicator(MSISDN resid);
    virtual ~DCModuleStatusIndicator();
    std::string datalog_str();

    void setModuleStatus(module_status_t status_value);
    void setModuleType(dc_module_t module_type);
    void setModulePara(std::string status_para);

    module_status_t getModuleStatus();
    dc_module_t getModuleType();
    std::string getModulePara();

private:

    module_status_t m_status_value;      //模块组件类型

    dc_module_t m_module_type;    //状态值

    std::string m_status_para;
};
#endif // MODULESTATUS_INDICATOR_H
