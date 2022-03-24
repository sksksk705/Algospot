//2022_03_24 동적계획법
//PI 원주율 외우기

//3,4,5글자로 나누고 문제 난이도 판별해서 다 찾아보기
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int cache[10000];
int n;
string sPI;

//구현을 할 수는 있는데 너무 복잡함.
int checkDiff(int idx, int prev) {
	int diff = 0;
	int lastNum = sPI[prev];
	return diff;
}

int PI(int idx) {
	int& ret = cache[idx];
	if (ret != INF)
		return ret;
	for (int i = 3; i < 6; ++i) {
		if (idx + i < n) {
			ret = min(ret, PI(idx + i) + checkDiff(idx, idx+i-1));
		}
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> sPI;
		n = sPI.size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cache[i][j] = INF;
		cout << PI(0, 0);
	}
}