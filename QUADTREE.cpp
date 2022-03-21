//2022_03_21 �������� ����Ʈ�� ������
//����Ǿ� �ִ� ����Ʈ���� ���� �������� �����Ͽ� �ٽ� �����ϰų�
//���� �������� ������ �����ϰų�

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