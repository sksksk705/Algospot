//2022_03_24 ������ȹ��
//PI ������ �ܿ��

//3,4,5���ڷ� ������ ���� ���̵� �Ǻ��ؼ� �� ã�ƺ���
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int cache[10000];
int n;
string sPI;

//������ �� ���� �ִµ� �ʹ� ������.
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