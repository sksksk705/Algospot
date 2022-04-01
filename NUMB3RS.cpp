//2022_03_20 ������ȹ��
//NUMB3RS �δϹ� �ڻ��� Ż������

//16:40 ���� 
//17:15 ��� ����� ���� ���� �ϴ� �� �� �˾Ҵµ� ���� 1/5�̾��� ��������� �� �� �ִ� ������ 3����� �ش� �������� Ȯ���� 1/15�� ����ؾ���.
//17:35 ���� ��
#include <bits/stdc++.h>

using namespace std;
int N, D, P;
double cache[51][101];
int connected[51][51], deg[51];

double search3(int here, int days) {
	if (days == 0) return (here == P ? 1.0 : 0.0);
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int there = 0; there < N; ++there) {
		if (connected[here][there])
			ret += search3(there, days - 1) / deg[there];
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N >> D >> P;
		memset(cache, -1,sizeof(cache));
		memset(connected, 0, sizeof(connected));
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				cin >> connected[i][j];
				if (connected[i][j] == 1)
					deg[i]++;
			}
		int T;
		cin >> T;
		for (int i = 0; i < T; ++i) {
			int Q;
			cin >> Q;
			cout << setprecision(8) << search3(Q, D)<<" ";
		}
		cout << '\n';
	}

}