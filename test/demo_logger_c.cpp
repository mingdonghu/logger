#include "m_logger.h"

int main(int argc, char** argv) {
  m_logger_init();
  LOG_DEBUG("hello, I am logger_c system. %d\n", 2023);
  LOG_INFO("support C/C++ on the Win32/FreeRTOS/Linux platform environment compile.\n");
  LOG_WARNING("welcome to use it.\n");
  int ret = -1;
  if (ret < 0) {
    error_handle(__FILE__, __LINE__);
  }
  return 0;
}
