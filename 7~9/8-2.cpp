#include <iostream>
using namespace std;

const int SIZE = 4;
double sumMajorDiagonal(const double m[][SIZE]); //�밢 ���� �� ���� �Լ�

int main() {
	//�迭 �Է�
	double matrix[SIZE][SIZE];
	cout << "Enter a 4-by-4 matrix row by row: " << endl;
	for (int i = 0;i < SIZE;i++)
		for (int j = 0;j < SIZE;j++)
			cin >> matrix[i][j];

	cout << "Sum of the elements in the major diagonal is " << sumMajorDiagonal(matrix) << endl;

	return 0;
}


double sumMajorDiagonal(const double m[][SIZE]) {

	double result = 0;
	for (int i = 0;i < SIZE;i++)
		result += m[i][i];

	return result;
}