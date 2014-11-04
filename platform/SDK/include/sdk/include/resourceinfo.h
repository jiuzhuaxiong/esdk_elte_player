/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    ResourceInfo.h
Author:      Wu yu wei
Created:     2012/07/26 14:00
Description:
*********************************************************************/
#ifndef RESOURCEINFO_H
#define RESOURCEINFO_H

#include <string>
#include "sdk_export.h"

#define FIELD_LENG  20

typedef int MSISDN;

class SDK_IMPORT_EXPORT ResourceInfo
{
public:
    ResourceInfo(MSISDN resId);
    virtual ~ResourceInfo();
    virtual std::string datalog_str();

    void setResId(MSISDN rid);
    const MSISDN getResId();

    const char* getUserName();
    const char* getPassWord();
    const char* getServerIp();
    const char* getLocalIp();
    const char* getSipPort();

    void setUserName(const char* user);
    void setPassWord(const char* pwd);
    void setServerIp(const char* serverip);
    void setLocalIp(const char* localip);
    void setSipPort(const char* sipport);

    MSISDN resId; //用户或组ID号

private:

    char user_name[FIELD_LENG]; //用户名或组名
    char password[FIELD_LENG];//用户或组密码
    char server_ip[FIELD_LENG];//需要注册的服务端IP
    char local_ip[FIELD_LENG]; //本端IP
    char sip_port[FIELD_LENG]; //sip_port
};

//DynamicGroup动态组对应的resourceinfo
class SDK_IMPORT_EXPORT DGResourceInfo : public ResourceInfo
{
public:
    DGResourceInfo(MSISDN resId, MSISDN dcid);
    ~DGResourceInfo();
    virtual std::string datalog_str();

protected:
    MSISDN dcid;
};

//TelephoneInterconnect电话互连资源对应的resourceinfo
class SDK_IMPORT_EXPORT TIResourceInfo : public ResourceInfo
{
public:
    TIResourceInfo(MSISDN resId, std::string telNumber);
    ~TIResourceInfo();
    const char* getTeleNumber();
    virtual std::string datalog_str();
protected:
    char telNumber[20];
};

#endif // RESOURCEINFO_H
