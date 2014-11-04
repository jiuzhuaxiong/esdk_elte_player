/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    provchange_indicator.h
Author:      Kai Wang
Created:     2012/12/07 08:36
Description: 本对象负责处理配置变更时从APP到GUI的指示
             ProvChangeIndicator 为基类
             ProvChangeIndicator_XXX 定义每一个变更的具体类
             DisplayManager::NotifyProvChange(ProvChangeIndicator*) 使用一个基类的多态指针
             使用者通过 getChangeMO来知道具体变化类并 down_cast 多态指针到具体类型
*********************************************************************/

#ifndef PROVCHANGE_INDICATOR_H
#define PROVCHANGE_INDICATOR_H

#include "sdk_export.h"
#include "provisionmanager.h"
#include "ubp_globe.hpp"

/**
   定义变更类型
**/

typedef enum {

    CHANGE_ADD =OP_ADD,
    CHANGE_MODIFY =OP_MODIFY,
    CHANGE_DELETE =OP_DELETE,
    CHANGE_QUERY =OP_QUERY,
    CHANGE_BATCHADD =OP_BATCH_ADD,
    CHANGE_BATCHMODIFY =OP_BATCH_MODIFY,
    CHANGE_BATCHDELETE=OP_BATCH_DELETE,
    CHANGE_BATCHIMPORT =OP_BATCH_IMPORT,
    CHANGE_BATCHIMPORTCSV =OP_BATCH_IMPORT_CSV,

    CHANGE_ENABLE =20,
    CHANGE_DISABLE =21

} Change_Type_t;

typedef enum {
    MO_PTTUser,
    MO_FixedUser,
    MO_DCAttribute,
    MO_Group,
    MO_DMGroup,
    MO_GroupPTTUser,
    MO_GroupFixedUser,
    MO_DynamicGroupMember,
    MO_DMGPhotoGroupUser,
    MO_UBPNode,
    MO_UBPService,
    MO_NeighbourNode,
    MO_BccCfg,
    MO_CallInhibited,
    MO_VGWDEC,
    MO_RangeList,
    MO_DCRanges,
    MO_HOTLINECFG,
    MO_STMSGCFG,
    MO_DECUSER,
    MO_UNKNOWN,
    MO_VGWDEVICE,
    MO_GISCFG,
    MO_GISIPC,
    MO_VPN,
    MO_VPNRange,
    MO_EXTERNALGROUP,
    MO_UEAbility,
    MO_DCDEC
} Change_MO_t;


class SDK_IMPORT_EXPORT ProvChangeIndicator
{
public:
    virtual ~ProvChangeIndicator();
    void setChangeType(Change_Type_t changetype) {_changetype = changetype;}
    void setChangeMO(Change_MO_t changemo){_changemo = changemo;}
    virtual std::string datalog_str();
    Change_Type_t getChangeType(){return _changetype;}
    Change_MO_t getChangeMO(){return _changemo;}
    virtual ProvChangeIndicator* clone(){return NULL;};

protected:
    void cloneBase(ProvChangeIndicator& pci)
    {
     _changetype = pci.getChangeType();
     _changemo = pci.getChangeMO() ;
    }

private:
    Change_Type_t _changetype;
    Change_MO_t   _changemo;
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_PTTUser
:public ProvChangeIndicator, public UserInfo
{
public:
    ProvChangeIndicator_PTTUser(const UserInfo& userinfo);
    //std::string datalog_str();
    virtual ProvChangeIndicator_PTTUser* clone();
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_Group
:public ProvChangeIndicator, public GroupInfo
{
public:
    ProvChangeIndicator_Group(const GroupInfo& groupinfo);
    //std::string datalog_str();

    virtual ProvChangeIndicator_Group* clone();
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_GrpUserInfo
:public ProvChangeIndicator, public GrpUserInfo
{
public:
    ProvChangeIndicator_GrpUserInfo(const GrpUserInfo& grpuserinfo);
    //std::string datalog_str();

    ProvChangeIndicator_GrpUserInfo* clone();
};

typedef  ProvChangeIndicator_PTTUser ProvChangeIndicator_FixedUser;

class SDK_IMPORT_EXPORT ProvChangeIndicator_DCAttribute
:public ProvChangeIndicator, public DcProperty
{
public:
    ProvChangeIndicator_DCAttribute(const DcProperty& grpuserinfo);
    //std::string datalog_str();
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_RangeList
:public ProvChangeIndicator, public RangeInfo
{
public:
    ProvChangeIndicator_RangeList(const RangeInfo& rangeinfo);
    //std::string datalog_str();
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_DCRange
:public ProvChangeIndicator
{
public:
    ProvChangeIndicator_DCRange(MSISDN dcid,int rangid);
    //std::string datalog_str();
    MSISDN dcid;
    int rangid;
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_HotlineCfg
:public ProvChangeIndicator, public Hotline
{
public:
    ProvChangeIndicator_HotlineCfg(const Hotline& msg);
    //std::string datalog_str();
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_StMsgCfg
:public ProvChangeIndicator, public SdsStMsgCfg
{
public:
    ProvChangeIndicator_StMsgCfg(const SdsStMsgCfg& msg);

};

class SDK_IMPORT_EXPORT ProvChangeIndicator_VgwDec
:public ProvChangeIndicator
{
public:
    ProvChangeIndicator_VgwDec(int devIndex_, int nodeId_, int chnNum_, std::string devAlias_,int devStatus_);

    int DevIndex; //'大屏ID'
    int NodeId; //'VGW节点ID'
    int ChnNum; //'分屏数'
    std::string DevAlias; //'大屏描述'
    int DevStatus;       //解码器状态
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_GisCfg
:public ProvChangeIndicator, public ProvGisCfg
{
public:
    ProvChangeIndicator_GisCfg(const ProvGisCfg& msg);

};

class SDK_IMPORT_EXPORT ProvChangeIndicator_GisIpc
:public ProvChangeIndicator, public ProvGisIpc
{
public:
    ProvChangeIndicator_GisIpc(const ProvGisIpc& msg);

    ProvChangeIndicator_GisIpc* clone();
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_PhotoGrpUserInfo
:public ProvChangeIndicator, public PhotoGrpUserInfo
{
public:
    ProvChangeIndicator_PhotoGrpUserInfo(const PhotoGrpUserInfo& grpuserinfo);
    //std::string datalog_str();
};


class SDK_IMPORT_EXPORT ProvChangeIndicator_VPN
:public ProvChangeIndicator, public VpnInfo
{
public:
    ProvChangeIndicator_VPN(const VpnInfo& vpn);
    //std::string datalog_str();
};

class SDK_IMPORT_EXPORT ProvChangeIndicator_VPNRange
:public ProvChangeIndicator, public VpnRangeInfo
{
public:
    ProvChangeIndicator_VPNRange(const VpnRangeInfo& rangeinfo);
    //std::string datalog_str();
};


class SDK_IMPORT_EXPORT ProvChangeIndicator_UEAbility
:public ProvChangeIndicator, public ProvUEAblity
{
public:
    ProvChangeIndicator_UEAbility(const ProvUEAblity& ueability);
    //std::string datalog_str();
};
#endif // PROVCHANGE_INDICATOR_H
