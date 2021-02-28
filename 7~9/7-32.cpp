#include <iostream>
using namespace std;

void prefix(const char s1[], const char s2[], char commonPrefix[]);

int main() {
	char s1[1000], s2[1000], commonPrefix[100] = { '\0' };

	cout << "Enter s1: ";
	cin.getline(s1, 1000, '\n');
	cout << "Enter s2: ";
	cin.getline(s2, 1000, '\n');

	prefix(s1, s2, commonPrefix);

	return 0;
}


void prefix(const char s1[], const char s2[], char commonPrefix[]) {
	bool flag = false;//prefix가 있는지 판별
	for (int i = 0;i < strlen(s1); i++) {
		if (s1[i] == s2[i]) {
			commonPrefix[i] = s1[i];
			flag = true;
		}
		else
			break;
	}
	if (flag)
		cout << "The common prefix is " << commonPrefix << endl;
	else
		cout << s1 << " and " << s2 << " have no common prefix" << endl;
}