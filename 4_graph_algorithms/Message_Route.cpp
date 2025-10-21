/*
Problem: Message Route
Category: Graph (Shortest Path - BFS)
CSES Link: https://cses.fi/problemset/task/1667
Difficulty: Medium
Time Complexity: O(N + M)
Space Complexity: O(N + M)

Approach:
Perform Breadth-First Search (BFS) from node 1 on the undirected, unweighted graph.
BFS finds shortest distances (in edges) from the source to every reachable node.
Track a `parent` array while exploring to reconstruct the shortest path from 1 to n.
If node n is unreachable, print "IMPOSSIBLE". Otherwise print the number of nodes
on the shortest route and the route itself.

Key Insights:
- BFS is ideal for shortest path in unweighted graphs because it explores level-by-level.
- Use a large sentinel (INF) to mark unvisited nodes in the distance array.
- Reconstruct path by following parent pointers from destination back to source.
- Use non-recursive approach (BFS) to avoid recursion depth issues on large inputs.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read number of nodes (computers) and edges (connections)
    int n, m;
    cin >> n >> m;

    // Build adjacency list (1-indexed)
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // undirected edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int INF = 1e9;
    vector<int> distance(n + 1, INF); // distance[i] = distance from node 1 to i
    vector<int> parent(n + 1, -1);     // parent[i] = previous node on shortest path to i

    // BFS initialization
    queue<int> q;
    distance[1] = 0;
    q.push(1);

    // Standard BFS loop
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            // If neighbor not visited yet
            if (distance[neighbor] == INF) {
                distance[neighbor] = distance[current] + 1; // one more edge
                parent[neighbor] = current;                 // record path
                q.push(neighbor);
            }
        }
    }

    // If destination node n is unreachable, print IMPOSSIBLE
    if (distance[n] == INF) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct path from n back to 1 using parent pointers
    vector<int> path;
    int node = n;
    while (node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    // Print number of nodes on path and the path itself
    cout << path.size() << '\n';
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }
    cout << '\n';
    return 0;
}
