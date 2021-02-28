#include <iostream>
#include "CircleWithConstantMemberFunctions.h"
using namespace std;

int main() {
	Circle c1(3), c2(6);

	cout << "c1's radius: " << c1.getRadius() << endl;
	cout << "c2's radius: " << c2.getRadius() << endl;

	cout << "c1 < c2 = " << ((c1 < c2) ? "true" : "false") << endl;
	cout << "c1 <= c2 = " << ((c1 <= c2) ? "true" : "false") << endl;
	cout << "c1 == c2 = " << ((c1 == c2) ? "true" : "false") << endl;
	cout << "c1 != c2 = " << ((c1 != c2) ? "true" : "false") << endl;
	cout << "c1 > c2 = " << ((c1 > c2) ? "true" : "false") << endl;
	cout << "c1 >= c2 = " << ((c1 >= c2) ? "true" : "false") << endl;

	return 0;
}