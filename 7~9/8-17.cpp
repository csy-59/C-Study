#include <iostream>
using namespace std;

void locateLargest(const double a[][4], int location[]);

int main() {
	double a[3][4] = { 0 };
	int location[2] = { 0 };

	cout << "Enter the array: " << endl;
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 4;j++)
			cin >> a[i][j];

	locateLargest(a, location);

	return 0;
}

void locateLargest(const double a[][4], int location[]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 4;j++) {
			if (a[i][j] > a[location[0]][location[1]]) {
				location[0] = i;
				location[1] = j;
			}
		}
	}

	cout << "The location of the largest element is at (" << location[0] << ", " << location[1] << ")" << endl;
}