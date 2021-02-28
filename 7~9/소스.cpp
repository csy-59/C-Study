#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 8;
void printBoard(const char board[][SIZE]);
void makeBoard(char board[][SIZE]);

int main() {
	char board[SIZE][SIZE] = { '\0' };

	makeBoard(board);

	return 0;
}

void printBoard(const char board[][SIZE]) {
	for (int i = 0;i < SIZE;i++) {
		cout << "|";
		for (int j = 0;j < SIZE;j++) {
			if (board[i][j] == '\0')
				cout << " |";
			else
				cout << board[i][j] << "|";
		}
		cout << endl;
	}
}

void makeBoard(char board[][SIZE]) {
	bool isThereQ[SIZE] = { false };
	bool flag = true;//가능한 자리인지 판별

	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			if (!isThereQ[j]) {
				for (int c = 1;c <= i;c++) {
					if (board[i - c][j - c] == 'Q') {
						flag = false;
						break;
					}
					if (j - c == 0)
						break;
				}
				for (int c = 1;c <= i;c++) {
					if (board[i - c][j + c] == 'Q') {
						flag = false;
						break;
					}
					if (j + c == SIZE - 1)
						break;
				}

				if (flag) {
					cout << i << ", " << j << endl;
					board[i][j] = 'Q';
					isThereQ[j] = true;
					break;
				}

				flag = true;
			}
			else
				continue;
		}
		printBoard(board);
	}

}