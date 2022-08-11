#include "ldlidar_logger.h"

int main(int argc, char** argv) {
  
  ldlidar::LdLidarLogger::Subscribe();

  LD_LOG_DEBUG("hello, I am loggerv1 system.");
  LD_LOG_INFO("LOG FILE WRITE TO %s", LDLIDAR_SDK_LOG_FILE_OUTPUT_PATH);
  LD_LOG_WARNING("welcom used.");
  LD_LOG_ERROR("the loggerv1, support C++11 environment compile.");
  
  return 0;
}
