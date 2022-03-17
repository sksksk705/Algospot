//2022_03_17 �ð� ���߱�
//����ġ�� 4�� ������ ���� �ᱹ ���ڸ��� ���ƿ��� ������
//��� ����ġ�� 1 ~ 3�� ���纸�� ������ ����Ž���� �� �� ����
//��� Ž������ ��� ����ġ�� 12�� ���ִٸ� ������� ���� ���� �������ִ� ������ ������


//ó���� ��� �κп� for���� �������� ���� ����ġ�� ������ �ٽ� �湮���� �ʾƵ� �Ǽ� �ٷ� �ѱ�� �ɷ� ó��
//��� ����ġ�� 12�� ���ִٸ� 0�� ��ȯ�ؼ� �� �� ���� ���� ���ϰ� ����
//�ǹ���: �� switch���� 10�� ���� ���� ������ ��µȴ�... ������ ��ȯ�ϴ� �Ͱ� ���� �ٸ� ����?
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
	//�� ���� ��ư�� ���� ���� �� ��ȯ�� �ؾ� ��Ȯ�� ���� ���´�...����?
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