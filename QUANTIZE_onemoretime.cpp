//2022_03_25 ������ȹ��
//Quantization ����ȭ

//19:34�� ����
//sort�ϰ� ���� ���밪�̻� ���̰� ���� ���ο� ���ڰ��� ����, �� �̻� ������ �� ���ٸ� ���� ū ���ڰ����� ��� -> �ּҰ��� ��ȯ
//����� �� �ִ� ������ �������� ������ �ֱ� ������ �����κб����� �������� ����
//19:54�� �о ���ش� �Ǵµ� ���� Ǯ �� �������� �𸣰���... ���߿� �ٽú��� �ɷ�

#include <bits/stdc++.h>

using namespace std;
vector<int> nums;
int cache[101][101][101];

//������ ������ ���� ����� �� ��
int getSquare(int idx, int quanidx) {
	
}


int quantization(int idx, int numofQuan, int quanidx) {
	int& ret = cache[idx][idx][idx];
	if (ret != -1)
		return ret;
	for(int i = idx+1;i < )
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		int n, s;
		cin >> n >> s;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			nums.push_back(num);
		}


	}
}