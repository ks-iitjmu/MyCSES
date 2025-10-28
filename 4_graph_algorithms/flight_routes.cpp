/*
Problem: Flight Routes (CSES Problem Set 1196)
Category: Graph Algorithms
Difficulty: Medium
Time Complexity: O(m * log(n * k))
Space Complexity: O(n * k)

Approach:
We are asked to find the k shortest flight routes from city 1 (Syrjälä) to city n (Metsälä).
This problem is an extension of Dijkstra’s algorithm.

Standard Dijkstra only finds the single shortest path to each node. 
To find the k shortest paths:
- We maintain, for each node, a list of its k smallest distances found so far.
- A min-heap (priority queue) is used to always explore the path with the smallest distance next.
- Each time we reach a node, if we have found fewer than k paths for it, we record the distance.
- If we already have k distances but find a smaller one, we replace the largest.

We continue until the priority queue is empty. 
The list `dist[n]` will contain the k shortest distances from node 1 to node n.

Key Insights:
- Each node can be visited multiple times because multiple paths might lead to it with different costs.
- Using a min-heap ensures we process paths in increasing order of cost.
- Storing only the k smallest distances per node ensures O(n*k) space.
- Edge case: Multiple routes may have the same cost — all are considered separately.

Edge Cases:
- Multiple edges between the same nodes.
- Graphs with cycles (since revisiting nodes is allowed).
- Large edge weights (up to 1e9), so use long long.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<long long, int>

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // Adjacency list: adj[u] = { {v, cost}, ... }
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[i] will store the k smallest distances found to reach node i
    vector<vector<long long>> dist(n+1);

    // Min-heap: {currentDistance, node}
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    // Starting from node 1 with distance 0
    pq.push({0, 1});
    dist[1].push_back(0);

    // Modified Dijkstra’s algorithm
    while (!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        // Optimization: If we already have k shortest distances and this is larger than the k-th, skip
        if (dist[node].size() > k && currDist > dist[node].back()) continue;

        // Traverse all outgoing edges from the current node
        for (auto &[next, wt] : adj[node]) {
            long long newDist = currDist + wt;

            // Case 1: Fewer than k distances found for this neighbor
            if (dist[next].size() < k) {
                dist[next].push_back(newDist);
                pq.push({newDist, next});
                sort(dist[next].begin(), dist[next].end());
            }
            // Case 2: Replace the largest if a better distance is found
            else if (newDist < dist[next].back()) {
                dist[next].push_back(newDist);
                sort(dist[next].begin(), dist[next].end());
                dist[next].resize(k); // Keep only k smallest distances
                pq.push({newDist, next});
            }
        }
    }

    // Output the k shortest distances to node n
    for (auto d : dist[n]) cout << d << " ";
    cout << "\n";

    return 0;
}
