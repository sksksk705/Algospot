#include <iostream>
#include <cstring>

using namespace std;

char board[20][20];
int coverd[20][20];
int H, W;
int block[4][3][2]{
	{{0, 0}, { 1,0 },{0,1}},
	{{0, 0}, { 1,0 },{1,1}},
	{{0, 0}, { 0,1 },{1,1}},
	{{0, 0}, { 0,1 },{-1,1}},
};

//delta������ ���ؼ� ���� ���� ����� ���ÿ� ���� ���� ����Ʈ
bool set(int y, int x, int type,int delta) {
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int nx = x + block[type][i][0];
		const int ny = y + block[type][i][1];
		if (nx < 0 || nx >= W ||
			ny < 0 || ny >= H)
			ok = false;
		//coverd �迭�� bool�� �ƴ� int�� �����ؼ� ���� ���� ���� �����ϰ� ��. 
		//bool�̾��ٸ� ���� ���� �� ���� ������, ���� ������ ������ ������ �� ��.
		else if ((coverd[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int boardCover() {
	int result = 0;
	int firstWhite = -1;
	int x = -1, y = -1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (coverd[i][j] == 0)
			{
				x = j;
				y = i;
				break;
			}
		}
		if (y != -1)
			break;
	}
	if (y == -1)
		return 1;
	for (int type = 0; type < 4; ++type) {
		if (set(y, x, type, 1))
			result += boardCover();
		set(y, x, type, -1);
	}
	return result;
}

int main() {
	int C;
	cin >> C;
	while (C--) {

		cin >> H >> W;
		memset(board, 0, sizeof(board));
		memset(coverd, 0, sizeof(coverd));
		int whiteSpace = 0;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> board[i][j];
				if (board[i][j] == '.')
					whiteSpace++;
				else
					coverd[i][j]++;
			}
		}
		if (whiteSpace % 3 != 0) {
			cout << 0 << '\n';
			continue;
		}
		cout << boardCover()<<'\n';
	}
}