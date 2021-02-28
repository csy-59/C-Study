#include "StopWatch.h"
#include <ctime>

StopWatch::StopWatch() {
	startTime = time(0);
}

int StopWatch::getStartTime() {
	return static_cast<int>(startTime);
}

int StopWatch::getEndTime() {
	return static_cast<int>(endTime);
}

void StopWatch::start() {
	startTime = clock();
}

void StopWatch::stop() {
	endTime = clock();
}

int StopWatch::getElapsedTime() {
	return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}