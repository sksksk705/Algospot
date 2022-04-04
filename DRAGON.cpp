//2022_04_04 동적계획법 k번째 실제해
//DRAGON 드래곤 커브

//문제를 해결하는 완전탐색을 작성한다 - 메모이제이션 한다
//skip개를 건너뛰고 답을 반환하는 재귀함수 구현

//실제 문자열을 만드는 함수
//해당 문자열에서 skip개를 건너뛰고 답을 반환하는 함수를 만들자.

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

//완전탐색
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

//책의 답안
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