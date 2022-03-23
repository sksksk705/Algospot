//2022_03_23 동적계획법 최적부분구조
//가장 긴 증가 부분 수열

#include <bits/stdc++.h>

using namespace std;

int n;
int seq[500];
int cache[501];
//완전탐색에서 시작
int lis(int idx, int prev) {
	//기저사례1: 더이상 큰 게 없을 때 prev를 리턴
	int result = prev;
	for (int i = idx + 1; i < n; ++i) {
		//큰 게 있다면 길이를 1늘려서 다시 탐색
		if (seq[i] > seq[idx] || idx == -1)
			result = max(result, lis(i, prev + 1));
	}
	return result;
}

//동적계획법 어떤 경로던 해당 부분문제의 가장 긴 수열을 반환
int lisDP(int idx) {
	int& ret = cache[idx+1];
	if (ret != -1)
		return ret;
	//최소 길이는 1
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
		//s[-1]은 빼줘야함
		cout << lisDP(-1)-1<<'\n';
	}
}