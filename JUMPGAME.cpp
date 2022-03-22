//������ȹ�� �ܹ߶ٱ� 2022_03_22 
//�ϴ� ��������� ������

#include <bits/stdc++.h>

using namespace std;

int n;
int board[100][100];

//ĳ�̿�
int cache[100][100];

//����üũ
bool inRange(int x, int y) {
	if (x < 0 || x >= n ||
		y < 0 || y >= n)
		return false;
	return true;
}

//����Ž��
bool canReachEnd(int x, int y) {
	//�������1: �����ʰ�
	if (!inRange(x, y))
		return false;
	//�������2: ���� ����
	if (x == n - 1 && y == n - 1)
		return true;
	return (canReachEnd(x + board[y][x], y) || canReachEnd(x, y + board[y][x]));
}

//������ȹ��
bool canReachEndDP(int x, int y) {
	//�������1: �����ʰ�
	if (!inRange(x, y))
		return false;
	int& ret = cache[y][x];
	//�κй���: �̹� �ٳ�ͺ� ���� ���
	if (ret != -1)
		return ret;
	return ret = (canReachEndDP(x + board[y][x], y) || canReachEndDP(x, y + board[y][x]));
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> board[i][j];

		//������ ĳ���� ��������
		cache[n - 1][n - 1] = 1;
		//if (canReachEnd(0, 0))
		if (canReachEndDP(0, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}