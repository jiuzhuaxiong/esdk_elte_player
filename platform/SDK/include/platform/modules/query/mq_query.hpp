/********************************************************************
  Copyright 2012,TD-Tech. Co., Ltd.
  Filename:    mq_query.hpp
  Author:      Wu Gang
  Created:     2013/01/9 17:11
  Description:

*********************************************************************/

#ifndef UBP_PLATFORM_QUERY_HPP_
#define UBP_PLATFORM_QUERY_HPP_

#include <string>
#include "ace/Basic_Types.h"

#include "platform/modules/mq/mq_context_itf.hpp"
#include "mq_query_def.hpp"

static const ACE_UINT32 BATCH_QUERY_MAX_COUNT = 1000;

namespace ubp
{
namespace platform
{
namespace query
{

enum QueryType
{
  QUERY_ALL = 1,
  QUERY_CONDITION
};

class UBP_MQ_QUERY_IMPORT_EXPORT QueryRequest
{
  public:

    QueryRequest(const std::string& moc,
                 const std::string& resultMsgId,
                 const std::string& cdn,
                 ACE_UINT32 checkpoint,
                 ACE_UINT32 limit);

    const std::string &MocName() const;

    void MocName(const std::string &val);

    const std::string &ResultMsgId() const;

    void ResultMsgId(const std::string &val);

    const std::string &Condition() const;

    void Condition(const std::string &val);

    ACE_UINT32 Checkpoint() const;

    void Checkpoint(ACE_UINT32 val);

    ACE_UINT32 Limit() const ;

    void Limit(ACE_UINT32 val);

  private:
    std::string mocName_;  //查询对象的MOC名称（name）.PTTUser
    std::string resultMsgId_;  //查询结果对象的消息ID，例如:ubp.cm.PTTUserList
    std::string condition_;
    ACE_UINT32 checkpoint_;
    ACE_UINT32 limit_;
};

class UBP_MQ_QUERY_IMPORT_EXPORT MqQuery
{
  public:
    MqQuery();
    ~MqQuery();

    static ACE_INT32 ClearTable(const string& mocname);
    ACE_INT32 QueryMO(const QueryRequest *req, IMessage **pQueryRsp);
    ACE_INT32 AddMO(const IMessage* mo);
    ACE_INT32 ModMO(const IMessage* mo);
    ACE_INT32 DelMO(const IMessage* mo);
	ACE_INT32 BatchAddMO(const IMessage *mo);
	ACE_INT32 BatchModMO(const IMessage *mo);
	ACE_INT32 BatchDelMO(const IMessage *mo);

  private:
  	ACE_INT32 CreateAddSQL(const IMessage *mo, string& sql);
	ACE_INT32 CreateModSQL(const IMessage *mo, string& sql);
	ACE_INT32 CreateDelSQL(const IMessage *mo, string& sql);
    std::string CreateQuerySQL(const std::string& mocname,
                               const std::string &condition, 
                               ACE_UINT32 limit,
                               QueryType queryType, 
                               const ACE_UINT32 checkpoint=0);
	std::string FormatSQLStr(const std::string& str);
};

}//namespace query
}//namespace platform
}//namespace ubp

#endif // UBP_PLATFORM_QUERY_HPP_