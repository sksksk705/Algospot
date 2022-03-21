//2022_03_21 ��������
//1: �߰����� �ؼ� �ִ� ũ�⸦ Ȯ��(1���� �����ؼ� �翷�� ũ�Ⱑ n���� ũ�ٸ� 1++), �߰��� �翷�� �ִ� ũ�⸦ ��, �ִ밪�� ��ȯ - �翷�� ���ǰ� ��ȣ �Ⱒ

#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

int getFence(int left, int right) {
	// ������� ���ڰ� 1���ۿ� ������ ���̸� ��ȯ
	if (left == right)
		return h[left];
	int mid = (left + right) / 2;
	// �߾��� �������� �翷�� �ذ� - ��������
	int ret = max(getFence(left, mid), getFence(mid+1, right));
	int lo = mid, hi = mid + 1;
	int height = min(h[lo],h[hi]);
	//���� ��ġ�� �߽����� ��ĭ�� ����
	ret = max(ret, height * 2);
	//���� ���� ������ Ȯ���ϸ� ���簢���� ���̸� ����
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
	//�ִ� ���̸� ��ȯ
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