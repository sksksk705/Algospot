//2022_03_25 동적계획법
//Quantization 양자화

//19:34분 시작
//sort하고 일정 절대값이상 차이가 나면 새로운 양자값을 제시, 더 이상 제시할 수 없다면 가장 큰 양자값으로 계산 -> 최소값을 반환
//사용할 수 있는 숫자의 가짓수에 제한이 있기 때문에 최적부분구조가 성립하지 않음
//19:54분 읽어서 이해는 되는데 내가 풀 수 있을지는 모르겠음... 나중에 다시보는 걸로

#include <bits/stdc++.h>

using namespace std;
vector<int> nums;
int cache[101][101][101];

//어디부터 어디까지 할지 계산이 안 됨
int getSquare(int idx, int quanidx) {
	
}


int quantization(int idx, int numofQuan, int quanidx) {
	int& ret = cache[idx][idx][idx];
	if (ret != -1)
		return ret;
	for(int i = idx+1;i < )
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		int n, s;
		cin >> n >> s;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			nums.push_back(num);
		}


	}
}