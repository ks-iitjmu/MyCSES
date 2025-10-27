#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> subordinates;

int dfs(int u) {
    int current_subtree_size = 1;

    for (int v : adj[u]) {
        current_subtree_size += dfs(v);
    }

    subordinates[u] = current_subtree_size - 1;

    return current_subtree_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    adj.resize(n + 1);
    subordinates.resize(n + 1);

    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << " ";
    }
    cout << "\n";

    return 0;
}