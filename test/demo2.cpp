#include "log_module.h"

int main(int argc, char** argv) {
  
  LD_LOG_INFO("test start","");

  for (int i = 0; i < 10; i++) {
    LD_LOG_DEBUG("test:%d", i);
    LD_LOG_INFO("get data","");
  }
  LD_LOG_WARN("dear friend, believe this is greate logger","");
  LD_LOG_INFO("test end","");
  
  return 0;
}
