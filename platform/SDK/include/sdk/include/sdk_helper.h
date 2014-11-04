#ifndef SDK_HELPER_H
#define SDK_HELPER_H

#include "sdk_export.h"
#include "platform/modules/timer/ubp_timer.hpp"
#include "uiparameter.h"

using namespace ubp::platform::timer;
class ResourceInfo;

class SDK_IMPORT_EXPORT SDK_Helper {
public:
    // Change Sip UA
    static void change_sip_ua(const char * sipua);
	    
    static void clean_invalid_reg();
    
    static int checkDcPriority(int , int);

	    //异步调用invoke Operation
    static int scheduleAsynchOperation(ResourceInfo *res_info, int op_type, void* para=0);
    //同步调用invoke Operation
    static int execsynchOperation(ResourceInfo *res_info, int op_type, void* para=0);

    static VideoStatistics_t* getVideoStatistics(MSISDN resid);

    static ubp::platform::timer::TimerDispatcher* getTimerDispatcher();

	static int getTaskId(MSISDN physicalResid);

	static void setResource(std::string resource);

	static int getCUrrentListener(bool isPTTtype);
};

#endif // SDK_HELPER_H
