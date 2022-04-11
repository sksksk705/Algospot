//2022_04_09 ����Ž��
//�����ϴ� ���ǿ�

#include <bits/stdc++.h>

using namespace std;

const double INF = 1e200;
const int MAX = 30;
int n; //���ü�
double dist[MAX][MAX]; //���ð� �Ÿ��� �����ϴ� �迭
double best; //������ ������
double minEdge[MAX]; //�� ���ÿ� ������ ������ ���� ª�� ���� �̸� ã���ش�.

//���� �ܼ��� ������ �޸���ƽ
double simpleHeuristic(const vector<bool>& visited) {
	double ret = minEdge[0];
	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			ret += minEdge[i];
	}
	return ret;
}

//������ 4���� ������ ��� �ִ� 2 ������ ������ �������.
bool pathSwapPruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int p = path[path.size() - 4];
	int a = path[path.size() - 3];
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	return dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q];
}

//���� ���ÿ� ���� ���ø� ������ �κа�θ� �������.
bool pathSwapPruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	for (int i = 0; i + 3 < path.size(); ++i) {
		int p = path[i];
		int a = path[i + 1];
		if (dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q])
			return true;
	}
	return false;
}

//path: ���ݱ��� ���� ���
//visited: �� ������ �湮����
//currentLength: ���ݱ��� ���� ����� ����
void search(vector<int>& path, vector<bool>& visited, double currentLength) {
	if (currentLength + simpleHeuristic(visited) >= best)
		return;
	int here = path.back();
	if (path.size() == n) {
		best = min(best, currentLength + dist[here][0]);
		return;
	}
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue;
		path.push_back(next);
		visited[next] = true;

		search(path, visited, currentLength + dist[here][next]);
		
		visited[next] = false;
		path.pop_back();
	}
}



double solve() {
	best = INF;
	for (int i = 0; i < n; ++i) {
		minEdge[i] = INF;
		for (int j = 0; j < n; ++j)
			if (i != j) minEdge[i] = min(minEdge[i], dist[i][j]);
	}
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;
	search(path, visited, 0);
	return best;
}

int main() {

}