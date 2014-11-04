/********************************************************************
  Copyright 2012,TD-Tech. Co., Ltd.
  Filename:    ubp_globe.hpp
  Author:      Wu Gang
  Created:     2012/12/19 20:11
  Description: 定义UPB全局变量

*********************************************************************/

#ifndef UBP_GLOBE_HPP__
#define UBP_GLOBE_HPP__

#include "ace/Basic_Types.h"

#ifdef WIN32
#pragma warning(disable:4996)
#pragma warning(disable:4068)
#else
#pragma GCC system_header  //屏蔽告警："-Wunused-variable"
#endif // WIN32

//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wunused-variable"
//#pragma GCC diagnostic pop
//#pragma GCC diagnostic ignored "-Wall"

//////////////////////////////////////////////////////////////////////////
//   订阅消息TOPIC全局定义
//////////////////////////////////////////////////////////////////////////
//配置变更消息
static const char *TOPIC_CM_MO_CHANGE = "UBP.CM.MO";  
//服务信息变更消息
static const char *TOPIC_SCA_SVC_INFO_CHANGE = "UBP.SCA.INFO.C";  
//服务信息变更消息(daem之间)
static const char *TOPIC_SCA_SVC_INFO_CHANGE_DAEM = "UBP.SCA.INFO.C.DAEM";  
//服务状态变更消息
static const char *TOPIC_SCA_SVC_STATE_CHANGE = "UBP.SCA.STAT.C";  
//服务状态变更消息(DAEM之间传送)
static const char *TOPIC_SCA_SVC_STATE_CHANGE_DAEM = "UBP.SCA.STAT.C.DAEM";  
//告警消息
static const char *TOPIC_FM_ALARM = "UBP.FM.ALARM";  
//软件升级消息
static const char *TOPIC_SWM_UPGRADE ="UBP.SWM.UPGRADE";

static const char *TOPIC_MON_SVCSTATE ="UBP.MONITOR.SVCSTATE";
static const char *TOPIC_MON_DISKSTATE ="UBP.MONITOR.DISKSTATE";
static const char *TOPIC_MON_MEMSTATE ="UBP.MONITOR.MEMSTATE";
static const char *TOPIC_MON_CPUSTATE ="UBP.MONITOR.CPUSTATE";
static const char *TOPIC_MON_DBSTATE  ="UBP.MONITOR.DBSTATE";

static const char *TOPIC_LICENSE_BROADCAST ="UBP.LICENSE.BROADCAST";//软件升级消息
static const char *TOPIC_LICENSE_EXPIREDDAYS ="UBP.LICENSE.BROADCAST";//
static const char *TOPIC_HEARTBEAT ="UBP.HEARTBEAT.BROADCAST";//心跳广播

static const char *TOPIC_BCC_USER_STATUS = "PeriodStatusInfo";  //bcc to dc/bcc , user status report
static const char *TOPIC_BCC_ALL_STATUS = "AllStatusInfo";  //bcc to dc/bcc , all status report

//////////////////////////////////////////////////////////////////////////
//UBP系统的package全局定义,在服务端处理消息响应时，
//同一服务的不同的模块可以注册不同的responser,以package名称区分不同的response
//////////////////////////////////////////////////////////////////////////
static const char *MSG_PACKAGE_PLATFORM = "ubp.platform";
static const char *MSG_PACKAGE_SCA = "ubp.platform.sca";
static const char *MSG_PACKAGE_BCC = "ubp.bcc";
static const char *MSG_PACKAGE_BDC = "ubp.bdc";
static const char *MSG_PACKAGE_CM = "ubp.cm";
static const char *MSG_PACKAGE_FM = "ubp.fm";
static const char *MSG_PACKAGE_LM = "ubp.lm";
static const char *MSG_PACKAGE_MRS = "ubp.mrs";
static const char *MSG_PACKAGE_VGW = "ubp.vgw";
static const char *MSG_PACKAGE_MONITOR ="ubp.monitor";
static const char *MSG_PACKAGE_SWM ="ubp.swm";
static const char *MSG_PACKAGE_LIC_MAN  =   "ubp.lic_man";

//////////////////////////////////////////////////////////////////////////
//MQ查询消息头的ID
//////////////////////////////////////////////////////////////////////////
static const char *MQ_QUERY_MSG_ID = "ubp.platform.MqQueryMsg";

//////////////////////////////////////////////////////////////////////////
//IMessageHeader中操作码码的全局定义
//message IMessageHeader
//{
//    required string msg_id = 1;   //待发送消息的ID，全局唯一，
//                                    类似"ubp.platform.ScaMessage"的字符串
//    required string src_svc_id = 2;  //发送方的svc_key,用于唯一标识发起方
//    optional string dest_svc_id = 3;  //目标方的svc_key,用于唯一标识目标方
//    optional uint32 operator_code = 4;  //全局操作码，有规划的区段
//    optional string module = 5;   //所属模块，预留暂时不用
//}
// Platform : 0   ~ 999 (CM:0~99;SWM:100~199)     
// BCC      :1000 ~ 1999;
// BDC      :2000 ~ 2999;
// MRS      :3000 ~ 3999;
// VGW      :4000 ~ 4999;
// DC       :5000 ~ 5999;
// 数据中心  :10000~ 10999;
//////////////////////////////////////////////////////////////////////////
enum OperateType {
	OP_ADD = 1,
	OP_MODIFY,
	OP_DELETE,
	OP_QUERY,
	OP_BATCH_ADD,
	OP_BATCH_MODIFY,
	OP_BATCH_DELETE,
	OP_BATCH_IMPORT,
	OP_BATCH_IMPORT_CSV,
	OP_COLLECT_TRACE
};

//////////////////////////////////////////////////////////////////////////
//MQ查询消息头的ID
//////////////////////////////////////////////////////////////////////////
//内部ReponseTask（同步）的binding地址，加前缀避免重复
static const char *BCC_BINDING_MSG_QUEUE_STR = "inproc://ubp.bcc.msgqueue_"; 

//CM每批量配置下发给终端的最大个数
static const ACE_UINT32 MAX_BATCH_DISPATCH_TO_UE = 300;

#endif //UBP_GLOBE_HPP__
