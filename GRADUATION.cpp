//2022_04_18 ��Ʈ����ũ
//GRADUATION ���� �б�

//n�� 12�̱� ������ 32��Ʈ ������ ǥ������ 16��Ʈ ������ ����
//�׸����� ��Ʈ����ũ�� ®��
//�б� ������ 1������ ��´ٴ� �����̱� ������ 2���� ���� �����Ѵٸ� fail�� ���� ����.
//���� ���� Ž������ ���� ������ ������
//������ȹ������ �����ϴ� ���� ��!
#include <bits/stdc++.h>

using namespace std;


int n, k, m, l;
unsigned short postLearn[12];
unsigned short semester[12];
const int INF = 987654321;

//sem �б� 
//learned ���ݱ��� ���� ����
int study(int sem, int learned, int pass)
{
	//�������1: ���� ����� ä��
	if (__popcnt16(learned) >= k)
 		return sem - pass;

	//�������2: ���� ����� ������ �� ä��
	if (sem >= m)
		return INF;

	unsigned short thisquater = 0;
	for (int lesson = 0; lesson < n; ++lesson)
	{
		//�̹� �б⿡ ���� �� ���� �����̸� continue;
		if (!(semester[sem] & (1 << lesson)))
			continue;

		//����� �ʾ����鼭 ���������� ��� �����ߴٸ� �̹��б⿡ ����;
		if (!(learned & (1 << lesson)) && (learned & postLearn[lesson]) == postLearn[lesson])
			thisquater |= (1 << lesson);
		
	}
	int ret = INF;
	//��� �κ������� ���� ���� �б⸦ üũ�Ѵ�.
	for (unsigned short subset = thisquater; subset; subset = ((subset - 1) & thisquater))
	{
		if (__popcnt16(subset) <= l)
			ret = min(ret, study(sem + 1, learned | subset, pass));
	}
	//�̹� �б⸦ �� ��� �Ѿ�� ���
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