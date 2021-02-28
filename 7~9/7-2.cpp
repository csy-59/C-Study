#include <iostream>
using namespace std;

int main() {
	const int LIST_SIZE = 10;
	int list[LIST_SIZE];

	//10정수 배열에 입력
	cout << "Enter numbers: " << endl;
	for (int i = 0; i < LIST_SIZE;i++)
		cin >> list[i];

	//역순 출력
	for (int i = LIST_SIZE - 1;i >= 0;i--)
		cout << list[i] << " ";

	return 0;
}