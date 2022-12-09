/**
* @file         loggers.h
* @author       David Hu (hmd_hubei_cn@163.com)
* @brief         
* @version      0.1
* @date         2022.08.10
* @note          
* @copyright    Copyright (c) 2022  DAVID HU  All rights reserved.
**/

#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "ulog.h"

#define ENABLE_LOG_TO_CONSOLE (1)
#define ENABLE_LOG_TO_FILE    (1)

class Loggers {
public:
  Loggers();
  ~Loggers();
  static void Subscribe(void);
  static void UnSubscribe(void);

private:
  static bool is_subscrible_flag_;
}; 

#endif //__LOGGER_H__
/********************* (C) COPYRIGHT DAVID HU *******END OF FILE ********/
