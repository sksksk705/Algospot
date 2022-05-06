//2022_05_06 깊이우선탐색
//고대어사전

#include <bits/stdc++.h>

using namespace std;

vector<int> seen, order;
vector<vector<int>> adj;

void makeGraph(const vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j) {
		int i = j - 1, len = min(words[i].size(), words[j].size());
		for(int k = 0; k < len;++k)
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
	}
}

void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there) {
		if (adj[here][there] && !seen[there])
			dfs(there);
	}
	order.push_back(here);
}

vector<int> topologicalSort() {
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	for (int i = 0; i < n; ++i) if (!seen[i]) dfs(i);
	reverse(order.begin(), order.end());

	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (adj[order[j]][order[i]])
				return vector<int>();
	return order;
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		int n;
		cin >> n;
		vector<string> dic(n);
		for (int i = 0; i < n; ++i)
			cin >> dic[i];
		
		makeGraph(dic);
		vector<int> result = topologicalSort();

		if (result.empty())
			cout << "INVALID HYPOTHESIS";
		else
			for (int word : result)
				cout << (char)('a' + word);
		cout << "\n";
	}
}