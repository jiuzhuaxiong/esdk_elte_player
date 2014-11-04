/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    appcontext.h
Author:      Wu yu wei
Created:     2012/07/10 10:00
Description:
*********************************************************************/
#ifndef DC_COMMON_H
#define DC_COMMON_H

#define WAIT_TIMER 5	//事件检测时间间隔ms，DTS2013030603146
#define REG_TIMER  500*10	    //注册时间间隔ms
#define EXPIRE_TIME 3600            //SIP Expire time

#define EXPIRE_CHECK_TIME 19            //定时器检测时间
#define SIP_KEEPALIVE_TIME 60           //每60s做一次SIP Keepalive检测

/*audio payload type*/
#define AMR_PAYLOAD_TYPE 114
#define AMR_PAYLOAD_TYPE_475 115
#define PCMU_PAYLOAD_TYPE 0
#define PCMA_PAYLOAD_TYPE 8
//#define TEL_PAYLOAD_TYPE 101

/*video payload type*/
#define H264_PAYLOAD_TYPE 102

#define AMR_MODE    "mode-set="
#define AMR_475_MODE   0
#define AMR_1220_MODE  7
#define INVALID_RSC   -1

/*txt_ptt_req :: type*///清SDK告警 [-Wwrite-strings
#define PTT_REQ_TYPE_REQUEST  const_cast<char *>("request")
#define PTT_REQ_TYPE_ACCEPT   const_cast<char *>("accept")
#define PTT_REQ_TYPE_WAITING  const_cast<char *>("waiting")
#define PTT_REQ_TYPE_REJECT   const_cast<char *>("reject")
#define PTT_REQ_TYPE_RLEASE  const_cast<char *>("release")

#define EMERGENCY_CALL "emergency_call"
#define PTT_STATUS_IND "Session_Ind"

#define VIDEO_DISPATCH "videodispatch"

/*txt_ptt_release :: reason*/
#define PTT_RELEASE_TIMEOUT "timeout"
#define PTT_RELEASE_FORCE  "force"
#define PTT_RELEASE_IDLE "idle"
#define PTT_RELEASE_ACTIVE "active"

/*SDS config info*/
#define DC_SDS_PATH  "data/mms";
#define INBOX        "inbox.xml"
#define OUTBOX       "outbox.xml"
#define DC_SDS_HTTPSERVER_PATH "upload";
#define DC_SDS_HTTPSERVER_PORT "9090";

/*XMPP 心跳检测周期*/
#define HEART_BEAT_CHECK_PERIOD   120

/*No ack检测周期*/
#define NO_ACK_CHECK_PERIOD   10

/*MIC 热插拔检测周期*/
#define SERIAL_CHECK_PERIOD   5

/*iconv转码路径最大长度*/
#define MAX_PATH_LENGTH   200

/*inconv转码字符最大长度*/
#define MAX_CHARACTOR_LENGTH   2000

/*REC :: type,Call-Info的格式定义如下
Call-Info: <0>;type=call_type;id1=user1;id2=user2
其中type为本次通话类型：single_voice_call表示语音点呼，single_video_call表示视频点呼，
single_emergency_call表示语音紧急点呼，group_call表示组呼，
group_emergency_call表示紧急组呼，video_upload表示视频回传。
*/
#define REC_P2P_CALL   "single_voice_call"
#define REC_P2P_VIDEO_CALL  "single_video_call"
#define REC_P2P_EMERGENCY_CALL  "single_emergency_call"
#define REC_GROUP_EMERGENCY_CALL "group_emergency_call"
#define REC_GROUP_CALL "group_call"
#define REC_VIDEO_UPLOAD "videoupload"


/*DC调度台只有在视频回传界面可以手动触发和停止录像，其它场景都只能触发和停止手动录音*/
//录制类型
#define REC_VOICE_TYPE    0 //录音
#define REC_VIDEO_TYPE    1 //录像

//录制业务类型
#define REC_P2P_TYPE             0  //点对点业务
#define REC_GROUP_TYPE           1  //集群业务
#define REC_UPOALD_VIDEO_TYPE    2  //视频上传业务

#define SIP_OK 200


//清SDK告警 [-Wwrite-strings
#define CALLINFO_EXT_TYPE  const_cast<char *>("type")
#define CALLINFO_EXT_ID1  const_cast<char *>("id1")
#define CALLINFO_EXT_ID2  const_cast<char *>("id2")
#define CALLINFO_EXT_VPN1  const_cast<char *>("vpn1")
#define CALLINFO_EXT_VPN2  const_cast<char *>("vpn2")
#define CALLINFO_EXT_GRPSTATUS  const_cast<char *>("groupstatus")
#define CALLINFO_EXT_SPEAKER  const_cast<char *>("speaker")
#define CALLINFO_EXT_SPEAKERNAME  const_cast<char *>("speakername")
#define CALLINFO_EXT_MUTE const_cast<char *>("mute")
#define CALLINFO_EXT_USRCONFIRM const_cast<char *>("user_confirm")
#define CALLINFO_EXT_FMT const_cast<char *>("fmt")
#define CALLINFO_EXT_CAMERA const_cast<char *>("camera")
#define CALLINFO_EXT_CHANNEL const_cast<char *>("channel")
#define CALLINFO_EXT_RESULT const_cast<char *>("result")
#define CALLINFO_EXT_GROUPCALL const_cast<char *>("group_call")
#define CALLINFO_EXT_PRIORITY const_cast<char *>("priority")
#define CALLINFO_EXT_CALLTYPE const_cast<char *>("calltype")
#define CALLINFO_EXT_TEMPGROUPCALL const_cast<char *>("temp_groupcall")
#define CALLINFO_EXT_EMERGENCY const_cast<char *>("emergency_callInd")
#define CALLINFO_EXT_MDCSTART const_cast<char *>("mdc_start")
#define CALLINFO_EXT_KICKOFF const_cast<char *>("kickoff")
#define CALLINFO_EXT_IP const_cast<char *>("newip")

#define STRING_ZERO const_cast<char *>("0")

//视频格式类型
typedef enum
{
    V_CIF,
    V_QCIF,
    V_D1,
    V_720P,
    V_1080P,
    INVALID_FMT
}Fmt_type;

//音频格式类型
typedef enum {
  invalid_ptype = -1,
  amr_475_ptype,
  amr_1220_ptype,
  pcmu_ptype,
  pcma_ptype
} Sound_t;

//去定义stun_udp里的bool定义

#ifdef bool
#undef bool
#endif
#ifdef true
#undef true
#endif
#ifdef false
#undef false
#endif

#endif // DC_COMMON_H
