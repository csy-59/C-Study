#include <iostream>
#include <string>
using namespace std;

void count(const string& s, int counts[], int size);

int main() {
	string s;
	int counts[26] = { 0 };
	int size = 26;

	cout << "Enter a string: ";
	getline(cin, s);

	count(s, counts, size);

	for (int i = 0;i < 26;i++)
		if (counts[i] != 0)
			cout << static_cast<char>('a' + i) << ": " << counts[i] << " times" << endl;

	return 0;
}

void count(const string& s, int counts[], int size) {
	for (int i = 0;i < s.size();i++) {
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
			counts[s[i] - 'A']++;
		else if ((s[i] >= 'a') && (s[i] <= 'z'))
			counts[s[i] - 'a']++;
	}
}