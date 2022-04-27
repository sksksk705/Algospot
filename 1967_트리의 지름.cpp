//2022_04_27 트리
//1967_트리의 지름

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int idx;
	vector<pair<int,TreeNode*>> child;
	TreeNode(int i) :idx(i) {}
};

//루트부터 시작해서 idx가 같으면 노드를 삽입해준다.
bool insert(TreeNode* root, int parent, int idx, int edge) {
	if (root->idx == parent)
	{
		TreeNode* node = new TreeNode(idx);
		root->child.push_back(make_pair(edge, node));
		return true;
	}
	for (auto child : root->child)
	{
		if (insert(child.second, parent, idx, edge))
			return true;
	}
	return false;
}

int ret = 0;
int getLongest(TreeNode* root) {
	int maxHeight = 0;
	for (auto child : root->child)
	{
		int subHeight = getLongest(child.second) + child.first;
		//루트로부터 가장 높은 2개의 서브트리의 높이를 더해준다.
		ret = max(ret, maxHeight + subHeight);
		maxHeight = max(subHeight, maxHeight);
	}
	return maxHeight;
}

int main() {
	TreeNode* root = new TreeNode(1);
	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i)
	{
		int parent, child, edge;
		cin >> parent >> child >> edge;
		insert(root, parent, child, edge);
	}
	getLongest(root);
	cout << ret;
}