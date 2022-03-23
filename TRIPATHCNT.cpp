//2022_03_23 전통적 최적화 문제 13:35
//삼각형 위의 최대 경로의 수 - 다른 문제인데 잘못 품

#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;
int maxValue;
int triangle[100][100];

//완전탐색에서 시작
void getPath(int y, int x, int prev) {
	int now = triangle[y][x] + prev;
	//가장 밑에 도달했을 때
	if (y == n-1) {
		if (now > maxValue) {
			maxValue = now;
			ans = 1;
		}
		else if (now == maxValue)
			ans++;
		return;
	}
	//바로 밑으로 이동
	getPath(y + 1, x, now);
	//오른쪽 아래로 이동
	getPath(y + 1, x + 1, now);
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				cin >> triangle[i][j];
			}
		}
		maxValue = -1;
		ans = 0;
		getPath(0, 0, 0);
		cout << ans<<'\n';
	}
}