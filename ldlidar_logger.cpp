/**
* @file         ldlidar_logger.cpp
* @author       LDRobot (support@ldrobot.com)
* @brief         
* @version      0.1
* @date         2022.08.10
* @note          
* @copyright    Copyright (c) 2022  SHENZHEN LDROBOT CO., LTD. All rights reserved.
**/

#include "ldlidar_logger.h"

#include <mutex>
#include <functional>
#include <string>

#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

#include <stdarg.h>
#define __in

namespace ldlidar {

std::mutex mutex_lock1_;
std::mutex mutex_lock2_;

std::string GetCurrentTime() {
	std::string currTime;
	//Current date/time based on current time
	time_t now = time(0); 
	// Convert current time to string
	currTime.assign(ctime(&now));

	// Last charactor of currentTime is "\n", so remove it
	std::string currentTime = currTime.substr(0, currTime.size()-1);
	return currentTime;
}

void LoggerOutputToConsole(ulog_level_t severity, char *msg) {
  std::lock_guard<std::mutex> lg(mutex_lock1_);
  printf("[ldrobot][%s][%s]:%s\n",
         GetCurrentTime().c_str(),
         ulog_level_name(severity),
         msg);
}

void LoggerOutputToFile(ulog_level_t severity, char *msg) {
  std::lock_guard<std::mutex> lg(mutex_lock2_);
  FILE *fp = fopen(LDLIDAR_SDK_LOG_FILE_OUTPUT_PATH, "a");
  if (fp == NULL) {
    printf("open log file:%s is error,errno:%d\n", LDLIDAR_SDK_LOG_FILE_OUTPUT_PATH, errno);
    return;
  }
  fprintf(fp, "[ldrobot][%s][%s]:%s\n",
         GetCurrentTime().c_str(),
         ulog_level_name(severity),
         msg);
  fclose(fp);
}

bool LdLidarLogger::is_subscrible_flag_ = false;

LdLidarLogger::LdLidarLogger() {
  
}

LdLidarLogger::~LdLidarLogger() {
  
}

void LdLidarLogger::Subscribe(void) {
  if (is_subscrible_flag_) {
    return;
  }
  ULOG_INIT();
#if (ENABLE_LOG_TO_CONSOLE)
  ULOG_SUBSCRIBE(LoggerOutputToConsole , ULOG_DEBUG_LEVEL);
#endif
#if (ENABLE_LOG_TO_FILE)
  ULOG_SUBSCRIBE(LoggerOutputToFile, ULOG_INFO_LEVEL);
#endif
  is_subscrible_flag_ = true;
  
  return;
}

void LdLidarLogger::UnSubscribe(void) {
  if (!is_subscrible_flag_) {
    return;
  }
#if (ENABLE_LOG_TO_CONSOLE)
  ULOG_UNSUBSCRIBE(LoggerOutputToConsole);
#endif
#if (ENABLE_LOG_TO_FILE)
  ULOG_UNSUBSCRIBE(LoggerOutputToFile); 
#endif
  is_subscrible_flag_ = false;
  return;
}

void LdLidarLogger::Test(void) {
  int arg = 42;
  // ULOG_DEBUG("arg=%d", arg);
  // LD_DEBUG("arg=%d", arg);
  // ULOG_INFO("arg=%d", arg);
  // ULOG_WARNING("arg=%d", arg);  
  // ULOG_ERROR("arg=%d", arg);
  // ULOG_CRITICAL("arg=%d", arg);
  // ULOG_ALWAYS("arg=%d", arg);
  LD_LOG_DEBUG("arg=%d", arg);
  LD_LOG_ERROR("arg=%d", arg);
  LD_LOG_INFO("arg=%d", arg);
  LD_LOG_WARNING("arg=%d", arg);
}

}
/********************* (C) COPYRIGHT SHENZHEN LDROBOT CO., LTD *******END OF FILE ********/
