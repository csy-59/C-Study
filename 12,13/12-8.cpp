#include <iostream>
#include "Vector.h"
using namespace std;

template<typename T>
void printMyVector(const Vector<T>& v) {
	for (int i = 0;i < v.size();i++)
		cout << v.vectorList[i] << " ";
	cout << endl;
}

int main() {
	Vector<int> v1, v2(5), v3(5, 100);
	
	//생성자, push_back 태스트
	for (int i = 0;i < 7;i++)
		v1.push_back(i+1);
	cout << "v1: ";
	printMyVector(v1);
	cout << "v2: ";
	printMyVector(v2);
	cout << "v3: ";
	printMyVector(v3);
	cout << endl;

	//pop_back 태스트
	v1.pop_back();
	cout << "v1: ";
	printMyVector(v1);
	cout << endl;

	//size, at 태스트
	cout << "Size of v1 is " << v1.size() << endl;
	cout << "4th Element int v1 is " << v1.at(3) << endl;
	cout << endl;

	//swap 태스트
	v1.swap(v2);
	cout << "v1: ";
	printMyVector(v1);
	cout << "v2: ";
	printMyVector(v2);
	cout << endl;

	//clear, empty 태스트
	v2.clear();
	if (v2.empty())
		cout << "v2 is empty" << endl;
	else
		cout << "v2 is not empty" << endl;


	return 0;
}