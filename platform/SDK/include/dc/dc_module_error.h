/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    dc_module_error.hpp
Author:      zhangjiansheng
Created:     2013/05/20 10:08
Description:
*********************************************************************/
#ifndef  UBP_DC_MODULES_ERROR_H
#define  UBP_DC_MODULES_ERROR_H

#include "platform/modules/error/ubp_error.hpp"

///////////////////////////////////////////////////////////////////////
//DC：-40000 ~ -49999 
//  |--SDK    : -40000 ~ -40999
//  |--APP    : -41000 ~ -41999
//  |--GUI    : -42000 ~ -42999
//For example : 
//static const ACE_INT32 ERR_UBP_DC_APP_XXX1 = -41000;
///////////////////////////////////////////////////////////////////////

//DC_SDK:-40000 ~ -40999
static const ACE_INT32 ERR_UBP_DC_SDK_BASE = -40000 ;
static const ACE_INT32 ERR_UBP_DC_SDK_STATE_MISMATCH = ERR_UBP_DC_SDK_BASE-1;     // (操作被APP接受，APP正在处理该操作)
static const ACE_INT32 ERR_UBP_DC_SDK_NO_SUCHRESOURCE = ERR_UBP_DC_SDK_BASE-2;	//(操作不被接受，因为没有该资源)
static const ACE_INT32 ERR_UBP_DC_SDK_NO_CAPABILITY = ERR_UBP_DC_SDK_BASE-3; 	    //（操作不被接受，因为对应资源不支持该操作能力）
static const ACE_INT32 ERR_UBP_DC_SDK_NO_CAPACITY = ERR_UBP_DC_SDK_BASE-4;  	    // （操作不被接受，因为超出APP处理能力）
static const ACE_INT32 ERR_UBP_DC_SDK_NO_PERMISSION = ERR_UBP_DC_SDK_BASE-5;  	// (操作不被接受，因为用户在对应资源上没有权限做该操作)
static const ACE_INT32 ERR_UBP_DC_SDK_PARALLEL_CONFLICT = ERR_UBP_DC_SDK_BASE-6;  //(操作不被接受, 业务并发受限）
static const ACE_INT32 ERR_UBP_DC_SDK_IP_REPEAT  = ERR_UBP_DC_SDK_BASE-7;        //(操作不被接受, IP地址不合法）
static const ACE_INT32 ERR_UBP_DC_SDK_IP_INVALID  = ERR_UBP_DC_SDK_BASE-8;        //(操作不被接受, IP地址不合法）
static const ACE_INT32 ERR_UBP_DC_SDK_OP_OK_QUEUED  = ERR_UBP_DC_SDK_BASE-9;        //(操作不被接受, IP地址不合法）
static const ACE_INT32 ERR_UBP_DC_SDK_PTT_RELEASE_ERROR  = ERR_UBP_DC_SDK_BASE-10;        //(release PTT error）
static const ACE_INT32 ERR_UBP_DC_SDK_NOT_SUBSCRIBED  = ERR_UBP_DC_SDK_BASE-11;

static const ACE_INT32 ERR_UBP_DC_SDK_REMOTE_TIMEOUT = ERR_UBP_DC_SDK_BASE-96;    // 服务器端超时
static const ACE_INT32 ERR_UBP_DC_SDK_REMOTE_FAILURE = ERR_UBP_DC_SDK_BASE-97;    // 服务器端返回错误, 操作被调度机拒绝
static const ACE_INT32 ERR_UBP_DC_SDK_GENERAL = ERR_UBP_DC_SDK_BASE-98;  	        // (操作不被接受, 原因不明)
static const ACE_INT32 ERR_UBP_DC_SDK_NOT_IMPLEMENTED = ERR_UBP_DC_SDK_BASE-99;   // 操作未实现， 可能在未来版本实现
static const ACE_INT32 ERR_UBP_DC_SDK_OSIP_INTERNAL = ERR_UBP_DC_SDK_BASE-100;    //OSIP信令处理内部错误
static const ACE_INT32 ERR_UBP_DC_SDK_MS2_INTERNAL = ERR_UBP_DC_SDK_BASE-101;    //MS2媒体处理内部错误
static const ACE_INT32 ERR_UBP_DC_SDK_ZMQ_INTERNAL = ERR_UBP_DC_SDK_BASE-102;    //ZMQ命令处理内部错误
static const ACE_INT32 ERR_UBP_DC_SDK_TIMER_INTERNAL = ERR_UBP_DC_SDK_BASE-103;    //定时器处理内部错误
static const ACE_INT32 ERR_UBP_DC_SDK_PARAMETER_ERROR = ERR_UBP_DC_SDK_BASE-104;    //参数错误
static const ACE_INT32 ERR_UBP_DC_SDK_LICENSE_LIMIT = ERR_UBP_DC_SDK_BASE-105;    //LICENSE超出限制
static const ACE_INT32 ERR_UBP_DC_SDK_TARGET_EXISTED = ERR_UBP_DC_SDK_BASE-106;    // 已经存在，重复分发
static const ACE_INT32 ERR_UBP_DC_SDK_TARGET_NOT_FOUND = ERR_UBP_DC_SDK_BASE-107;    //该用户不存在
static const ACE_INT32 ERR_UBP_DC_SDK_TARGET_NOT_REGISTERED = ERR_UBP_DC_SDK_BASE-108;    //该用户没有注册
static const ACE_INT32 ERR_UBP_DC_SDK_SCHEDULE_FAIL = ERR_UBP_DC_SDK_BASE-109;    //定时器调度失败

static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_BEYOND_MAX_NUM = ERR_UBP_DC_SDK_BASE-111;    //动态重组有关的错误码
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_WRONG_DMG_NUM = ERR_UBP_DC_SDK_BASE-112;
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_BEYOND_MAX = ERR_UBP_DC_SDK_BASE-113;
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_TIMEROUT = ERR_UBP_DC_SDK_BASE-114;
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_BEYOND_MAX_GROUP = ERR_UBP_DC_SDK_BASE-115;
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_DMGMEMBER_NOT_RIGISTERED = ERR_UBP_DC_SDK_BASE-116;
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_NO_MATCH_VERSION = ERR_UBP_DC_SDK_BASE-117;
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_DMG_ALREADY_EXISTED = ERR_UBP_DC_SDK_BASE-118;
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_NO_OTHER_MEMBER = ERR_UBP_DC_SDK_BASE-119;
static const ACE_INT32 ERR_UBP_DC_SDK_DGNA_ECN_HADLE_FAIL = ERR_UBP_DC_SDK_BASE-120;
static const ACE_INT32 ERR_UBP_DC_SDK_ZMQ_BREAK_IN_REJECT = ERR_UBP_DC_SDK_BASE-121;
static const ACE_INT32 ERR_UBP_DC_SDK_MAX_LIMIT = ERR_UBP_DC_SDK_BASE-122;
//DC_APP:-41000 ~ -41999
static const ACE_INT32 ERR_UBP_DC_APP_BASE = -41000;  //init asyn socket error



//DC_GUI:-42000 ~ -42999
static const ACE_INT32 ERR_UBP_DC_GUI_BASE = -42000;  //init asyn socket error



#endif //UBP_DC_MODULES_ERROR_H
