//2022_04_12 최적화 문제를 결정 문제로
//ARCTIC 남극기지

#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double>> basement;
bool reach[100];
int n;

bool bfs(double d) {
	memset(reach, 0, sizeof(reach));
	reach[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;
	while (!q.empty()) {
		int idx = q.front();
		double x = basement[idx].first;
		double y = basement[idx].second;
		q.pop();
		seen++;
		for (int next = 0; next < n; ++next)
		{
			if (reach[next])
				continue;
			double nextx = basement[next].first;
			double nexty = basement[next].second;
			double dist = sqrt(pow(x - nextx, 2) + pow(y - nexty, 2));
			if (dist < d) {
				reach[next] = true;
				q.push(next);
			}
		}
	}
	return seen == n;
}

double solve() {
	double lo = 0;
	double hi = 1416.00;//1000루트2

	for(int i = 0; i < 100;++i) {
		double mid = (lo + hi) / 2;
		if (bfs(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

void input() {
	cin >> n;
	basement.clear();
	for (int i = 0; i < n; ++i)
	{
		double x, y;
		cin >> x >> y;
		basement.push_back(make_pair(x, y));
	}
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		input();
		cout << fixed;
		cout.precision(2);
		cout<<round(solve()*100)/100<<'\n';
	}
}