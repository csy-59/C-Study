#include <iostream>
#include <ctime>
using namespace std;

void createNumberArray(int num[]); //숫자를 저장하는 배열 생성
void showNumberArray(const int num[]); //숫자 저장 배열 출력
void createCountsArray(const int num[], int counts[]); //갯수를 저장하는 배열 생성
void showCountsArray(const int counts[]); //갯수 저장 배열 출력

//각 배열의 크기 전역변수로 정의
const int NUMBER_ARRAY_SIZE = 100;
const int COUNTS_ARRAY_SIZE = 10;

int main() {
	int num[NUMBER_ARRAY_SIZE];
	int counts[COUNTS_ARRAY_SIZE];

	cout << "#Creating Number Array..." << endl;
	createNumberArray(num);

	cout << "#Number Array: " << endl;
	showNumberArray(num);

	cout << "#Creating Counts Array..." << endl;
	createCountsArray(num, counts);

	cout << "#Final result: " << endl;
	showCountsArray(counts);
	return 0;
}

void createNumberArray(int num[]) {

	srand(time(0));
	for (int i = 0;i < NUMBER_ARRAY_SIZE;i++)
		num[i] = rand() % COUNTS_ARRAY_SIZE;

	cout << "> Done." << endl;
}

void showNumberArray(const int num[]) {
	//10개 씩 10줄 출력
	for (int i = 0; i < NUMBER_ARRAY_SIZE;i++) {
		cout << num[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}

	cout <<"> Done."<< endl;
}

void createCountsArray(const int num[], int counts[]) {
	//counts 배열 0으로 초기화
	for (int i = 0;i < COUNTS_ARRAY_SIZE;i++)
		counts[i] = 0;

	//숫자 개수 배열에 입력
	for (int i = 0;i < NUMBER_ARRAY_SIZE;i++)
		counts[num[i]]++;

	cout << "> Done." << endl;
}

void showCountsArray(const int counts[]) {
	for (int i = 0;i < COUNTS_ARRAY_SIZE;i++)
		cout << i << ": " << counts[i] << endl;

	cout << "> Done." << endl;
}