#include "log_module.h"

int main(int argc, char** argv) {
  
  LD_LOG_INFO("SDK initializing","");

  for (int i = 0; i < 100; i++) {
    LD_LOG_DEBUG("test:%d", i);
  }
  
  return 0;
}
