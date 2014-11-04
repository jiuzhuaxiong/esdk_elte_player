/********************************************************************

Copyright 2012,TD-Tech. Co., Ltd.

Filename:    dcstate.h

Author:      Wu yu wei

Created:     2012/07/07 10:00

Description: 定义DC上的各种业务的数据结构，包括组呼业务， 视频业务， 视频轮询等等

*********************************************************************/

#ifndef DCSTATE_H

#define DCSTATE_H

#include "uiparameter.h"
#include "mq/resourcestatus_indicator.h"
#include <map>
#include <memory>
#include <string>
#include "displaymanager.h"
#include "sdk_export.h"

//从网络上发来的用户状态值，状态信息在StatusController中维护
//发起业务， 业务进行中， 振铃中， 业务结束
typedef enum {
    INVITING = 0,
    RINGING = 1,
    TALKING = 2,
    CLOSING = 3
}User_Status_Value;

//定义业务类型
typedef enum {
    UNREG =0,
    REG =1,
    VOICEP2P =2,
    VIDEOP2P =3,
    UPLOADP2P =4,
    VIDEODISP =5,
    VIDEOONWALL=6,
    VOICEP2G = 7,
    ABMIENCELISTENP2P = 8
}Call_Type_t;

typedef struct {
    res_status_value_t userStatus; //调度台定义的资源状态值
    int peerUserID;
    Call_Type_t calltype;
    int calldir;

}User_Call_Status;

typedef struct {
    res_status_value_t regResult; //资源注册结果
    resource_status_t regType; //资源注册类型
}Res_Reg_Status;

typedef struct {
    MSISDN grpid;
    bool bCallActivated;
    int callPriority;
    MSISDN speaker;
}Group_Status;

typedef enum {
    PROXY,
    DIRECT
}Reg_Type_t;

class GroupInfo;

//群组业务信息的数据结构，群组呼叫信息保存在GrpCallInfo中
class SDK_IMPORT_EXPORT SubscribeInfo {

public:
    SubscribeInfo();
    ~SubscribeInfo();
    bool bSelected;     //该组是否被选中为当前组

    bool bMuted;        //改组是否被静音

    int grpPriority;    //该组的优先级

    bool bRecording;    //该组是否正被录音

    bool bDiscretListening; ////该组是否正被DL

    bool bCallActivated;    //该组是否有呼叫进行中

    bool bTempGroup;        //该组是否为临时组

    DGNA_parameter* tempGroupInfo;

    MSISDN setupDcId;       //临时组或动态组有setupDcId

    bool bPTTReleaseLater;      //PTT按键是否released with failure

    MSISDN OrigDcID;       //组呼状态OrigDcID
    //计算当在调度台在该组发起呼叫时呼叫的优先级： 由组优先级和发起人优先级共同决定
    int calcPttPriority();
};


//视频业务信息数据结构，视频呼叫信息保存在VideoCallInfo中
class SDK_IMPORT_EXPORT VideoInfo {

public:
    bool bMuted;    //该视频是否被静音

    int camera;    //视频使用的摄像头 0：前置, 1:后置

    bool bOnWall;  //该视频是否在上墙 fix DTS2013022504891
};


//用户群组查询的数据结构
typedef struct user_inGrp_info

{

    MSISDN userID;		//用户号

    bool is_joined_grp;		//用户是否加入群组

    MSISDN grpID;		//用户加入的组号

}user_inGrp_info;


class SDK_IMPORT_EXPORT DcState

{
public:
    static DcState* getInstance();

    virtual void set_login_info(MSISDN dcid,const char* password,const char* serverIP, int sipPort, const char* localIP,const char* lang );

    virtual void setSipPort(const std::string &org);

    virtual const char* getSipPort();

    virtual void setSipLocalPort(const std::string &org);

    virtual const char* getSipLocalPort();

    virtual void setServerIP(const std::string &org);

    virtual std::string& getServerIP();

    virtual void setLocalIP(const std::string &org);
    virtual void setLocalIP4RTP(const std::string &org);
    virtual std::string& getLocalIP();
    virtual std::string& getLocalIP4RTP();

    virtual void setPwd(const std::string &org);

    virtual std::string& getPwd();

    virtual void setUser(const std::string &org);

    virtual std::string& getUser();

    virtual void setLogin(bool login);

    virtual bool isLogin();

    virtual void resetState();

    virtual std::string & getLang();

    virtual void setLang(const std::string &org);

    //DC ID

    virtual int getDCID(void);

    virtual void setDCID(int id);

    virtual SubscribeInfo * findSubscribe(MSISDN grpid) ;

    /* 根据resID查询VideoInfo */
    virtual std::auto_ptr<VideoInfo> findVideoInfo(MSISDN resID);

    //临时群组的管理函数
    virtual MSISDN getNextTempGroupID();

    virtual int unsubscribeTempGroup(MSISDN grpid);
    virtual bool isTempGroup(MSISDN grpid);

    virtual int getDCVPN(void);

    virtual User_Call_Status* findUserStatus(MSISDN userid, Call_Type_t calltype);
    virtual Res_Reg_Status* findUserRegStatus(MSISDN userid, Reg_Type_t regtype);
};


#endif // DCSTATE_H

