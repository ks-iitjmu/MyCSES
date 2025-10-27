#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
vector<vector<int>> adj;

pair<int, int> bfs(int start_node) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(start_node);
    dist[start_node] = 0;

    int farthest_node = start_node;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] > max_dist) {
            max_dist = dist[u];
            farthest_node = u;
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {farthest_node, max_dist};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pair<int, int> first_bfs_result = bfs(1);
    int farthest_node_from_1 = first_bfs_result.first;

    pair<int, int> second_bfs_result = bfs(farthest_node_from_1);
    int diameter = second_bfs_result.second;

    cout << diameter << "\n";

    return 0;
}