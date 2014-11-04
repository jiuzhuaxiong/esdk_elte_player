/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    UIParameter.h
Author:      zhangjiansheng
Created:     2012/07/26 16:00
Description: DC GUI 设置参数结构
*********************************************************************/
#ifndef UIPARAMETER_H
#define UIPARAMETER_H

#include <list>
#include "resourceinfo.h"
#include "common.h"

/**********************云台控制命令 begin*************************/
#define LIGHT_PWRON		2	/* 接通灯光电源 */
#define WIPER_PWRON		3	/* 接通雨刷开关 */
#define FAN_PWRON		4	/* 接通风扇开关 */
#define HEATER_PWRON	5	/* 接通加热器开关 */
#define AUX_PWRON1		6	/* 接通辅助设备开关 */
#define AUX_PWRON2		7	/* 接通辅助设备开关 */
#define SET_PRESET		8	/* 设置预置点 */
#define CLE_PRESET		9	/* 清除预置点 */

#define ZOOM_IN			11	/* 焦距以速度SS变大(倍率变大) */
#define ZOOM_OUT		12	/* 焦距以速度SS变小(倍率变小) */
#define FOCUS_NEAR      13  /* 焦点以速度SS前调 */
#define FOCUS_FAR       14  /* 焦点以速度SS后调 */
#define IRIS_OPEN       15  /* 光圈以速度SS扩大 */
#define IRIS_CLOSE      16  /* 光圈以速度SS缩小 */

#define TILT_UP			21	/* 云台以SS的速度上仰 */
#define TILT_DOWN		22	/* 云台以SS的速度下俯 */
#define PAN_LEFT		23	/* 云台以SS的速度左转 */
#define PAN_RIGHT		24	/* 云台以SS的速度右转 */
#define UP_LEFT			25	/* 云台以SS的速度上仰和左转 */
#define UP_RIGHT		26	/* 云台以SS的速度上仰和右转 */
#define DOWN_LEFT		27	/* 云台以SS的速度下俯和左转 */
#define DOWN_RIGHT		28	/* 云台以SS的速度下俯和右转 */
#define PAN_AUTO		29	/* 云台以SS的速度左右自动扫描 */

#define FILL_PRE_SEQ	30	/* 将预置点加入巡航序列 */
#define SET_SEQ_DWELL	31	/* 设置巡航点停顿时间 */
#define SET_SEQ_SPEED	32	/* 设置巡航速度 */
#define CLE_PRE_SEQ		33	/* 将预置点从巡航序列中删除 */
#define STA_MEM_CRUISE	34	/* 开始记录轨迹 */
#define STO_MEM_CRUISE	35	/* 停止记录轨迹 */
#define RUN_CRUISE		36	/* 开始轨迹 */
#define RUN_SEQ			37	/* 开始巡航 */
#define STOP_SEQ		38	/* 停止巡航 */
#define GOTO_PRESET		39	/* 快球转到预置点 */

/**********************云台控制命令 end*************************/

typedef struct FVG_control{
        unsigned int ptz_control_code;    //PTZ控制命令码
        unsigned int ptz_control_value;   //PTZ控制参数
}FVG_control;

typedef struct Video_UL_parameter{
        char * fmtvalue;       //视频格式，取值为“D1”、“CIF”、“QCIF”、“1080P”、“720P”
        char * cameratype;     //“0”表示前置； “1”表示后置
        char * user_confirm_type; //“0”表示不需要用户确认；“1”表示需要用户确认
        char * mutetype;          //“0”表示需要伴音；“1”表示不需要伴音
}Video_UL_parameter;


typedef struct Video_Negotiate_parameter{
        Fmt_type fmt;       //视频格式
        int mute;          //0表示需要伴音；1表示不需要伴音
}Video_Negotiate_parameter;


#define VIDEO_DISPATCH_NUM   32

typedef std::list<MSISDN> DISP_LIST;
typedef struct Video_Dispatch_parameter{
        const char * fmtvalue;            //视频格式，取值为“D1”、“CIF”、“QCIF”、“1080P”、“720P”
        MSISDN   dispatch_num;         //视频源用户号
        DISP_LIST  dstviewerlist;   //视频分发的目的终端列表
        int  channel;               //reserved
}Video_Dispatch_parameter;

typedef std::list<MSISDN> DC_LIST;
typedef struct Video_CircDisplay_parameter{
        int   TimerPeriod;      //轮询周期，以秒为单位
        DC_LIST  Displaylist;   //轮询的摄像头列表
}Video_CircDisplay_parameter;

