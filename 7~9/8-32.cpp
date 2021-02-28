#include <iostream>
#include <cmath>
using namespace std;

const int SIZE2 = 2;
double getTringleArea(const double points[][SIZE2]);

int main() {
	double points[3][2] = { 0 };

	cout << "Enter x1, y1, x2, y2, x3, y3: ";
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < SIZE2;j++)
			cin >> points[i][j];

	double area = getTringleArea(points);

	if (area == 0)
		cout << "The three points are on the same line" << endl;
	else
		cout << "The area of the traingle is " << area << endl;

	return 0;
}

double getTringleArea(const double points[][SIZE2]) {
	double angle1 = (points[1][0] - points[0][0]) / (points[1][1] - points[0][1]);
	double angle2 = (points[2][0] - points[1][0]) / (points[2][1] - points[1][1]);

	if (angle1 == angle2)
		return 0;
	else
		return abs(0.5*((points[0][0] * points[1][1] + points[1][0] * points[2][1] + points[2][0] * points[0][1]) - (points[0][0] * points[2][1] + points[2][0] * points[1][1] + points[1][0] * points[0][1])));

}