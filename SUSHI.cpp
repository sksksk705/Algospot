//2022_04_06 반복적 동적 계획법
//SUSHI 회전초밥

//가격은 항상 100의 배수 즉 100 이하의 예산은 생각할 필요가 없다 10000000(천만)개면 된다.
//%각 초밥의 가격은 20000이하이기 때문에 슬라이딩 윈도우를 쓸 수 있다%
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