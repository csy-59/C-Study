#include <iostream>
using namespace std;

int main() {
	const int SIZE1 = 10;
	int arr[SIZE1] = { 0 };
	int arrSize = 0;
	int buff = 0;
	bool flag = true;

	cout << "Enter " << SIZE1 << " numbers : ";
	for (int i = 0;i < SIZE1;i++) {
		cin >> buff;
		for (int j = 0;j < arrSize;j++) {
			if (buff == arr[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			arr[arrSize] = buff;
			arrSize++;
		}
		flag = true;
	}

	for (int i = 0;i < arrSize;i++)
		cout << arr[i] << " ";
	cout << endl;


	return 0;
}