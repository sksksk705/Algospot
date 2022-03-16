//2022_03_16 완전탐색 소풍

#include <iostream>
#include <cstring>

using namespace std;

bool isFriend[10][10];
bool hasTeam[10];
int n, m;
int makeTeam(int remain) {
	int result = 0;
	//기저사례: 모든 친구가 짝이 있음( 사례 + 1 )
	if (remain == 0)
		return 1;
	int noTeam = -1;
	for (int i = 0; i < n; ++i) {
		if (!hasTeam[i]) {
			noTeam = i;
			break;
		}
	}
	for (int i = noTeam + 1; i < n; ++i) {
		// 현재 짝이 없는 사람의 친구도 짝이 없을 경우 2명이 짝.
		if (isFriend[noTeam][i] && !hasTeam[i])
		{
			hasTeam[noTeam] = true;
			hasTeam[i] = true;
			//만들어 줘야하는 사람의 수를 줄임.
			result += makeTeam(remain - 2);
			hasTeam[noTeam] = false;
			hasTeam[i] = false;
		}
	}
	return result;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		memset(isFriend, 0, sizeof(isFriend));
		memset(hasTeam, 0, sizeof(hasTeam));
		for (int i = 0; i < m; ++i) {
			int from, to;
			cin >> from >> to;
			isFriend[from][to] = true;
			isFriend[to][from] = true;
		}
		cout << makeTeam(n)<<'\n';
	}
}