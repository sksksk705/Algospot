//2022_04_06 반복적 동적계획법
//GENIUS 지니어스

//노래중에 가장 긴 것이 4분이니까 슬라이딩 윈도우를 사용할 수 있다.
//실수 1: 노래가 지속되는 모든 순간을 더해줘야함!
//last를 더하는 방법을 + 5로 초반 마이너스를 없애주는 센스
#include <bits/stdc++.h>

using namespace std;

int n, k,m;
int length[51];
double possiblity[51][51];
double cache[51][6];

void genius() {
	cache[0][0] = 1;
	for (int time = 1; time <= k; ++time) {
		for (int song = 0; song < n; ++song) {
			double& prob = cache[time % 5][song];
			prob = 0;
			for (int last = 0; last < n; ++last)
				prob += cache[(time - length[last] + 5) % 5][last] * possiblity[last][song];
		}
	}
}


int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> k >> m;
		for (int i = 0; i < n; ++i)
			cin >> length[i];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> possiblity[i][j];
		genius();

		double ret[51]{ 0 };
		for (int song = 0; song < n; ++song) {
			for (int start = k - length[song] + 1; start <= k; ++start) {
				ret[song] += cache[start % 5][song];
			}
		}

		while (m--) {
			int Q;
			cin >> Q;
			cout << fixed << ret[Q] << " ";
		}
	}
}