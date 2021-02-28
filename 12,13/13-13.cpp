#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
	srand(time(0));
	int num = 0;

	//파일 생성
	fstream output("Excercise13_13.txt", ios::out | ios::binary);

	for (int i = 0;i < 100;i++) {
		num = rand() % 100;
		output.write(reinterpret_cast<char*>(&num), sizeof(num));
	}

	output.close();

	fstream input("Excercise13_13.txt", ios::in | ios::binary);

	cout << "Content of file:" << endl;
	int i = 1;

	input.read(reinterpret_cast<char*>(&num), sizeof(num));
	cout << setw(3) << num << " ";
	while (!input.eof()) {
		int num;
		
		input.read(reinterpret_cast<char*>(&num), sizeof(num));
		cout << setw(3) << num << " ";
		
		i++;
		if (i == 10) {
			cout << endl;
			i = 0;
		}
	}
	cout << endl;
	//100개에서 하나가 더 출력됨....

	input.close();

	return 0;
}