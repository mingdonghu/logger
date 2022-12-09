# 日志库
- 一共两种日志库，分别为loggerv1、loggerv2，建议使用loggerv2
- 适用于C++89及以上标准下的开发

---

## ***loggerv1***
### 位于`src/loggerv1/`
### 应用实例：
> 见源码test/demo.cpp
``` c++
#include "loggers.h"

int main(int argc, char** argv) {
  
  Loggers::Subscribe();

  LOGGER_DEBUG("hello, I am loggerv1 system.");
  LOGGER_INFO("LOG FILE WRITE TO ...");
  LOGGER_WARNING("welcom used.");
  LOGGER_ERROR("the loggerv1, support C++11 environment compile.");
  
  return 0;
}
```
- 效果
``` bash
linux@ubuntu:~/robotsensor_sdk/logger/test$ ./demo
[LOG][2022-12-9,14:48:56][DEBUG]:hello, I am loggerv1 system.
[LOG][2022-12-9,14:48:56][INFO]:LOG FILE WRITE TO ...
[LOG][2022-12-9,14:48:56][WARNING]:welcom used.
[LOG][2022-12-9,14:48:56][ERROR]:the loggerv1, support C++11 environment compile.
```

---

## ***loggerv2***
### 位于`src/loggerv2/`
### 应用实例：
> 见源码test/demo2.cpp
``` c++
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
```
- 效果
``` bash
linux@ubuntu:~/robotsensor_sdk/logger/test$ ./demo2
[LOG][2022-12-9,14:49:1][1670568541.40398441][INFO][demo2.cpp][main][5][1.test start]
[LOG][2022-12-9,14:49:1][1670568541.40741545][DEBUG][demo2.cpp][main][6][1.I am debugger.]
[LOG][2022-12-9,14:49:1][1670568541.40951605][WARN][demo2.cpp][main][7][1.dear friend, believe this is greate logger]
[LOG][2022-12-9,14:49:1][1670568541.41090077][ERROR][demo2.cpp][main][8][1.test end]
[LOG][2022-12-9,14:49:1][1670568541.41347080][INFO][2.test start]
[LOG][2022-12-9,14:49:1][1670568541.41495832][DEBUG][2.I am debugger.]
[LOG][2022-12-9,14:49:1][1670568541.41653944][WARN][2.dear friend, believe this is greate logger]
[LOG][2022-12-9,14:49:1][1670568541.41797107][ERROR][2.test end]
[LOG][2022-12-9,14:49:1][1670568541.41927313][INFO]3.test start
3.I am debugger.
```