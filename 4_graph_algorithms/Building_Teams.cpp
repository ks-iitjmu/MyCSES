/*
CSES - Building Teams
Link: https://cses.fi/problemset/task/1668
Difficulty: Medium
Time Complexity: O(N + M)
Space Complexity: O(N + M)

Approach:
Use graph coloring (bipartite check) with BFS to assign pupils to two teams.
Each pupil is a node and each friendship is an undirected edge. We attempt to color
the graph with two colors (1 and 2) so that no adjacent nodes share the same color.
Process every connected component (graph may be disconnected).

Key Insights:
- A graph is bipartite iff it is 2-colorable (no odd-length cycles).
- BFS is used to color level-by-level: if current node has color c, all uncolored
  neighbors get color 3 - c.
- If an edge connects two nodes with the same color, the graph is not bipartite,
  and the answer is "IMPOSSIBLE".
- Iterative BFS avoids recursion depth issues on large inputs.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read number of pupils (n) and friendships (m)
    int n, m;
    cin >> n >> m;

    // Build adjacency list for 1-indexed nodes
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        // undirected friendship edge
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // color[i] = 0 -> unvisited, 1 or 2 -> team assignment
    vector<int> color(n + 1, 0);

    // Process all components to handle disconnected graphs
    for (int start = 1; start <= n; ++start) {
        // If already colored in previous BFS, skip
        if (color[start] != 0) continue;

        // Start BFS from this unvisited node, assign color 1
        queue<int> q;
        color[start] = 1;
        q.push(start);

        // Standard BFS loop
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Check all neighbors of u
            for (int v : adj[u]) {
                if (color[v] == 0) {
                    // Assign the opposite color to the neighbor
                    color[v] = 3 - color[u]; // 1 -> 2, 2 -> 1
                    q.push(v);
                } else if (color[v] == color[u]) {
                    // Conflict detected: same color on both ends of an edge
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }

    // If we reach here, graph is bipartite; print team assignments
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << color[i];
    }
    cout << '\n';
    return 0;
}
