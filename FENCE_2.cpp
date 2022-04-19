//2022_04_19 스택
//FENCE 울타리 잘라내기

#include <bits/stdc++.h>

using namespace std;

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		vector<int> fence;
		int n;
		cin >> n;
		fence.reserve(n+1);
		for (int i = 0; i < n; ++i)
		{
			int height;
			cin >> height;
			fence.push_back(height);
		}
		fence.push_back(0);
		stack<int> s;
		int ret = 0;
		for (int i = 0; i < fence.size(); ++i)
		{
			while (!s.empty() && fence[s.top()] >= fence[i]) {
				int j = s.top(); s.pop();
				int width = -1;
				if (s.empty())
					width = i;
				else
					width = (i - s.top() - 1);
				ret = max(ret, fence[j] * width);
			}
			s.push(i);
		}
		cout << ret << '\n';
	}
}