#include <iostream>
#include "MyDate.h"
using namespace std;

int main() {
	MyDate date1, date2(3435555513);

	cout << "Date1 is " << date1.getYear() << "." << date1.getMonth()<< "." << date1.getDay() << endl;
	cout << "Date2 is " << date2.getYear() << "." << date2.getMonth() << "." << date2.getDay() << endl;

	return 0;
}