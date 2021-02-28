#include <iostream>
#include <vector>
using namespace std;

const int ROW = 6;
const int COLUMN = 7;
vector<vector<char>> board(ROW);

void printBoard(const vector<vector<char>> board); //������(��Ȳ) ���
void dropDisk(vector<vector<char>> board, int dropState[], const int drop, const char color);//��ũ�� �Է�
int minDropColumn(const int dropState[]);//����ڰ� �Է°����� �ּ� ��
int maxDropColumn(const int dropState[]);//����ڰ� �Է°����� �ִ� ��
bool gameSet(const vector<vector<char>> board, const int dropState[], int* win);//���� ����, ���º�, ������ �Ǻ�

int main() {
	//char board[ROW][COLUMN] = { '\0' };//������
	for (int i = 0;i < ROW;i++)
		board[i] = vector<char>{ '\0','\0','\0','\0','\0','\0','\0' };

	int dropState[COLUMN] = { 0 };//�� �ٿ� �󸶳� ��ũ�� ����ִ��� 
	int drop = -1;//����ڰ� �Է��� ��
	int win = -1;//���� �̰����, ���º� ���� �Ǵ�
	
	while (true) {
		printBoard(board);
		cout << "------------------------" << endl;
		cout << "Drop a red disk a column (" << minDropColumn(dropState) << "-" << maxDropColumn(dropState) << ") : ";
		cin >> drop;
		//dropDisk(board, dropState, drop, 'R');
		board[ROW - 1 - dropState[drop]][drop] = 'R'; //dropState�� �̿��Ͽ� ��ũ�� �Է��� ��� ���ϱ�
		dropState[drop]++;

		if (gameSet(board, dropState, &win))
			break;


		printBoard(board);
		cout << "------------------------" << endl;
		cout << "Drop a yellow disk a column (" << minDropColumn(dropState) << "-" << maxDropColumn(dropState) << ") : ";
		cin >> drop;
		//dropDisk(board, dropState, drop, 'Y');
		board[ROW - 1 - dropState[drop]][drop] ='Y'; //dropState�� �̿��Ͽ� ��ũ�� �Է��� ��� ���ϱ�
		dropState[drop]++;

		if (gameSet(board, dropState, &win))
			break;
	}

	printBoard(board);
	cout << "------------------------" << endl;

	if (win == 0)
		cout << "The game is tied" << endl;
	else if (win == 1)
		cout << "The red player won" << endl;
	else if (win == 2)
		cout << "The yellow player won" << endl;
	else
		cout << "Error" << endl;

		
	return 0;
}

void printBoard(const vector<vector<char>> board) {
	for (int i = 0;i < ROW;i++) {
		cout << "|";
		for (int j = 0;j < COLUMN;j++) {
			if (board[i][j] == '\0')
				cout << " |";
			else
				cout << board[i][j] << "|";
		}
		cout << endl;
	}
}

void dropDisk(vector<vector<char>> board, int dropState[], const int drop, const char color) {
	board[ROW - 1 - dropState[drop]][drop] = color; //dropState�� �̿��Ͽ� ��ũ�� �Է��� ��� ���ϱ�
	cout << board[ROW - 1 - dropState[drop]][drop] << ROW - 1 - dropState[drop] << drop << endl;
	dropState[drop]++;
}

bool gameSet(const vector<vector<char>> board, const int dropState[], int* win) {
	//���� �Ǻ�
	for (int j = 0;j < COLUMN - 3;j++) {

		//�ش� ���� ��ũ�� ������ �ѱ��
		if (dropState[j] == 0)
			continue;

		else {
			for (int i = ROW - 1;i > 3;i--) {
				//�� �Ǻ�
				if (dropState[j] > 3) {
					if ((board[i][j] == board[i - 1][j]) & (board[i - 1][j] == board[i - 2][j]) & (board[i - 2][j] == board[i - 3][j])) {
						if (board[i][j] == 'R')
							*win = 1;
						else if (board[i][j] == 'Y')
							*win = 2;
						return true;
					}
				}

				//�� �Ǻ�
				if ((dropState[j + 1] > ROW - 1 - i)&(dropState[j + 2] > ROW - 1 - i)&(dropState[j + 3] > ROW - 1 - i)) {
					if ((board[i][j] == board[i][j + 1])&(board[i][j + 1] == board[i][j + 2])&(board[i][j + 2] == board[i][j + 3])) {
						if (board[i][j] == 'R')
							*win = 1;
						else if (board[i][j] == 'Y')
							*win = 2;
						cout << board[i][j] << endl;
						return true;
					}
				}

				//���� �밢�� �Ǻ�
				if ((dropState[j + 1] > ROW - i)&(dropState[j + 2] > ROW - 1 - i)&(dropState[j + 3] > ROW - 2 - i)) {
					if ((board[i][j] == board[i - 1][j + 1])&(board[i - 1][j + 1] == board[i - 2][j + 2])&(board[i - 2][j + 2] == board[i - 3][j + 3])) {
						if (board[i][j] == 'R')
							*win = 1;
						else if (board[i][j] == 'Y')
							*win = 2;
						return true;
					}
				}

				//�Ʒ��� �밢�� �Ǻ�
				if ((dropState[COLUMN - 1 - j] > 0)&(dropState[COLUMN - 2 - j] > 1)&(dropState[COLUMN - 3 - j] > 2)&(dropState[COLUMN - 4 - j] > 3)&(i>ROW - 1 - dropState[COLUMN - 1 - j])) {
					if ((board[i][COLUMN - 1 - j] == board[i - 1][COLUMN - 2 - j])&(board[i - 1][COLUMN - 2 - j] == board[i - 2][COLUMN - 3 - j])&(board[i - 2][COLUMN - 3 - j] == board[i - 3][COLUMN - 4 - j])) {
						if (board[i][COLUMN - 2 - j] == 'R')
							*win = 1;
						else if (board[i][COLUMN - 2 - j] == 'Y')
							*win = 2;
						return true;
					}
				}
			}
		}
	}

	bool flag = true;
	//���º�, ���� �� �Ǻ�
	for (int i = 0;i < COLUMN; i++) {
		if (dropState[i] != ROW) {
			flag = false;
			break;
		}
	}

	if (flag)
		*win = 0;


	return flag;

}

int minDropColumn(const int dropState[]) {
	for (int i = 0;i < COLUMN;i++)
		if (dropState[i] != COLUMN - 1)
			return i;
}

int maxDropColumn(const int dropState[]) {
	for (int i = COLUMN - 1;i >= 0;i--)
		if (dropState[i] != COLUMN - 1)
			return i;
}