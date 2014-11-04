/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:      service_info.hpp
Author:        ZhongWei
Created:       2013/01/05 17/18
Description:   Define ServiceInfo
*********************************************************************/

#ifndef  PLATFORM_MODULES_SCA_SERVICEINFO_HPP_
#define  PLATFORM_MODULES_SCA_SERVICEINFO_HPP_

#include <vector>
#include <string>
#include "ace/Basic_Types.h"
#include "svc_mgr_def.hpp"


namespace ubp
{
namespace platform
{
namespace svcmgr
{
class SVCMGR_IMPORT_EXPORT ServiceType
{
  public:
    ServiceType();

    ServiceType(
      const std::string &svc_type,
      const std::string &default_name,
      ACE_INT32 rpn_port,    //TODO::to be removed
      ACE_INT32 pub_port,
      ACE_INT32 pair_port, //TODO::set to dealport
      ACE_INT32 ip_type=0 //0:om;1:med
      );

    virtual ~ServiceType();

  public:
    std::string svc_type_;
    std::string default_name_;
    ACE_INT32 rpn_port_;
    ACE_INT32 pub_port_;
    ACE_INT32 pair_port_;
    ACE_INT32 ip_type_;
};

class SVCMGR_IMPORT_EXPORT ServiceInfo
{
  public:
    ServiceInfo();

    ServiceInfo(ACE_INT32 node_id,
                const std::string &host_ip,
                const std::string &svc_name,
                const std::string &svc_type,
                ACE_INT32 rpn_port,
                ACE_INT32 pub_port,
                ACE_INT32 pair_port,
                const std::string &core,
                const std::string& domain,
                const std::string &hostname);

    ServiceInfo(const std::string &host_ip,
        const std::string &svc_name,
        const std::string &svc_type,
        ACE_INT32 pub_port,
        ACE_INT32 deal_port,
        const std::string &core,
        const std::string &hostname);

    //编译器自动生成了拷贝构造函数和赋值函数
    //ServiceInfo(const ServiceInfo &service_info);
    //ServiceInfo& operator=(const ServiceInfo& svcinfo); //赋值操作

    virtual ~ServiceInfo();

    const std::string &GetServiceKey(void) const;

    bool operator==(const ServiceInfo &svcinfo) const;//对比操作

    inline void Copy(const std::string& ip,const ServiceType& svctype); //从service type构造

    //void Print();

    std::string ToString();

  public:
    ACE_INT32 node_id_;     //only used in db mode
    std::string host_ip_;
    std::string svc_name_;
    std::string svc_type_;
    std::string svc_key_;
    ACE_INT32 rpn_port_;
    ACE_INT32 pub_port_;
    ACE_INT32 pair_port_;
    std::string core_;      //绑定服务进程到指定的CPU核
    std::string domain_;    //服务所属的domain
    std::string hostname_;  //服务所属的hostname
};
typedef std::vector<std::string> ServiceKeySet;


}
}
}

#endif //PLATFORM_MODULES_SCA_SERVICEINFO_HPP_

