/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:      dao_common.hpp
Author:        XiaoLongguang
Created:       2012/11/24 09:01
Description:
*********************************************************************/

#ifndef UBP_PLATFORM_MODULES_DAO_DAO_COMMON_HPP_
#define UBP_PLATFORM_MODULES_DAO_DAO_COMMON_HPP_

#include "platform/modules/trace/ubp_trace.hpp"
/* 定义此宏是为了解决WINDOWS平台单实例类对象在dll和exe中并非同一实例的bug */
/* dll中需要export，使用时需要import */
#ifdef WIN32
#ifdef DAO_EXPORT
#define DAO_IMPORT_EXPORT __declspec(dllexport)
#else//NOT DAO_EXPORT
#define DAO_IMPORT_EXPORT __declspec(dllimport)
#endif//DAO_EXPORT
#else//NOT WIN32
#define DAO_IMPORT_EXPORT
#endif//WIN32

#define DAO_FUN_TRACE(FUNC) UBP_FUNC_TRACE("PLATFORM.DAO",FUNC) 
#define DAO_FUN_INFO(FUNC) UBP_FUNC_INFO("PLATFORM.DAO",FUNC)
#define UBP_DAO_DEBUG(LOG) UBP_LOGGER_DEBUG("PLATFORM.DAO", LOG)
#define UBP_DAO_INFO(LOG) UBP_LOGGER_INFO("PLATFORM.DAO", LOG)
#define UBP_DAO_WARN(LOG) UBP_LOGGER_WARN("PLATFORM.DAO", LOG)
#define UBP_DAO_ERROR(LOG) UBP_LOGGER_ERROR("PLATFORM.DAO", LOG)
#define UBP_DAO_FATAL(LOG) UBP_LOGGER_FATAL("PLATFORM.DAO", LOG)

#define DAO_CHECK_CONDITION_RETURN(CONDITION,ERRMSG) \
    CHECK_CONDITION_RETURN(UBP_DAO_ERROR,CONDITION,ERRMSG)

#define DAO_CHECK_CONDITION_RETURN_FAIL(CONDITION,ERRMSG) \
    CHECK_CONDITION_RETURN_FAIL(UBP_DAO_ERROR,CONDITION,ERRMSG)

#define DAO_CHECK_CONDITION_RETURN_ERRCODE(CONDITION,ERROR_CODE) \
    CHECK_CONDITION_RETURN_ERRCODE(UBP_DAO_ERROR,CONDITION,ERROR_CODE)

#define DAO_CHECK_CONDITION_RETURN_NULL(CONDITION,ERRMSG) \
    CHECK_CONDITION_RETURN_NULL(UBP_DAO_ERROR,CONDITION,ERRMSG)

#define DAO_CHECK_VAL_RETURN(CHECK_VAL,ERRMSG) \
    CHECK_VAL_RETURN(UBP_DAO_ERROR,CHECK_VAL,ERRMSG)

#define DAO_CHECK_VAL_RETURN_FAIL(CHECK_VAL,ERRMSG)\
    CHECK_VAL_RETURN_FAIL(UBP_DAO_ERROR,CHECK_VAL,ERRMSG)

#define DAO_CHECK_VAL_RETURN_NULL(CHECK_VAL,ERRMSG) \
    CHECK_VAL_RETURN_NULL(UBP_DAO_ERROR,CHECK_VAL,ERRMSG)

#define DAO_CHECK_VAL_RETURN_ERRCODE(CHECK_VAL,ERRMSG) \
    CHECK_VAL_RETURN_ERRCODE(UBP_DAO_ERROR,CHECK_VAL,ERRMSG)

#define DAO_CHECK_NULL_RETURN(PTR,ERRMSG) \
    CHECK_NULL_RETURN(UBP_DAO_ERROR,PTR,ERRMSG)

#define DAO_CHECK_NULL_RETURN_FAIL(PTR,ERRMSG) \
    CHECK_NULL_RETURN_FAIL(UBP_DAO_ERROR,PTR,ERRMSG)

