#ifndef SERVICECONTEXTLOADER_H
#define SERVICECONTEXTLOADER_H

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
//#include "boost/shared_ptr.hpp"
#include "sdk_export.h"

#include "platform/modules/frame/module_context.hpp"

#include <memory>

using namespace ubp::platform::frame;

//typedef boost::shared_ptr<ModuleContext> ModuleContextRef;

class ServiceContextLoader
{
   friend class ACE_Unmanaged_Singleton<ServiceContextLoader, ACE_Null_Mutex>;

public:
    ServiceContextLoader();

    ~ServiceContextLoader();

    //初始化组件
    ACE_INT32 initComponents();
    //去初始化组件
    ACE_INT32 FiniComponents();

    //从daem取得service info
    ACE_INT32 getServiceInfoFromDaem(std::string& serverip);

    //获取ModuleContext
    ModuleContext* getModuleContext();

    /* 获取平台提供的Module */
    template<typename T>
    T* GetModule()
    {
        T* ptr = NULL;
        if (module_context != NULL)
        {
            ptr = module_context->ModuleRef<T>();
        }
        return ptr;
    }

private:

    //存储module_context
    ModuleContext*  module_context;

};

typedef ACE_Unmanaged_Singleton<ServiceContextLoader, ACE_Null_Mutex> ServiceContextLoader_T;

#endif // SERVICECONTEXTLOADER_H
