//2022_03_22 ���ϵ�ī�� ������ȹ��
//���� ��Ž���� �غ��� ����


//�Ǽ�1: ���ϵ�ī�尡 '*'�� ��찡 �����ε� filename ����ִ� �ͺ��� üũ - ���� �ٲ�
//�Ǽ�2: �ƽ�Ű�ڵ� ������� ��� �� ��	- vector�� �����ϰ� sort�� ���
//�Ǽ�3: �Ƹ��� * �ڿ� Ư�����ڰ� ���� ���ڿ��� ���ؼ� ������ �߻����� ������? - *�� ��� ��� ����� ���� ã�� ������ ����
//- ����
#include <bits/stdc++.h>

using namespace std;

//ĳ�̿�
int cache[100][100];

//����Ž��
bool isfileMatch(const string& wildcard, const string& filename) {
	//�������1: ��Ȯ�� �������� ���
	if (filename == "" && wildcard == "")
		return true;
	//�������2: ���ϵ�ī�尡 '*'�� ���
	if (wildcard.size() == 1 && wildcard[0] == '*')
		return true;
	//�������3: �ϳ��� ����µ� �ϳ��� �����ִ� ���
	if (wildcard == "" || filename == "")
		return false;

	//�׿�
	char head = wildcard[0];
	string subwildcard = wildcard.substr(1);
	bool ans = false;
	switch (head) {
	case '*':
		//'*'�� ��� ��� ��ʸ� ����(*,? Ư������ �ذ��� ���� ������ ����)
		for (int i = 0; i < filename.size(); ++i) {
				if(isfileMatch(subwildcard, filename.substr(i)))
					ans = true;
		}
		break;
	case '?':
		//'?'�� ��� 1���� �߶󳻰� ����
		if (isfileMatch(subwildcard, filename.substr(1)))
			ans = true;
		break;
	default:
		//������ ��� �� ���� ���ڸ� ���ϰ� �ٸ��� false ������ 1���� �߶󳻰� ����
		if (head != filename[0])
			return false;
		else
			if (isfileMatch(subwildcard, filename.substr(1)))
				ans = true;
	}
	return ans;
}

//������ȹ��
bool isfileMatchDP(const string& wildcard, const string& filename, int wildidx, int fileidx) {
	//�������1: ��Ȯ�� �������� ���
	if (filename == "" && wildcard == "")
		return true;
	//�������2: ���ϵ�ī�尡 '*'�� ���
	if (wildcard.size() == 1 && wildcard[0] == '*')
		return true;
	//�������3: �ϳ��� ����µ� �ϳ��� �����ִ� ���
	if (wildcard == "" || filename == "")
		return false;
	
	//�κй���
	int& ret = cache[wildidx][fileidx];
	if (ret != -1)
		return ret;

	//���� ���� �ʴٰ� ����
	ret = false;
	//�׿�
	char head = wildcard[0]; //ù����
	string subwildcard = wildcard.substr(1); //���� ���ϵ�ī��
	switch (head) {
	case '*':
		//'*'�� ��� ��� ��ʸ� ����(*,? Ư������ �ذ��� ���� ������ ����)
		for (int i = 0; i < filename.size(); ++i) {
			if (isfileMatchDP(subwildcard, filename.substr(i),wildidx + 1, fileidx + i))
				ret = true;
		}
		break;
	case '?':
		//'?'�� ��� 1���� �߶󳻰� ����
		if (isfileMatchDP(subwildcard, filename.substr(1),wildidx+1,fileidx+1))
			ret = true;
		break;
	default:
		//������ ��� �� ���� ���ڸ� ���ϰ� �ٸ��� false ������ 1���� �߶󳻰� ����
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