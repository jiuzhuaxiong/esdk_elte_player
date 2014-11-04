/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    provision_manager.h
Author:      Wang Kai
Created:     2012/12/04 14:00
Description: 配置管理类
*********************************************************************/

#ifndef PROVISION_MANAGER_H
#define PROVISION_MANAGER_H

#include <list>
#include <map>
#include <vector>
#include <string>
#include "sdk_export.h"

//前向声明 UserStatusIndicator and GroupStatusIndicator

class ACE_Null_Mutex;
class DisplayManager;
class ProvListener;
class UserStatusIndicator;
class GrpDspInfo;
class ProvChangeIndicator;
typedef GrpDspInfo GroupStatusIndicator;
class LicenseListener;

typedef int MSISDN;

#define ALIAS_MAX_LENGTH 64
#define STMSG_MAX_LENGTH 64

typedef enum {
    ENUM_UE=0,
    ENUM_MOBILE_STATION=1

}Ue_Model_t;


typedef enum{
    ENUM_UE_VERSION=0
}Ue_Version_t;


typedef enum{
    ENUM_UE_NULL=0,
    ENUM_UE_QCIF=1,
    ENUM_UE_CIF=2,
    ENUM_UE_D1=3,
    ENUM_UE_720p=4,
    ENUM_UE_1080P=5
}Ue_Ability_t;


typedef enum {
    DISPATCHER =0,      //Dispatcher 调度台用户
    FIXEDCAMERA = 1,    //固定摄像头；
    PSTNUSER = 2,       //  PSTN用户；
    TETRAUSER = 3,      // TETRA用户；
    PLMNUSER = 4,       //  PLMN移动用户；
    EXTERNALPTT = 5,    // 外部PTT用户
    DECUSER = 6,         //DEC用户
    PTTUSER = 9,         //PTT用户
    ALLTYPEUSER = 10,     // 所有用户，不分类型
    OTHERUSER = 255       // 其它未分类用户"
}User_Category_t;

typedef enum {
    LOCAL_USER =0,      //本调度机用户
    EXTERNAL_USER = 1   //外部调度机用户；

}User_Location_t;

typedef enum {
    GRP_ALLBROADCAST =0,      //全网广播组
    GRP_GENERAL = 1,        //普通组；
    GRP_AREABROADCAST = 2,       //  区域广播组；
    GRP_EXTERNAL=8,         //外部组，用在分级场景
    GRP_DYNAMICGRP = 9,      //动态组
    GRP_ALLTYPE   = 10
}Group_Category_t;

typedef enum {
    MEMBER_GROUP = 0,
    MEMBER_USER = 1

}Group_Member_t;

typedef enum {
    PREV_BREAKOFF =1,      //强拆权限
    PREV_BREAKIN = 2,    //强插权限；
    PREV_LISTEN = 4,       //  监听权限；
    PREV_MONITOR = 8,      // 视频监控权限；
    PREV_SDSEXPORT= 16,       //  短信导出权限；
    PREV_ENVLISTEN= 32,       //环境监听权限；
    PREV_VWALL= 64         //环境监听权限；
}Dc_Previlege_t;

typedef int Prov_Result_t;  //0代表成功， 负值代表失败

typedef enum {
    GISEVENT_PERSONDOWN =1, //倒地告警
    GISEVENT_EMERGENCY =2   //紧急呼叫
}Gis_Event_t;

enum Rec_Call_Dir_t
{
  ENUM_CALLER,    //主叫
  ENUM_CALLEE     //被叫
};

enum Rec_Call_Type_t
{
    ENUM_REC_UNKNOW_CALL_TYPE = -1,
    ENUM_REC_P2P_AUDIO = 0,
    ENUM_REC_P2P_VIDEO =1,
    ENUM_REC_VIDEO_UPLOAD =2,
    ENUM_REC_PTT =3

};

enum Rec_Media_Type_t
{
    ENUM_MEDIA_AUDIO, //音频
    ENUM_MEDIA_VIDEO //视频
};
class SDK_IMPORT_EXPORT ProvUEAblity
{
public:
    MSISDN userid;
    Ue_Model_t UEModel;
    Ue_Version_t UESoftwareVersion;
    Ue_Version_t UAppVersion;
    Ue_Ability_t PreCamera;
    Ue_Ability_t PostCamera;
    Ue_Ability_t ExtCamera;

