#include <iostream>
#include "Location.h"
using namespace std;

const int ROW_SIZE = 3;
const int COLUMN_SIZE = 4;
Location locateLargest(const double a[][COLUMN_SIZE]);

int main() {
	double a[ROW_SIZE][COLUMN_SIZE] = { 0 };

	cout << "Enter a " << ROW_SIZE << "-by-" << COLUMN_SIZE << " tow-dimensional array : " << endl;
	for (int i = 0;i < ROW_SIZE;i++)
		for (int j = 0;j < COLUMN_SIZE;j++)
			cin >> a[i][j];

	Location l1 = locateLargest(a);
	cout << "The location of the largest element is " << l1.getMaxValue() << " at (" << l1.getRow() << ", " << l1.getcolumn() << ")" << endl;

	return 0;
}

Location locateLargest(const double a[][COLUMN_SIZE]) {
	Location l1;
	int row = 0, column = 0;
	double max = a[0][0];

	for (int i = 0;i < ROW_SIZE;i++) {
		for (int j = 0;j < COLUMN_SIZE;j++) {
			if (a[i][j] > max) {
				row = i;
				column = j;
				max = a[i][j];
			}
		}
	}

	l1.setRow(row);
	l1.setColumn(column);
	l1.setMaxValue(max);

	return l1;
}