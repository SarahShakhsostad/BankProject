#include <iostream>
#include <queue>
using namespace std;
using namespace std;
int board[9][9];
void generate(int board[9][9]) {
	for (int i = 0; i < 9; i++) {

		for (int i = 0; i < 9; i++) {
			int sw = 0;
			int temp = rand() % 9 + 1;
			for (int j = 0; j < i; j++) {
				if (temp == board[0][j]) sw++;
			}
			if (!sw) {
				board[0][i] = temp;
			}
			else {
				i--;
			}
		}
		
	}
	for (int i = 3; i < 9; i++) {
		board[1][i - 3] = board[0][i];
	}
	for (int i = 0; i < 3; i++) {
		board[1][i + 6] = board[0][i];
	}
}
void main() {
	srand(time(0));
	generate(board);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}