    ProvUEAblity(){;}
    ProvUEAblity(const ProvUEAblity& uety);
    void operator =(const ProvUEAblity& uety);
    void update(const ProvUEAblity& uety);
};

typedef std::map<MSISDN,ProvUEAblity*> ProvUEAbilityMap;

class SDK_IMPORT_EXPORT RECQueryInfo
{
public:
    Rec_Call_Type_t call_type;      //0=点呼， 3=组呼
    MSISDN caller;
    MSISDN callee;
    MSISDN resourceid;
    std::string start_sec;      //"yyyy-mm-dd hh:mm:ss"
    std::string end_sec;
    RECQueryInfo();
    std::string toConditionStr();
};

class SDK_IMPORT_EXPORT UserRecFileInfo
{
public:
    int call_type;	//呼叫类型： 3=组呼，0=点呼
    MSISDN caller;		//主叫
    MSISDN callee;		//被叫
    MSISDN resourceid;	//resourceid
    std::string start_sec;	//该录音文件的起始时间, //"yyyy-mm-dd hh:mm:ss"
    std::string end_sec;	//该录音文件的结束时间
    std::string urlFTP; //该录音文件的FTP URL
    std::string urlRTSP; //该录音文件的RTSP URL

	UserRecFileInfo(){;}
};

typedef std::list<UserRecFileInfo*> UserRecFileInfoList;

class SDK_IMPORT_EXPORT ProvGisCfg
{
    public:
        MSISDN userid;
        unsigned int reportSwitch; //上报开关, 0=关闭， 1=开启
        unsigned int reportPeriod;
        unsigned int reportCapability;
        unsigned int reportDistance;//支持GIS终端上报

        ProvGisCfg(){;}
        ProvGisCfg(const ProvGisCfg& gc);
        void operator =(const ProvGisCfg& gc);
};
typedef std::vector<ProvGisCfg*> ProvGisCfgList;

class SDK_IMPORT_EXPORT ProvGisIpc
{
    public:
        MSISDN userid;
        double latitude;
        double longitude;
        double altitude;
        std::string address;

        ProvGisIpc(){;}
        ProvGisIpc(const ProvGisIpc& gisipc);
        void operator =(const ProvGisIpc& gisipc);
};
typedef std::vector<ProvGisIpc*> ProvGisIpcList;

class SDK_IMPORT_EXPORT SdsStMsgCfg
{
    public:
        int id;
        std::string stmsg;

        SdsStMsgCfg(){;}
        SdsStMsgCfg(const SdsStMsgCfg& dc);
};
typedef std::vector<SdsStMsgCfg*> SdsStMsgCfgList;


class SDK_IMPORT_EXPORT DcProperty
{
    public:
        MSISDN dcid;
        int priviledge;
        int role; //supervisor, operator

        //int userpriority;
        std::string Alias;
        DcProperty(){;}
        DcProperty(const DcProperty& dc);
};
typedef std::vector<DcProperty*> DcList;

class SDK_IMPORT_EXPORT RangeInfo
{
    public:
        int rangid;
        int Rangecategory;  //group range, user range,
        MSISDN From;
        MSISDN To;
        std::string Alias;

        RangeInfo(){;}
        RangeInfo(const RangeInfo& range);

};
typedef std::vector<RangeInfo*> DcRanges;

class SDK_IMPORT_EXPORT Hotline
{
    public:
        MSISDN DcId;
        int HotIndex;
        MSISDN Number;
        std::string Alias;

        Hotline(){;}
        Hotline(const Hotline& user);
};
typedef std::vector<Hotline*> DcHotlines;

class SDK_IMPORT_EXPORT VpnInfo
{
    public:

        int VpnId;  //VPN号码
        std::string VpnName; //VPN名称
        VpnInfo(){;}
        VpnInfo(const VpnInfo& vpn);
};
typedef std::vector<VpnInfo*> VpnList;


class SDK_IMPORT_EXPORT VpnRangeInfo
{
    public:
        int VpnId;
        MSISDN From;
        MSISDN To;

        VpnRangeInfo(){;}
        VpnRangeInfo(const VpnRangeInfo& range);

};
typedef std::vector<VpnRangeInfo*> VpnRanges;

