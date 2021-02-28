#include <iostream>
using namespace std;

int main() {
	int num[10]; //사용자에게 받을 숫자
	int selectNum[10] = { NULL }; //중복을 제외한 숫자

	cout << "Insert numbers: " << endl;

	for (int i = 0;i < 10;i++)
		cin >> num[i];

	cout << "Available combos are..." << endl;


	int size = 0; //selectNum의 배열 크기
	bool flag = true;//selectNum에 입력할지 판별

	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < size;j++) {
			if (num[i] == selectNum[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			selectNum[size] = num[i];
			size++;
		}
		flag = true;
	}
	
	int i = 0, j = 0;
	while (i < size) {
		j = i;
		while (j < size) {
			cout << "(" << selectNum[i] << ", " << selectNum[j] << ")";
			j++;
		}
		cout << endl;
		i++;
	}
}
