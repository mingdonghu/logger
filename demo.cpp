#include "ldlidar_logger.h"

int main(int argc, char** argv) {
  
  ldlidar::LdLidarLogger::Subscribe();

  ldlidar::LdLidarLogger::Test();
  
  
  return 0;
}
