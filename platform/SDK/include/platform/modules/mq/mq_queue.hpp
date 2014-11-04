/********************************************************************
  Copyright 2012,TD-Tech. Co., Ltd.
  Filename:    mq_queue.hpp
  Author:      Wu Gang
  Created:     2013/11/25 13:42
  Description:

*********************************************************************/
#ifndef UBP_PLATFORM_MOUDLES_MQ_QUEUE_HPP_
#define UBP_PLATFORM_MOUDLES_MQ_QUEUE_HPP_

#include "ace/Basic_Types.h"
#include <memory>
#include <list>
#include <string>

#include "platform/modules/thread/ubp_threadpool.hpp"
#include "mq_context_itf.hpp"

namespace ubp
{
namespace platform
{
namespace mq
{

class IMessageSocket;
class MsgWorkerTask;

class MQ_IMPORT_EXPORT MsgQueue
{
  public:
    MsgQueue(IMessageContext *pContext,
             const std::string &endpoint,
             const std::string &workId);
    virtual ~MsgQueue();

    ACE_INT32 Init(MsgWorkerTask* pTask);

    ACE_INT32 Fini();

    ACE_INT32 PushMsg(void *pMsg);

  protected:
    //void RecvMsg();
    ACE_INT32 InitPusher();
    ACE_INT32 InitPullTask(MsgWorkerTask* pTask);

  private:
    IMessageSocket *pPushSocket_;
    //std::list<MsgWorkerTask *> taskList_;
    MsgWorkerTask *pTask_;
    IMessageContext *pMqContext_;
    std::string endpoint_;
    std::string workId_;
    ACE_UINT64 taskId_;
    //ACE_UINT32 maxWorkerTask_;
};

//////////////////////////////////////////////////////////////////////////
class MQ_IMPORT_EXPORT MsgWorkerTask: private ubp::platform::thread::WorkerRequest
{
    friend MsgQueue;
  public:
    MsgWorkerTask();
    ~MsgWorkerTask();
    virtual ACE_INT32 OnMessage(void *pMsg);
    virtual ACE_INT32 call(void);
    bool IsRun() const;
    void SetRun(bool val);
  protected:
    void RecvMsg();
    void *pArg_;
  private:
    IMessageSocket *pPullSocket_;
    bool run_;

};


}//mq
}//platform
}//ubp
#endif //UBP_PLATFORM_MOUDLES_MQ_QUEUE_HPP_