#define DAO_CHECK_NULL_RETURN_NULL(PTR,ERRMSG) \
    CHECK_NULL_RETURN_NULL(UBP_DAO_ERROR,PTR,ERRMSG)

#define DAO_CHECK_NULL_RETURN_ERRCODE(PTR,ERROR_CODE) \
    CHECK_NULL_RETURN_ERRCODE(UBP_DAO_ERROR,PTR,ERROR_CODE)

//todo:接口返回具体的错误码
#define UBP_DAO_SUCCESS 0
#define UBP_DAO_FAIL -1
#define UBP_DAO_NO_RES 1

#define UBP_DAO_NULL_PTR -2          //null_pointer--"NULL pointer"

#define UBP_DAO_IN_TRANS -3          //already_in_transaction--"transaction already in progress in this thread"
#define UBP_DAO_NOTIN_TRANS -4       //not_in_transaction--"operation can only be performed in transaction"
#define UBP_DAO_TRANS_FIN -5         //transaction_already_finalized--"transaction already committed or rolled back"

#define UBP_DAO_IN_SESS -6           //already_in_session--"session already in effect in this thread"
#define UBP_DAO_NOTIN_SESS -7        //not_in_session--"session not in effect in this thread"
#define UBP_DAO_SESS_REQ -8          //session_required--"session required to load this object relationship"

#define UBP_DAO_RECOVERABLE -9       //recoverable--
#define UBP_DAO_DEADLOCK -10         //deadlock--"transaction aborted due to deadlock"
#define UBP_DAO_CON_LOST -11         //connection_lost--"connection to database lost"
#define UBP_DAO_TIMEOUT -12          //timeout--"database operation timeout"
#define UBP_DAO_OBJ_NOTEXIST -13     //object_not_persistent--"object not persistent"
#define UBP_DAO_OBJ_EXIST -14        //object_already_persistent--"object already persistent"
#define UBP_DAO_OBJ_CHANGED -15      //object_changed--"object changed concurrently"
#define UBP_DAO_RES_NOTCACH -16      //result_not_cached--"query result is not cached"
#define UBP_DAO_DATA_EXC -17         //database_exception

#define UBP_DAO_ABS_CLASS -18        //abstract_class--"database operation on instance of abstract class"
#define UBP_DAO_NOTYPE_INFO -19      //no_type_info--"no type information"

#define UBP_DAO_UNKNOWN_SCHEMA -20   //unknown_schema--"unknown database schema

/*
//MySQL返回的列字段类型
enum enum_field_types
{
  MYSQL_TYPE_DECIMAL, 
  MYSQL_TYPE_TINY,
  MYSQL_TYPE_SHORT,
  MYSQL_TYPE_LONG,
  MYSQL_TYPE_FLOAT,
  MYSQL_TYPE_DOUBLE,
  MYSQL_TYPE_NULL,
  MYSQL_TYPE_TIMESTAMP,
  MYSQL_TYPE_LONGLONG,
  MYSQL_TYPE_INT24,
  MYSQL_TYPE_DATE,
  MYSQL_TYPE_TIME,
  MYSQL_TYPE_DATETIME,
  MYSQL_TYPE_YEAR,
  MYSQL_TYPE_NEWDATE,
  MYSQL_TYPE_VARCHAR,
  MYSQL_TYPE_BIT,
  MYSQL_TYPE_NEWDECIMAL = 246,
  MYSQL_TYPE_ENUM = 247,
  MYSQL_TYPE_SET = 248,
  MYSQL_TYPE_TINY_BLOB = 249,
  MYSQL_TYPE_MEDIUM_BLOB = 250,
  MYSQL_TYPE_LONG_BLOB = 251,
  MYSQL_TYPE_BLOB = 252,
  MYSQL_TYPE_VAR_STRING = 253,
  MYSQL_TYPE_STRING = 254,
  MYSQL_TYPE_GEOMETRY = 255
};
*/

#endif  //UBP_PLATFORM_MODULES_DAO_DAO_COMMON_HPP_
