//2022_04_18 비트마스크
//GRADUATION 졸업 학기

//n이 12이기 때문에 32비트 정수로 표현가능 16비트 정수도 가능
//그리디한 비트마스크만 짰음
//학기 제한을 1번부터 듣는다는 가정이기 때문에 2번을 먼저 들어야한다면 fail이 나올 거임.
//차라리 완전 탐색으로 가도 나쁘지 않을듯
//동적계획법까지 적용하는 것이 끝!
#include <bits/stdc++.h>

using namespace std;


int n, k, m, l;
unsigned short postLearn[12];
unsigned short semester[12];
const int INF = 987654321;

//sem 학기 
//learned 지금까지 들은 수업
int study(int sem, int learned, int pass)
{
	//기저사례1: 졸업 요건을 채움
	if (__popcnt16(learned) >= k)
 		return sem - pass;

	//기저사례2: 졸업 요건을 끝까지 못 채움
	if (sem >= m)
		return INF;

	unsigned short thisquater = 0;
	for (int lesson = 0; lesson < n; ++lesson)
	{
		//이번 학기에 들을 수 없는 수업이면 continue;
		if (!(semester[sem] & (1 << lesson)))
			continue;

		//배우지 않았으면서 선수과목을 모두 수강했다면 이번학기에 배운다;
		if (!(learned & (1 << lesson)) && (learned & postLearn[lesson]) == postLearn[lesson])
			thisquater |= (1 << lesson);
		
	}
	int ret = INF;
	//모든 부분집합을 돌며 다음 학기를 체크한다.
	for (unsigned short subset = thisquater; subset; subset = ((subset - 1) & thisquater))
	{
		if (__popcnt16(subset) <= l)
			ret = min(ret, study(sem + 1, learned | subset, pass));
	}
	//이번 학기를 안 듣고 넘어가는 경우
	ret = min(ret, study(sem + 1, learned, pass+1));
	return ret;
}


int main() {
	int C;
	cin >> C;
	while (C--)
	{
		memset(postLearn, 0, sizeof(postLearn));
		memset(semester, 0, sizeof(semester));
		cin >> n >> k >> m >> l;
		for (int i = 0; i < n; ++i)
		{
			int lesson;
			cin >> lesson;
			while (lesson--)
			{
				int need;
				cin >> need;
				postLearn[i] |= (1 << need);
			}
		}
		for (int i = 0; i < m; ++i)
		{
			int lesson;
			cin >> lesson;
			while (lesson--)
			{
				int need;
				cin >> need;
				semester[i] |= (1 << need);
			}
		}
		int result = study(0,0,0);
		if (result == INF)
			cout << "IMPOSSIBLE\n";
		else
			cout << result<<'\n';
	}
}