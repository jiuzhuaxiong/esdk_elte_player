/********************************************************************
filename    :    eLTE_Log.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    ��־�����ࡣ��װlog4cpp����Ҫ������־�ļ����
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_LOG_H__
#define __ELTE_OCX_LOG_H__


#include "DataType.h"
#include "log4cpp.h"

//lint -e773
//�˴��꺯�����ܼ�����
//������־���𣬴�ӡ�������
#define DEBUG_LOG() eLTE_Log::GetCategoryInstance().debugStream()  << "{" << __FUNCTION__ << "} "
#define INFO_LOG()  eLTE_Log::GetCategoryInstance().infoStream()   << "{" << __FUNCTION__ << "} "
#define WARN_LOG()  eLTE_Log::GetCategoryInstance().warnStream()   << "{" << __FUNCTION__ << "} "
#define ERROR_LOG() eLTE_Log::GetCategoryInstance().errorStream()  << "{" << __FUNCTION__ << "} "

#define EXP1(param1) #param1 << " = " << (param1)
#define EXP2(param1, param2) \
	EXP1(param1) << ", " << EXP1(param2)
#define EXP3(param1, param2, param3) \
	EXP2(param1, param2) << ", " << EXP1(param3)
#define EXP4(param1, param2, param3, param4) \
	EXP3(param1, param2, param3) << ", " << EXP1(param4)
#define EXP5(param1, param2, param3, param4, param5) \
	EXP4(param1, param2, param3, param4) << ", " << EXP1(param5)
#define EXP6(param1, param2, param3, param4, param5, param6) \
	EXP5(param1, param2, param3, param4, param5) << ", " << EXP1(param6)

//��������ӡinfo������־�����6������
#define INFO_PARAM0() INFO_LOG()
#define INFO_PARAM1(param1) \
	INFO_PARAM0() << EXP1(param1)
#define INFO_PARAM2(param1, param2) \
	INFO_PARAM0() << EXP2(param1, param2)
#define INFO_PARAM3(param1, param2, param3) \
	INFO_PARAM0() << EXP3(param1, param2, param3)
#define INFO_PARAM4(param1, param2, param3, param4) \
	INFO_PARAM0() << EXP4(param1, param2, param3, param4)
#define INFO_PARAM5(param1, param2, param3, param4, param5) \
	INFO_PARAM0() << EXP5(param1, param2, param3, param4, param5)
#define INFO_PARAM6(param1, param2, param3, param4, param5, param6) \
	INFO_PARAM0() << EXP6(param1, param2, param3, param4, param5, param6)

//��������ӡdebug������־�����6������
#define DEBUG_PARAM0() DEBUG_LOG()
#define DEBUG_PARAM1(param1) \
	DEBUG_PARAM0() << EXP1(param1)
#define DEBUG_PARAM2(param1, param2) \
	DEBUG_PARAM0() << EXP2(param1, param2)
#define DEBUG_PARAM3(param1, param2, param3) \
	DEBUG_PARAM0() << EXP3(param1, param2, param3)
#define DEBUG_PARAM4(param1, param2, param3, param4) \
	DEBUG_PARAM0() << EXP4(param1, param2, param3, param4)
#define DEBUG_PARAM5(param1, param2, param3, param4, param5) \
	DEBUG_PARAM0() << EXP5(param1, param2, param3, param4, param5)
#define DEBUG_PARAM6(param1, param2, param3, param4, param5, param6) \
	DEBUG_PARAM0() << EXP6(param1, param2, param3, param4, param5, param6)

//��������ӡerror������־�����6������
#define ERROR_PARAM0() ERROR_LOG()
#define ERROR_PARAM1(param1) \
	ERROR_PARAM0() << EXP1(param1)
#define ERROR_PARAM2(param1, param2) \
	ERROR_PARAM0() << EXP2(param1, param2)
#define ERROR_PARAM3(param1, param2, param3) \
	ERROR_PARAM0() << EXP3(param1, param2, param3)
#define ERROR_PARAM4(param1, param2, param3, param4) \
	ERROR_PARAM0() << EXP4(param1, param2, param3, param4)
#define ERROR_PARAM5(param1, param2, param3, param4, param5) \
	ERROR_PARAM0() << EXP5(param1, param2, param3, param4, param5)
#define ERROR_PARAM6(param1, param2, param3, param4, param5, param6) \
	ERROR_PARAM0() << EXP6(param1, param2, param3, param4, param5, param6)
//lint +e773


//��־��ʽ"%d���� %t�߳�id %p���ȼ� %m��Ϣ %n���з�"
#define LOG_PATTERN			"[%d][%-5t][%5p]-%m%n"

//֧�ֵ���־����
enum LOGLEVEL
{
	DEBUG_LEVEL = 0,
	INFO_LEVEL,
	WARN_LEVEL,
	ERROR_LEVEL
};

//��־��
class eLTE_Log
{
public:
	static void InitParam(int logLevel, size_t logSize, unsigned int logCount, const std::string& logPath);
	static eLTE_RET SetLogPath(const std::string& logPath);
	static eLTE_RET SetLogLevel(int logLevel);

	static log4cpp::Category& GetCategoryInstance();
	static void DestroyInstance();

private:
	eLTE_Log(void);
	~eLTE_Log(void);

private:
	int SetLog4cppLevel() const;//��ȡLog4cpp����־����
	int LoadLog4cpp() const;	//����Log4cpp

private:
	static int m_LogLevel;
	static size_t m_logSize;
	static unsigned int m_logCount;
	static std::string m_logPath;
	static std::string m_defaultPath;

	static eLTE_Log* m_Instance;
};

#endif
