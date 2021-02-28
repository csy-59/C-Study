#include <iostream>
#include <vector>
using namespace std;

const int ROW_SIZE = 6;
const int COLUMN_SIZE = 7;

bool isConsecutiveFour(vector<vector<int>>& values);
bool checkVerti(vector<vector<int>>& values);
bool checkHori(vector<vector<int>>& values);
bool checkDia(vector<vector<int>>& values);

int main()
{
	//2차원 백터 설정
	vector<vector<int>> values(ROW_SIZE);
	for (int i = 0;i < ROW_SIZE;i++)
		values[i] = vector<int>(COLUMN_SIZE);

	//백터 입력
	for (int i = 0; i < values.size(); i++)
		for (int j = 0; j < values[i].size(); j++)
			cin >> values[i][j];

	cout << isConsecutiveFour(values) << endl;
	return 0;
}

bool isConsecutiveFour(vector<vector<int>>& values)
{
	return (checkVerti(values) || checkHori(values) || checkDia(values));
	
	return false;

}

bool checkVerti(vector<vector<int>>& values) //세로
{
	
	for (int i = 0; i < COLUMN_SIZE; i++) {
		int start = values[0][i];
		int count = 1;
		for (int j = 1; j < ROW_SIZE; j++) {
			if (start == values[j][i]) {
				count++;
			}
			else {
				start = values[j][i];
				count = 1;
			}

			if (count == 4) {
				return true;
			}
		}
	}
	

	return false;
}

bool checkHori(vector<vector<int>>& values) //가로
{
	
	for (int i = 1; i < ROW_SIZE; i++) {
		int start = values[i][0];
		int count = 1;
		for (int j = 1; j < COLUMN_SIZE; j++) {
			if (start == values[i][j]) {
				count++;
			}
			else {
				start = values[i][j];
				count = 1;
			}

			if (count == 4) {
				return true;
			}
		}
	}
	
	
	return false;
}

bool checkDia(vector<vector<int>>& values) //대각선
{
	for (int i = 0; i < ROW_SIZE; i++) {
		int start = values[i][0];
		int count = 1;
		for (int j = i + 1, k = 1; j < ROW_SIZE && k < COLUMN_SIZE; j++, k++) {
			if (start == values[j][k]) {
				count++;
			}
			else {
				start = values[j][k];
				count = 1;
			}
			if (count == 4) {
				return true;
			}
		}
	}

	for (int i = 0; i < COLUMN_SIZE; i++) {
		int start = values[0][i];
		int count = 1;
		for (int j = i + 1, k = 1; j < COLUMN_SIZE && k < ROW_SIZE; j++, k++) {
			if (start == values[k][j]) {
				count++;
			}
			else {
				start = values[k][j];
				count = 1;
			}

			if (count == 4) {
				return true;
			}
		}
	}

	for (int i = 0; i < COLUMN_SIZE; i++) {
		int start = values[0][i];
		int count = 1;
		for (int j = 1, k = i - 1; j < ROW_SIZE && k >= 0; j++, k--) {
			if (start == values[j][k]) {
				count++;
			}
			else {
				start = values[j][k];
				count = 1;
			}
			if (count == 4) {
				return true;
			}
		}
	}

	for (int i = 0; i < ROW_SIZE; i++) {
		int start = values[i][COLUMN_SIZE - 1];
		int count = 1;
		for (int j = i + 1, k = COLUMN_SIZE - 2; j < ROW_SIZE && k >= 0; j++, k--) {
			if (start == values[j][k]) {
				count++;
			}
			else {
				start = values[j][k];
				count = 1;
			}
			if (count == 4) {
				return true;
			}
		}
	}

	return false;

}