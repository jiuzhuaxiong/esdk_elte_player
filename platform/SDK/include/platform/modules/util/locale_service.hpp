/********************************************************************
  Copyright 2012,TD-Tech. Co., Ltd.
  Filename:    locale_service.hpp
  Author:      Xu Bingbing
  Created:     2013/05/21 15:53
  Description:

*********************************************************************/
#ifndef    UBP_PLATFORM_LOCALE_SERVICE_HPP_
#define    UBP_PLATFORM_LOCALE_SERVICE_HPP_

#include "platform/modules/util/locale_def.hpp"
#include <stdio.h>
#include <locale.h>
#include <libintl.h>
#include <string>
/************************************************************************/
/* 实现LOCALE功能                                 */
/************************************************************************/
namespace ubp
{
namespace platform
{
namespace util
{
const std::string LOCALE_ID_ZH_CN = "zh_CN";
const std::string LOCALE_ID_EN = "en";
const std::string LOCALE_STR_WIN_ZH_CN = "Chinese_People's Republic of China.936";
const std::string LOCALE_STR_LINUX_ZH_CN = "zh_CN.utf8";
const std::string LOCALE_UBP = "ubp";
class UBP_LOCALE_IMPORT_EXPORT LocaleService
{
public:
    LocaleService();
    static int Init(const std::string &module);
	static const std::string getCurrentLocale();

    virtual ~LocaleService();




private:


    std::string module_;


};

}//namespace util
}//namespace platform
}//namespace ubp

#endif // UBP_PLATFORM_LOCALE_SERVICE_HPP_