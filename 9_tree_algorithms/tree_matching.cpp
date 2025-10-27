#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> matched;
int matching_size = 0;

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            if (!matched[u] && !matched[v]) {
                matched[u] = true;
                matched[v] = true;
                matching_size++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj.resize(n + 1);
    matched.resize(n + 1, false);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << matching_size << "\n";

    return 0;
}