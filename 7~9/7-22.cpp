#include <iostream>
using namespace std;

int main() {
	int num[10]; //����ڿ��� ���� ����
	int selectNum[10] = { NULL }; //�ߺ��� ������ ����

	cout << "Insert numbers: " << endl;

	for (int i = 0;i < 10;i++)
		cin >> num[i];

	cout << "Available combos are..." << endl;


	int size = 0; //selectNum�� �迭 ũ��
	bool flag = true;//selectNum�� �Է����� �Ǻ�

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
