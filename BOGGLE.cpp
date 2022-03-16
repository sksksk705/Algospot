// 2022_03_16 완전탐색 시간초과

#include <iostream>
#include <string>

using namespace std;

int dx[8]{ -1,0,1,1,1,0,-1,-1 };
int dy[8]{ 1,1,1,0,-1,-1,-1,0 };

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
					if (hasWord(j, i, word))
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