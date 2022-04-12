//2022_04_12 최적화문제를 결정문제로
//CANADATRIP 캐나다 여행

//최적화를 더 하자면:
//1. 부분합을 미리 더 해놓기(어떤 도시까지 도착했을 때 표지판의 갯수)
#include <bits/stdc++.h>

using namespace std;

//city 0: 다음 도시까지 거리, 1: 표지판 거리, 2: 표지판 간 거리
int city[5001][3];
//n: 도시수
//k: 표지판 수
int n, k;

bool decision(int dist) {
	int seen = 0;
	for (int i = 0; i < n; ++i) {
		if (dist >= city[i][0])
		{
			seen += city[i][1] / city[i][2]+1;
		}
		else
		{
			int remain = dist - (city[i][0] - city[i][1]);
			if (remain >= 0)
				seen += remain / city[i][2] + 1; 
		}
	}
	return seen >= k;
}

int solve() {
	int lo = 0;
	int hi = INT_MAX;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid))
		{
			hi = mid-1;
			ans = mid;
		}
		else
			lo = mid+1;
	}
	return ans;
}

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> city[i][0] >> city[i][1] >> city[i][2];
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		input();
		int result = solve();
		cout << result << '\n';
	}
}