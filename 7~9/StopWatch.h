#pragma once
#include <ctime>
class StopWatch {
public:
	StopWatch();
	int getStartTime();
	int getEndTime();
	void start();
	void stop();
	int getElapsedTime();
private:
	clock_t startTime;
	clock_t endTime;
};