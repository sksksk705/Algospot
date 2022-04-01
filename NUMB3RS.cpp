//2022_03_20 동적계획법
//NUMB3RS 두니발 박사의 탈옥문제

//16:40 시작 
//17:15 모든 경우의 수에 따라 하는 건 줄 알았는데 전날 1/5이었던 출발지에서 갈 수 있는 방향이 3개라면 해당 도착지의 확률은 1/15로 계산해야함.
//17:35 공부 끝
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