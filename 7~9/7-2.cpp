#include <iostream>
using namespace std;

int main() {
	const int LIST_SIZE = 10;
	int list[LIST_SIZE];

	//10���� �迭�� �Է�
	cout << "Enter numbers: " << endl;
	for (int i = 0; i < LIST_SIZE;i++)
		cin >> list[i];

	//���� ���
	for (int i = LIST_SIZE - 1;i >= 0;i--)
		cout << list[i] << " ";

	return 0;
}