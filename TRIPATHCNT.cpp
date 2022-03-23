//2022_03_23 ������ ����ȭ ���� 13:35
//�ﰢ�� ���� �ִ� ����� �� - �ٸ� �����ε� �߸� ǰ

#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;
int maxValue;
int triangle[100][100];

//����Ž������ ����
void getPath(int y, int x, int prev) {
	int now = triangle[y][x] + prev;
	//���� �ؿ� �������� ��
	if (y == n-1) {
		if (now > maxValue) {
			maxValue = now;
			ans = 1;
		}
		else if (now == maxValue)
			ans++;
		return;
	}
	//�ٷ� ������ �̵�
	getPath(y + 1, x, now);
	//������ �Ʒ��� �̵�
	getPath(y + 1, x + 1, now);
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				cin >> triangle[i][j];
			}
		}
		maxValue = -1;
		ans = 0;
		getPath(0, 0, 0);
		cout << ans<<'\n';
	}
}