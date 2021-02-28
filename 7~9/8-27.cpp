#include <iostream>
using namespace std;

const int SIZE = 3;
void sortColumns(const double m[][SIZE], double result[][SIZE]);

int main() {
	double m[SIZE][SIZE] = { 0 };
	double result[SIZE][SIZE] = { 0 };

	cout << "Enter a 3 by 3 matrix row by row:" << endl;
	for (int i = 0;i < SIZE;i++)
		for (int j = 0;j < SIZE;j++)
			cin >> m[i][j];

	sortColumns(m, result);

	return 0;
}

void sortColumns(const double m[][SIZE], double result[][SIZE]) {
	for (int i = 0;i < SIZE;i++)
		for (int j = 0;j < SIZE;j++)
			result[i][j] = m[i][j];

	int min = 0;
	for (int j = 0;j < SIZE;j++) {

		for (int i1 = 0;i1 < SIZE;i1++) {
			min = i1;
			for (int i2 = i1;i2 < SIZE;i2++) {
				if (result[min][j] > result[i2][j])
					min = i2;
			}
			double value = result[i1][j];
			result[i1][j] = result[min][j];
			result[min][j] = value;
		}

	}

	cout << "The column-sorted array is" << endl;

	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}