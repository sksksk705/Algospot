#include <bits/stdc++.h>

using namespace std;

int n;
int triangle[100][100];
int cache[100][100];

//����Ž������ ����
int getPath(int y, int x, int prev) {
	int now = triangle[y][x] + prev;
	//���� �ؿ� �������� ��
	if (y == n - 1)	return now;

	//�ٷ� ������ �̵�,������ �Ʒ��� �̵�
	return max(getPath(y + 1, x, now), getPath(y + 1, x + 1, now));
}

//������ȹ�� - prev�� �������� �����ذῡ ������ �� ��
int getPathDP(int y, int x) {
	//�������1: ���� �ؿ� �������� ��
	if (y == n - 1)	return triangle[y][x];
	int& ret = cache[y][x];

	//�̹� �ذ�� ����
	if (ret != -1)
		return ret;

	//�ٷ� ������ �̵�,������ �Ʒ��� �̵�
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