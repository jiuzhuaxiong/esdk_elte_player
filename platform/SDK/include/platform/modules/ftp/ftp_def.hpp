/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:      ftp_def.hpp
Author:        Xu Bingbing
Created:       2013/01/24 17:11
Description:
*********************************************************************/

#ifndef UBP_PLATFORM_FTP_DEF_HPP_
#define UBP_PLATFORM_FTP_DEF_HPP_

#ifdef WIN32
#ifdef UBP_FTP_EXPORT
#define UBP_FTP_IMPORT_EXPORT __declspec(dllexport)
#else//NOT UBP_FTP__EXPORT
#define UBP_FTP_IMPORT_EXPORT __declspec(dllimport)
#endif//UBP_FTP_EXPORT
#else//NOT WIN32
#define UBP_FTP_IMPORT_EXPORT
#endif//WIN32

enum  
{  
	OS_DEFAULT = 0,  
	OS_LINUX   = 1,  
	OS_WIN32   = 2,  
	OS_AIX     = 3,  
	OS_HP_UNIX = 4,  
	OS_SUNOS   = 5  
};  

#endif  //UBP_PLATFORM_FTP_CLIENT_DEF_HPP_
