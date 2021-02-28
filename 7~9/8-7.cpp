#include <iostream>
using namespace std;

void rowCheck(char arr[][5], int size);
void columnCheck(char arr[][5], int size);
void majorDiagonalCheck(char arr[][5], int size);
void subDiagonalCheck(char arr[][5], int size);

int main() {
	char arr[4][5];

	//행렬 입력
	for (int i = 0;i < 4;i++)
		cin >> arr[i];

	cout << endl;

	//결과 출력
	rowCheck(arr, 4);
	columnCheck(arr, 4);
	majorDiagonalCheck(arr, 4);
	subDiagonalCheck(arr, 4);

	return 0;
}

void rowCheck(char arr[][5], int size) {
	bool check = true;//모두 같은 숫자일 경우를 판별
	bool key = true;//하나라도 다를시

	for (int i = 0;i < size;i++) {
		check = true;
		for (int j = 0;j < 3;j++) {
			if (arr[i][j] != arr[i][j + 1]) {
				check = false;
				break;
			}
		}

		if (check) {
			key = false;
			if(arr[i][0] == '0')
				cout << "All 0's on row " << i << endl;
			else
				cout << "All 1's on row " << i << endl;
		}
	}

	if (key)
		cout << "No same numbers a row" << endl;
}
void columnCheck(char arr[][5], int size) {
	bool check = true;
	bool key = true;

	for (int i = 0;i < size;i++) {
		check = true;
		for (int j = 0;j < 3;j++) {
			if (arr[j][i] != arr[j+1][i]) {
				check = false;
				break;
			}
		}

		if (check) {
			key = false;
			if (arr[0][i] == '0')
				cout << "All 0's on column " << i << endl;
			else
				cout << "All 1's on column " << i << endl;
		}
	}

	if (key)
		cout << "No same numbers a column" << endl;
}
void majorDiagonalCheck(char arr[][5], int size) {
	bool check = true;
	bool key = true;

	for (int i = 0;i < size-1;i++) {
		if (arr[i][i] != arr[i + 1][i + 1]) {
			check = false;
			break;
		}
	}

	if (check) {
		key = false;
		if (arr[0][0] == '0')
			cout << "All 0's on major diagonal " << endl;
		else
			cout << "All 1's on major diagonal " << endl;
	}

	if (key)
		cout << "No same numbers a major diagonal" << endl;
}
void subDiagonalCheck(char arr[][5], int size) {
	bool check = true;
	bool key = true;

	for (int i = 0;i < size - 1;i++) {
		if (arr[i][size-1-i] != arr[i + 1][size-2-i]) {
			check = false;
			break;
		}
	}

	if (check) {
		key = false;
		if (arr[0][3] == '0')
			cout << "All 0's on sub-diagonal " << endl;
		else
			cout << "All 1's on sub-diagonal " << endl;
	}

	if (key)
		cout << "No same numbers a sub-diagonal" << endl;
}