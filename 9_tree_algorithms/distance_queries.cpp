#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int MAXLOG = 18;

vector<int> adj[MAXN];
int depth[MAXN];
int P[MAXN][MAXLOG];

void dfs(int u, int p, int d) {
    depth[u] = d;
    P[u][0] = p;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

void precompute_lca(int n) {
    for (int j = 1; j < MAXLOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    for (int j = MAXLOG - 1; j >= 0; --j) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = P[u][j];
        }
    }

    if (u == v) {
        return u;
    }

    for (int j = MAXLOG - 1; j >= 0; --j) {
        if (P[u][j] != P[v][j]) {
            u = P[u][j];
            v = P[v][j];
        }
    }

    return P[u][0];
}

int dist(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0); 
    precompute_lca(n);

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << dist(u, v) << "\n";
    }

    return 0;
}