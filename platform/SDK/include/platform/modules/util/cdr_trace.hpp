/********************************************************************
  Copyright 2012,TD-Tech. Co., Ltd.
  Filename:    cdr_trace.hpp
  Author:      lijing
  Created:     2013/05/21 15:53
  Description:

*********************************************************************/
#ifndef    UBP_PLATFORM_CDR_TRACE_HPP_
#define    UBP_PLATFORM_CDR_TRACE_HPP_

#include <stdio.h>
#include <string>
#include <ace/Basic_Types.h>
#include "ace/Null_Mutex.h"
#include "ace/OS_NS_stdio.h"
#include "ace/Singleton.h"
#include "log4cxx/logger.h"
#include "platform/modules/util/no_copy.hpp"

#ifdef WIN32
#ifdef UBP_CDR_EXPORT
#define UBP_CDR_TRACE_IMPORT_EXPORT __declspec(dllexport)
#else//NOT UBP_CDR__EXPORT
#define UBP_CDR_TRACE_IMPORT_EXPORT __declspec(dllimport)
#endif//UBP_CDR_EXPORT
#else//NOT WIN32
#define UBP_CDR_TRACE_IMPORT_EXPORT
#endif//WIN32


namespace ubp
{
namespace platform
{
namespace util
{
#define CDR_TRACE_0(NODEID,SVCTYPE,SESSIONID,CALLER,CALLEE,GROUPID,STARTTIME,ENDTIME,RESULT,CAUSE) \
  do \
  { \
    CDRTrace::instance().Trace(NODEID,SVCTYPE,SESSIONID,CALLER,CALLEE,GROUPID,STARTTIME,ENDTIME,RESULT,CAUSE); \
  }while(0);

class UBP_CDR_TRACE_IMPORT_EXPORT CDRTrace : private ubp::platform::util::NonCopyable
{
protected:
    CDRTrace();
public:
    static CDRTrace &instance();
    
	  virtual ACE_INT32 Trace(std::string NODEID,std::string SVCTYPE, std::string SESSIONID, std::string CALLER, std::string CALLEE, std::string GROUPID, std::string STARTTIME, std::string ENDTIME, std::string RESULT,std::string CAUSE)=0;

    virtual ~CDRTrace();
private:
};

#define CDR_TRACE(NODEID,SVCTYPE,SESSIONID,CALLER,CALLEE,STARTTIME,ENDTIME,RESULT,CAUSE) \
  do \
  { \
    CDRTraceAdp::instance().Trace(NODEID,SVCTYPE,SESSIONID,CALLER,CALLEE,STARTTIME,ENDTIME,RESULT,CAUSE); \
  }while(0);

class UBP_CDR_TRACE_IMPORT_EXPORT CDRTraceAdp : private ubp::platform::util::NonCopyable
{
private:
  CDRTraceAdp();
  ACE_INT32 LoadCfg();
public:
  static CDRTraceAdp &instance();
    
	virtual ACE_INT32 Trace(std::string NODEID,std::string SVCTYPE, std::string SESSIONID, std::string CALLER, std::string CALLEE, std::string STARTTIME, std::string ENDTIME, std::string RESULT,std::string CAUSE);

  virtual ~CDRTraceAdp();
private:
  std::string cdr_path_;
  std::map<std::string, std::string> cfg_;
  ACE_Recursive_Thread_Mutex trace_mutex_;
};

//#ifdef WIN32
//#ifdef UBP_CDR_EXPORT
//#define CDR_TRACE_IMPORT_EXPORT __declspec(dllexport)
//#define CDR_TRACE_IMPORT_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) \
//  template class __declspec (dllexport) SINGLETON_TYPE<CLASS, LOCK>;
//#else
//#define CDR_TRACE_IMPORT_EXPORT __declspec(dllimport)
//#define CDR_TRACE_IMPORT_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) \
//  extern template class SINGLETON_TYPE <CLASS, LOCK>;
//#endif
//#else
//#define CDR_TRACE_IMPORT_EXPORT
//#define CDR_TRACE_IMPORT_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
//#endif

//class CDR_TRACE_IMPORT_EXPORT CDRTraceEx : private ubp::platform::util::NonCopyable
//{
//    friend class ACE_Singleton<CDRTraceEx, ACE_Null_Mutex>;
//
//  public:
//    CDRTraceEx(void);
//    virtual ~CDRTraceEx(void);
//    ACE_INT32 Init();
//    ACE_INT32 ConfLog(const std::string & aFileName);
//    //ACE_INT32 SetConsole(bool need_console);
//    //ACE_INT32 SetLevel(const char *level);
//    //ACE_INT32 SetMaxFileSize(const char *file_size = "20000KB");
//    //ACE_INT32 SetMaxBackupIndex(int max_backup_index = 20);
//
//  private:
//    std::string log_name_;
//    char env_process_name_[64];
//    char env_process_id_[64];
//};

//////////////////////////////////////////////////////////////////////////

//typedef ACE_Unmanaged_Singleton<CDRTraceEx, ACE_Null_Mutex> CDRTrace_T;
//CDR_TRACE_IMPORT_EXPORT_SINGLETON_DECLARE(
//  ACE_Unmanaged_Singleton, CDRTraceEx, ACE_Null_Mutex)

}//namespace util
}//namespace platform
}//namespace ubp

#endif // UBP_PLATFORM_CDR_TRACE_HPP_
