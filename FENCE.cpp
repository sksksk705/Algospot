//2022_03_21 분할정복
//1: 중간부터 해서 최대 크기를 확인(1부터 시작해서 양옆의 크기가 n보다 크다면 1++), 중간과 양옆의 최대 크기를 비교, 최대값을 반환 - 양옆의 정의가 모호 기각

#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

int getFence(int left, int right) {
	// 기저사례 판자가 1개밖에 없으면 넓이를 반환
	if (left == right)
		return h[left];
	int mid = (left + right) / 2;
	// 중앙을 기준으로 양옆을 해결 - 분할정복
	int ret = max(getFence(left, mid), getFence(mid+1, right));
	int lo = mid, hi = mid + 1;
	int height = min(h[lo],h[hi]);
	//현재 위치를 중심으로 두칸의 넓이
	ret = max(ret, height * 2);
	//가장 높은 쪽으로 확대하며 직사각형의 넓이를 구함
	while (lo > left || hi < right) {
		if (hi < right && (lo == left || h[hi+1] > h[lo-1])) {
			hi++;
			height = min(height, h[hi]);
		}
		else
		{
			lo--;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	//최대 넓이를 반환
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		h.clear();
		int n;
		cin >> n;
		while (n--) {
			int fence;
			cin >> fence;
			h.push_back(fence);
		}
		cout << getFence(0, h.size()-1)<<'\n';
	}
}