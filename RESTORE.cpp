//2022_04_05 ���� �̿��� �޸������̼�
//RESTORE ���� ������ �����ϱ�

//13:19�� ����
//1. ���λ� - ���̻�, ���̻� - ���λ� �� ��쿡�� ��ĥ �� ����
//2. �� �ܾ ���� ª�� ��ġ�� �Լ�, ��� ������ ������ �Լ�(15!)
//14:13�� ����! ����Ȯ��
//��Ʈ����ũ ������ �𸣴ϱ� ĳ���� �ϴµ� ������� ���� ���ǿ� ������ �ٽ� ���߰���

#include <bits/stdc++.h>

using namespace std;

int k;
const int INF = 987654321;

string combination(const string& s1, const string& s2) {
	if (s1.find(s2) != string::npos)
		return s1;
	//s1�� �ڿ� s2�� ��ġ��
	int maxReplace = s1.size();
	for (int i = s1.size() - 1; i >= 0; --i) {
		if (s1[i] == s2[0]) {
			int idx1 = i + 1, idx2 = 1;
			bool canReplace = true;
			while (idx1 < s1.size() && idx2 < s2.size()) {
				if (s1[idx1] != s2[idx2]) {
					canReplace = false;
				}
				idx1++; idx2++;
			}
			if (canReplace == true)
				maxReplace = i;
		}
	}
	return s1.substr(0, maxReplace) + s2;
}

//wordUsed: ���ݱ��� ����� �ܾ��� ��
//visited: used�迭�� intȭ�� ����
//prev: ���� ����� �ܾ�
int solve1(int wordUsed, int visited, int prev) {
	//�������1: ��� �ܾ �� ����ߴٸ� 0�� ��ȯ
	if (wordUsed == k)
		return 0;
	int& ret = cache[wordUsed][visited];
	if (ret != -1)
		return ret;
	ret = INF;
	int bestChoice = -1;
	for (int i = 0; i < k; ++i) {
		//���� ������� ���� �ܾ ã�Ƽ� ���� �ܾ� �ڿ� ������.
		if (!used[i]) {
			used[i] = true;
			int cand = solve1(wordUsed+1, boolToint(), i) + combination(words[prev], words[i]).size();
			if (cand < ret) {
				ret = cand;
				bestChoice = i;
			}
			used[i] = false;
		}
	}
	choice[prev] = bestChoice;
	return ret;
}

//���� ��� �籸��
void reconstruct(int start, string& result) {
	if (start != -1) result = result.substr(combination(result, words[start])) + words[start];
	int next = choice[start + 1];
	if (next != -1) reconstruct(next, result);
}

//used�迭�� int�� �ٲ��ش�.
int boolToint() {
	int trans = 0;
	for (int i = 0; i < k; ++i) {
		if (used[i] == true) {
			trans += pow(2, i);
		}
	}
	return trans;
}

int choice[15];
int cache[15][40000];
vector<int> wordLength(15);
vector<bool> used(15);
vector<string> words;

int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));

	}
}