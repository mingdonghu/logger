# 日志库
- 一共两种日志库，分别为loggerv1、loggerv2，建议使用loggerv2
- 适用于C++89及以上标准下的开发

## ***loggerv1***
### 位于`src/loggerv1/`
### 应用实例：
> 见源码test/demo.cpp
``` c++
#include "ldlidar_logger.h"

int main(int argc, char** argv) {
  
  ldlidar::LdLidarLogger::Subscribe();

  LD_LOG_DEBUG("hello, I am loggerv1 system.");
  LD_LOG_INFO("LOG FILE WRITE TO %s", LDLIDAR_SDK_LOG_FILE_OUTPUT_PATH);
  LD_LOG_WARNING("welcom used.");
  LD_LOG_ERROR("the loggerv1, support C++11 environment compile.");
  
  return 0;
}
```
- 效果
``` bash
linux@ubuntu:~/logger/test$ ./demo
[LD][2022-11-27,18:14:11][DEBUG]:hello, I am loggerv1 system.
[LD][2022-11-27,18:14:11][INFO]:LOG FILE WRITE TO ...
[LD][2022-11-27,18:14:11][WARNING]:welcom used.
[LD][2022-11-27,18:14:11][ERROR]:the loggerv1, support C++11 environment compile.
```

## ***loggerv2***
### 位于`src/loggerv2/`
### 应用实例：
> 见源码test/demo2.cpp
``` c++
#include "log_module.h"

int main(int argc, char** argv) {
  
  LOG_A_INFO("test start","");
  LOG_A_DEBUG("I am debugger.","");
  LOG_A_WARN("dear friend, believe this is greate logger","");
  LOG_A_ERROR("test end","");

  LOG_B_INFO("test start","");
  LOG_B_DEBUG("I am debugger.","");
  LOG_B_WARN("dear friend, believe this is greate logger","");
  LOG_B_ERROR("test end","");
  
  return 0;
}

```
- 效果
``` bash
linux@ubuntu:~/logger/test$ ./demo2
[LOG_A][INFO][2022-11-27,17:55:23][demo2.cpp][main][5][test start]
[LOG_A][DEBUG][1669542923.525749645][demo2.cpp][main][6][I am debugger.]
[LOG_A][WARN][2022-11-27,17:55:23][demo2.cpp][main][7][dear friend, believe this is greate logger]
[LOG_A][ERROR][2022-11-27,17:55:23][demo2.cpp][main][8][test end]
[LOG_B][INFO][1669542923.525797099][test start]
[LOG_B][DEBUG][1669542923.525799683][I am debugger.]
[LOG_B][WARN][1669542923.525801032][dear friend, believe this is greate logger]
[LOG_B][ERROR][1669542923.525803071][test end]
```