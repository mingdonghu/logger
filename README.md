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
  LD_LOG_WARN("dear friend, believe this is greate logger","");
  LD_LOG_INFO("test end","");

  LDS_LOG_DEBUG("test1 ave is %d", 20);
  LDS_LOG_INFO("test1 is ok","");
  LDS_LOG_ERROR("test2 is abnormal","");
  
  return 0;
}
```
- 效果
``` bash
linux@ubuntu:/mnt/hgfs/hmd_ubuntu/logger/test$ ./demo2
[LDS][INFO][Thu Aug 11 21:13:06 2022][demo2.cpp][main][5][test start]
[LDS][WARNING][Thu Aug 11 21:13:06 2022][demo2.cpp][main][6][dear friend, believe this is greate logger]
[LDS][INFO][Thu Aug 11 21:13:06 2022][demo2.cpp][main][7][test end]
[LDS][DEBUG][1660223586.873051740][test1 ave is 20]
[LDS][INFO][1660223586.873057530][test1 is ok]
[LDS][ERROR][1660223586.873062271][test2 is abnormal]
```