#include <bits/stdc++.h>

using namespace std;

struct OptimizedDisjointSet {
    vector<int> parent, rank,size,enemy;
    OptimizedDisjointSet(int n) : parent(n), rank(n, 1),size(n,1),enemy(n,-1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    int merge(int u, int v) {
        if (u == -1 || v == -1) return max(u, v);
        u = find(u); v = find(v);
        if (u == v) return u;
        if (rank[u] > rank[v]) swap(u, v);
        //이제 v의 랭크가 u의 랭크보다 낮지 않으므로 u를 v의 자식으로 보낸다
        parent[u] = v;
        if (rank[u] == rank[v]) ++rank[v];
        size[v] += size[u];
        return v;
    }

    bool dis(int u, int v) {
        u = find(u), v = find(v);

        if (u == v) return false;

        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return true;
    }
    bool ack(int u, int v) {
        u = find(u), v = find(v);

        if (enemy[u] == v) return false;

        int a = merge(u, v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if (b != -1) enemy[b] = a;
        return true;
    }
};

const string ACK = "ACK";
const string DIS = "DIS";
int n, m;

int maxParty(const OptimizedDisjointSet& buf) {
    int ret = 0;
    for (int node = 0; node < n; ++node) {
        if (buf.parent[node] == node) {
            int enemy = buf.enemy[node];

            if (enemy > node) continue;
            int mySize = buf.size[node];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);

            ret += max(mySize, enemySize);
        }
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> m;
        OptimizedDisjointSet editor(n);
        bool noProblem = true;
        int contradiction = -1;
        for (int i = 0; i < m; ++i) {
            string comment;
            int a, b;
            cin >> comment >> a >> b;
            if (comment == ACK)
                noProblem = editor.ack(a, b);
            else
                noProblem = editor.dis(a, b);

            if (!noProblem)
                contradiction = i + 1;
            }
        if (contradiction != -1)
            cout << contradiction;
        else
            cout << maxParty(editor);
    }
}