#include <iostream>
#include <ctime>
#include "StopWatch.h"
using namespace std;

//7-12에서 사용한 함수를 사용했습니다.
void createArray(int list[], int listSize);
void Sort(int list[], int listSize);

int main() {
	int list[100000];
	StopWatch watch;

	createArray(list, 100000);

	cout << "Sorting..." << endl;

	watch.start();
	Sort(list, 100000);
	watch.stop();

	cout << "Sorting took " << watch.getElapsedTime() << "s" << endl;

	return 0;
}

void createArray(int list[], int listSize) {
	for (int i = 0; i < listSize;i++)
		list[i] = rand() % 1000;
}
void Sort(int list[], const int listSize) {
	int min, value;
	for (int i = 0;i < listSize;i++) {
		min = i;
		for (int j = i;j < listSize;j++) {
			if (list[min] > list[j])
				min = j;
		}
		value = list[i];
		list[i] = list[min];
		list[min] = value;
	}

	cout << "*Sort succeed!*" << endl;
}