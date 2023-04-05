#include "logger.h"

int main(int argc, char** argv) {
  logger_init();
  LOG_DEBUG("hello, I am logger_c system. %d\n", 2023);
  LOG_INFO("support C/C++ on the Win32/FreeRTOS/Linux platform environment compile.\n");
  LOG_WARNING("welcome to use it.\n");
  LOG_ERROR("....\n");
  return 0;
}
