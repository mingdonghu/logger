all:
	@echo "start commplie"
	@g++ demo.cpp ldlidar_logger.cpp ulog.c  -std=c++11 -o demo
	@g++ demo2.cpp log_module.cpp -std=c++11 -lpthread -o demo2
	@echo "end commplie"
clean:
	@rm ./demo demo2
	@rm ./*.log
	@echo "clean commplie generate file"