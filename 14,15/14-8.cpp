#include <iostream>
#include <complex>
using namespace std;

int main() {
	int a = 0, b = 0;

	cout << "Enter complex number( _ + _i): ";
	cin >> a >> b;

	complex<double> complexC(a, b);
	complex<double> temp(0, 0);

	for (int i = 0;i < 60;i++) {
		if (abs(temp) > 2) {
			cout << "Complex number " << a << " + " << b << "i is not Mandelbrot set."<<endl;
			return 0;
		}
		temp = temp*temp + complexC;
	}

	cout << "Complex number " << a << " + " << b << "i is Mandelbrot set." << endl;
	
	return 0;
}