// 2022_03_16 완전탐색 시간초과
// 2022_03_22 DP로 시도
// 이미 가본 곳을 false 하는 순간 다음에 가능할 수도 있는 것을 없애버림 
// 다 찾을 때까지는 false하지 말고  8방향이 다 안 되었을 때 false하는 방법을 찾아야할듯

#include <iostream>
#include <string>

using namespace std;

int dx[8]{ 1,1,0,-1,-1,-1,-1,0 };
int dy[8]{ 0,1,1,1,0,-1,-1,-1 };

//캐싱용
int cache[5][5];

char board[5][5];

// 범위체크 
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
	//기저사레1: 범위초과
	if (!inRange(x, y))
		return false;

	//기저사례2: 단어가 맞지 않음
	if (board[y][x] != word[0])
		return false;
	
	//기저사례3: 모든 단어완성
	if (word.size() == 1)
		return true;

	//부분사례
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	//현재는 못찾음
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