/**
* @file         ldlidar_logger.h
* @author       LDRobot (support@ldrobot.com)
* @brief         
* @version      0.1
* @date         2022.08.10
* @note          
* @copyright    Copyright (c) 2022  SHENZHEN LDROBOT CO., LTD. All rights reserved.
**/

#ifndef __LDLIDAR_LOGGER_H__
#define __LDLIDAR_LOGGER_H__

#include "ulog.h"

#define LDLIDAR_SDK_LOG_FILE_OUTPUT_PATH "./ldlidar-driver.log"

#define ENABLE_LOG_TO_CONSOLE (1)
#define ENABLE_LOG_TO_FILE    (1)

namespace ldlidar {

class LdLidarLogger {
public:
  LdLidarLogger();
  ~LdLidarLogger();
  static void Subscribe(void);
  static void UnSubscribe(void);

private:
  static bool is_subscrible_flag_;
};

} // namespace ldlidar 

#endif //__LDLIDAR_LOGGER_H__
/********************* (C) COPYRIGHT SHENZHEN LDROBOT CO., LTD *******END OF FILE ********/
