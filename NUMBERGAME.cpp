//2022_04_05 ���հ���
//NUMBERGAME ���ڰ���

#include <bits/stdc++.h>

using namespace std;

const int EMPTY = -987654321;
int n;
int scores[51];
int cache[51][51];
int numberGame(int front, int back) {
	//��� ���ڸ� �� ���� ���
	if (front > back)
		return 0;
	int& ret = cache[front][back];
	//1. ��������
	if (ret != EMPTY) return ret;
	ret = max(scores[front] - numberGame(front + 1, back),
		scores[back] - numberGame(front,back-1));
	//2. ���ش�(2�� �̻�)
	if (back - front+1 >= 2) {
		ret = max(ret, -numberGame(front + 2, back));
		ret = max(ret, -numberGame(front, back - 2));
	}
	return ret;

}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> scores[i];
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cache[i][j] = EMPTY;

		cout << numberGame(0, n-1)<<'\n';
	}
}