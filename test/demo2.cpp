#include "log_module.h"

int main(int argc, char** argv) {
  
  LOG_A_INFO("test start","");
  LOG_A_DEBUG("I am debugger.","");
  LOG_A_WARN("dear friend, believe this is greate logger","");
  LOG_A_ERROR("test end","");

  LOG_B_INFO("test start","");
  LOG_B_DEBUG("I am debugger.","");
  LOG_B_WARN("dear friend, believe this is greate logger","");
  LOG_B_ERROR("test end","");
  
  return 0;
}
