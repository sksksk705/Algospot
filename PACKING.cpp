//2022_04_01 동적계획법 실제 답
//PACKING 여행 짐 싸기

//16;03분 시작
//원래대로하면 각 부분에서 시작해서 무게 미만의 가장 이상적인 답을 찾아온다 즉 1번에서 시작했을 때 3번까지, 3번에서 시작했을 때 4번까지라면 결과가 1,2,3,4로 나오는 거임.
//무게 제한을 둬서 reconstruct 할 때 무게 제한을 넘어가면 못 담게 만들었더니... 오답이 나왔다.
//각 문제에 대해 담을 것인지 담지 않을 것인지만 체크했는데 nw의 값이 작아서 가능한듯
//17:02 공부 끝
#include <bits/stdc++.h>

using namespace std;

int choice[101], cache[101][1001];
int things[101][2];
string thingsName[101];
int n,w;


//내가 짠 dp코드
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

//내가 짠 재구성 코드
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