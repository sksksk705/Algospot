//2022_05_02 트리
//RUNNINGMEDIAN 변화하는 중간 값

#include <bits/stdc++.h>

using namespace std;

// 선형 합동 난수 생성기(Linear congruential random number generator)
struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int solve(int n, RNG rng) {
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int result = 0;
	int median = 0;
	for (int i = 0; i < n; ++i) {
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());

		if (!minHeap.empty() && !maxHeap.empty() &&
			minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b); minHeap.push(a);
		}
		result = (result + maxHeap.top()) % 20090711;
	}
	return result;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int n, a, b;
		cin >> n >> a >> b;
		RNG rng;
		int result = solve(n, rng);
		cout << result;
	}
}