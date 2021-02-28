#pragma once
#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {
public:
	Vector();
	Vector(int size);
	Vector(int size, T defaultValue);
	~Vector();

	void push_back(T element);
	void pop_back();
	unsigned size() const;
	T at(int index) const;
	bool empty() const;
	void clear();
	void swap(Vector<T>& v2);

	T* vectorList;
	int Size;
private:
	const int MAX_SIZE = 50;
	int capacity;
	T defaultValue;
};

template<typename T>
Vector<T>::Vector() : Size(0), capacity(50), defaultValue('\0') {
	vectorList = new T[MAX_SIZE];
}
template<typename T>
Vector<T>::Vector(int size){
	this->Size = size;
	capacity = 0;

	while (capacity < size)
		capacity += MAX_SIZE;

	vectorList = new T[this->capacity];

	this->defaultValue = '\0';
	for (int i = 0;i < this->Size;i++)
		this->vectorList[i] = this->defaultValue;
}
template<typename T>
Vector<T>::Vector(int size, T defaultValue) {
	this->Size = size;
	capacity = 0;

	while (capacity < size)
		capacity += MAX_SIZE;

	vectorList = new T[this->capacity];

	this->defaultValue = defaultValue;
	for (int i = 0;i < this->Size;i++)
		this->vectorList[i] = this->defaultValue;
}
template<typename T>
Vector<T>::~Vector() {
	delete[] vectorList;
}

template<typename T>
void Vector<T>::push_back(T element) {
	if (this->Size + 1 > capacity)
		capacity += MAX_SIZE;

	this->vectorList[Size] = element;
	this->Size++;

}
template<typename T>
void Vector<T>::pop_back() {
	this->Size--;
}
template<typename T>
unsigned Vector<T>::size() const {
	return this->Size;
}
template<typename T>
T Vector<T>::at(int index) const {
	return this->vectorList[index];
}
template<typename T>
bool Vector<T>::empty() const {
	if (this->Size == 0)
		return true;
	return false;

}
template<typename T>
void Vector<T>::clear() {
	this->Size = 0;
}
template<typename T>
void Vector<T>::swap(Vector<T>& v2) {
	int maxSize, minSize;
	if (this->Size > v2.size()) {
		maxSize = this->Size;
		minSize = v2.size();

		for (int i = 0;i < minSize;i++) {
			T buff = this->at(i);
			this->vectorList[i] = v2.at(i);
			v2.vectorList[i] = buff;
		}

		for (int i = minSize;i < maxSize;i++)
			v2.push_back(this->at(i));

		this->Size = minSize;
	}
	else {
		maxSize = v2.size();
		minSize = this->size();

		for (int i = 0;i < minSize;i++) {
			T buff = this->at(i);
			this->vectorList[i] = v2.at(i);
			v2.vectorList[i] = buff;
		}

		for (int i = minSize;i < maxSize;i++)
			this->push_back(v2.at(i));

		v2.Size = minSize;
	}

	cout << endl;
}
#endif // !VECTOR_H
