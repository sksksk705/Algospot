//2022_04_07 Ž���
//MATCHORDER �������� ���ϱ�

#include <bits/stdc++.h>

using namespace std;

int order(const vector<int>& russian,
	const vector<int>& korean) {
	int n = russian.size(), wins = 0;
	multiset<int> ratings(korean.begin(), korean.end());
	for (int rus = 0; rus < n; ++rus) {
		//���� �������� ���� �ѱ� ������ �̱� �� ���� ���
		//���� �������� ���� ������ ����Ų��.
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