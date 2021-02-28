#include <iostream>
#include <ctime>
using namespace std;

void createNumberArray(int num[]); //���ڸ� �����ϴ� �迭 ����
void showNumberArray(const int num[]); //���� ���� �迭 ���
void createCountsArray(const int num[], int counts[]); //������ �����ϴ� �迭 ����
void showCountsArray(const int counts[]); //���� ���� �迭 ���

//�� �迭�� ũ�� ���������� ����
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
	//10�� �� 10�� ���
	for (int i = 0; i < NUMBER_ARRAY_SIZE;i++) {
		cout << num[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}

	cout <<"> Done."<< endl;
}

void createCountsArray(const int num[], int counts[]) {
	//counts �迭 0���� �ʱ�ȭ
	for (int i = 0;i < COUNTS_ARRAY_SIZE;i++)
		counts[i] = 0;

	//���� ���� �迭�� �Է�
	for (int i = 0;i < NUMBER_ARRAY_SIZE;i++)
		counts[num[i]]++;

	cout << "> Done." << endl;
}

void showCountsArray(const int counts[]) {
	for (int i = 0;i < COUNTS_ARRAY_SIZE;i++)
		cout << i << ": " << counts[i] << endl;

	cout << "> Done." << endl;
}