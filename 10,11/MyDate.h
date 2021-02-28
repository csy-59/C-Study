#pragma once
#ifndef MYDATE_H
#define MYDATE_H
#include <ctime>

class MyDate {
public:
	MyDate();
	MyDate(long long time);
	MyDate(int year, int month, int day);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(long long elapsedTime);

private:
	int year;
	int month;
	int day;
	struct tm Date;//변환을 더 쉽게하기 위해 추가
};

#endif // !MYDATE_H
