//2022_04_19 부분합
//CHRISTMAS 크리스마스 인형

#include <bits/stdc++.h>

using namespace std;

int n, k;
const int MOD = 20091101;
int playground[100001];
int psum[100001];

int first()
{
	int ret = 0;
	vector<long long> count(k, 0);
	for (int i = 0; i <= n; ++i) {
		count[psum[i]]++;
	}
	for (int i = 0; i < k; ++i)
		if (count[i] >= 2)
			ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;
	return ret;
}


int second(int i) {
	vector<int> ret(n, 0);
	vector<int> prev(k, -1);
	for (int i = 0; i <= n; ++i) {
		if (i > 0)
			ret[i] = ret[i - 1];
		else
			ret[i] = 0;
		int loc = prev[psum[i]];
		if (loc != -1) 
			ret[i] = max(ret[i], ret[loc] + 1);
		prev[psum[i]] = i;
	}
	return ret.back();
}

int main() {
	int C;
	cin >> C; 
	while (C--)
	{
		cin >> n >> k;
		memset(playground, 0, sizeof(playground));
		memset(psum, 0, sizeof(psum));

		for (int i = 1; i <= n; ++i)
			cin >> playground[i];

		for (int i = 1; i <= n; ++i)
			psum[i] = (playground[i] + psum[i - 1]) % k;

		cout << first()<<" "<<second();
	}

}