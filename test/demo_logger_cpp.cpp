#include "log_module.h"

int main(int argc, char** argv) {
  LOG_INFO("1.test start","");
  LOG_DEBUG("1.I am debugger.","");
  LOG_WARN("1.dear friend, believe this is greate logger","");
  LOG_ERROR("1.test end","");

  LOG_INFO_LITE("2.test start","");
  LOG_DEBUG_LITE("2.I am debugger.","");
  LOG_WARN_LITE("2.dear friend, believe this is greate logger","");
  LOG_ERROR_LITE("2.test end","");

  LOG_INFO_PRINT("3.test start\n","");
  LOG_DEBUG_PRINT("3.I am debugger.\n","");
  
  return 0;
}
