#include <iostream>
using namespace std;

const int SIZE = 3;
void printBoard(const char board[][SIZE]);//���Ӻ��� ���
void markBoard(char board[][SIZE], int row, int column, char side, int *error);//xoǥ���ϱ�
int gameSet(const char board[][SIZE], char side);//����, ������ �Ǻ�
bool isTied(const char board[][SIZE]);//���º� �Ǻ�

int main() {
	char board[SIZE][SIZE] = { '\0' };
	int markRow = -1;
	int markColumn = -1;
	int error = 0; //�Է°����� ������� �Ǻ�

	while (true) {
		printBoard(board);
		while (true) {
			cout << "Enter a row (0, 1, or 2) for player X: ";
			cin >> markRow;
			cout << "Enter a column (0, 1, or 2) for player X: ";
			cin >> markColumn;
			markBoard(board, markRow, markColumn, 'X', &error);
			if (error == 1) {
				cout << "That spot is aready taken. Try again." << endl;
				error = 0;
			}
			else if (error == 0)
				break;
		}

		//�¸� �Ǻ�
		if (gameSet(board, 'X') == 1) {
			printBoard(board);
			cout << "X player won" << endl;
			break;
		}
		//���º�
		else if (gameSet(board, 'X') == 2) {
			printBoard(board);
			cout << "The game is tied" << endl;
		}

		printBoard(board);
		while (true) {
			cout << "Enter a row (0, 1, or 2) for player O: ";
			cin >> markRow;
			cout << "Enter a column (0, 1, or 2) for player O: ";
			cin >> markColumn;
			markBoard(board, markRow, markColumn, 'O', &error);
			if (error == 1) {
				cout << "That spot is aready taken. Try again." << endl;
				error = 0;
			}
			else if (error == 0)
				break;
		}

		if (gameSet(board, 'O') == 1) {
			printBoard(board);
			cout << "O player won" << endl;
			break;
		}
		else if (gameSet(board, 'O') == 2) {
			printBoard(board);
			cout << "The game is tied" << endl;
		}


	}

	return 0;
}

void printBoard(const char board[][SIZE]) {

	cout << "---------------" << endl;
	for (int i = 0;i < SIZE;i++) {
		cout << " | ";
		for (int j = 0;j < SIZE;j++) {
			if (board[i][j] == '\0')
				cout << "  | ";
			else
				cout << board[i][j] << " | ";
		}
		cout << "\n---------------" << endl;
	}
}

void markBoard(char board[][SIZE], int row, int column, char side, int *error) {
	if (board[row][column] != '\0') //�̹� ox�� �����Ѵٸ�(ä�����ִٸ�)
		*error = 1;
	else
		board[row][column] = side;
}

int gameSet(const char board[][SIZE], char side) {
	bool flag = false;
	int count = 0;

	//row column ���� �Ǻ�
	for (int i = 0;i < SIZE;i++) {
		count = 0;
		for (int j = 0;j < SIZE;j++)
			if (board[i][j] == side)
				count++;
		if (count == SIZE)
			return 1;
	}
	count = 0;

	//�Ʒ��� �밢�� ���� �Ǻ�
	for (int i = 0;i < SIZE;i++)
		if (board[i][i] == side)
			count++;
	if (count == SIZE)
		return 1;
	count = 0;

	//���� �밢�� ���� �Ǻ�
	for (int i = SIZE - 1;i >= 0;i--)
		if (board[i][SIZE - 1 - i] == side)
			count++;
	if (count == SIZE)
		return 1;
	count = 0;

	if (isTied(board))
		return 2;
}

bool isTied(const char board[][SIZE]) {
	for (int i = 0;i < SIZE;i++)
		for (int j = 0;j < SIZE;j++)
			if (board[i][j] == '\0')
				return false;

	return true;
}