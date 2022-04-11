//2022_04_09 탐욕법
//STRJOIN 문자열 합치기

//항상 가장 짧은 단어 2개를 합친다. priority_queue
//탐욕적 선택 증명: 가장 짧은 단어를 합치지 않는 최적해가 존재한다.
//맨 처음에 합쳤던 단어를 가장 짧은 단어로 교체하면 결과가 더 작아진다.
#include <bits/stdc++.h>

using namespace std;

int main() {
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		priority_queue<int,vector<int>,greater<int>> strLength;
		for (int i = 0; i < n; ++i) {
			int str;
			cin >> str;
			strLength.push(str);
		}
		int total = 0;
		while (strLength.size() != 1) {
			int first, second;
			first = strLength.top(); strLength.pop();
			second = strLength.top(); strLength.pop();
			int newString = first + second;
			total += newString;
			strLength.push(newString);
		}
		cout << total<<'\n';
	}
}