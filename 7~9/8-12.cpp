#include <iostream>
#include <cmath>
using namespace std;

//거리 구하는 함수
double getDistance(double x1, double y1, double z1, double x2, double y2, double z2);

int main() {
	const int ROW_NUMBER = 8;
	double points[ROW_NUMBER][3] = { {-1,0,3},{-1,-1,-1},{4,1,1},{2,0.5,9},{3.5,2,-1},{3,1.5,3},{-1.5,4,2},{5.5,4,-0.5} };

	int p1 = 0, p2 = 1;
	double shortestDistance = getDistance(points[p1][0], points[p1][1], points[p1][3], points[p2][0], points[p2][1], points[p2][2]);

	for (int i = 0;i < ROW_NUMBER;i++) {
		for (int j = i + 1;j < ROW_NUMBER;j++) {
			double distance = getDistance(points[i][0], points[i][1], points[i][3], points[j][0], points[j][1], points[j][2]);
			if (shortestDistance > distance) {
				p1 = i;
				p2 = j;
				shortestDistance = distance;
			}
		}
	}

	cout << "The closest tow points are " << "(" << points[p1][0] << ", " << points[p1][1] << ", " << points[p1][3]
		<< ") and (" << points[p2][0] << ", " << points[p2][1] << ", " << points[p2][2] << ")" << endl;

	return 0;
}

double getDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1));
}