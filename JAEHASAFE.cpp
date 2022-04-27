//2022_04_25 문자열
//JAEHASAFE 재하의 금고

//시계방향 역방향을 구현해서 각각 상태를 체크하는 방법밖에 모르겠다.

#include <bits/stdc++.h>

using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int n = N.size();
	vector<int> pi(n, 0);

	int begin = 1, matched = 0;
	while (begin + matched < n) {
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

vector<int> kmpSearch(const string& H, const string N) {
	int n = H.size(), m = N.size();
	vector<int> pi = getPartialMatch(N);
	vector<int> ret;
	int matched = 0;
	for (int i = 0; i < n; ++i)
	{
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		if (H[i] == N[matched]) {
			++matched;
			if (matched == m) {
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

//환형시프트 구현
int shifts(const string& original, const string& target) {
	return kmpSearch(original + original, target)[0];
}

int main() {

}

