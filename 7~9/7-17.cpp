#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int result[50] = { 0 };
	int ball = 0;
	int slot = 0;
	int rightCount = 0;

	cout << "Enter the number of balls to drop: ";
	cin >> ball;
	cout << "Enter the number of slots int the bean machine(3~50): ";
	cin >> slot;

	//해당 슬롯에 넣기+화면에 경로 띄우기
	cout << endl;
	srand(time(0));
	for (int i = 0;i < ball;i++) {
		for (int j = 0;j < slot;j++) {
			if (rand() % 2 == 1) {
				cout << "R";
				rightCount++;
			}
			else
				cout << "L";
		}
		cout << endl;
		result[rightCount-1]++;
		rightCount = 0;
	}
	cout << endl;

	//출력을 위해 슬롯에 있는 공의 최대값 구하기
	int max = result[0];
	for (int i = 0;i < slot;i++)
		if (result[i] > max)
			max = result[i];

	//공 출력하기
	for (int i = 0;i < max;i++) {
		for (int j = 0;j < slot;j++) {
			if (result[j] >= max - i)
				cout << "0";
			else
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}