//2022_04_28 트리
//NERD2 너드인가, 너드가 아닌가? 2

#include <bits/stdc++.h>

using namespace std;

bool isDominated(int x, int y, map<int, int>& coords) {
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end()) return false;
	return y < it->second;
}

void removeDominated(int x, int y, map<int, int>& coords) {
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.begin()) return;
	--it;
	while (true) {
		if (it->second > y) break;
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}

int registered(int x, int y, map<int, int>& coords) {
	if (isDominated(x, y,coords)) return coords.size();
	removeDominated(x, y, coords);
	coords[x] = y;
	return coords.size();

}
int main() {
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		map<int, int> coords;
		int result = 0;
		for (int i = 0; i < N; ++i)
		{
			int x, y;
			cin >> x >> y;
			result += registered(x, y, coords);
		}
		cout << result << '\n';
	}
}