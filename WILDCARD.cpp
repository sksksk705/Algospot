//2022_03_22 와일드카드 동적계획법
//먼저 완탐으로 해보고 생각


//실수1: 와일드카드가 '*'인 경우가 먼저인데 filename 비어있는 것부터 체크 - 순서 바꿈
//실수2: 아스키코드 순서대로 출력 안 함	- vector에 저장하고 sort후 출력
//실수3: 아마도 * 뒤에 특수문자가 나온 문자열에 대해서 문제가 발생하지 않을까? - *일 경우 모든 경우의 수를 찾는 것으로 변경
//- 정답
#include <bits/stdc++.h>

using namespace std;

//캐싱용
int cache[100][100];

//완전탐색
bool isfileMatch(const string& wildcard, const string& filename) {
	//기저사례1: 정확히 떨어졌을 경우
	if (filename == "" && wildcard == "")
		return true;
	//기저사례2: 와일드카드가 '*'인 경우
	if (wildcard.size() == 1 && wildcard[0] == '*')
		return true;
	//기저사례3: 하나는 비었는데 하나가 남아있는 경우
	if (wildcard == "" || filename == "")
		return false;

	//그외
	char head = wildcard[0];
	string subwildcard = wildcard.substr(1);
	bool ans = false;
	switch (head) {
	case '*':
		//'*'인 경우 모든 사례를 검증(*,? 특수문자 해결을 위해 비교하지 않음)
		for (int i = 0; i < filename.size(); ++i) {
				if(isfileMatch(subwildcard, filename.substr(i)))
					ans = true;
		}
		break;
	case '?':
		//'?'인 경우 1개씩 잘라내고 검증
		if (isfileMatch(subwildcard, filename.substr(1)))
			ans = true;
		break;
	default:
		//문자인 경우 맨 앞의 문자를 비교하고 다르면 false 맞으면 1개씩 잘라내고 검증
		if (head != filename[0])
			return false;
		else
			if (isfileMatch(subwildcard, filename.substr(1)))
				ans = true;
	}
	return ans;
}

//동적계획법
bool isfileMatchDP(const string& wildcard, const string& filename, int wildidx, int fileidx) {
	//기저사례1: 정확히 떨어졌을 경우
	if (filename == "" && wildcard == "")
		return true;
	//기저사례2: 와일드카드가 '*'인 경우
	if (wildcard.size() == 1 && wildcard[0] == '*')
		return true;
	//기저사례3: 하나는 비었는데 하나가 남아있는 경우
	if (wildcard == "" || filename == "")
		return false;
	
	//부분문제
	int& ret = cache[wildidx][fileidx];
	if (ret != -1)
		return ret;

	//아직 맞지 않다고 가정
	ret = false;
	//그외
	char head = wildcard[0]; //첫글자
	string subwildcard = wildcard.substr(1); //다음 와일드카드
	switch (head) {
	case '*':
		//'*'인 경우 모든 사례를 검증(*,? 특수문자 해결을 위해 비교하지 않음)
		for (int i = 0; i < filename.size(); ++i) {
			if (isfileMatchDP(subwildcard, filename.substr(i),wildidx + 1, fileidx + i))
				ret = true;
		}
		break;
	case '?':
		//'?'인 경우 1개씩 잘라내고 검증
		if (isfileMatchDP(subwildcard, filename.substr(1),wildidx+1,fileidx+1))
			ret = true;
		break;
	default:
		//문자인 경우 맨 앞의 문자를 비교하고 다르면 false 맞으면 1개씩 잘라내고 검증
		if (head != filename[0])
			return false;
		else
			if (isfileMatchDP(subwildcard, filename.substr(1), wildidx +1,fileidx+1))
				ret = true;
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		string wild;
		cin >> wild;
		int n;
		cin >> n;
		vector<string> files;
		for (int i = 0; i < n; ++i) {
			string file;
			cin >> file;
			memset(cache, -1, sizeof(cache));
			//if (isfileMatch(wild, file))
			if (isfileMatchDP(wild, file, 0, 0))
				files.push_back(file);
		}
		sort(files.begin(), files.end());
		for (auto filename : files)
			cout << filename<<'\n';
	}
}