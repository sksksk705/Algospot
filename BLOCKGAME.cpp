//2022_04_06 조합게임
//BLOCKGAME 블록게임

#include <bits/stdc++.h>

using namespace std;
//2의 25승 가능한가? 33,554,432개 메모리 가능? 가능은 한듯?

int cache[33554433];

int bijection(const vector<string>& board) {
	int ret = 0;
	for(int i = 0; i < 5;++i)
		for (int j = 0; j < 5; ++j) {
			ret *= 2;
			if (board[i][j] == '#') ++ret;
		}
	return ret;
}

bool canWin(vector<string>& board) {
	int& ret = cache[bijection(board)];
	if (ret != -1) return ret;
	ret = 0;
	
	//각 칸에 블럭이 들어갈 수 있는지 체크
	//들어갈 수 있다면 넣고 ret = ret || !canWin(board);

	return ret;
}

int main() {

}