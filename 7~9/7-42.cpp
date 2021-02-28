#include <iostream>
using namespace std;

void dec2Hex(int value, char hexString[]);

int main() {
	int value;
	char hexString[20] = { '\0' };

	cout << "Enter number: ";
	cin >> value;

	dec2Hex(value, hexString);

	return 0;
}

void dec2Hex(int value, char hexString[]) {
	int i = 0;

	while (value >= 16) {

		if (value % 16 > 9)
			hexString[i] = 'a' + value % 16 - 10;
		else
			hexString[i] = '0' + value % 16;

		value /= 16;
		i++;
	}

	if (value > 9)
		hexString[i] = 'a' + value - 10;
	else
		hexString[i] = '0' + value;

	cout << "Result is ";

	for (int j = strlen(hexString) - 1;j >= 0;j--)
		cout << hexString[j];

	cout << endl;
}