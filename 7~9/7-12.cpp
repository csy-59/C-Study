#include <iostream>
#include <ctime>
using namespace std;

/*���� �迭�� 0~999 ������ ���� �����Ͽ����ϴ�*/
/*�������� �����̴� �����ϴ� �ð��� �����ɷ��� �׷����ϴ�...*/
/*���� �ð��� 0���� ������ ���� ���� �ð��� �ʹ� ª�� �����ϱ� ��Ʊ� �����Դϴ�...*/

//����� �Լ�(list 7.9, 7.10)
double linearSearch(const int list[], int key, int arraySize); //���� Ž��
double binarySearch(const int list[], int key, int listSize); //���� Ž��
void createArray(int list[], int listSize);//�迭 ����
void Sort(int list[], int listSize); //�迭 ����(���� ����)

int main() {
	srand(time(0));
	const int SIZE = 100000;
	int array[SIZE];
	int key = rand() % 1000;

	createArray(array, SIZE);
	
	//���� Ž��
	cout << "Time using LinearSearch: " << linearSearch(array, key, SIZE) << "s" << endl;

	//�迭 ����
	cout << "Sorting...." << endl;
	Sort(array, SIZE);

	//���� Ž��
	cout << "Time using BinarySearch: " << binarySearch(array, key, SIZE) << "s" << endl;


	return 0;
}

void createArray(int list[], int listSize) {
	for (int i = 0; i < listSize;i++)
		list[i] = rand() % 1000;
}

void Sort(int list[], int listSize) {
	int min, value;
	for (int i = 0;i < listSize;i++) {
		min = i;
		for (int j = i;j < listSize;j++) {
			if (list[min] > list[j])
				min = j;
		}
		value = list[i];
		list[i] = list[min];
		list[min] = value;
	}

	cout << "*Sort succeed!*" << endl;
}

double linearSearch(const int list[], int key, int arraySize) {
	clock_t startTime, endTime;
	startTime = clock();

	for (int i = 0;i < arraySize;i++) {
		if (key == list[i]) {
			cout << key << " is at " << i << endl;
			break;
		}
	}

	endTime = clock();
	return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

double binarySearch(const int list[], int key, int listSize) {
	clock_t startTime, endTime;
	startTime = clock();

	int low = 0;
	int high = listSize - 1;

	while (high >= low) {
		int mid = (low + high) / 2;
		if (key < list[mid])
			high = mid - 1;
		else if (key == list[mid]) {
			cout << key << " is at " << mid << endl;
			break;
		}
		else
			low = mid + 1;
	}

	endTime = clock();
	return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}