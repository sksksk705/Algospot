//2022_04_09 Ž���
//STRJOIN ���ڿ� ��ġ��

//�׻� ���� ª�� �ܾ� 2���� ��ģ��. priority_queue
//Ž���� ���� ����: ���� ª�� �ܾ ��ġ�� �ʴ� �����ذ� �����Ѵ�.
//�� ó���� ���ƴ� �ܾ ���� ª�� �ܾ�� ��ü�ϸ� ����� �� �۾�����.
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