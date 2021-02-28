#include <iostream>
#include "Fan.h"
using namespace std;

int main() {
	Fan f1, f2;

	f1.setSpeed(3);
	f1.setOn(true);
	f1.setRadius(10);

	f2.setSpeed(2);
	f2.setOn(false);
	f2.setRadius(5);

	cout << "f1 is..." << endl;
	cout << "Speed: " << f1.getSpeed() << " On: " << f1.getOn() << " Radius: " << f1.getRadius() << endl;
	cout << "f2 is..." << endl;
	cout << "Speed: " << f2.getSpeed() << " On: " << f2.getOn() << " Radius: " << f2.getRadius() << endl;
	return 0;
}