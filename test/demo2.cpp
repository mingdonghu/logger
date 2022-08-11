#include "log_module.h"

int main(int argc, char** argv) {
  
  LD_LOG_INFO("test start","");
  LD_LOG_WARN("dear friend, believe this is greate logger","");
  LD_LOG_INFO("test end","");

  LDS_LOG_DEBUG("test1 ave is %d", 20);
  LDS_LOG_INFO("test1 is ok","");
  LDS_LOG_ERROR("test2 is abnormal","");
  
  return 0;
}
