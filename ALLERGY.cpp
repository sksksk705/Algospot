//2022_04_11 조합탐색
//ALLERGY 알러지가 심한 친구들

//탐색 방향을 바꾸는 것이 더 효과적인 최적화 방법
//- 아직 음식을 못 먹은 친구를 위해 음식을 정한다.
#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> menu;
vector<string> friends;
bool visited[20];
const int INF = 987654321;
int best;
int n, m;

void input() {
	menu.clear();
	friends.clear();
	cin >> n >> m;
	menu.resize(m);
	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;
		friends.push_back(name);
	}
	for (int food = 0; food < m; ++food)
	{
		int noAL;
		cin >> noAL;
		for (int j = 0; j < noAL; ++j)
		{
			string whoCanEat;
			cin >> whoCanEat;
			menu[food].push_back(whoCanEat);
		}
	}
}

vector<int> whoAdded(int idx) {
	vector<int> ret;
	for (int i = 0; i < menu[idx].size(); ++i) {
		int friendidx = find(friends.begin(), friends.end(), menu[idx][i]) - friends.begin();
		if (friendidx == n || visited[friendidx])
			continue;
		visited[friendidx] = true;
		ret.push_back(friendidx);
	}
	return ret;
}


void search(int currentFood, int idx) {
	//휴리스틱
	if (currentFood >= best)
		return;

	//기저사례: 모두 먹을 수 있다.
	bool finished = true;
	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == false)
			finished = false;
		if (!finished)
			break;
	}
	if (finished) {
		best = min(currentFood, best);
		return;
	}

	//조합을 만들어서 먹을 수 있는 사람들을 채운다.
	vector<int> newAdded = whoAdded(idx);
	if (newAdded.size() > 0) {
			search(currentFood + 1, idx+1);
	}
	for (auto friendidx : newAdded)
		visited[friendidx] = false;
	return;
}

int solve() {
	best = INF;
	search(0,0);
	return best;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		input();
		int result = solve();
		cout << result<<'\n';
	}
}