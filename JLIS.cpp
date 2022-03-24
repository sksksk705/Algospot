//2022_03_24 ������ȹ��
//��ģ LIS

//����Ž�� -> ��ü��ΰ� �ƴ� �κа���� �ִ밪 -> �����κб��� -> �����ϰ� �Է� ��ȯ -> �޸������̼� ����
//���� ���ļ� sort�ϰ� lis��ȯ�ϸ� �Ǵ� �� �ƴѰ�? - ����(sort�ϸ� �ڿ� ���ڰ� ������ �� �� �ְ� ��)
//�� �������� �ϳ��� ������ ���� �� �ִ�. �׷��ٸ� �Լ��� 2���� ������ ����?
//dp�� �׻� ��ȭ�� ����� ���� �ֿ켱������ �����ؾ���.
#include <bits/stdc++.h>

using namespace std;
const long long NEGINF = LLONG_MIN;
int n, m;
long long cache[101][101];
vector<long long> seq1;
vector<long long> seq2;
long long jLis(int idx1, int idx2) {
	long long& ret = cache[idx1+1][idx2+1];
	if (ret != -1)
		return ret;
	ret = 2;
	long long min1 = (idx1 == -1 ? NEGINF : seq1[idx1]);
	long long min2 = (idx2 == -1 ? NEGINF : seq2[idx2]);
	long long max_elem = max(min1, min2);
	for (int i = idx1 + 1; i < n; ++i)
		if (seq1[i] > max_elem)
			ret = max(ret, (jLis(i, idx2) + 1));

	for (int i = idx2 + 1; i < m; ++i)
		if (seq2[i] > max_elem)
			ret = max(ret, (jLis(idx1, i) + 1));

	return ret;
}

int main()
{
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));
		seq1.clear();
		seq2.clear();
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			seq1.push_back(num);
		}
		for (int i = 0; i < m; ++i) {
			int num;
			cin >> num;
			seq2.push_back(num);
		}

		cout << jLis(-1,-1)-2 << '\n';
	}
}