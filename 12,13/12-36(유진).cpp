#include <iostream>
#include <vector>
using namespace std;

const int ROW = 6;
const int COLUMN = 7;
vector<vector<char>> board(ROW);

void printBoard(const vector<vector<char>> board); //게임판(현황) 출력
void dropDisk(vector<vector<char>> board, int dropState[], const int drop, const char color);//디스크를 입력
int minDropColumn(const int dropState[]);//사용자가 입력가능한 최소 열
int maxDropColumn(const int dropState[]);//사용자가 입력가능한 최대 열
bool gameSet(const vector<vector<char>> board, const int dropState[], int* win);//게임 승패, 무승부, 게임중 판별

int main() {
	//char board[ROW][COLUMN] = { '\0' };//게임판
	for (int i = 0;i < ROW;i++)
		board[i] = vector<char>{ '\0','\0','\0','\0','\0','\0','\0' };

	int dropState[COLUMN] = { 0 };//그 줄에 얼마나 디스크가 들어있는지 
	int drop = -1;//사용자가 입력한 열
	int win = -1;//누가 이겼는지, 무승부 여부 판단
	
	while (true) {
		printBoard(board);
		cout << "------------------------" << endl;
		cout << "Drop a red disk a column (" << minDropColumn(dropState) << "-" << maxDropColumn(dropState) << ") : ";
		cin >> drop;
		//dropDisk(board, dropState, drop, 'R');
		board[ROW - 1 - dropState[drop]][drop] = 'R'; //dropState를 이용하여 디스크를 입력할 장소 구하기
		dropState[drop]++;

		if (gameSet(board, dropState, &win))
			break;


		printBoard(board);
		cout << "------------------------" << endl;
		cout << "Drop a yellow disk a column (" << minDropColumn(dropState) << "-" << maxDropColumn(dropState) << ") : ";
		cin >> drop;
		//dropDisk(board, dropState, drop, 'Y');
		board[ROW - 1 - dropState[drop]][drop] ='Y'; //dropState를 이용하여 디스크를 입력할 장소 구하기
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
	board[ROW - 1 - dropState[drop]][drop] = color; //dropState를 이용하여 디스크를 입력할 장소 구하기
	cout << board[ROW - 1 - dropState[drop]][drop] << ROW - 1 - dropState[drop] << drop << endl;
	dropState[drop]++;
}

bool gameSet(const vector<vector<char>> board, const int dropState[], int* win) {
	//승패 판별
	for (int j = 0;j < COLUMN - 3;j++) {

		//해당 열에 디스크가 없으면 넘기기
		if (dropState[j] == 0)
			continue;

		else {
			for (int i = ROW - 1;i > 3;i--) {
				//행 판별
				if (dropState[j] > 3) {
					if ((board[i][j] == board[i - 1][j]) & (board[i - 1][j] == board[i - 2][j]) & (board[i - 2][j] == board[i - 3][j])) {
						if (board[i][j] == 'R')
							*win = 1;
						else if (board[i][j] == 'Y')
							*win = 2;
						return true;
					}
				}

				//열 판별
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

				//윗쪽 대각선 판별
				if ((dropState[j + 1] > ROW - i)&(dropState[j + 2] > ROW - 1 - i)&(dropState[j + 3] > ROW - 2 - i)) {
					if ((board[i][j] == board[i - 1][j + 1])&(board[i - 1][j + 1] == board[i - 2][j + 2])&(board[i - 2][j + 2] == board[i - 3][j + 3])) {
						if (board[i][j] == 'R')
							*win = 1;
						else if (board[i][j] == 'Y')
							*win = 2;
						return true;
					}
				}

				//아랫쪽 대각선 판별
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
	//무승부, 게임 중 판별
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