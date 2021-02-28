#include <iostream>
#include <string>
using namespace std;

template<typename T>
int binarySearch(const T list[], T key, int listSize);

int main() {
	const int SIZE = 6;
	int intSearch[] = { 2, 5, 12, 77, 98, 120 };
	double doubleSearch[] = { 3.6, 8.92, 53.7, 89.1, 93.3, 105.8 };
	string stringSearch[] = { "apple","blue","corn","exam","garmmer", "jelly" };

	cout << "Int List: " << endl;
	for (int i = 0;i < SIZE;i++)
		cout << intSearch[i] << " ";
	cout << endl;
	cout << "Finding 77 by using binarySearch: " << binarySearch(intSearch, 77, SIZE) << "\n" << endl;

	cout << "Double List: " << endl;
	for (int i = 0;i < SIZE;i++)
		cout << doubleSearch[i] << " ";
	cout << endl;
	cout << "Finding 93.3 by using binarySearch: " << binarySearch(doubleSearch, 93.3, SIZE) << "\n" << endl;

	cout << "String List: " << endl;
	for (int i = 0;i < SIZE;i++)
		cout << stringSearch[i] << " ";
	cout << endl;
	cout << "Finding corn by using binarySearch: " << binarySearch(stringSearch, string("corn"), SIZE) << "\n" << endl;

	return 0;
}

template<typename T>
int binarySearch(const T list[], T key, int listSize) {
	int low = 0;
	int high = listSize - 1;

	while (high >= low) {
		int mid = (low + high) / 2;
		if (key < list[mid])
			high = mid - 1;
		else if (key == list[mid])
			return mid;
		else
			low = mid + 1;
	}

	return -low - 1;
}