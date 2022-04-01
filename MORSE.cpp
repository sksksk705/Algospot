//2022_04_01 동적계획법 테크닉
//MORSE 모스부호

//이항계수? 로 표현할 수 있다...?
//경우의 수는 수학적으로 생각할 수 있어야 문제를 풀 수 있을 거 같다...
#include<bits/stdc++.h>

using namespace std;

vector<string> vec;

int bino[201][201];
const int M = 1000000000 + 100;
int skip;

void calcBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; ++i) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; ++j)
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}

void morse(int n, int m, string s) {
	if(skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}
	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0) morse(n - 1, m, s + "-");
	if (m > 0) morse(n, m-1, s + "o");
}

int main() {
	int C;
	cin >> C;
	calcBino();
	while (C--) {
		vec.clear();
		int n, m, k;
		cin >> n >> m >> k;
		skip = k - 1;
		morse(n, m, "");
	}
}