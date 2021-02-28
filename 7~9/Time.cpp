#include "Time.h"
#include <ctime>

Time::Time()
{
	second = time(0);
}

Time::Time(int elapseTime)
{
	second = elapseTime;
}

int Time::getHour()
{
	return ((second / 60) / 60) % 24;
}

int Time::getMinute()
{
	return (second / 60) % 60;
}

int Time::getSecond()
{
	return second % 60;
}

void Time::setTime(int elapseTime)
{
	second = (elapseTime >= 0) ? elapseTime : 0;
}
