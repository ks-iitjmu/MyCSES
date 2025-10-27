#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, q;
int max_log;
vector<vector<int>> up; 
vector<int> depth; 

void dfs(int u, int p, int d, const vector<vector<int>>& child_list_ref) {
    depth[u] = d;
    up[u][0] = p;

    for (int j = 1; j <= max_log; ++j) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }

    for (int v : child_list_ref[u]) {
        dfs(v, u, d + 1, child_list_ref);
    }
}

int get_kth_ancestor(int u, int k) {
    if (k > depth[u]) {
        return -1;
    }

    for (int j = max_log; j >= 0; --j) {
        if (k & (1 << j)) {
            u = up[u][j];
        }
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    max_log = log2(n) + 1;

    up.assign(n + 1, vector<int>(max_log + 1, 0));
    depth.assign(n + 1, 0);
    
    vector<vector<int>> child_list(n + 1);
    
    for (int i = 2; i <= n; ++i) {
        int boss;
        if (!(cin >> boss)) return 0;
        child_list[boss].push_back(i);
    }
    
    up[1][0] = 0; 
    
    dfs(1, 0, 0, child_list);

    for (int i = 0; i < q; ++i) {
        int x, k;
        if (!(cin >> x >> k)) return 0;
        cout << get_kth_ancestor(x, k) << "\n";
    }

    return 0;
}
