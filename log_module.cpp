/**
* @file         ldlidar_logger.cpp
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
#include "log_module.h"

#include <time.h>
#include <string.h>

#ifndef LINUX
#include <comutil.h>  
#pragma comment(lib, "comsuppw.lib")
#else
#include <stdlib.h>
#endif

//使用vswprintf会出现奔溃的情况如果，传入数据大于 VA_PARAMETER_MAX 就会出现崩溃
#define  VA_PARAMETER_MAX  1024 * 2

LogModule* LogModule::s_pLogModule = NULL;


LogModule* LogModule::getInstance(__in const char* fileName, __in const char* funcName, __in int lineNo,LogLevel level,ILogRealization*plog) {
	if (s_pLogModule == NULL) {
		s_pLogModule = new LogModule();
	}
	s_pLogModule->m_logInfo.strFileName = fileName;
	s_pLogModule->m_logInfo.strFuncName = funcName;
	s_pLogModule->m_logInfo.nLineNo = lineNo;
	s_pLogModule->m_logInfo.Loglevel = level;
	
	if (plog != NULL) {
		s_pLogModule->m_pRealization->free();
		s_pLogModule->m_pRealization = plog;
	}
	return s_pLogModule;
}

LogModule::LogModule() {
	m_logInfo.nLineNo = -1;
	m_logInfo.strFileName = "";
	m_logInfo.strFuncName = "";
#ifndef LINUX
	m_pRealization = new LogOutputString();
#else
	m_pRealization = new LogPrint();
#endif
	initLock();
}

LogModule::~LogModule() {
	realseLock();
}

void LogModule::LogPrintA(const char* format,...) {
	lock();
	if (m_pRealization) {
		std::string strTemp;
		// manufacture
		strTemp.append("[ldrobot]");
		//LogLevel
		strTemp.append(getLevelValue(m_logInfo.Loglevel));
		//时间
		strTemp.append(getFormatValue(getCurrentTime()));
		//文件名称
		strTemp.append(getFormatValue(m_logInfo.strFileName));
		strTemp.append(getFormatValue(m_logInfo.strFuncName));
		//行号
		strTemp.append(getFormatValue(m_logInfo.nLineNo));

		va_list ptr;
		va_start(ptr, format);
		char cValue[VA_PARAMETER_MAX] = {0};
		vsnprintf(cValue,sizeof(cValue),format,ptr);
		va_end(ptr);

		strTemp.append(getFormatValue(cValue));

		m_pRealization->LogPrintA(strTemp.c_str());
	}
	unlock();
}

void LogModule::initLock() {
#ifndef LINUX
	InitializeCriticalSection(&m_Mutex);
#else
  pthread_mutex_init(&m_Mutex,NULL);
#endif
}

void LogModule::realseLock() {
#ifndef LINUX
	DeleteCriticalSection(&m_Mutex);
#else
	pthread_mutex_unlock(&m_Mutex);
#endif
}

void LogModule::lock() {
#ifndef LINUX
	EnterCriticalSection(&m_Mutex);
#else
	pthread_mutex_lock(&m_Mutex);
#endif
}

void LogModule::unlock() {
#ifndef LINUX
	LeaveCriticalSection(&m_Mutex);
#else
	pthread_mutex_unlock(&m_Mutex);
#endif
}

std::string LogModule::getCurrentTime() {
	std::string currTime;
	//Current date/time based on current time
	time_t now = time(0); 
	// Convert current time to string
	currTime.assign(ctime(&now));
	// Last charactor of currentTime is "\n", so remove it
	std::string currentTime = currTime.substr(0, currTime.size()-1);
	return currentTime;
}

std::string LogModule::getFormatValue(std::string strValue) {
	std::string strTemp;
	strTemp.append("[");
	strTemp.append(strValue);
	strTemp.append("]");
	return strTemp;
}

std::string LogModule::getFormatValue(int nValue) {
	std::string strTemp;
	strTemp.append("[");
	char cValue[16];
	sprintf(cValue,"%d",nValue);
	strTemp.append(cValue);
	strTemp.append("]");
	return strTemp;
}

std::string  LogModule::getLevelValue(int level){
	std::string tmp;
	switch (level) {
	case DEBUG_LEVEL:
		tmp = "DEBUG";
		break;
	case WARNING_LEVEL:
		tmp = "WARNING";
		break;
	case ERROR_LEVEL:
		tmp = "ERROR";
		break;
	case INFO_LEVEL:
		tmp = "INFO";
		break;
	default:
		tmp = "UnKnown";
		break;
	}
	std::string strTemp;
	strTemp.append("[");
	strTemp.append(tmp);
	strTemp.append("]");
	return strTemp;
}

std::string LogModule::ws2s(const std::wstring& ws) {
	std::string result = "";
#ifndef LINUX
	_bstr_t t = ws.c_str();  
	char* pchar = (char*)t;  
	result = pchar;  
#else
	long  wslen = ws.length();
	char* p = new char[wslen + 1];
	if (!p) {
		return result;
	}
	memset(p,0,sizeof(p));
	int nRet = wcstombs(p,ws.c_str(),wslen);
	result = p;
	if (nRet == -1) {
		result = "";
	}

	if (p) {
		delete[] p;
	}
#endif
	return result;  
}

std::wstring LogModule::s2ws(const std::string& s) {
	std::wstring result = s2ws("");
#ifndef LINUX
	_bstr_t t = s.c_str();  
	wchar_t* pwchar = (wchar_t*)t;  
	result = pwchar;  
#else
	long  slen = s.length();
	wchar_t* p = new wchar_t[slen + 1];
	if (!p) {
		return result;
	}
	memset(p,0,sizeof(p));
	int nRet = mbstowcs(p,s.c_str(),slen);
	result = p;
	if (nRet == -1) {
		result = s2ws("");
	}

	if (p) {
		delete[] p;
	}
#endif
	return result; 
}

void LogPrint::Initializion(const char* path) {
	return ;
}

void LogPrint::free(ILogRealization *pLog) {
	LogPrint* pOutput = static_cast<LogPrint*>(pLog);
	if (pOutput != NULL) {
		delete pOutput;
	}
}

void LogPrint::LogPrintA(const char* str) {
#ifdef ENABLE_CONSOLE_LOG_OUT
	printf("%s\r\n", str);
#else
	FILE *fp = fopen(LOGFILEPATH,"a");
	if(!fp) {
		printf("%s open filed!\n", LOGFILEPATH);
		return ;
	}
	printf_s(fp,str);
	printf_s(fp,"\r\n");
	fclose(fp);
#endif
}

/********************* (C) COPYRIGHT SHENZHEN LDROBOT CO., LTD *******END OF FILE ********/