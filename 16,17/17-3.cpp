#include <iostream>
using namespace std;

int gcd(int m, int n) {
	if (m%n == 0)
		return n;
	else
		gcd(n, m%n);
}

int main() {
	int m, n;
	cout << "Enter first number: ";
	cin >> m;
	cout << "Enter second number: ";
	cin >> n;
	
	cout << "Greatest Common Divisor of " << m << " and " << n << " is " << gcd(m, n) << endl;

	return 0;
}