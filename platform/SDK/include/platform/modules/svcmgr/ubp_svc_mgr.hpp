/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    ubp_svc_mgr.hpp
Author:      ZhongWei
Created:     2012/10/26 10:28
Description: interface for  ServiceMgr
*********************************************************************/

#ifndef  PLATFORM_MODULES_SCA_UBP_SVC_MGR_HPP_
#define  PLATFORM_MODULES_SCA_UBP_SVC_MGR_HPP_

#include "service_info.hpp"
#include "platform/modules/frame/module.hpp"
#include "platform/modules/frame/module_context.hpp"

namespace ubp
{
namespace platform
{
namespace svcmgr
{

//定义服务变更的事件类型
enum SERIVCE_CHANGE_EVENT_TYPE
{
  SERVICE_ADD = 0,      //新增服务
  SERVICE_DEL,          //删除服务
  SERVICE_MOD           //修改服务
};

//定义服务变更事件处理器原型
class ServiceInfoChangeHandler
{
public:
    virtual ACE_INT32 handle_change(SERIVCE_CHANGE_EVENT_TYPE event_type,
        ServiceInfo *service_info_ptr) = 0;

    void *parent_;      
};

class SVCMGR_IMPORT_EXPORT ServiceMgr
    : public ubp::platform::frame::Module
{
  public:
    //Module must support a static function "ModuleName"
    static const std::string& ModuleName(void);

    //Todo:　后面加入本Module对外提供的接口
    //脱离ModuleContext环境，创建一个实例,不建议使用
    static ServiceMgr* CreateInstance(ubp::platform::frame::ModuleContext* context);

    //  初始化ServiceMgr对象，db_mode表示是否从数据库加载服务信息
    //virtual ACE_INT32 Init(const std::string &service_name, bool db_mode)=0;

    //从deploy_policy.xml加载数据,only_local为true表示只加载本机的服务
    virtual ACE_INT32 LoadPolicy(const std::string &service_name,const char *file_name = NULL)=0;

    //从数据库中加载服务信息,only_local为true表示只加载本机的服务
    //virtual ACE_INT32 LoadPolicyFromDB(const std::string &service_name)=0;


    //获取Service Key相关接口//
    //GetCurrentServiceKey:获取本服务的Service Key，返回Service Key
    //virtual std::string GetCurrentServiceKey(void)=0;

    //获取本机所属的daem的Service Key
    virtual std::string GetDaemServiceKey(void)=0;

    //获取master主机的Service Key
    //virtual std::string GetMasterDaemServiceKey()=0;

    //virtual std::string GetServiceKey(const std::string &hostIp, const std::string &servcieName)=0;

    //GetServiceKey:获取指定主机、指定服务的Service Key，host_ip不填表示本机，返回Service Key
    virtual std::string GetServiceKey(const char *svcname, const char *host_ip = NULL)=0;

    //GetServiceKeyByNodeID:获取指定NodeID的Service Key，仅对DB模式有效
    //virtual std::string GetServiceKeyByNodeID(int nodeID)=0;

    //GetServiceKeyAll:获取所有主机上所有服务的Service Key放入svc_key_array，返回service数量
    //virtual ACE_INT32 GetServiceKeyAll(ServiceKeySet &svc_key_array)=0;

    //GetServiceKeyByHost:获取指定主机上所有服务的Service Key放入svc_key_array，host_ip不填表示本机，返回service数量
    //virtual ACE_INT32 GetServiceKeyByHost(ServiceKeySet &svc_key_array, const char *host_ip = NULL)=0;

    //函数功能：获取制定的服务类型的Service Key
    //返回值：service数量，svc_key_array: Service Key集合
    //domain:域名称，其中，NULL：本域； * ：所有域；
    //host_ip:主机所在的IP;NULL:所有主机
    virtual ACE_INT32 GetServiceKeyByType(ServiceKeySet &svc_key_array, 
        const char *svc_type,const char* domain=NULL,const char* host_ip = NULL)=0;

    //根据主机名获取
    virtual ACE_INT32 GetServiceKeyByTypeH(ServiceKeySet &svc_key_array, 
      const char *svc_type,const char* domain=NULL,const char* host_name = NULL)=0;

    //函数功能：获取制定的服务类型的ServiceInfo
    //返回值：service数量，svc_array: ServiceInfo集合
    //domain:域名称，其中，NULL：本域； * ：所有域；
    //host_ip:主机所在的IP;NULL:所有主机
    virtual ACE_INT32 GetServicesByType(std::vector<ServiceInfo> &svc_array, 
        const char *svc_type,const char* domain=NULL,const char* host_ip = NULL)=0;

    //获取本系统的服务,如果有masterip取masterip的服务,没有则取本机的服务
    virtual ACE_INT32 GetLocalSysSvcsByType(std::vector<ServiceInfo> &svc_array, 
      const char *svc_type)=0;

    //根据主机名获取
    virtual ACE_INT32 GetServicesByTypeH(std::vector<ServiceInfo> &svc_array, 
      const char *svc_type,const char* domain=NULL,const char* host_name = NULL)=0;

      /*获取Service Info相关接口*/
    //GetCurrentServiceInfo:获取本服务的Service Info，返回到svcinfo中
    virtual ACE_INT32 GetCurrentServiceInfo(ServiceInfo &svcinfo)=0;

    //GetServiceInfo:获取指定主机、指定服务的Service Info，host_ip不填表示本机，返回到svcinfo中
    //virtual ACE_INT32 GetServiceInfo(ServiceInfo &svcinfo,
    //                         const char *svcname, const char *host_ip = NULL)=0;

    //GetServiceInfo:获取指定ServiceKey的ServiceInfo，返回到svcinfo中
    virtual ACE_INT32 GetServiceInfo(ServiceInfo &svcinfo,
                             const std::string &svcKey)=0;

    //GetServicesAll:获取所有主机上所有服务的Service Info放入svc_array，返回service数量
    //    ACE_INT32 GetServicesAll(std::vector<ServiceInfo> &svc_array);

    //GetServicesAll:获取所有主机上所有服务的Service Info的MAP
    //const ServiceInfoMap &GetServicesAll(); 修改成如下接口，以便多线程并发控制
    virtual ACE_INT32 GetServicesAll(std::vector<ServiceInfo> &svc_array)=0;

    //获取远程daem在本地的db中
//    virtual ACE_INT32 GetRemoteDaemInLocalDB(std::vector<ServiceInfo> &svc_array)=0;

    //GetServicesByHost:获取指定主机上所有服务的Service Info放入svc_array，host_ip不填表示本机，返回service数量
    virtual ACE_INT32 GetServicesByHost(std::vector<ServiceInfo> &svc_array, const char *host_ip = NULL)=0;

    //GetServicesByHostName:获取指定主机上所有服务的Service Info放入svc_array，aHostName 不填表示本机，返回service数量
    virtual ACE_INT32 GetServicesByHostName(std::vector<ServiceInfo> &svc_array, const char *aHostName = NULL)=0;

    //获取local domain名称
    virtual const std::string& GetLocalDomain() = 0;

    virtual const std::string& OmIP() = 0;
    virtual const std::string& MedIP() = 0;
    virtual const std::string& MasterIP() = 0;
    virtual const std::string& ServiceMode() = 0;
    virtual const std::string& VeritasMode() = 0;
    //注册服务信息变更处理器，当服务信息发生变更时，会调用注册了的处理函数
    virtual ACE_INT32 RegistServiceChangeHandler(ServiceInfoChangeHandler *phandler, void *parent)=0;

    //注销服务信息变更处理器
    virtual ACE_INT32 UnregistServiceChangeHandler(ServiceInfoChangeHandler *phandler)=0;

    //检查本机的服务是否有变化，并调用相应的handler
    virtual ACE_INT32 CheckChanged()=0;

    //更新一台主机ServiceInfo,然后检查是否有变化，并调用相应的handler
    virtual ACE_INT32 UpdateServiceInfosByHost(std::string host_ip,
        std::vector<ServiceInfo> svcs_ter) = 0;

    //更新一台主机ServiceInfo,然后检查是否有变化，不调用相应的handler
    virtual ACE_INT32 UpdateServiceInfosByHostNameA(std::string host_name,
      std::vector<ServiceInfo> svcs_ter) = 0;

    //更新所有ServiceInfo,然后检查是否有变化，并调用相应的handler
    virtual ACE_INT32 UpdateServiceInfos(std::vector<ServiceInfo> svcs_ter,
        ACE_INT32 version_id = 0)=0;

    //更新所有ServiceInfo,检查是否有变化，但不调用handler
    virtual ACE_INT32 UpdateServiceInfosA(std::vector<ServiceInfo> svcs_ter,
      ACE_INT32 version_id = 0)=0;

    //取得ServiceInfo的版本
    virtual ACE_INT32 GetVersion(void) = 0;

    virtual ACE_INT32 SetVersion(ACE_INT32 aVersion)=0;

    //获取主机ip
    virtual const std::string& GetMasterIP() = 0;

    //删除服务
    virtual ACE_INT32 DelSvcsByHostName(const std::string &host_name)=0;
    //根据ip删除服务
    virtual ACE_INT32 DelSvcsByIP(const std::string &aIP)=0;

    virtual ACE_INT32 GetPortOffset() const = 0;
};

}
}
}

#endif //PLATFORM_MODULES_SCA_UBP_SVC_MGR_HPP_

