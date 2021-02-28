#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream input;
	input.open("Excercise13_3.txt", ios::in);

	int score = 0;
	int sum = 0;
	int count = 0;

	while (!input.eof()) {
		input >> score;
		cout << score << " ";
		sum += score;
		count++;
	}
	cout << endl;

	cout << "Total sum is " << sum << endl;
	cout << "Average is " << sum / count << endl;

	input.close();

	return 0;
}