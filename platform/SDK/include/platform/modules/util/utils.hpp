/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:      utils.hpp
Author:        ZhongWei
Created:       2012/12/31 10/22
Description:   Utils support
*********************************************************************/

#ifndef UBP_PLATFORM_UTIL_UTILS_HPP_
#define UBP_PLATFORM_UTIL_UTILS_HPP_

#include <string>
#include <list>
#include <vector>
#include <time.h>
#include "ace/Basic_Types.h"

#include "platform/modules/util/no_copy.hpp"
#include "platform/modules/util/platform_util_def.hpp"

//#include "platform/modules/dao/dao_assistant.hpp"
//#include "ubp_svcmgr_svc_info-odb.hxx"

//using namespace ubp::platform::dao;

namespace ubp
{
namespace platform
{
namespace util
{

typedef std::vector<std::string> StringList;

class UBP_PLATFORM_UTIL_IMPORT_EXPORT Utils: private NonCopyable
{
  public:
  	
  	static std::string ReplaceAllDistinct(const std::string& str, const std::string old_value, const std::string new_value);
    //Split "text" with delimiter to a string array(into tokens)
    static void Split(const std::string &text, const std::string &delimiter,
                      std::list<std::string> &tokens);

    static void Split(const std::string &text, const std::string &delimiter,
                      std::vector<std::string> &tokens);

    static void SplitB(const std::string &text, const std::string &delimiter, std::vector<std::string> &tokens);
    //对time_t 类型的时间格式化为可读
    static void TimeFormat(const time_t &source, std::string &dest);

    /*判断指定IP是否是本机上的IP*/
    static bool IsLocalIP(const std::string &ip);

    /*获取本机上的所有IP地址，返回IP地址的个数*/
    static const std::vector<std::string> &GetLocalIP();

    /*检查文件是否存在*/
    static bool FileExist(const std::string &fullFileName);

    /*创建文件目录*/
    static bool MkDir(const std::string &path);

    /*删除文件*/
	static bool DeleteFile(const std::string &path);

    /*删除目录*/
	static bool DeleteDir(const std::string &path);

    /*取得目录大小*/
	static unsigned int DirSize(const std::string &path);

    /*判断是否为有效目录*/
    static bool Is_Dir(const std::string &path);

    /*获取指定路径下指定文件类型的全文件名*/
    static std::string GetFullFileName(const std::string &filePath
                                       , const char *suffix = NULL);

    //获取UBP的安装路径
    static std::string GetUBPRootPath();

    //获取指定目录下的文件名称列表，可设置文件名称的过滤条件(待优化支持正则)
    static void ListFile(const std::string &filePath,
                         std::vector<std::string> &files,
                         const std::string &filter = "");

    //重命名
    static bool Rename(const std::string &aSrcName,const std::string &aDestName);

    //文件大小
    static bool GetFileSize(const std::string &aName, unsigned long &aSize);

    //是否启动vargland内存检测
    static bool IsCheckMemory();

    static bool Ping(const std::string& peerIp,ACE_UINT32 retry=3);
    static ACE_UINT64 GetTickCount();
    static bool IsNameExistsWithPid(const std::string &aName, ACE_INT32 aPid);
    static std::string GetLocalHostName();
    //static void PrintTabData(const vec_table_data &recordset);
    static bool IsStringNull(const std::string& orgString);
    static std::string Int2Str(int a);
    static int Str2Int(const std::string &a);
    static int TrimLeft(std::string& orgString);
    static int TrimRight(std::string& orgString);
    static int TrimLeftRight(std::string& orgString);
    static bool splitteStringEx(const std::string &strToSplitte, const char separator, StringList & vecResult);
    static std::string GetCurTime();
    
    //DES加解密
    static int encryptStr ( unsigned char key[8], unsigned char* data, int blocks = 1 );
    static int decryptStr ( unsigned char key[8], unsigned char* data, int blocks = 1 );
private:
    /*获取本机上的所有IP地址，返回IP地址的个数*/
    static int LoadLocalIP(std::vector<std::string> &local_ips);
    static std::vector<std::string> local_ips_;
};

//释放指针对象
#define UBP_RELEASE_PTR(OBJ_POINTER) \
    do { if(OBJ_POINTER != NULL) { \
    delete OBJ_POINTER; \
    OBJ_POINTER = NULL;}  \
    } while (0)

}//namespace util
}//namespace platform
}//namespace ubp

#endif // UBP_PLATFORM_UTIL_UTILS_HPP_