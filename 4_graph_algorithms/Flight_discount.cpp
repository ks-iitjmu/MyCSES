/*
Problem: Flight Discount
Category: Graphs / Shortest Path (Dijkstra’s Algorithm)
Difficulty: Medium

Time Complexity: O((n + m) * log n)
Space Complexity: O(n + m)

Approach:
---------
We need to find the cheapest path from city 1 (Syrjälä) to city n (Metsälä)
where we can use a *single discount coupon* on any one flight. The coupon halves
the cost of that flight (using floor division).

We can solve this using a modified version of **Dijkstra’s algorithm** with
a "state expansion" approach:

Each city (node) can be visited in two possible states:
1. Without using the discount yet.
2. After using the discount.

We maintain two distances for each city:
- dist[node][0]: Minimum cost to reach this city without using the discount.
- dist[node][1]: Minimum cost to reach this city after using the discount.

We use a priority queue (min-heap) to always process the smallest cost first.

At each step:
- If the discount hasn’t been used yet:
    - We can either travel normally (cost = w)
    - Or use the discount now (cost = floor(w / 2))
- If the discount has already been used:
    - We can only travel normally.

The final answer is `dist[n][1]`, representing the minimum cost to reach city `n`
with the discount used optimally.

Key Insights:
--------------
- Use a 2D distance array to track both “used discount” and “not used” states.
- Always use a priority queue to ensure optimal Dijkstra performance.
- Be careful with integer division for `floor(w/2)`.
- Large input sizes require fast I/O and long long type for safety.

Edge Cases:
------------
- Graphs where the direct edge with discount is cheaper than multi-edge paths.
- Situations where the best discount usage is *not* on the highest-cost edge.
- Self-loops or redundant edges should not affect correctness.

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Adjacency list representation: adj[u] = { {v, cost}, ... }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[node][0] -> min distance to node without using coupon
    // dist[node][1] -> min distance to node after using coupon
    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    dist[1][0] = 0;

    // Min-heap: {distance, node, used_discount_flag}
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();

        // Skip if already found a better route
        if (d != dist[u][used]) continue;

        for (auto [v, w] : adj[u]) {
            // Option 1: Travel normally
            if (d + w < dist[v][used]) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }

            // Option 2: Use discount (if not used yet)
            if (!used && d + w / 2 < dist[v][1]) {
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << dist[n][1] << "\n";
    return 0;
}
