//2022_04_09 조합탐색
//여행하는 외판원

#include <bits/stdc++.h>

using namespace std;

const double INF = 1e200;
const int MAX = 30;
int n; //도시수
double dist[MAX][MAX]; //도시간 거리를 저장하는 배열
double best; //현재의 최적해
double minEdge[MAX]; //각 도시에 인접한 간선중 가장 짧은 것을 미리 찾아준다.

//가장 단순한 형태의 휴리스틱
double simpleHeuristic(const vector<bool>& visited) {
	double ret = minEdge[0];
	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			ret += minEdge[i];
	}
	return ret;
}

//마지막 4개의 도시중 가운데 있는 2 도시의 순서를 뒤집어본다.
bool pathSwapPruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int p = path[path.size() - 4];
	int a = path[path.size() - 3];
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	return dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q];
}

//시작 도시와 현재 도시를 제외한 부분경로를 뒤집어본다.
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

//path: 지금까지 만든 경로
//visited: 각 도시의 방문여부
//currentLength: 지금까지 만든 경로의 길이
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