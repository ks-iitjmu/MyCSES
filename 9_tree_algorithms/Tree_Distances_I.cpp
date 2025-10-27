#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> max1_down, max2_down;
vector<int> up_dist;

void dfs1(int u, int p) {
    max1_down[u] = 0;
    max2_down[u] = 0;

    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u);
            int dist = max1_down[v] + 1;

            if (dist > max1_down[u]) {
                max2_down[u] = max1_down[u];
                max1_down[u] = dist;
            } else if (dist > max2_down[u]) {
                max2_down[u] = dist;
            }
        }
    }
}

void dfs2(int u, int p) {
    int parent_max_path;
    
    if (max1_down[u] + 1 == max1_down[p]) {
        parent_max_path = max2_down[p];
    } else {
        parent_max_path = max1_down[p];
    }
    
    up_dist[u] = max(up_dist[p], parent_max_path) + 1;

    for (int v : adj[u]) {
        if (v != p) {
            dfs2(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    adj.resize(n + 1);
    max1_down.resize(n + 1);
    max2_down.resize(n + 1);
    up_dist.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0);

    up_dist[1] = 0;
    dfs2(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << max(max1_down[i], up_dist[i]) << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}
