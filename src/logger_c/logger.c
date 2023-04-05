#include "logger.h"

static void my_console_logger(ulog_level_t level, char *msg) {
  printf("[LOG][%s]%s", ulog_level_name(level), msg);
 }

void logger_init(void) {
  ULOG_INIT();
  ULOG_SUBSCRIBE(my_console_logger, ULOG_DEBUG_LEVEL);
}
