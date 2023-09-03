#include "m_logger.h"
#include <unistd.h>

void error_handle(const char* filename, int lineno) {
  while (1) {
    LOG_ERROR("error:%s:%d\n", filename, lineno);
    sleep(1);
  }
}

static void my_console_logger(ulog_level_t level, char *msg) {
  printf("[%s]%s", ulog_level_name(level), msg);
 }

void m_logger_init(void) {
  ULOG_INIT();
  ULOG_SUBSCRIBE(my_console_logger, ULOG_DEBUG_LEVEL);
}
