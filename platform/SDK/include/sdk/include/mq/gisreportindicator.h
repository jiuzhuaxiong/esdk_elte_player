/*---------------------------------------------------------
Copyright 2013,TD-Tech. Co., Ltd.
Filename:    gisreportindicator.h
Author:      wu yu wei
Created:     2013/01/24 16:36
Description: GIS 消息通知的Indicator
-------------------------------------------------------------*/

#ifndef GISREPORTINDICATOR_H
#define GISREPORTINDICATOR_H

#include <string>
#include <sdk_export.h>
#include <map>

typedef enum ack_rsp
{
    ACK_SUCCESS,
    ACK_FAIL
}ack_rsp_t;


typedef enum reason_code
{
    PERIOD_RPT,
    EMERGENCY, //紧急事件开启
    OTHER //紧急事件结束
}reason_code_t;

typedef enum rpt_state
{
    NORMAL_STATE, //正常上报
    SEARCH_FAIL, //搜星失败
    OTHER_EXCEPTION, //其他异常
    UNREGISTER //去注册
}rpt_state_t;

typedef std::map<int, ack_rsp> AckResultMap;

class SDK_IMPORT_EXPORT GISReportIndicator
{
public:
    GISReportIndicator(std::string sender, std::string msgTp);
    GISReportIndicator(GISReportIndicator& copy);
    virtual ~GISReportIndicator();
    std::string datalog_str();

    void setSender(std::string sender); /* 上报方 */
    void setTime(std::string time); /* 上报时间 */
    void setAltitude(std::string altitude); /* 高度 */
    void setLongitude(std::string longitude); /* 经度 */
    void setLatitude(std::string latitude); /* 纬度 */
    void setDirection(std::string direction); /* 方向 207.5*/
    void setAckRsp(AckResultMap & ackMap); /*1001:0;1002:1;1003:0*/

    void setReasonCode(reason_code_t rc); /* 周期上报(0)，特定事件（1,紧急呼叫）*/
    void setRptState(rpt_state_t ust);  /* GPS正常开启(0)，GPS搜星失败(1)或其它异常(2) */

    bool isAck();
    AckResultMap& getAckRsp();
    std::string getLongitude();
    std::string getLatitude();
    std::string getAltitude();
    std::string getDirection();
    std::string getTime();
    std::string getSender();
    reason_code_t getReasonCode();
    rpt_state_t getRptState();
    std::string getMsgType();

private:
    std::string _sender;
    std::string _latitude;
    std::string _longitude;
    std::string _altitude;
    std::string _direction;
    std::string _time;
    std::string _msgTp;
    AckResultMap _rspMap;
    reason_code_t  _reasoncd;
    rpt_state_t _ust;
};


#endif // GISREPORTINDICATOR_H
