#include <iostream>
#include <ctime>
using namespace std;

/*정수 배열은 0~999 사이의 수로 생성하였습니다*/
/*실행중의 딜레이는 정렬하는 시간이 오래걸려서 그렇습니다...*/
/*실행 시간이 0으로 나오는 것은 실행 시간이 너무 짧아 측정하기 어렵기 때문입니다...*/

//사용할 함수(list 7.9, 7.10)
double linearSearch(const int list[], int key, int arraySize); //선형 탐색
double binarySearch(const int list[], int key, int listSize); //이진 탐색
void createArray(int list[], int listSize);//배열 생성
void Sort(int list[], int listSize); //배열 정렬(선택 정렬)

int main() {
	srand(time(0));
	const int SIZE = 100000;
	int array[SIZE];
	int key = rand() % 1000;

	createArray(array, SIZE);
	
	//선형 탐색
	cout << "Time using LinearSearch: " << linearSearch(array, key, SIZE) << "s" << endl;

	//배열 정렬
	cout << "Sorting...." << endl;
	Sort(array, SIZE);

	//이진 탐색
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