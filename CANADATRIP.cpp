//2022_04_12 ����ȭ������ ����������
//CANADATRIP ĳ���� ����

//����ȭ�� �� ���ڸ�:
//1. �κ����� �̸� �� �س���(� ���ñ��� �������� �� ǥ������ ����)
#include <bits/stdc++.h>

using namespace std;

//city 0: ���� ���ñ��� �Ÿ�, 1: ǥ���� �Ÿ�, 2: ǥ���� �� �Ÿ�
int city[5001][3];
//n: ���ü�
//k: ǥ���� ��
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