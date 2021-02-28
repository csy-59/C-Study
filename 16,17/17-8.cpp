#include <iostream>
using namespace std;

void reverseDisplay(int value) {
	if (value != 0) {
		cout << value % 10;
		reverseDisplay(value / 10);
	}
}

int main() {
	int value;
	cout << "Enter number: ";
	cin >> value;

	cout << "Reverse of " << value << " is ";
	reverseDisplay(value);
	cout << endl;
}