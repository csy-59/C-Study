#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	char commonCharacters[100] = { '\0' };
	int size = 0;

	cout << "Enter a string s1: ";
	cin >> s1;
	cout << "Enter a string s2: ";
	cin >> s2;

	for (int i = 0;i < s1.size();i++) {
		if (s2.find(s1[i]) != string::npos) {
			commonCharacters[size] = s1[i];
			size++;
		}
	}

	if (strlen(commonCharacters) != 0) {
		cout << "The common characters are ";
		for (int i = 0;i < strlen(commonCharacters);i++)
			cout << commonCharacters[i];
		cout << endl;
	}
	else
		cout << "No common characters" << endl;

	return 0;
}