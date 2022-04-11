//2022_04_11 ����Ž��
//ALLERGY �˷����� ���� ģ����

//Ž�� ������ �ٲٴ� ���� �� ȿ������ ����ȭ ���
//- ���� ������ �� ���� ģ���� ���� ������ ���Ѵ�.
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
	//�޸���ƽ
	if (currentFood >= best)
		return;

	//�������: ��� ���� �� �ִ�.
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

	//������ ���� ���� �� �ִ� ������� ä���.
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