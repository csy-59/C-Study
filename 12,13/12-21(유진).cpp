//¹Ì¿Ï
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

string cardNames[] = { "Spades","Diamonds","Hearts","Clubs" };
string cardNumbers[] = { "Ace", "2","3","4","5","6","7","8","9","10","Jack","Queen","King" };


int isVailable(int operatingNumber, int operNum, int count, int targetNumber) {
	if (count == 4)
		return operatingNumber;
	else {
		int result = 0;
		for (int i = 0;i < 4;i++) {
			switch (operNum)
			{
			case 0: result += isVailable(operatingNumber + 1, i, count + 1, 24); break;
			case 1: result -= isVailable(operatingNumber + 1, i, count + 1, 24); break;
			case 2: result *= isVailable(operatingNumber + 1, i, count + 1, 24); break;
			case 3: result /= isVailable(operatingNumber + 1, i, count + 1, 24); break;
			default: cout << "Error! Wrong operNum" << endl;
				return -1;
				break;
			}
		}

	}
}


int main() {
	int wrongCount;
	int totalCount;
	bool isFound = false;

	for (int i1 = 1;i1 <= 49;i1++) {
		for (int i2 = i1 + 1;i2 <= 50;i2++) {
			for (int i3 = i2 + 1;i3 <= 51;i3++) {
				for (int i4 = i3 + 1;i4 <= 52;i4++) {
					totalCount++;
					if (i1 + i2 + i3 + i4 == 24)
						wrongCount++;
					else if (i1 + i2 + i3 - i4 == 24)
						wrongCount++;
					else if (i1 + i2)
						wrongCount++;
				}
			}
		}
	}
}