//2022_04_12 조합탐색
//KAKURO2 카쿠로

//비트마스크 공부하고 다시 봐야할듯.
#include <bits/stdc++.h>

using namespace std;

int boolBoard[21][21];
int realBoard[21][21];
int hint[21][21][2];
int n, q;

bool check(int y, int x, int value) {
	int sum = value;
	for (int row = y-1; row >= 1; --row) {
		if (boolBoard[row][x] == 0) {
			if (sum > hint[row][x][1])
				return false;
		}
		else {
			if (realBoard[row][x] == realBoard[y][x])
				return false;
			else
				sum += realBoard[row][x];
		}
	}

	sum = value;
	for (int col = x - 1; col >= 1; --col) {
		if (boolBoard[y][col] == 0) {
			if (sum > hint[y][col][0])
				return false;
		}
		else {
			if (realBoard[y][col] == realBoard[y][x])
				return false;
			else
				sum += realBoard[y][col];
		}
	}
	return true;
}

void printBoard() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
		{
			cout << realBoard[i][j] << ' ';
		}
		cout << '\n';
	}

}

bool solve() {
	int y = -1, x = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			if (boolBoard[i][j] == 1 && realBoard[i][j] == 0 && y == -1) {
				y = i;
				x = j;
			}
		if (y != -1)
			break;
	}

	//기저사례: 모든 칸이 채워졌다.
	if (y == -1) {
		printBoard();
		return true;
	}


	for (int num = 1; num < 10; ++num) {
		realBoard[y][x] = num;
		if (check(y, x, num))
			if (solve())
				return true;
		realBoard[y][x] = 0;
	}

}

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> boolBoard[i][j];
			realBoard[i][j] = 0;
		}

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int y, x, dir, sum;
		cin >> y >> x >> dir >> sum;
		hint[y][x][dir] = sum;
	}
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		input();
		solve();
	}
}