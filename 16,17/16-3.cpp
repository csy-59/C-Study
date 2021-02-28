#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Course{
public:
	Course(const string& courseName, int capacity);
	~Course();
	string getCourseName() const;
	void addStudent(const string& name);
	void dropStudent(const string& name);
	string* getStudents() const;
	int getNumberOfStudents() const;

private:
	string courseName;
	string* students;
	int numberOfStudents;
	int capacity;
};

Course::Course(const string& courseName, int capacity) {
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}
Course::~Course() {
	delete[] students;
}
string Course::getCourseName() const {
	return courseName;
}
void Course::addStudent(const string& name) {
	if (numberOfStudents + 1 > capacity)
		throw runtime_error("Students number is over capacity");
	students[numberOfStudents] = name;
	numberOfStudents++;
}
void Course::dropStudent(const string& name) {
	int position = -1;

	for (int i = 0;i < numberOfStudents;i++) {
		if (students[i] == name) {
			position = i;
			break;
		}
	}

	if (position != -1) {
		for (int i = position;i < numberOfStudents - 1;i++) {
			students[i] = students[i + 1];
		}
		numberOfStudents--;
	}

}
string* Course::getStudents() const {
	return students;
}
int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

int main() {
	Course c1("C++", 3);
	string name = "Student";
	for (int i = 0; i < 4;i++) {
		cout << "Adding Student" << i << "..." << endl;
		name += "1" + i;
		try {
			c1.addStudent(name);
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	return 0;
}