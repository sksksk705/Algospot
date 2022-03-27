//2022_03_27 동적계획법
//비대칭 타일링 ASYMTILING

//일단 숫자만큼 그려서 방법을 찾자
//vector에 넣고 펠린드롬인지 확인할까? 연산이 너무 많아 질 거 같은데...
#include <bits/stdc++.h>

using namespace std;

int cache[100];

const int MOD = 1000000007;

int tiling(int n) {
	if (n <= 1)
		return 1;
	int& ret = cache[n];
	return ret = tiling(n - 1) + tiling(n - 2);
}

//대칭인 경우의 수를 전체 경우의 수에서 빼주기
int asymmetric(int width) {
	if (width % 2 == 1)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	int ret = tiling(width);
	ret = (ret - tiling(width / 2)+MOD) % MOD;
	ret = (ret - tiling(width / 2 - 1)+MOD) % MOD;
	return ret;

}

int main()
{
	int C;
	cin >> C;
	memset(cache, -1, sizeof(cache));
	while (C--) {
		int n;
		cin >> n;
		cout << asymmetric(n) << '\n';
	}
	
}