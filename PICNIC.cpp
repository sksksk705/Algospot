//2022_03_16 ����Ž�� ��ǳ

#include <iostream>
#include <cstring>

using namespace std;

bool isFriend[10][10];
bool hasTeam[10];
int n, m;
int makeTeam(int remain) {
	int result = 0;
	//�������: ��� ģ���� ¦�� ����( ��� + 1 )
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
		// ���� ¦�� ���� ����� ģ���� ¦�� ���� ��� 2���� ¦.
		if (isFriend[noTeam][i] && !hasTeam[i])
		{
			hasTeam[noTeam] = true;
			hasTeam[i] = true;
			//����� ����ϴ� ����� ���� ����.
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