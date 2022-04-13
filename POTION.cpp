//2022_04_13 정수론
//POTION 마법의약

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> need;
vector<int> already;

void input() {
	need.clear();
	already.clear();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int elem;
		cin >> elem;
		need.push_back(elem);
	}
	for (int i = 0; i < n; ++i) {
		int elem;
		cin >> elem;
		already.push_back(elem);
	}
}

int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p%q);
}

vector<int> solve(){
	if (n == 1)
		return vector<int>(0);

	int ratio = gcd(need[0], need[1]);
	for (int i = 2; i < n; ++i) {
		ratio = gcd(need[i], ratio);
	}

	for (int i = 0; i < n; ++i) {
		need[i] /= ratio;
	}

	double minRatio = -1;
	for (int i = 0; i < n; ++i) {
		minRatio = max(minRatio, (double)already[i] / need[i]);
	}
	minRatio = ceil(minRatio);

	vector<int> result(n);

	for (int i = 0; i < n; ++i) {
		result[i] = need[i] * minRatio - already[i];
	}

	return result;
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		input();
		auto ans = solve();
		for (auto add : ans)
			cout << add << ' ';
		cout << '\n';
	}
}