class SDK_IMPORT_EXPORT GroupInfo
{
    public:
        MSISDN grpid;
        Group_Category_t grpcategory; //全网， 区域， 静态， 动态， etc
        int grppriority;
        std::string grpname;
        int grpstate;    //0=disable, 1=enable
        int vpnid;
        MSISDN setupDcId;    //creator, valid if it's dynamic or temp group
        GroupInfo();
        GroupInfo(const GroupInfo& user);
        void update(const GroupInfo& grp);
};

typedef std::vector<GroupInfo*> DcGroups;
typedef std::map<MSISDN, GroupInfo*> DcGroupsMap_T;

class SDK_IMPORT_EXPORT UserInfo
{
    public:
        MSISDN userid;
        User_Category_t usercategory; //包括PTTuser， Camera, FixedLine, etc
        int userpriority;
        std::string username;
        int vpnid ;
        int vpnout;
        int vpnin;
        User_Location_t location;
        UserInfo();
        UserInfo(const UserInfo& user);
        void update(const UserInfo& user);
};

typedef std::vector<UserInfo*> DcUsers;
typedef std::map<MSISDN, UserInfo*> DcUsersMap_T;

class SDK_IMPORT_EXPORT PhotoGrpUserInfo
{
    public:
        MSISDN dmgid;
        MSISDN userid;
        MSISDN grpid;
        PhotoGrpUserInfo(){;}
        PhotoGrpUserInfo(const PhotoGrpUserInfo& user);
};

class SDK_IMPORT_EXPORT GrpUserInfo
{
    public:
        MSISDN userid;                      //根据membertype，可能为静态用户或组 ID
        MSISDN grpid;                       //可能为静态组或动态组
        int userpriorityInGrp;
        Group_Member_t memberType;         //1=普通用户成员， 0=动态重组中的组成员
        GrpUserInfo(){;}
        GrpUserInfo(const GrpUserInfo& user);

};
typedef std::vector <GrpUserInfo*> GrpUserList;

typedef std::vector<UserStatusIndicator*> UserStatusList;
typedef std::vector<GroupStatusIndicator*> GroupStatusList;

class SDK_IMPORT_EXPORT VWallInfo:public UserInfo
{
    public:

        int DevIndex; //解码器设备ID
        int ChnNo;    //视频通道号
        std::string Alias; //视频墙的别名
        int Status;        //0=disable, 1=enable
        VWallInfo();
        VWallInfo(const VWallInfo& vwall);
};
typedef std::vector<VWallInfo*> VWallInfoList;

class SDK_IMPORT_EXPORT ProvisionManager
{
    friend class ProvisonManager_T;

public:

	//单例模式的访问函数，在非本DLL中只用使用此函数！！！
    static ProvisionManager* getInstance();

    /*
      ProvisionManager初始化，从服务器端下载数据
        @param serverIP： 服务器的IP地址
        @param dcid： 当DC调用ProvisionManager时需要设置DCID， 非DC调用ProvisionManager时可以不填
    */
    void init(std::string serverIP,MSISDN dcid);
    /*
      init from applicationContext
    */

    void initMRS(std::string mrsServerIP);
    void exit();

