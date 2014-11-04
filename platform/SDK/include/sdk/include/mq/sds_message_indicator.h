/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    sds_message_indicator.h
Author:      zhangjiansheng
Created:     2012/12/12 16:36
Description: 本对象负责处理短数据接收过程中，将短数据信息上报给GUI
*********************************************************************/

#ifndef SDS_MESSAGE_INDICATOR_H
#define SDS_MESSAGE_INDICATOR_H

#include <string>
#include "sdk_export.h"
#include "ace/Basic_Types.h"
#include "uiparameter.h"
#include <list>

typedef std::list<std::string> RecvfileList;	/** Receiver list */


class SDK_IMPORT_EXPORT SdsMessageIndicator
{
public:
    SdsMessageIndicator(std::string from);
    SdsMessageIndicator(SdsMessageIndicator& copy);
    virtual ~SdsMessageIndicator();
    std::string datalog_str();

    void setSdsType(std::string type);
    void setSdsContent(std::string content);
    void setSdsFrom(std::string from);
    void setSdsTo(std::string to);
    void setSdsFilename(RecvfileList &mmsfilename);
    void setSdsSubject(std::string subject);
    void setTime(std::string date,std::string time);
    void setStatusCode(unsigned int code);
    void setMsgState(MSG_STATE_t msgstate);
    void setSdsDirection(bool direction);

    std::string getSdsType();
    std::string getSdsContent();
    std::string getSdsFrom();
    std::string getSdsTo();
    RecvfileList getSdsFilename();
    std::string getSdsSubject();
    std::string getSdsDate();
    std::string getSdsTime();
    unsigned int getStatusCode();
    MSG_STATE_t getMsgState();
    bool getSdsDirection();

private:
    std::string _type;			/** Message type */
    std::string _content;		/** Message content */
    std::string _from;			/** Message from (JID) */
    RecvfileList _mmsfilename;	        /** Attach file name (MMS) */
    std::string _subject;	        /** Message subject */
    std::string _date;			/** Date (Not used yet) */
    std::string _time;			/** Time (Not used yet) */
    unsigned int _statusCode;           /** statusCode for StatusMsg **/
    MSG_STATE_t _msgstate;
    std::string _to;        /** Message to **/
    bool _direction;        /** SDS recieve:false；SDS send:true **/
};


#endif // SDS_MESSAGE_INDICATOR_H
