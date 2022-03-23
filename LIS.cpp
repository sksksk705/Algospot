//2022_03_23 ������ȹ�� �����κб���
//���� �� ���� �κ� ����

#include <bits/stdc++.h>

using namespace std;

int n;
int seq[500];
int cache[501];
//����Ž������ ����
int lis(int idx, int prev) {
	//�������1: ���̻� ū �� ���� �� prev�� ����
	int result = prev;
	for (int i = idx + 1; i < n; ++i) {
		//ū �� �ִٸ� ���̸� 1�÷��� �ٽ� Ž��
		if (seq[i] > seq[idx] || idx == -1)
			result = max(result, lis(i, prev + 1));
	}
	return result;
}

//������ȹ�� � ��δ� �ش� �κй����� ���� �� ������ ��ȯ
int lisDP(int idx) {
	int& ret = cache[idx+1];
	if (ret != -1)
		return ret;
	//�ּ� ���̴� 1
	ret = 1;
	for (int i = idx + 1; i < n; ++i) {
		//s[-1] = -INF
		if (seq[i] > seq[idx] || idx == -1)
			ret = max(ret, lisDP(i)+1);
	}
	return ret;
}


int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; ++i)
			cin >> seq[i];
		//lis(-1,0);
		//s[-1]�� �������
		cout << lisDP(-1)-1<<'\n';
	}
}