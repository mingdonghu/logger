#include "loggers.h"

int main(int argc, char** argv) {
  
  Loggers::Subscribe();

  LOGGER_DEBUG("hello, I am loggerv1 system.");
  LOGGER_INFO("LOG FILE WRITE TO ...");
  LOGGER_WARNING("welcom used.");
  LOGGER_ERROR("the loggerv1, support C++11 environment compile.");
  
  return 0;
}
