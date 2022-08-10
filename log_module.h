/**
* @file         ldlidar_logger.h
* @author       LDRobot (support@ldrobot.com)
* @brief         
* @version      0.1
* @date         2022.08.10
* @note          
* @copyright    Copyright (c) 2022  SHENZHEN LDROBOT CO., LTD. All rights reserved.
* Licensed under the MIT License (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License in the file LICENSE
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/
#ifndef  __LOGMODULE_H_
#define  __LOGMODULE_H_


#define LINUX

//#define ENABLE_CONSOLE_LOG_OUT

#define LOGFILEPATH "./ldlidar-driver.log"

#include <stdio.h>
#include <string>
#include <stdlib.h>

#ifndef LINUX
#include <windows.h>
#else
//#include <pthread.h>
#include <stdarg.h>
#define printf_s(fileptr,str)  (fprintf(fileptr,"%s",str))
#define __in
#endif // ??????????????????????


struct LogVersion
{
    int		nVersion;     //??????
    std::string  strDescruble; //????
};


class ILogRealization
{
public:
    virtual void Initializion(const char* path = NULL) = 0;
    virtual void LogPrintA(const char* str) = 0;
    void free(){
        free(this);
        //this = NULL;
    };
private:
    virtual void free(ILogRealization *pLog) = 0 ;
};


#define  ILOGFREE(LogRealizationClass)  virtual void free(ILogRealization* pLog)	\
{																					\
    LogRealizationClass* pRealization = static_cast<LogRealizationClass*>(pLog);    \
    if (pRealization != NULL){ delete pRealization;}								\
}

class LogPrint
    :public ILogRealization
{

public:
    virtual void Initializion(const char* path = NULL);
    virtual void free(ILogRealization *pLog);
    virtual void LogPrintA(const char* str);

};

#ifndef LINUX
class LogOutputString
    :public ILogRealization
{

public:
    virtual void Initializion(const char* path = NULL)
    {
        return ;
    }

    virtual void LogPrintA(const char* str)
    {
        OutputDebugString((LPCTSTR)str);
        OutputDebugString("\r\n");
    }

    ILOGFREE(LogOutputString)
/*
    virtual void free(ILogRealization *pLog)
    {
        LogOutputString* pOutput = static_cast<LogOutputString*>(pLog);
        if (pOutput != NULL)
        {
            delete pOutput;
        }
    }
*/
};
#endif


class LogModule
{
public:

    enum LogLevel
    {
        DEBUG_LEVEL,
        WARNING_LEVEL,
        ERROR_LEVEL,
        INFO_LEVEL
    };

    struct LOGMODULE_INFO
    {
        LogLevel	Loglevel;       //LogLevel
        std::string		strFileName;  //???????
        std::string		strFuncName;  //????????
        int			nLineNo;	  //?????
    }m_logInfo;

    ILogRealization* m_pRealization; //????????
public:
    static  LogModule* getInstance( __in const char* fileName, __in const char* funcName,__in int lineNo,LogLevel level,ILogRealization*plog = NULL );

    void LogPrintA(const char* format,...);

private:
    LogModule();

    ~LogModule();

    void initLock();

    void realseLock();

    void lock();

    void unlock();

    std::string getCurrentTime();

    std::string getFormatValue(std::string strValue);

    std::string  getFormatValue(int nValue);

    std::string  getLevelValue(int level);

    std::string ws2s(const std::wstring& ws);

    std::wstring s2ws(const std::string& s);

    static LogModule*  s_pLogModule;

#ifndef LINUX
    //??
    CRITICAL_SECTION   m_Mutex;
#else
    pthread_mutex_t    m_Mutex;
#endif


};

#define  LOG(level,format,...)   LogModule::getInstance(__FILE__, __FUNCTION__, __LINE__,level)->LogPrintA(format,__VA_ARGS__);
#define  LD_LOG_DEBUG(format,...)   LOG(LogModule::DEBUG_LEVEL,format,__VA_ARGS__)
#define  LD_LOG_INFO(format,...)    LOG(LogModule::INFO_LEVEL,format,__VA_ARGS__)
#define  LD_LOG_ERROR(format,...)   LOG(LogModule::ERROR_LEVEL,format,__VA_ARGS__)



#endif
