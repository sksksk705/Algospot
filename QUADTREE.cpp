//2022_03_21 분할정복 쿼드트리 뒤집기
//압축되어 있는 쿼드트리를 분할 정복으로 복원하여 다시 압축하거나
//분할 정복으로 뒤집고 머지하거나

#include <iostream>
#include <string>
using namespace std;

string reversequad(string::iterator& it) {
	char head = *it;
	it++;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string topleft = reversequad(it);
	string topright = reversequad(it);
	string bottomleft = reversequad(it);
	string bottomright = reversequad(it);
	string result = "x" + bottomleft + bottomright + topleft + topright;
	return result;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		string s;
		cin >> s;
		string::iterator it = s.begin();
		cout << reversequad(it)<<'\n';
	}
}