// 2022_03_16 ����Ž�� �ð��ʰ�
// 2022_03_22 DP�� �õ�
// �̹� ���� ���� false �ϴ� ���� ������ ������ ���� �ִ� ���� ���ֹ��� 
// �� ã�� �������� false���� ����  8������ �� �� �Ǿ��� �� false�ϴ� ����� ã�ƾ��ҵ�

#include <iostream>
#include <string>

using namespace std;

int dx[8]{ 1,1,0,-1,-1,-1,-1,0 };
int dy[8]{ 0,1,1,1,0,-1,-1,-1 };

//ĳ�̿�
int cache[5][5];

char board[5][5];

// ����üũ 
bool inRange(int x, int y) {
	if (x < 0 || x >= 5 ||
		y < 0 || y >= 5)
		return false;
	return true;
}

bool hasWord(int x, int y, const string& word) {
	if (!inRange(x, y))
		return false;
	if (board[y][x] != word[0])
		return false;
	if (word.size() == 1)
		return true;
	for (int i = 0; i < 8; ++i) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (hasWord(nextx, nexty, word.substr(1)))
			return true;
	}
	return false;
}

bool hasWordDP(int x, int y, const string& word) {
	//�����緹1: �����ʰ�
	if (!inRange(x, y))
		return false;

	//�������2: �ܾ ���� ����
	if (board[y][x] != word[0])
		return false;
	
	//�������3: ��� �ܾ�ϼ�
	if (word.size() == 1)
		return true;

	//�κл��
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	//����� ��ã��
	ret = false;
	for (int i = 0; i < 8; ++i) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (hasWordDP(nextx, nexty, word.substr(1)))
			ret = true;
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				cin >> board[i][j];
		int N;
		cin >> N;
		while (N--) {
			string word;
			cin >> word;
			cout << word;
			bool canMake = false;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j) {
					memset(cache, -1, sizeof(cache));
					//if(hasWord(j,i,word))
					if (hasWordDP(j, i, word))
					{
						canMake = true;
						break;
					}
				}
			if (canMake)
				cout << " YES\n";
			else
				cout << " NO\n";
		}
	}
}