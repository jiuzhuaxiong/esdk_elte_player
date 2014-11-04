/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    p2pcallstatus_indicator.h
Author:      Kai Wang
Created:     2012/08/014 16:36
Description: 本对象负责处理点对点呼叫过程中，状态变更时从APP到GUI的指示
              一般为广播形式， 从而保证多个GUI同步联动

*********************************************************************/

#ifndef P2PCALLSTATUS_INDICATOR_H
#define P2PCALLSTATUS_INDICATOR_H

#include "sdk_export.h"
#include "common.h"
#include <string>
/**
   定义群组显示数据结构
**/
typedef enum {
	P2P_IND_STATUS_UNKNOWN=2000,
    /*--------信令面状态--------*/
    P2P_IND_STATUS_INITIATED,
    P2P_IND_STATUS_RECEIVED,
    P2P_IND_STATUS_ANSWERED,
    P2P_IND_STATUS_EMERGENCY,
    P2P_IND_STATUS_PROCEEDING,
    P2P_IND_STATUS_RINGING,
    P2P_IND_STATUS_ACKED,
    P2P_IND_STATUS_RELEASED,
    P2P_IND_STATUS_HANGUPED,
    P2P_IND_STATUS_HANGUPED_ACTIVE,
    P2P_IND_STATUS_CANCELLED,
    P2P_IND_STATUS_PREMPTED,
    P2P_IND_STATUS_RELEASED_BUSY,
    P2P_IND_STATUS_BREAKIN_FAIL,
    P2P_IND_STATUS_BREAKIN_SUCCESS,
    P2P_IND_STATUS_PROHIBITED,
    P2P_IND_STATUS_REMOTE_NOANSWER,
    P2P_IND_STATUS_REMOTE_NOTFOUND,
    P2P_IND_STATUS_LICENSE_LIMIT,
    /*--------媒体面状态--------*/
    P2P_IND_STATUS_MEDIAPLANE_ERROR,
    P2P_IND_STATUS_MEDIAPLANE_MUTE,
    P2P_IND_STATUS_MEDIAPLANE_UNMUTE,
    P2P_IND_STATUS_REMOTE_NOTSUPPORTED,
    P2P_IND_STATUS_REMOTE_NOTCONNECTED
} P2pcall_Status_t;

class SDK_IMPORT_EXPORT P2pcallStatusIndicator
{
public:
    P2pcallStatusIndicator(MSISDN caller, MSISDN callee);
    P2pcallStatusIndicator(P2pcallStatusIndicator& copy);
    virtual ~P2pcallStatusIndicator();

    std::string datalog_str();

    void setStatus(P2pcall_Status_t status);
    void setPeers(MSISDN caller, MSISDN callee);
    void setBreakins(MSISDN inserter, MSISDN targeter);
	void setPorts(int localPort, int remotePort);
	void setRemoteIP(unsigned long IP);
    void setSoundPtype(Sound_t Ptype); 
    MSISDN getCaller();
    MSISDN getCallee();
    MSISDN getInserter();
    MSISDN getTargeter();

    P2pcall_Status_t getStatus();
    unsigned long getRemoteIP();
    int getLocalPort();
    int getRemotePort();
    Sound_t getSoundPtype();

private:
    P2pcall_Status_t theStatus;
    MSISDN theCaller;
    MSISDN theCallee;
    MSISDN theInserter;//抢权者
    MSISDN theTargeter;//抢权对应对象

    int theLocalPort;
    int theRemotePort;
    unsigned long theRemoteIP;
    Sound_t soundpldtype;
};

#endif // P2PCALLSTATUS_INDICATOR_H
