/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    uidspinfo.h
Author:      Wu yu wei
Created:     2012/08/01 14:00
Description:
*********************************************************************/
#ifndef UIDSPINFO_H
#define UIDSPINFO_H

#include "sdk_export.h"
#include "common.h"
#include <string>
/**
   定义群组显示数据结构
**/
typedef enum {
    PTT_IND_STATUS_UNKNOWN=1000,
    PTT_IND_STATUS_RECEIVED,
    PTT_IND_STATUS_REQUEST,
    PTT_IND_STATUS_ACCEPT,
    PTT_IND_STATUS_WAITING,
    PTT_IND_STATUS_REJECT,
    PTT_IND_STATUS_SNATCH,
    PTT_IND_STATUS_HANGUP_OK,
    PTT_IND_STATUS_CLOSE_OK,
    PTT_IND_STATUS_CANCEL_OK,
    PTT_IND_STATUS_PREMPTED,
    /*--------媒体面变化的通知-------------*/
    PTT_IND_STATUS_TX_BEGIN,        //组呼话权变化
    PTT_IND_STATUS_TX_IDLE,         //组呼话权空闲
    PTT_IND_STATUS_MEDIAPLANE_ERROR,
    PTT_IND_STATUS_EMERGENCY_BEGIN,
    PTT_IND_STATUS_EMERGENCY_UPDATE,
    PTT_IND_STATUS_LICENSE_LIMIT
} Speaker_Status_t;

class GrpCallInfo;

class SDK_IMPORT_EXPORT GrpDspInfo
{
public:
    GrpDspInfo(MSISDN grpId);
    GrpDspInfo(GrpDspInfo& clone);
    virtual ~GrpDspInfo();
    std::string datalog_str();

    void setGrpId(MSISDN grpId);
    void setSpStatus(Speaker_Status_t status);
    void setSpeaker(MSISDN speaker);
    void setSpeakerName(std::string name);
    void setPorts(int localPort, int remotePort);
    void setRemoteIP(unsigned long IP);
    void setSoundPtype(Sound_t Ptype); 
    Speaker_Status_t getSpStatus();
    std::string getSpeakerName();
    MSISDN getSpeaker();
    MSISDN getGrpId();

    unsigned long getRemoteIP();
    int getLocalPort();
    int getRemotePort();
    Sound_t getSoundPtype();

private:
    MSISDN _grpId; //组号
    Speaker_Status_t _sp_status; //主讲状态
    MSISDN _speaker; //主讲人， 可能为空

    //SDP协商出来的端口，在mediaByPass模式的时候需要传给GUI
    int theLocalPort;//本地端口
    int theRemotePort;//远端端口
    unsigned long theRemoteIP;//对端IP
    Sound_t soundpldtype;
    std::string _speakerName;
};

typedef GrpDspInfo GroupStatusIndicator;

#endif // UIDSPINFO_H
