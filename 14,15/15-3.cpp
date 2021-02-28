#include <iostream>
#include "ThreeDPoint.h"
using namespace std;

int main() {
	ThreeDPoint t1, t2(10, 30, 25.5);
	cout << "t1 is " << "(" << t1.getX() << ", " << t1.getY() << ", " << t1.getZ() << ")" << endl;
	cout << "t2 is " << "(" << t2.getX() << ", " << t2.getY() << ", " << t2.getZ() << ")" << endl;
	cout << "Distance between t1 and t2 is " << t1.distance(t2) << endl;

	return 0;
}