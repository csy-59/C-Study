#include <iostream>
#include <stdexcept>
using namespace std;

class EmptyStackException : public runtime_error {
public:
	EmptyStackException(int size) : runtime_error("Error! Stack is empty") {
		this->size = size;
	}
	double getSize() {
		return size;
	}
private:
	int size;
};

class StackOfIntegers
{
public:
	StackOfIntegers() {
		size = 0;
	}
	bool isEmpty() const {
		return size == 0;
	}
	int peek() const {
		if (this->isEmpty())
			throw EmptyStackException(size);
		return elements[size - 1];
	}
	int push(int value) {
		elements[size++] = value;
	}
	int pop() {
		if (this->isEmpty())
			throw EmptyStackException(size);
		return elements[--size];
	}
	int getSize() const {
		return size;
	}

private:
	int elements[100];
	int size;
};

int main() {
	StackOfIntegers s1;
	cout << "s1->peek():" << endl;
	try {
		s1.peek();
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	cout << "s1->pop():" << endl;
	try {
		s1.pop();
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}