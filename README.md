# 日志库
> 用于传感器SDK软件,一共两种，分别为loggerv1、loggerv2，建议使用loggerv2

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
linux@ubuntu:/mnt/hgfs/hmd_ubuntu/logger/test$ ./demo
[LD][Thu Aug 11 17:40:13 2022][DEBUG]:hello, I am loggerv1 system.
[LD][Thu Aug 11 17:40:13 2022][INFO]:LOG FILE WRITE TO ./ldlidar-driver.log
[LD][Thu Aug 11 17:40:13 2022][WARNING]:welcom used.
[LD][Thu Aug 11 17:40:13 2022][ERROR]:the loggerv1, support C++11 environment compile.
```

## ***loggerv2***
### 位于`src/loggerv2/`
### 应用实例：
> 见源码test/demo2.cpp
``` c++
#include "log_module.h"

int main(int argc, char** argv) {
  
  LD_LOG_INFO("test start","");

  for (int i = 0; i < 10; i++) {
    LD_LOG_DEBUG("test:%d", i);
    LD_LOG_INFO("get data","");
  }
  LD_LOG_WARN("dear friend, believe this is greate logger","");
  LD_LOG_INFO("test end","");
  
  return 0;
}
```
- 效果
``` bash
linux@ubuntu:/mnt/hgfs/hmd_ubuntu/logger/test$ ./demo2
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][5][test start]
[LDS][DEBUG][1660209444.151633347][demo2.cpp][main][8][test:0]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151655323][demo2.cpp][main][8][test:1]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151668173][demo2.cpp][main][8][test:2]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151679482][demo2.cpp][main][8][test:3]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151690954][demo2.cpp][main][8][test:4]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151702120][demo2.cpp][main][8][test:5]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151713177][demo2.cpp][main][8][test:6]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151724477][demo2.cpp][main][8][test:7]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151735835][demo2.cpp][main][8][test:8]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][DEBUG][1660209444.151746797][demo2.cpp][main][8][test:9]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][9][get data]
[LDS][WARNING][Thu Aug 11 17:17:24 2022][demo2.cpp][main][11][dear friend, believe this is greate logger]
[LDS][INFO][Thu Aug 11 17:17:24 2022][demo2.cpp][main][12][test end]
```