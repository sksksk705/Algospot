//2022_04_04 ������ȹ�� k��° ������
//DRAGON �巡�� Ŀ��

//������ �ذ��ϴ� ����Ž���� �ۼ��Ѵ� - �޸������̼� �Ѵ�
//skip���� �ǳʶٰ� ���� ��ȯ�ϴ� ����Լ� ����

//���� ���ڿ��� ����� �Լ�
//�ش� ���ڿ����� skip���� �ǳʶٰ� ���� ��ȯ�ϴ� �Լ��� ������.

//FX  FX+YF  FX+YF+FX-YF  //FX+YF+FX-YF
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000000 + 51;
int Length[51];
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

void calcLength() {
	Length[0] = 1;
	for (int i = 1; i <= 50; ++i)
		Length[i] = min(MAX, Length[i - 1] * 2 + 2);
}

//����Ž��
string dragon1(string& str, int n, int p, int l) {
	if (n == 0)
		return str.substr(p,l);
	string newDragon = "";
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'X')
			newDragon += "X+YF";
		else if (str[i] == 'Y')
			newDragon += "FX-Y";
		else
			newDragon += str[i];
	}
	return dragon1(newDragon, n - 1,p,l);
}

//å�� ���
char expand(const string& dragonCurve, int generations, int skip) {
	if (generations == 0) {
		assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}
	for (int i = 0; i < dragonCurve.size(); ++i) {
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= Length[generations])
				skip -= Length[generations];
			else if (dragonCurve[i] == 'X')
				return expand(EXPAND_X, generations - 1, skip);
			else
				return expand(EXPAND_Y, generations - 1, skip);
		}
		else if (skip > 0)
			--skip;
		else
			return dragonCurve[i];
	}
	return '#';

}

int main() {
	int C;
	cin >> C;
	calcLength();
	while (C--) {
		int n, p, l;
		cin >> n >> p >> l;
		string firstDragon = "FX";
		for (int i = p-1; i < p + l-1; ++i) {
			cout << expand(firstDragon, n, i);
		}
		cout << "\n";
	}
}