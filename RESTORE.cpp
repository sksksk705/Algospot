//2022_04_05 정수 이외의 메모이제이션
//RESTORE 실험 데이터 복구하기

//13:19분 시작
//1. 접두사 - 접미사, 접미사 - 접두사 일 경우에만 합칠 수 있음
//2. 두 단어를 가장 짧게 합치는 함수, 모든 순열을 만들어보는 함수(15!)
//14:13분 포기! 정답확인
//비트마스크 개념을 모르니까 캐싱을 하는데 어려움이 많음 외판원 문제를 다시 봐야겠음

#include <bits/stdc++.h>

using namespace std;

int k;
const int INF = 987654321;

string combination(const string& s1, const string& s2) {
	if (s1.find(s2) != string::npos)
		return s1;
	//s1의 뒤에 s2를 합치기
	int maxReplace = s1.size();
	for (int i = s1.size() - 1; i >= 0; --i) {
		if (s1[i] == s2[0]) {
			int idx1 = i + 1, idx2 = 1;
			bool canReplace = true;
			while (idx1 < s1.size() && idx2 < s2.size()) {
				if (s1[idx1] != s2[idx2]) {
					canReplace = false;
				}
				idx1++; idx2++;
			}
			if (canReplace == true)
				maxReplace = i;
		}
	}
	return s1.substr(0, maxReplace) + s2;
}

//wordUsed: 지금까지 사용한 단어의 수
//visited: used배열을 int화한 숫자
//prev: 전에 사용한 단어
int solve1(int wordUsed, int visited, int prev) {
	//기저사례1: 모든 단어를 다 사용했다면 0을 반환
	if (wordUsed == k)
		return 0;
	int& ret = cache[wordUsed][visited];
	if (ret != -1)
		return ret;
	ret = INF;
	int bestChoice = -1;
	for (int i = 0; i < k; ++i) {
		//아직 사용하지 않은 단어를 찾아서 전에 단어 뒤에 붙힌다.
		if (!used[i]) {
			used[i] = true;
			int cand = solve1(wordUsed+1, boolToint(), i) + combination(words[prev], words[i]).size();
			if (cand < ret) {
				ret = cand;
				bestChoice = i;
			}
			used[i] = false;
		}
	}
	choice[prev] = bestChoice;
	return ret;
}

//최종 결과 재구성
void reconstruct(int start, string& result) {
	if (start != -1) result = result.substr(combination(result, words[start])) + words[start];
	int next = choice[start + 1];
	if (next != -1) reconstruct(next, result);
}

//used배열을 int로 바꿔준다.
int boolToint() {
	int trans = 0;
	for (int i = 0; i < k; ++i) {
		if (used[i] == true) {
			trans += pow(2, i);
		}
	}
	return trans;
}

int choice[15];
int cache[15][40000];
vector<int> wordLength(15);
vector<bool> used(15);
vector<string> words;

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));

	}
}