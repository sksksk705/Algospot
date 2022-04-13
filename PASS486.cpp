//2022_04_13 정수론
//PASS486 비밀번호 486

#include <bits/stdc++.h>

using namespace std;


int numOfFactor[10000001];
int MAX = 10000001;

void eratos() {
	numOfFactor[1] = 1;

	//자신의 배수에 +1;
	for (int i = 1; i <= MAX/2; ++i){
		for (int j = i; j < MAX; j += i)
			numOfFactor[j]++;
	}
}

int solve(int lo, int hi, int factor) {
	int ret = 0;
	for (int i = lo; i <= hi; ++i)
	{
		if (numOfFactor[i] == factor)
			ret++;
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	eratos();
	while (C--)
	{
		int n, lo, hi;
		cin >> n >> lo >> hi;
		int result = solve(lo, hi, n);
		cout << result<<'\n';
	}
}