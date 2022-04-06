//2022_04_05 조합게임
//TICTACTOE 틱택토

//3 * 3 배열을 아홉자리 3진수로 표현(0: 아무도 안 둠, 1 : A, 2: B)
//결과: 무조건 비긴다
#include <bits/stdc++.h>

using namespace std;

//
bool isFinished(const vector<string>& board, char turn) {}

int bijection(const vector<string>& board)
{
	int ret = 0;
	for(int y = 0; y< 3;++y)
		for (int x = 0; x < 3; ++x) {
			ret = ret * 3;
			if (board[y][x] == 'o') ++ret;
			else if (board[y][x] == 'x') ret += 2;
		}
	return ret;
}

int cache[19683];

int canWin(vector<string>& board, char turn) {
	if (isFinished(board, 'o' + 'x' - turn)) return -1;
	int& ret = cache[bijection(board)];
	if (ret != -1) return ret;
	int minValue = 2;
	for (int y = 0; y < 3; ++y)
		for (int x = 0; x < 3; ++x)
			if (board[y][x] == '.') {
				board[y][x] = turn;
				minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
				board[y][x] = '.';
			}
	if (minValue == 2 || minValue == 0) return ret;
	return ret = -minValue;
}


int main() {

}