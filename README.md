# 日志库
- 一共两种日志库:
  - 1. [logger_c](./src/logger_c/) : 基于C99标准，适合FreeRTOS/Linux/Win32平台下使用C/C++开发使用
  - 2. [logger_cpp](./src/logger_cpp/) : 基于C++89标准，适合Linux/Win32平台下C++开发使用
---

# 应用实例：

## 1. logger_c

``` c++
#include "logger.h"

int main(int argc, char** argv) {
  logger_init();
  LOG_DEBUG("hello, I am logger_c system. %d\n", 2023);
  LOG_INFO("support C/C++ on the Win32/FreeRTOS/Linux platform environment compile.\n");
  LOG_WARNING("welcome to use it.\n");
  LOG_ERROR("....\n");
  return 0;
}

```
- 效果
``` bash
hmd@MingDong:/mnt/d/project/logger/test$ ./demo_logger_c
[LOG][DEBUG][demo_logger_c.cpp:5: main()]hello, I am logger_c system. 2023
[LOG][INFO][demo_logger_c.cpp:6: main()]support C/C++ on the Win32/FreeRTOS/Linux platform environment compile.
[LOG][WARNING][demo_logger_c.cpp:7: main()]welcome to use it.
[LOG][ERROR][demo_logger_c.cpp:8: main()]....
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
hmd@MingDong:/mnt/d/project/logger/test$ ./demo_logger_cpp
[LOG][2023-4-5,15:46:17][1680680777.20415700][INFO][demo_logger_cpp.cpp][main][5][1.test start]
[LOG][2023-4-5,15:46:17][1680680777.20723200][DEBUG][demo_logger_cpp.cpp][main][6][1.I am debugger.]
[LOG][2023-4-5,15:46:17][1680680777.20932400][WARN][demo_logger_cpp.cpp][main][7][1.dear friend, believe this is greate logger]
[LOG][2023-4-5,15:46:17][1680680777.21158500][ERROR][demo_logger_cpp.cpp][main][8][1.test end]
[LOG][2023-4-5,15:46:17][1680680777.21359300][INFO][2.test start]
[LOG][2023-4-5,15:46:17][1680680777.21592900][DEBUG][2.I am debugger.]
[LOG][2023-4-5,15:46:17][1680680777.21827500][WARN][2.dear friend, believe this is greate logger]
[LOG][2023-4-5,15:46:17][1680680777.22066200][ERROR][2.test end]
[LOG][2023-4-5,15:46:17][1680680777.22239100][INFO]3.test start
3.I am debugger.
```