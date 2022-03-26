//2022_03_26 18:00 동적계획법-경우의수
//TILING2 타일링 방법의 수 세기

#include <bits/stdc++.h>

using namespace std;

int cache[101];
const int MOD = 1000000007;

int tiling(int n) {
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	int& ret = cache[n];
	if (ret != -1)
		return ret;
	ret = tiling(n - 2) + tiling(n - 1);
	ret %= MOD;
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		cout << tiling(n)<<'\n';
	}
}