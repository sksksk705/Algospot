//2022_03_24 동적계획법
//합친 LIS

//완전탐색 -> 전체경로가 아닌 부분경로의 최대값 -> 최적부분구조 -> 적절하게 입력 변환 -> 메모이제이션 적용
//전부 합쳐서 sort하고 lis반환하면 되는 거 아닌가? - 오답(sort하면 뒤에 숫자가 앞으로 올 수 있게 됨)
//각 수열에서 하나의 수열만 구할 수 있다. 그렇다면 함수를 2개로 나눠서 쓸까?
//dp는 항상 점화식 세우는 것을 최우선적으로 생각해야함.
#include <bits/stdc++.h>

using namespace std;
const long long NEGINF = LLONG_MIN;
int n, m;
long long cache[101][101];
vector<long long> seq1;
vector<long long> seq2;
long long jLis(int idx1, int idx2) {
	long long& ret = cache[idx1+1][idx2+1];
	if (ret != -1)
		return ret;
	ret = 2;
	long long min1 = (idx1 == -1 ? NEGINF : seq1[idx1]);
	long long min2 = (idx2 == -1 ? NEGINF : seq2[idx2]);
	long long max_elem = max(min1, min2);
	for (int i = idx1 + 1; i < n; ++i)
		if (seq1[i] > max_elem)
			ret = max(ret, (jLis(i, idx2) + 1));

	for (int i = idx2 + 1; i < m; ++i)
		if (seq2[i] > max_elem)
			ret = max(ret, (jLis(idx1, i) + 1));

	return ret;
}

int main()
{
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));
		seq1.clear();
		seq2.clear();
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			seq1.push_back(num);
		}
		for (int i = 0; i < m; ++i) {
			int num;
			cin >> num;
			seq2.push_back(num);
		}

		cout << jLis(-1,-1)-2 << '\n';
	}
}