#include "StdAfx.h"
#include "eLTE_Log.h"
#include "eLTE_Tool.h"


eLTE_Log* eLTE_Log::m_Instance = NULL;
int eLTE_Log::m_LogLevel = 0;
size_t eLTE_Log::m_logSize = 0;
unsigned int eLTE_Log::m_logCount = 0;
std::string eLTE_Log::m_logPath = "";
std::string eLTE_Log::m_defaultPath = "";

eLTE_Log::eLTE_Log()
{

}

eLTE_Log::~eLTE_Log()
{

}

void eLTE_Log::InitParam(int logLevel, size_t logSize, unsigned int logCount, const std::string& logPath)
{
	m_LogLevel = logLevel;
	m_logSize = logSize;
	m_logCount = logCount;
	m_logPath = logPath;
	m_defaultPath = logPath;
}

eLTE_RET eLTE_Log::SetLogPath(const std::string& logPath)
{
	if (NULL != m_Instance)
	{
		// 日志已经开始，无法设置logPath
		return eLTE_FAILED;
	}
	if (logPath.rfind(".log") != logPath.size()-strlen(".log"))
	{
		// 没有日志文件名
		return eLTE_FAILED;
	}

	m_logPath = logPath;
	eLTE_Tool::RelativePathToAbsolute(m_logPath);	
	return eLTE_SUCCESS;
}

eLTE_RET eLTE_Log::SetLogLevel(int logLevel)
{
	if (NULL != m_Instance)
	{
		// 日志已经开始，无法设置logLevel
		return eLTE_FAILED;
	}
	if (DEBUG_LEVEL > logLevel || ERROR_LEVEL < logLevel)
	{
		// 日志级别不正确
		return eLTE_FAILED;
	}

	m_LogLevel = logLevel;
	return eLTE_SUCCESS;
}

log4cpp::Category& eLTE_Log::GetCategoryInstance()
{
	if(NULL == m_Instance)
	{
		m_Instance = new eLTE_Log();
		(void)m_Instance->LoadLog4cpp();
		(void)m_Instance->SetLog4cppLevel();		
		log4cpp::Category& root = log4cpp::Category::getRoot();
		root.critStream() << "==============log start============";
	}

	log4cpp::Category& root = log4cpp::Category::getRoot();
	return root;
}

void eLTE_Log::DestroyInstance()
{
	if (NULL != m_Instance)
	{
		try
		{
			log4cpp::Category& root = log4cpp::Category::getRoot();
			root.critStream() << "==============log end==============";
			log4cpp::Category::shutdown();
		}
		catch (...)
		{

		}

		delete m_Instance;
		m_Instance = NULL;
	}
}

int eLTE_Log::SetLog4cppLevel() const
{
	log4cpp::Category& root = log4cpp::Category::getRoot();
	switch (m_LogLevel)
	{
	case INFO_LEVEL:
		{
			root.setPriority(log4cpp::Priority::INFO);
			break;
		}
	case DEBUG_LEVEL:
		{
			root.setPriority(log4cpp::Priority::DEBUG);
			break;
		}
	case WARN_LEVEL:
		{
			root.setPriority(log4cpp::Priority::WARN);
			break;
		}
	case ERROR_LEVEL:
		{
			root.setPriority(log4cpp::Priority::ERROR);
			break;
		}
	default:
		{
			root.setPriority(log4cpp::Priority::INFO);
		}
	}

	return 0;
}

int eLTE_Log::LoadLog4cpp() const
{
		/*lint -save -e429*/
	log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
	if (NULL == pLayout)//lint !e774
	{
		return eLTE_FAILED;
	}
	pLayout->setConversionPattern(LOG_PATTERN);

	// Create path
	std::string onlypath = m_logPath.substr(0, m_logPath.rfind("\\")+1);
	if (!eLTE_Tool::IsExistPath(onlypath))
	{
		if (!eLTE_Tool::CreateMultipleDirectory(onlypath))
		{
			// 如果创建用户设置的目录失败，则使用配置文件里面的默认目录。
			m_logPath = m_defaultPath;
			onlypath = m_logPath.substr(0, m_logPath.rfind("\\")+1);
			if (!eLTE_Tool::CreateMultipleDirectory(onlypath))
			{
				return FALSE;
			}
		}
	}

	log4cpp::RollingFileAppender* rollfileAppender = 
		new log4cpp::RollingFileAppender("rollfileAppender", m_logPath, m_logSize, m_logCount);//logPath必须使用绝对路径
	if (NULL == rollfileAppender)//lint !e774
	{
		return eLTE_FAILED;
	}
	rollfileAppender->setLayout(pLayout);
	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.addAppender(rollfileAppender);
	return 0;
	/*lint -restore*/
}//lint !e429
