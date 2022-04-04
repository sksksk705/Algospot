//2022_04_04 동적계획법 정수이외의 메모이제이션
//ZIMBABWE 웨브바짐

#include <bits/stdc++.h>

using namespace std;

long long toLL(vector<int>& e) {
	long long original = 0;
	for (int i = e.size()-1; i >= 0; --i) {
		original += e[i] * pow(10, i);
	}
	return original;
}

vector<int> toVec(long long e) {
	vector<int> eVec;
	for (int i = log10(e); i >=0 ; --i) {
		eVec.push_back((e / (int)pow(10, i) % 10));
	}
	return eVec;
}

vector<int> cache(0, 14);
long long lastPrice(vector<int>now_vec, vector<int>& e, int m, int idx)
{
	return m;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		long long e;
		int m;
		cin >> e >> m;
		vector<int> eVec = toVec(e);
		e = toLL(eVec);
		return 0;
	}
}