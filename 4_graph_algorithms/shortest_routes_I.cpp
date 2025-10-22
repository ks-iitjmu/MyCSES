/*
Problem: Shortest Routes I
Category: Graph Algorithms (Single Source Shortest Path)
Difficulty: Medium
Time Complexity: O((n + m) * log n)
Space Complexity: O(n + m)

Approach:
This problem asks for the shortest distance from a source city (1) to every other city in a directed, weighted graph.
Since all edge weights are positive, Dijkstra’s Algorithm is the optimal approach.

Steps:
1. Represent the graph using an adjacency list where each node stores pairs (neighbor, weight).
2. Initialize all distances as infinity (INF = 1e18) and set the source city’s distance (city 1) to 0.
3. Use a min-heap (priority queue) to always pick the node with the smallest current distance.
4. For each node popped from the queue:
   - If the current distance is greater than the stored distance, skip (outdated entry).
   - For all adjacent nodes, relax the edge: 
       if dist[u] + w < dist[v], update dist[v] and push (dist[v], v) into the priority queue.
5. After processing all nodes, print the distances from city 1 to every city in order.

Key Insights:
- Dijkstra’s algorithm is efficient for graphs with **non-negative weights**, unlike Bellman-Ford.
- Priority queue ensures that each edge relaxation happens optimally, minimizing redundant work.
- Since the problem guarantees that all nodes are reachable from city 1, there’s no need to handle disconnected components.
- Using `long long` (64-bit integers) prevents overflow, as path lengths can exceed 1e9.
- Fast I/O (`ios::sync_with_stdio(false); cin.tie(nullptr);`) is essential due to large input size.
- Memory-efficient representation with adjacency list handles up to 2×10^5 edges comfortably.

Optimization Tricks:
- Avoid reprocessing nodes by checking `if (d > dist[u]) continue;`.
- Store distances in a vector instead of an unordered_map for faster access (since node indices are contiguous).
- Use `greater<pair<int, int>>` with priority_queue for min-heap behavior.

Edge Cases:
- Multiple edges between same nodes → Dijkstra naturally handles it (shorter path replaces longer one).
- Single city (n = 1) → Output is just 0.
- Large input graphs → Must ensure O((n + m) log n) implementation to stay within 1s time limit.

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;  // Large value representing infinity

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1); // {neighbor, weight}

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0; // Distance to source is 0

    // Min-heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Skip outdated entry

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
