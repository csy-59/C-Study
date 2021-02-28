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
	struct tm Date;//��ȯ�� �� �����ϱ� ���� �߰�
};

#endif // !MYDATE_H
