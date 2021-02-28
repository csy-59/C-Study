#include <iostream>
#include <ctime>
#include "MyDate.h"
using namespace std;


MyDate::MyDate() {
	time_t currentTime = time(0);

	localtime_s(&Date, &currentTime);

	year = Date.tm_year + 1900;
	month = Date.tm_mon;
	day = Date.tm_mday;

}
MyDate::MyDate(long long time) {
	time_t currentTime = time;

	localtime_s(&Date, &currentTime);

	year = Date.tm_year + 1900;
	month = Date.tm_mon;
	day = Date.tm_mday;
}

MyDate::MyDate(int year, int month, int day) {
	this->year = year;
	this->month = month - 1;
	this->day = day;
}

int MyDate::getYear() {
	return year;
}
int MyDate::getMonth() {
	return month + 1;
}
int MyDate::getDay() {
	return day;
}
void MyDate::setDate(long long elapsedTime) {
	time_t currentTime = elapsedTime + mktime(&Date);

	localtime_s(&Date, &currentTime);

	year = Date.tm_year + 1900;
	month = Date.tm_mon;
	day = Date.tm_mday;
	
}