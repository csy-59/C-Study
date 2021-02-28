#include <iostream>
using namespace std;

void count(const char s[], int counts[]);

int main() {
	char s[1000];
	int counts[26] = { 0 };

	cout << "Enter a string: ";
	cin.getline(s, 1000, '\n');

	count(s, counts);

	for (int i = 0;i < 26;i++) 
		if (counts[i] != 0) 
			cout << static_cast<char>('a' + i) << ": " << counts[i] << " times" << endl;

	return 0;
}

void count(const char s[], int counts[]) {
	for (int i = 0;i < strlen(s);i++) {
		if (isupper(s[i]))
			counts[s[i] - 'A']++;
		else if(islower(s[i]))
			counts[s[i] - 'a']++;
	}
}