typedef std::list<std::string> AttachFileList;	/** Attach file list */

/**
* Describes message types.
*/
typedef enum{
    MsgNormal	= 1,			/** 普通消息 */
    MsgStatus	= 2,			/** 状态消息 */
    MsgAlert	= 3,			/** 紧急告警 */
    MsgMMS      = 4,			/** 多媒体消息 */
    MsgDrop     = 5,			/** 倒地告警 */
    MsgCommand	= 6,			/** 调度台命令 */
    MsgACK      = 0xAA,			/** 消息确认 */
    MsgSUBGIS	= 0x07,			/** GIS订阅 */
    MsgSUBGIS_ACK	= 17,		/** GIS订阅ACK */
    MsgUNSUBGIS	= 8,			/** GIS去订阅 */
    MsgUNSUBGIS_ACK	= 18			/** GIS去订阅ACK */
}SDSMSG_TYPE_t;


/**
  define constants for sds

*/
const std::string EXMPP_MSG_TYPE	= "MsgType";
const std::string EXMPP_MSG_TEXT	= "MsgText";
const std::string MMS_FILE_NAME		= "attach";
const std::string EXMPP_INTEGER		= "integer";
const std::string EXMPP_STRING		= "string";

const std::string ACK_STRING            = "ACK";

//分段消息默认长度
const unsigned long MSG_MAX_SIZE	= 4096;


const std::string EXMPP_MSG_TYPE_NORMAL		= "0001";
const std::string EXMPP_MSG_TYPE_STATUS		= "0002";
const std::string EXMPP_MSG_TYPE_ALERT		= "0003";
const std::string EXMPP_MSG_TYPE_MMS		= "0004";
const std::string EXMPP_MSG_TYPE_DROP		= "0005";
const std::string EXMPP_MSG_TYPE_ACK		= "0010";

/* GIS Msg Type definition */
const std::string EXMPP_MSG_TYPE_GISRPT		= "0006";
const std::string EXMPP_MSG_TYPE_SUBGIS         = "07";
const std::string EXMPP_MSG_TYPE_SUBGIS_ACK	= "17";
const std::string EXMPP_MSG_TYPE_UNSUBGIS       = "08";
const std::string EXMPP_MSG_TYPE_UNSUBGIS_ACK	= "18";


typedef struct SDS_parameter{
    std::string sdstype; //SDS短数据类型
    std::string msg_body; //SDS短数据内容
    std::string receiver; //收件人
    AttachFileList files;//附件地址
}SDS_parameter;

typedef struct  GIS_parameter{
    SDSMSG_TYPE_t subtype;  // GIS短数据类型 , MsgSUBGIS-订阅; MsgUNSUBGIS-去订阅
    std::string msg_body;   //   关注的终端列表，以分号分隔
    std::string subscriber; // GIS Subscriber
} GIS_parameter;


typedef enum
{
    ON_LINE, //在线
    OFF_LINE //离线
}MSG_STATE_t;


typedef struct SDS_export_parameter{

    std::string exportpath; //导出目标路径

}SDS_export_parameter;

typedef struct Record_parameter{
    unsigned int task_type; //0表示录音 1表示录像
    unsigned int call_type; //0表示点呼 1表示组呼 2视频回传
}Record_parameter;

typedef struct VWallStart_parameter{
    MSISDN DstObjId ;/* 视频上墙的目的地， 为一个视频通道*/
    MSISDN SrcObjId ;  /*视频上墙的源， 为一个摄像头*/
    std::string StrFmt ; /*预留，2.0不用*/

}VWallStart_parameter;

typedef struct VWallStop_parameter{
    MSISDN DstObjId ;/* 视频上墙的目的地， 为一个视频通道*/
    MSISDN SrcObjId ;  /*视频上墙的源， 为一个摄像头*/
}VWallStop_parameter;


typedef struct DGNA_parameter{
                MSISDN grpId ;/* 动态组组号*/
                MSISDN dcId ;  /*创建该动态组的DC用户号*/
                std::string alias; /*该动态组别名*/
                int priority;	/*该动态组优先级*/
                int maxPeriod; //该组的最大通话时长
                MSISDN grpList[8];	//组成员列表
                MSISDN userList[200];	//用户成员列表
}DGNA_parameter;

typedef struct {
    int framerate;
    int packetlossrate;
    float bitrate;
} VideoStatistics_t;

typedef struct Mute_parameter{
    bool task_type; //false表示unmute true表示mute
    int call_type; //0表示点呼 1表示组呼 2视频回传
}Mute_parameter;

#endif // UIPARAMETER_H
