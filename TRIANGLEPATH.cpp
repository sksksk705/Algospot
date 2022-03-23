#include <bits/stdc++.h>

using namespace std;

int n;
int triangle[100][100];
int cache[100][100];

//완전탐색에서 시작
int getPath(int y, int x, int prev) {
	int now = triangle[y][x] + prev;
	//가장 밑에 도달했을 때
	if (y == n - 1)	return now;

	//바로 밑으로 이동,오른쪽 아래로 이동
	return max(getPath(y + 1, x, now), getPath(y + 1, x + 1, now));
}

//동적계획법 - prev는 앞으로의 문제해결에 도움이 안 됨
int getPathDP(int y, int x) {
	//기저사례1: 가장 밑에 도달했을 때
	if (y == n - 1)	return triangle[y][x];
	int& ret = cache[y][x];

	//이미 해결된 문제
	if (ret != -1)
		return ret;

	//바로 밑으로 이동,오른쪽 아래로 이동
	return ret = max(getPathDP(y + 1, x), getPathDP(y + 1, x + 1)) + triangle[y][x];
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		memset(triangle, 0, sizeof(triangle));
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				cin >> triangle[i][j];
			}
		}
		//getPath(0,0,0);
		cout << getPathDP(0, 0) << '\n';
	}
}