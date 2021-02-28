#include <iostream>
using namespace std;

int getBiggest(const int list[], int num, int key) {
	if (num == 8)
		return key;
	else {
		if (list[num] > key)
			key = list[num];
		return getBiggest(list, num + 1, key);
	}
}
int getBiggest(const int list[]) {
	return getBiggest(list, 1, list[0]);
}

int main() {
	int list[8];
	cout << "Enter 8 numbers: ";
	for (int i = 0;i < 8;i++)
		cin >> list[i];


	cout << "The Biggest number is " << getBiggest(list) << endl;

	return 0;
}