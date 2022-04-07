//2022_04_07 Å½¿å¹ý
//LUNCHBOX µµ½Ã¶ô µ¥¿ì±â

#include <bits/stdc++.h>

using namespace std;

int lunchTime(const vector<pair<int, int>> lunchBoxs, int boxs) {
	int total = 0;
	int eatTime = 0;

	for (int i = 0; i < boxs;++i) {
		auto nowBox = lunchBoxs[i];
		int nowHeat = nowBox.second;
		int nowEat = nowBox.first;
		if (i != 0)
			eatTime -= nowHeat;
		total += nowHeat;
		if (eatTime < nowEat)
			eatTime = nowEat;
	}
	total += eatTime;
	return total;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		vector<pair<int, int>> boxs;
		vector<int> heat;
		vector<int> eat;
		for (int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			heat.push_back(m);
		}
		for (int i = 0; i < n; ++i) {
			int e;
			cin >> e;
			eat.push_back(e);
		}
		for (int i = 0; i < n; ++i) {
			boxs.push_back(make_pair(eat[i], heat[i]));
		}
		sort(boxs.begin(), boxs.end(),greater<pair<int,int>>());
		int result = lunchTime(boxs,n);
		cout << result << '\n';
	}
}