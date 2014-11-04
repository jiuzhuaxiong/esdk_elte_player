/********************************************************************
filename    :    log4cpp.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    负责log4cpp库的链接和头文件包含
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 初始版本
*********************************************************************/

#ifndef __ELTE_OCX_LOG4CPP_H__
#define __ELTE_OCX_LOG4CPP_H__


// includes & warning suppress
#pragma warning(push)
#pragma warning(disable:4244) // conversion from 'size_t' to '...', possible loss of data
#pragma warning(disable:4267) // conversion from 'size_t' to '...', possible loss of data
#pragma warning(disable:4512) // assignment operator could not be generated

#include "./log4cpp/config-win32.h"
#include "./log4cpp/Category.hh"
#include "./log4cpp/RollingFileAppender.hh"
#include "./log4cpp/OstreamAppender.hh"
#include "./log4cpp/PatternLayout.hh"

#pragma warning(pop)

// auto-link
#ifdef _DEBUG
// # define LOG4CPP_LIB_NAME "log4cppd.lib"
# define LOG4CPP_LIB_NAME "log4cpp.lib"
#else
# define LOG4CPP_LIB_NAME "log4cpp.lib"
#endif

#pragma message("log4cpp : Auto Linking to "LOG4CPP_LIB_NAME)
#pragma comment(lib, LOG4CPP_LIB_NAME)

#endif