    /*
    设置DisplayManager + ProvListener的回调接口，当配置变更时通过该接口来通知
        @param dm: DisplayManager的接口指针
    */
	void setDisplayManager(DisplayManager* dm);
        DisplayManager* getDisplayManager();
        void setProvListener(ProvListener* pl);
        ProvListener* getProvListener();
    /*
      获得本DC管理的所有热线信息，返回值为一份克隆的数据，由调用者负责操纵并最终销毁
      @param dcid： 本调度台的用户号，如果此调度台用户不存在则返回NULL
    */
    DcHotlines* getDcHotlinesClone(MSISDN Dcid);
    Prov_Result_t addDcHotline(MSISDN dcid,const Hotline& hotline );
    Prov_Result_t delDcHotline(MSISDN dcid, const Hotline& hotline);
    bool isInDcRange(MSISDN userid, MSISDN dcid);
    bool isInOnlyDcRange(MSISDN userid, MSISDN dcid);
    /*
      获得本DC管理的所有Group，返回值为一份克隆的数据，由调用者负责操纵并最终销毁
      @param dcid： 本调度台的用户号，如果 Dcid==0， 则返回全网所有的Group

    */
    DcGroups* getDcGroupsClone(MSISDN Dcid);
    DcGroups* getDcGroupsByType(MSISDN Dcid, Group_Category_t cat);
    DcGroups* getDcGroupsByTypeAndVpnId(MSISDN Dcid, Group_Category_t cat,int Vpnid);
    DcUsers* getDcAloneUsersCloneByType(MSISDN Dcid, User_Category_t cat,int vpnid);
    /*
      获得本DC管理的所有User (包括fixeduser 类型)， 返回值为一份克隆的数据，由调用者负责操纵并最终销毁
      @param dcid: 本调度台的用户号; 如果 Dcid==0， 则返回全网所有的User
    */
    DcUsers* getDcUsersClone(MSISDN Dcid);
    DcUsers* getDcUsersCloneByType(MSISDN Dcid, User_Category_t cat);
    DcUsers* getDcExternalUsersCloneByType(MSISDN Dcid, User_Category_t cat);
    DcUsers* getDcUsersCloneByTypeAndVpnId(MSISDN Dcid, int VpnId, User_Category_t cat);
    /*
      获得本DC管理的所有Camera User， 返回值为一份克隆的数据，由调用者负责操纵并最终销毁
      @param dcid: 本调度台的用户号;如果 Dcid==0， 则返回全网所有的Camera User
    */
    DcUsers* getDcCameraUsersClone(MSISDN Dcid);
    DcUsers* getDcCameraUsersClonebyVpnId(MSISDN Dcid,int VpnId);
    ProvGisIpcList* getDcGisIpcClone(MSISDN dcid);
    /*
      获得某个组里的所有User， 返回值为一份克隆的数据，由调用者负责操纵并最终销毁
      @param grpid: 组号;如果该组不存在， 则返回NULL
    */
    GrpUserList* getGroupUsersClone(MSISDN  grpid);
    //获取动态重组的静态组成员里的用户快照
    GrpUserList* getDynamicGroupPhotoUsersClone(MSISDN  dynamicgrpid, MSISDN photogrpid);
    /*
      获得单个组的属性， 返回值为一份克隆的数据，由调用者负责操纵并最终销毁
      @param grpid: 组号;如果该组不存在， 则返回NULL
    */
    GroupInfo* getGroupInfoClone(MSISDN  grpid);
    UserInfo*  getUserInfoClone(MSISDN userid);
    /*
      获得所有的DC， 返回值为一份克隆的数据，由调用者负责操纵并最终销毁
      @param none:
    */
    DcList* getAllDcClone();
    DcProperty* getDcProperty(MSISDN Dcid);
    int getDcUserPriority(MSISDN Dcid);

    VpnInfo* getDcVpnINfo(MSISDN Dcid);
    VpnList* getAllVpnClone();
    bool isGroupMember(MSISDN userid, MSISDN grpid);

    //获取状态信息
    UserStatusList* getVWallsCurrentStatus(MSISDN Dcid);
    UserStatusList* getUsersCurrentStatus(MSISDN Dcid);
    GroupStatusList* getGroupsCurrentStatus(MSISDN Dcid);

    //获取状态短信配置
    SdsStMsgCfg* getStatusMsgClone(/*unsigned*/ int code);

    //获取视频解码通道信息
    VWallInfoList* getVWallsClone();

    /* GISCFG 的读写接口
    */
    ProvGisCfg* getGisCfgClone(MSISDN dcid,MSISDN userid);
    Prov_Result_t ModifyGisCfg(const ProvGisCfg& gc );
    Prov_Result_t AddGisCfg(const ProvGisCfg& gc );

    static void notifyProvisionChange(ProvChangeIndicator* pci);
    static void notifyProvisionAllResync();
    Prov_Result_t GetGisLic(const std::string &aCtrlItm,std::string &Itmvalue);
    LicenseListener *getListener();
    void setListener(LicenseListener *Listener);

    /*RECFile 的查询接口 */
    UserRecFileInfoList* getUserRecFileInfoList( RECQueryInfo* condition);


    //UEAbility终端的订阅和SDK的查询
    ProvUEAblity* getUEAbilityClone(MSISDN ueid);

public:
    ProvisionManager();

};

//typedef ACE_Unmanaged_Singleton<ProvisionManager, ACE_Null_Mutex> ProvisionManager_T;

class SDK_IMPORT_EXPORT ProvisionManager_T
{
public:
  /// Global access point to the Singleton.
  static ProvisionManager *instance (void);
};

#endif // PROVISION_MANAGER_H
