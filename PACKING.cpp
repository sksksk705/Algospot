//2022_04_01 ������ȹ�� ���� ��
//PACKING ���� �� �α�

//16;03�� ����
//��������ϸ� �� �κп��� �����ؼ� ���� �̸��� ���� �̻����� ���� ã�ƿ´� �� 1������ �������� �� 3������, 3������ �������� �� 4��������� ����� 1,2,3,4�� ������ ����.
//���� ������ �ּ� reconstruct �� �� ���� ������ �Ѿ�� �� ��� ���������... ������ ���Դ�.
//�� ������ ���� ���� ������ ���� ���� �������� üũ�ߴµ� nw�� ���� �۾Ƽ� �����ѵ�
//17:02 ���� ��
#include <bits/stdc++.h>

using namespace std;

int choice[101], cache[101][1001];
int things[101][2];
string thingsName[101];
int n,w;


//���� § dp�ڵ�
int pack1(int idx, int weight) {
	int& ret = cache[idx + 1][weight];
	if (ret != -1)
		return ret;
	ret = 0;
	int bestNext = -1;
	for (int i = idx + 1; i < n; ++i) {
		if (idx == -1 || things[i][0] + weight <= w) {
			int cand = pack1(i,weight + things[i][0])+things[i][1];
			if (cand > ret)
			{
				ret = cand;
				bestNext = i;
			}
		}
	}
	choice[idx+1] = bestNext;
	return ret;
}

//���� § �籸�� �ڵ�
void recontruct1(int start, vector<string>& bag, int weight) {
	if (weight > w) return;
	if (start != -1) bag.push_back(thingsName[start]);
	int next = choice[start + 1];
	if (next != -1) recontruct1(next, bag,weight + things[next][0]);
}

int pack2(int idx, int capacity) {
	if (idx == n) return 0;
	int& ret = cache[idx][capacity];
	if (ret != -1)
		return ret;
	ret = pack2(idx + 1, capacity);
	if (capacity >= things[idx][0])
		ret = max(ret, pack2(idx + 1, capacity - things[idx][0]) + things[idx][1]);
	return ret;
}

void recontruct2(int start, vector<string>& bag, int weight) {
	if (start == n) return;
	if (pack2(start, weight) == pack2(start + 1, weight)) {
		recontruct2(start + 1, bag, weight);
	}
	else {
		bag.push_back(thingsName[start]);
		recontruct2(start + 1, bag, weight - things[start][0]);
	}
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(choice, -1, sizeof(choice));
		memset(cache, -1, sizeof(cache));
		cin >> n >> w;
		for (int i = 0; i < n; ++i) {
			cin >> thingsName[i];
			cin >> things[i][0] >> things[i][1];
		}
		int result = pack2(0, w);
		vector<string> bag;
		recontruct2(0, bag,w);
		cout << result << ' ' << bag.size() << '\n';
		for (auto thing : bag) {
			cout << thing << '\n';
		}

	}
}