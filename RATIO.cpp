//2022_04_13 수치해석 이분법
//RATIO 승률 올리기

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000000000;

//played: 게임수
//win: 이긴 게임수
int solve(double played, double win)
{
	int lo = 0;
	int hi = 2000000000;
	double winRate = win / played * 100;
	for (int i = 0; i < 100; ++i) {
		int mid = (lo + hi) / 2;
		double newWinRate = (win + mid) / (played + mid) * 100;
		if ((int)newWinRate - (int)winRate >= 1)
			hi = mid;
		else
			lo = mid;
	}
	if (hi == MAX)
		return -1;
	else
		return hi;
}


int main() {
	int C;
	cin >> C;
	while (C--)
	{
		double n, m;
		cin >> n >> m;
		cout << solve(n, m) << '\n';
	}
}