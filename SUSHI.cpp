//2022_04_06 �ݺ��� ���� ��ȹ��
//SUSHI ȸ���ʹ�

//������ �׻� 100�� ��� �� 100 ������ ������ ������ �ʿ䰡 ���� 10000000(õ��)���� �ȴ�.
//%�� �ʹ��� ������ 20000�����̱� ������ �����̵� �����츦 �� �� �ִ�%
#include <bits/stdc++.h>

using namespace std;

int price[21];
int preference[21];
int n, m;
int cache[201];

int eatSushi() {
	int ret = 0;
	for (int money = 0; money <= m; ++money) {
		int cand = 0;
		for (int sushi = 0; sushi < n; ++sushi) {
			if (money >= price[sushi]) {
				cand = max(cand, cache[(money - price[sushi])%201] + preference[sushi]);
			}
		}
		cache[money % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		m /= 100;
		for (int i = 0; i < n; ++i) {
			cin >> price[i];
			price[i] /= 100;
			cin >> preference[i];
		}
		cout << eatSushi();
		memset(cache, 0, sizeof(cache));
	}


}