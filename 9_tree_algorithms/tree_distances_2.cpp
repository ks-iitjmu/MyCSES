#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<long long> subtree_size;
vector<long long> dist_sum_down;
vector<long long> ans;

void dfs_down(int u, int p) {
    subtree_size[u] = 1;
    dist_sum_down[u] = 0;

    for (int v : adj[u]) {
        if (v != p) {
            dfs_down(v, u);
            
            subtree_size[u] += subtree_size[v];
            
            dist_sum_down[u] += dist_sum_down[v] + subtree_size[v];
        }
    }
}

void dfs_up(int u, int p) {
    if (p != 0) {
        long long sum_to_rest_of_tree = ans[p] - (dist_sum_down[u] + subtree_size[u]);
        
        long long size_of_rest_of_tree = n - subtree_size[u];
        
        ans[u] = sum_to_rest_of_tree + size_of_rest_of_tree;
        ans[u] += dist_sum_down[u];
    }

    for (int v : adj[u]) {
        if (v != p) {
            dfs_up(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    adj.resize(n + 1);
    subtree_size.resize(n + 1);
    dist_sum_down.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        if (!(cin >> a >> b)) return 0;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_down(1, 0);

    ans[1] = dist_sum_down[1];

    dfs_up(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}
