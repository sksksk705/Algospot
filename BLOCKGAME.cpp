//2022_04_06 ���հ���
//BLOCKGAME ��ϰ���

#include <bits/stdc++.h>

using namespace std;
//2�� 25�� �����Ѱ�? 33,554,432�� �޸� ����? ������ �ѵ�?

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
	
	//�� ĭ�� ���� �� �� �ִ��� üũ
	//�� �� �ִٸ� �ְ� ret = ret || !canWin(board);

	return ret;
}

int main() {

}