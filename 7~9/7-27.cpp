#include <iostream>
using namespace std;

bool isSorted(const int list[], int size);

int main() {

	int list[80];
	int size;

	cout << "Enter list: ";
	cin >> size;
	for (int i = 0;i < size;i++)
		cin >> list[i];

	if (isSorted(list,size))
		cout << "The list is already sorted" << endl;
	else
		cout << "The list is not sorted" << endl;

	return 0;
}

bool isSorted(const int list[], int size) {
	bool flag = false;
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < i;j++) {
			if (list[j] > list[i]) {
				flag = true;
				break;
			}
		}
		
		if (flag) {
			return false;
		}
	}
	return true;
}