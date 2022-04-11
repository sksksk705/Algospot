//2022_04_11 조합탐색
//BOARDCOVER2 게임판 덮기

#include <bits/stdc++.h>

using namespace std;
const int MAX = 10;
char board[MAX][MAX];
int best;
int H, W, R, C;
int blockSize;
vector<vector<pair<int, int>>> rotations;


//블럭을 쪼개서 넣을 수 있는 과대평가 알고리즘.
int simpleHeuristic() {
	int ret = 0;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			if (board[i][j] == '.')
				ret++;
	return ret / blockSize;
}


//모든 블럭을 생성하는 것이 이 문제의 중점인듯.
vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(),' '));
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0; j < arr[0].size(); ++j)
			ret[j][arr.size() - i - 1] = arr[i][j];
	return ret;
}

void generateRotations(vector<string> block) {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; ++rot) {
		int originY = -1, originX = -1;
		for(int i = 0; i < block.size();++i)
			for(int j = 0; j < block[0].size();++j)
				if (block[i][j] == '#') {
					if (originY == -1) {
						originY = i;
						originX = j;
					}
					rotations[rot].push_back(make_pair(i - originX, j - originY));
				}
		block = rotate(block);

	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size();
}


bool setBlock(int x, int y, const vector<pair<int,int>>& block, bool delta) {
	for (int i = 0; i < block.size(); ++i) {
		int nx = x + block[i].first;
		int ny = y + block[i].second;
		if (board[ny][nx] == '#')
			return false;
		board[ny][nx] = '#';
	}
	return true;
}

void search(int placed) {
	if (placed + simpleHeuristic() <= best)
		return;

	//아직 덮여 있지 않은 가장 위에 있는 칸을 찾는다.
	int y = -1, x = -1;
	for (int i = 0; i < H; +i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == '.') {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}

	//기저사례: 보드가 다 덮어졌다.
	if (y == -1) {
		best = max(best, placed);
		return;
	}

	//블럭을 덮을 수 있다면 덮고 탐색한다.
	for (int i = 0; i < rotations.size(); ++i) {
		if (setBlock(x, y, rotations[i], true));
		search(placed + 1);
		setBlock(x, y, rotations[i],false);
	}

	//해당 칸을 채운 상태로 다시 탐색한다.
	board[y][x] = '#';
	search(placed);
	board[y][x] = '.';
}

int solve() {
	best = 0;
	search(0);
	return best;
}

int main() {

}