/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    license_control.h
Author:      Wang Kai
Created:     2012/09/03 10:00
Description: Observer 模式的接口类， APP 通过本接口通知上层相关业务信息
             上层可以实现自己的LicenseControl， 如Rec_LicenseControl，
			 Dc_LicenseControl等等

*********************************************************************/

#ifndef LICENSE_CONTROL_H
#define LICENSE_CONTROL_H

#include "sdk_export.h"
#include <string>
#include "common.h"

//定义业务类型
typedef enum
{
    DIAL, //点呼
    VIDEO_P2P, //视频点呼
    VIDEO_UPLOAD, //视频回传
    PTT,  //组呼
    UNDEFINED_TP
}Service_type;

//定义呼叫优先类型
typedef enum
{
    EMERGENCY, //紧急呼叫类型
    NORMAL  //普通呼叫类型
}Priority_type;

class SDK_IMPORT_EXPORT ServInfo
{
public:
    ServInfo(MSISDN caller, MSISDN callee);
    ServInfo(const ServInfo& sInfo);

    std::string datalog_str();

    void setServiceType(Service_type stype);
    void setPriType(Priority_type ctype);
    void setFmt(Fmt_type FmtVlaue);
    void setMute(int MuteValue);
    void setCallId(MSISDN callid);

    MSISDN getCaller();
    MSISDN getCallee();
    Service_type getServiceType();
    Priority_type getPriType();
    Fmt_type getFmt();
    int getMute();
    MSISDN getCallId();

private:
    MSISDN m_Caller;
    MSISDN m_Callee;
    Service_type m_stype;
    Priority_type m_ctype;
    Fmt_type m_ftype;
    int m_mute;
    MSISDN m_callid;
};

class SDK_IMPORT_EXPORT LicenseControl
{
public:

    //license是否允许接入，true表示允许，false表示禁止
    virtual bool is_license_accept(ServInfo *Sinfo) =0;

};


class SDK_IMPORT_EXPORT ConnInfo
{
public:
    ConnInfo();

    void setLocalIp(char *localip);
    void setAudioport(unsigned int aport);
    void setVideoport(unsigned int vport);

    char * getLocalIp();
    unsigned int getAudioport();
    unsigned int getVideoport();
    std::string datalog_str();

private:
    char * m_LocalIp;
    unsigned int m_audioport;
    unsigned int m_videoport;

};


class SDK_IMPORT_EXPORT ConnectionControl
{
public:

    //获取上层设置的网络连接信息，true表示成功，false表示失败
    virtual bool get_Connection_info(ServInfo *Sinfo,ConnInfo *Cinfo) =0;

};
#endif // LICENSE_CONTROL_H
