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
	std::string curr_time;
#if 0
	//Current date/time based on current time
	time_t now = time(0); 
	// Convert current time to string
	curr_time.assign(ctime(&now));
	// Last charactor of currentTime is "\n", so remove it
	std::string current_time = curr_time.substr(0, curr_time.size()-1);
	return current_time;
#else
  char stdtime_str[50] = {0};
	time_t std_time = 0;
	struct tm* local_time = NULL;
	std_time = time(NULL);
	local_time = localtime(&std_time);
	snprintf(stdtime_str, 50, "%d-%d-%d,%d:%d:%d", 
	local_time->tm_year+1900, local_time->tm_mon+1, local_time->tm_mday,
	local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
	curr_time.assign(stdtime_str);
  return curr_time;
#endif
}

std::string GetLogFilePathName(void) {
	std::string curr_date_log_file;
  char stdtime_str[50] = {0};
	time_t std_time = 0;
	struct tm* local_time = NULL;
	std_time = time(NULL);
	local_time = localtime(&std_time);
	snprintf(stdtime_str, 50, "./log-%d-%2d-%2d-%2d.log", 
	local_time->tm_year+1900, local_time->tm_mon+1, local_time->tm_mday,
	local_time->tm_hour);
	curr_date_log_file.assign(stdtime_str);
  return curr_date_log_file;
}

void LoggerOutputToConsole(ulog_level_t severity, char *msg) {
  std::lock_guard<std::mutex> lg(mutex_lock1_);
  printf("[LD][%s][%s]:%s\n",
        GetCurrentTime().c_str(),
        ulog_level_name(severity),
        msg);
}

void LoggerOutputToFile(ulog_level_t severity, char *msg) {
  std::lock_guard<std::mutex> lg(mutex_lock2_);
  std::string ldlidar_sdk_log_file_output_path = GetLogFilePathName();
  FILE *fp = fopen(ldlidar_sdk_log_file_output_path.c_str(), "a");
  if (fp == NULL) {
    printf("open log file:%s is error,errno:%d\n",
      ldlidar_sdk_log_file_output_path.c_str() , errno);
    return;
  }
  fprintf(fp, "[LD][%s][%s]:%s\n",
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

}
/********************* (C) COPYRIGHT SHENZHEN LDROBOT CO., LTD *******END OF FILE ********/
