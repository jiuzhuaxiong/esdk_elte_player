/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    operationmanager.h
Author:      Wu yu wei
Created:     2012/07/26 16:00
Description: GUI向app发送命令的SDK接口
*********************************************************************/
#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include "sdk_export.h"
#include "dc/dc_module_error.h"
class OperationManager;
class ResourceInfo;

#define OP_OK_ACCEPTED UBP_SUCCESS
typedef ACE_INT32 Op_Return_t;

typedef enum
{
    DC_LOGIN, //调度员登入
    DC_LOGOUT, //调度员注销
    DC_EXIT, //调度台退出
    PTT_DIAL, //发起组呼/PTT抢权
    PTT_RELEASE, //发起PTT放权
    PTT_HANGUP, //组呼业务强拆
    SIP_INIT, //Sip初始化
    P2P_DIALOUT, //点对点拨打
    P2P_RECV, //点对点接听
    P2P_HANGUP, //点对点挂断
    P2P_REJECT, //点对点拒绝
    P2P_VIDEO_DIAL,//点对点视频拨打
    P2P_VIDEO_RECV,//点对点视频接听
    P2P_VIDEO_HANGUP,//点对点视频挂断
    P2P_VIDEO_MONITOR,//视频监控
    P2P_VIDEO_DISPATCH,//视频分发
    P2P_VIDEO_STARTCIRCDISPLAY,//发起视频轮询
    P2P_VIDEO_STOPCIRCDISPLAY,//停止视频轮询
    GRP_SUB, //群组订阅
    GRP_UNSUB, //群组去订阅
    GRP_JOIN, //加入群组
    GRP_LEAVE, //退出群组
    GRP_BREAKOFF, //强拆组呼
    GRP_QUERY, //用户当前群组查询
    P2P_BREAKOFF, //强拆点呼
    P2P_BREAKIN, //点呼抢权
    DC_PZT_CONCTROL, //PZT控制
    VOL_MUTE, //静音控制
    VOL_UNMUTE, //关闭静音控制
    BATCH_CFG,   //系统启动批配置操作
    SDS_SEND,   //发送短数据
    SDS_EXPORT,   //短数据导出
    REC_START,   //开始录音\录像
    REC_STOP,    //停止录音\录像
    VWALL_START,   //启动视频上墙
    VWALL_STOP,   //停止上墙
    DL_START,   //开始Discreet Listen
    DL_STOP,    //停止DL
    GIS_SUBSCRIBE, //GIS订阅/去订阅
    DGNA_CREATE,    //创建动态重组
    DGNA_CANCEL,     //取消动态重组
    TIC_DIALOUT,    //Telephone-Interconnect-Call dialout
    TIC_HANGUP,      //Telephone-Interconnect-Call hangup
    TEMPGRP_CREATE,  //创建临时组
    TEMP_PTT,        //发起临时组呼
    P2P_VIDEO_REJECT,//视频呼叫拒接
    P2P_VIDEO_PREVIEW, //视频预览，使用bypass模式
    P2P_VIDEO_SWITCHBACK, //视频切换，恢复non-bypass模式
    P2P_ENVIRONMENT_LISTEN, //个呼环境监听
    P2P_VIDEO_RECV_PARA, //点对点视频接听,带参数(fmt,mute),
    TEMPGRP_DELETE
}Operation_t;

class SDK_IMPORT_EXPORT OperationManager
{
public:
    OperationManager();    
    /**
      GUI Operation to invoke app
    **/
    ACE_INT32 invokeOp(ResourceInfo * res_info, Operation_t op_type);
    ACE_INT32 invokeOp_multipara(ResourceInfo * res_info, void * multi_para, Operation_t op_type);
};

class SDK_IMPORT_EXPORT OperationManager_T
{
public:
  /// Global access point to the Singleton.
  static OperationManager *instance (void);
};
#endif // OPERATIONMANAGER_H
