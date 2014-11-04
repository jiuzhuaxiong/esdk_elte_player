/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    StatusObserver.h
Author:      Wang Kai
Created:     2012/09/03 10:00
Description: Observer 模式的接口类， APP 通过本接口通知GUI各种状态指示信息
             不同的GUI可以实现自己的DisplayManager， 如QtDisplayManager， ZMQDisplayManager等等

*********************************************************************/

#ifndef STATUSOBSERVER_H
#define STATUSOBSERVER_H

#include "sdk_export.h"

class GrpDspInfo;
class ResourceStatusIndicator;
class P2pcallStatusIndicator;
class P2pvideocallStatusIndicator;
class ProvChangeIndicator;
class SdsMessageIndicator;
class DCModuleStatusIndicator;
class SDK_IMPORT_EXPORT DisplayManager
{
public:

    //通知组呼的状态变更信息
    virtual void notifyGroupStatus(GrpDspInfo * grpInfo) =0;
    //通知用户和群组资源的状态变更信息
    virtual void notifyResourceStatus(ResourceStatusIndicator * resourceStatus)=0;
    //通知点对点呼叫的状态变更信息
    virtual void notifyP2pcallStatus(P2pcallStatusIndicator * callStatus)=0;
    //通知视频呼叫的状态变更信息（包括视频回传）
    virtual void notifyP2pvideocallStatus(P2pvideocallStatusIndicator * callStatus)=0;

    virtual void notifyUserStatus(ResourceStatusIndicator * resourceStatus)=0;
    virtual void notifyUserSdsStatus(SdsMessageIndicator * sdsmsg)=0;
    virtual void notifyModuleStatus(DCModuleStatusIndicator * moduleStatus)=0;

    //短数据信息上报给GUI
    virtual void notifySMS(SdsMessageIndicator * sdsmsg)=0;

    //通知配置对象的变更信息， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
    virtual void notifyProvisionChange(ProvChangeIndicator* ) =0;

    //通知配置对象的全同步， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
    virtual void notifyProvisionAllResync(ProvChangeIndicator* ) =0;

    //通知状态对象的全同步， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
    virtual void notifyStatusAllResync(ResourceStatusIndicator* ) =0;

//private:
        /*DisplayManager本质上为一个接口类，不允许实例化*/
        //DisplayManager(){}
};

class SDK_IMPORT_EXPORT ProvListener
{
public:

    //通知配置对象的变更信息， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
    virtual void notifyProvisionChange(ProvChangeIndicator* ) =0;

    //通知配置对象的全同步， 参数为一个多态指针， 使用者需要downcast 为对应的变更子类
    virtual void notifyProvisionAllResync(ProvChangeIndicator* ) =0;

};

#endif // STATUSOBSERVER_H
