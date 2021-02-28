#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;



const int SIZE = 4;

int main() {
	//2차원 백터 설정
	vector<vector<int>> matrix(SIZE);
	for (int i = 0;i < SIZE;i++)
		matrix[i] = vector<int>(SIZE);

	int checkBox[SIZE] = { false };

	srand(time(0));

	//백터 랜덤으로 채우기 + 출력
	for (unsigned i = 0;i < matrix.size();i++) {
		for (int unsigned j = 0;j < matrix[i].size();j++) {
			matrix[i][j] = rand() % 2;
			cout << matrix[i][j];
		}
		cout << endl;
	}

	cout << "The largest row index: ";
	int maxOneCount = 0;
	int oneCount = 0;

	for (int j = 0;j < SIZE;j++) {
		oneCount = 0;

		for (int i = 0;i < SIZE;i++) 
			if (matrix[i][j] == 1)
				oneCount++;

		checkBox[j] = oneCount;
		if (oneCount > maxOneCount)
			maxOneCount = oneCount;
	}

	for (int i = 0;i < SIZE;i++)
		if (checkBox[i] == maxOneCount)
			cout << i << ",";
	cout << endl;

	maxOneCount = 0;

	cout << "The largest colum index: ";
	for (int i = 0;i < SIZE;i++) {
		oneCount = 0;

		for (int j = 0;j < SIZE;j++)
			if (matrix[i][j] == 1)
				oneCount++;

		checkBox[i] = oneCount;
		if (oneCount > maxOneCount)
			maxOneCount = oneCount;
	}

	for (int i = 0;i < SIZE;i++)
		if (checkBox[i] == maxOneCount)
			cout << i << ",";
	cout << endl;

	return 0;
}