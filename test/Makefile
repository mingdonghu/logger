all:
	@echo "start commplie"
	@g++ demo_logger_c.cpp ../src/logger_c/*.c -I ../src/logger_c/ -lpthread -o demo_logger_c
	@g++ demo_logger_cpp.cpp ../src/logger_cpp/*.cpp -I ../src/logger_cpp/ -std=c++11 -lpthread -o demo_logger_cpp
	@echo "end commplie"
clean:
	@rm ./demo_logger_c demo_logger_cpp
	@echo "clean commplie generate file"
	@rm *.log
	@echo "clean all log file"