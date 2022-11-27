all:
	@echo "start commplie"
	@g++ demo.cpp ../src/loggerv1/ldlidar_logger.cpp ../src/loggerv1/ulog.c -I ../src/loggerv1/ -std=c++11 -o demo
	@g++ demo2.cpp ../src/loggerv2/log_module.cpp -I ../src/loggerv2/ -std=c++11 -lpthread -o demo2
	@echo "end commplie"
clean:
	@rm ./demo demo2
	@echo "clean commplie generate file"
	@rm *.log
	@echo "clean all log file"