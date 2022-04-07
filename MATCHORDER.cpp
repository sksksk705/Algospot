//2022_04_07 탐욕법
//MATCHORDER 출전순서 정하기

#include <bits/stdc++.h>

using namespace std;

int order(const vector<int>& russian,
	const vector<int>& korean) {
	int n = russian.size(), wins = 0;
	multiset<int> ratings(korean.begin(), korean.end());
	for (int rus = 0; rus < n; ++rus) {
		//가장 레이팅이 높은 한국 선수가 이길 수 없는 경우
		//가장 레이팅이 낮은 선수와 경기시킨다.
		if (*ratings.rbegin() < russian[rus])
			ratings.erase(ratings.begin());
		else {
			ratings.erase(ratings.lower_bound(russian[rus]));
			wins++;
		}
	}
	return wins;
}

int main() {
	
}