# 日志库
- 一共两种日志库:
  - 1. [logger_c](./src/logger_c/) : 基于C99标准，适合FreeRTOS/Linux/Win32平台下使用C/C++开发使用
  - 2. [logger_cpp](./src/logger_cpp/) : 基于C++89标准，适合Linux/Win32平台下C++开发使用
---

# 应用实例：

## 1. logger_c

``` c++
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

```
- 效果
``` bash
davidhu@ubuntu18-04-vm:/mnt/hgfs/vmshare/004Middleware_and_Module/logger/test$ ./demo_logger_c
[D][demo_logger_c.cpp:5]hello, I am logger_c system. 2023
[I][demo_logger_c.cpp:6]support C/C++ on the Win32/FreeRTOS/Linux platform environment compile.
[W][demo_logger_c.cpp:7]welcome to use it.
[E][../src/logger_c/m_logger.c:6]error:demo_logger_c.cpp:10
[E][../src/logger_c/m_logger.c:6]error:demo_logger_c.cpp:10
[E][../src/logger_c/m_logger.c:6]error:demo_logger_c.cpp:10
[E][../src/logger_c/m_logger.c:6]error:demo_logger_c.cpp:10
[E][../src/logger_c/m_logger.c:6]error:demo_logger_c.cpp:10
[E][../src/logger_c/m_logger.c:6]error:demo_logger_c.cpp:10
```

---

## logger_cpp
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
davidhu@ubuntu18-04-vm:/mnt/hgfs/vmshare/004Middleware_and_Module/logger/test$ ./demo_logger_cpp
[2023-9-3,20:21:41][1693743701.595306250][LOG][I][demo_logger_cpp.cpp:4:main()]1.test start
[2023-9-3,20:21:41][1693743701.595318753][LOG][D][demo_logger_cpp.cpp:5:main()]1.I am debugger.
[2023-9-3,20:21:41][1693743701.595322861][LOG][W][demo_logger_cpp.cpp:6:main()]1.dear friend, believe this is greate logger
[2023-9-3,20:21:41][1693743701.595326758][LOG][E][demo_logger_cpp.cpp:7:main()]1.test end
[2023-9-3,20:21:41][1693743701.595329674][LOG][I]2.test start
[2023-9-3,20:21:41][1693743701.595332379][LOG][D]2.I am debugger.
[2023-9-3,20:21:41][1693743701.595334793][LOG][W]2.dear friend, believe this is greate logger
[2023-9-3,20:21:41][1693743701.595337138][LOG][E]2.test end
[2023-9-3,20:21:41][1693743701.595339632][LOG][I]3.test start
3.I am debugger.
```