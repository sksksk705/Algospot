//동적계획법 외발뛰기 2022_03_22 
//일단 재귀적으로 만들어보기

#include <bits/stdc++.h>

using namespace std;

int n;
int board[100][100];

//캐싱용
int cache[100][100];

//범위체크
bool inRange(int x, int y) {
	if (x < 0 || x >= n ||
		y < 0 || y >= n)
		return false;
	return true;
}

//완전탐색
bool canReachEnd(int x, int y) {
	//기저사례1: 범위초과
	if (!inRange(x, y))
		return false;
	//기저사례2: 끝에 도착
	if (x == n - 1 && y == n - 1)
		return true;
	return (canReachEnd(x + board[y][x], y) || canReachEnd(x, y + board[y][x]));
}

//동적계획법
bool canReachEndDP(int x, int y) {
	//기저사례1: 범위초과
	if (!inRange(x, y))
		return false;
	int& ret = cache[y][x];
	//부분문제: 이미 다녀와본 길의 결과
	if (ret != -1)
		return ret;
	return ret = (canReachEndDP(x + board[y][x], y) || canReachEndDP(x, y + board[y][x]));
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> board[i][j];

		//끝점은 캐싱의 정답으로
		cache[n - 1][n - 1] = 1;
		//if (canReachEnd(0, 0))
		if (canReachEndDP(0, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}