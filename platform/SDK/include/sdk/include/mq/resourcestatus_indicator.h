/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    resourcestatus_indicator.h
Author:      Kai Wang
Created:     2012/08/08 16:36
Description: 本对象负责处理各种资源状态变更时从APP到GUI的指示
              一般为广播形式， 从而保证多个GUI同步联动
              资源状态类型定义在resource_status_t枚举类型中
*********************************************************************/

#ifndef RESOURCESTATUS_INDICATOR_H
#define RESOURCESTATUS_INDICATOR_H

#include "resourceinfo.h"
#include "uieventlist.h"

#include "sdk_export.h"

/**
   定义资源状态指示数据结构
**/
typedef  BundleKey resource_status_t;

typedef enum {
	RESOURCE_STATUS_UNKNOWN = 4000,
    STATUS_SELECTED,    //资源选中状态
    STATUS_UNSELECTED,  //资源去选中状态

    STATUS_ASSIGNED,    //资源指派状态-
    STATUS_DEASSIGNED,  //资源去指派状态-

    STATUS_LISTENING,   //资源监听中状态
    STATUS_LISTENEND,   //资源监听结束状态

    STATUS_LOGGING,      //资源录音中状态
    STATUS_NOLOGGING,    //资源未设置录音

    STATUS_INPATCH,      //资源被派接
    STATUS_OUTPATCH,     //资源解除派接

    STATUS_REGOK,        //资源注册成功
    STATUS_REGFAIL,      //资源注册失败(general)
    STATUS_FORBIDEN,     //资源未授权 500
    STATUS_NOT_FOUND,    //资源不存在 404
    STATUS_TEMP_UNAVAILABLE, //资源暂时不可用 480
    STATUS_RES_CONFILCT, //资源冲突 450
    STATUS_UNAUTHORIZED, //未鉴权 401
    STATUS_LICENSE_LIMIT, //License受限 503
    STATUS_PASSWORD_WRONG, //密码错误 403

    //下面四个状态的顺序很重要， 因为 isValidTransition（）需要参考顺序
    STATUS_INVITING,    //the resource is initializing a call
    STATUS_RINGING,      //the resource is ringing
    STATUS_TXMTING,     //the resource is talking/transimitting in a call
    STATUS_TXMTIDLE,    //the resource is idle

    STATUS_DGNAOK,       //dynamic regrouping OK
    STATUS_DGNAFAIL,      //dynamic regrouping fail
    STATUS_DGNA_UEFAIL,   //dynamic regrouping one UE fail
    STATUS_GROUP_ACTIVATED,
    STATUS_GROUP_DEACTIVATED

} res_status_value_t;

class SDK_IMPORT_EXPORT ResourceStatusIndicator: public ResourceInfo
{
public:
    ResourceStatusIndicator(MSISDN resourceid);
    virtual ~ResourceStatusIndicator();
    ResourceStatusIndicator(ResourceStatusIndicator& copy);
    //void ResourceStatusIndicator::operator=(ResourceStatusIndicator& copy);

    std::string datalog_str();
    void setStatus(resource_status_t status_type, res_status_value_t status_value);
    void setAttachingGrp(MSISDN _grpID);
    resource_status_t getStatusType();
    res_status_value_t getStatusValue();
    MSISDN getAttachingGrp();


private:

    resource_status_t status_type;      //status type
    res_status_value_t status_value;    //status value for this type


    //status_type = RESTXSTATUS， STATUS_DGNAFAIL
    MSISDN attaching_grp;                  //user in this group

};

//when status_type = USERSTATUS 时， use below derived class
class SDK_IMPORT_EXPORT UserStatusIndicator: public ResourceStatusIndicator
{
public:
    UserStatusIndicator(MSISDN resourceid);
    std::string datalog_str();
    virtual ~UserStatusIndicator();
    UserStatusIndicator(UserStatusIndicator& copy);
    //UserStatusIndicator::operator=(UserStatusIndicator& copy);

    void setPeerUser(MSISDN peerid){_peerid=peerid;}
    void setDirection(int dir){_dir=dir;}
    void setCallType(int calltype){_calltype=calltype;}
    MSISDN getPeerUser(){return _peerid;}
    int getDirection(){return _dir;}
    int getCallType(){return _calltype;}

private:
    MSISDN _peerid;
    int _dir;       // 1=caller， 2=callee
    int _calltype;  // 1= p2paudio, 2=p2pvideo, 3=videoupload
};

//when status_type = VIDEOSTATUSSTATUS ,use below derived class
class SDK_IMPORT_EXPORT VideoDispatchStatusIndicator: public UserStatusIndicator
{
public:
    VideoDispatchStatusIndicator(MSISDN resourceid);
    VideoDispatchStatusIndicator(VideoDispatchStatusIndicator& copy);
    virtual ~VideoDispatchStatusIndicator();

    MSISDN getCamID();
    void setCamID(MSISDN camID);
private:
    MSISDN _camID;
};

//when status_type = USERDGNASTATUS ,use below derived class
class SDK_IMPORT_EXPORT DGNAStatusIndicator: public ResourceStatusIndicator
{
public:
    DGNAStatusIndicator(MSISDN resourceid);
    virtual ~DGNAStatusIndicator();   
    DGNAStatusIndicator(DGNAStatusIndicator& copy);
    //DGNAStatusIndicator::operator=(DGNAStatusIndicator& copy);

    int getCause();
    void setCause(int cause);
private:
    int _cause;  //DGNA failure cause
};

//when status_type = GRPCALLSTATUS ,use below derived class
class SDK_IMPORT_EXPORT GrpResourceStatusIndicator: public ResourceStatusIndicator
{
public:
    GrpResourceStatusIndicator(MSISDN resourceid);
    virtual ~GrpResourceStatusIndicator();
    GrpResourceStatusIndicator(GrpResourceStatusIndicator& copy);
    //void GrpResourceStatusIndicator::operator=(GrpResourceStatusIndicator& copy);

    MSISDN getSpeakerID();
    std::string getSpeakerName();
    void setSpeakerID(MSISDN);
    void setSpeakerName(std::string);
private:
    MSISDN _speakerID;
    std::string _speakerName;
};

#endif // RESOURCESTATUS_INDICATOR_H
