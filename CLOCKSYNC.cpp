//2022_03_17 시계 맞추기
//스위치를 4번 누르는 것은 결국 제자리로 돌아오기 때문에
//모든 스위치를 1 ~ 3번 맞춰보는 것으로 완전탐색을 할 수 있음
//재귀 탐색으로 모든 스위치가 12에 가있다면 현재까지 누른 값을 전달해주는 것으로 마무리


//처음엔 모든 부분에 for문을 돌렸지만 현재 스위치를 다음에 다시 방문하지 않아도 되서 바로 넘기는 걸로 처리
//모든 스위치가 12에 가있다면 0을 반환해서 그 전 돌린 값과 더하게 해줌
//의문점: 꼭 switch값이 10에 있을 때만 정답이 출력된다... 그전에 반환하는 것과 뭐가 다른 거지?
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int clocks[16];
const int INF = 987654321;

vector<vector<int>> buttons{
	{0,1,2},
	{3,7,9,11},
	{4,10,14,15},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15},
	{3,14,15},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13}
};

int clocksync(int currentButton) {
	int ret = INF;
	//꼭 현재 버튼이 끝에 있을 때 반환을 해야 정확한 값이 나온다...왜지?
	if (currentButton == 10) {
		bool synced = true;
		for (int i = 0; i < 16; ++i) {
			if (clocks[i] != 0)
			{
				synced = false;
				break;
			}
		}
		if (synced)
			return 0;
		else
			return ret;
	}
	for (int j = 0; j < 4; ++j) {
		ret =  min(ret, j + clocksync(currentButton+1));
		for (auto linkedClock : buttons[currentButton])
		{
			clocks[linkedClock] += 3;
			clocks[linkedClock] %= 12;
		}
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		for (int i = 0; i < 16; ++i) {
			int time;
			cin >> time;
			clocks[i] = time % 12;
		}
		int result = clocksync(0);
		if (result >= INF)
			cout << -1<<'\n';
		else
			cout << result<<'\n';
	}
}