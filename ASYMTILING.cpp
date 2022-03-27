//2022_03_27 ������ȹ��
//���Ī Ÿ�ϸ� ASYMTILING

//�ϴ� ���ڸ�ŭ �׷��� ����� ã��
//vector�� �ְ� �縰������� Ȯ���ұ�? ������ �ʹ� ���� �� �� ������...
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

//��Ī�� ����� ���� ��ü ����� ������ ���ֱ�
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