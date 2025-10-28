/*
Problem: Flight Routes (CSES Problem Set 1196)
Category: Graph Algorithms
Difficulty: Medium
Time Complexity: O(m * log(n * k))
Space Complexity: O(n * k)

Approach:
This is a variant of Dijkstra’s algorithm where we need the k shortest paths
from the source (1) to destination (n), allowing repeated nodes in routes.

We maintain for each node a max-heap of up to k shortest distances found so far.
We process nodes in increasing order of distance (via a min-heap).
If a new smaller distance is found, we push it into that node's heap.
If the heap exceeds k, we remove the largest (keeping only k smallest).

This avoids sorting every time (unlike a vector-based approach),
resulting in much faster performance for large graphs.

Key Insights:
- Standard Dijkstra only tracks one best distance per node; here we track up to k.
- Using a max-heap per node allows O(log k) insertion/removal.
- We only store k distances per node → O(n * k) memory.
- Since k ≤ 10, the algorithm is very efficient.

Edge Cases:
- Multiple edges between the same nodes.
- Repeated visits to the same node with different costs.
- Large weights (use long long).
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

    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // Max-heaps to store up to k shortest distances per node
    vector<priority_queue<long long>> dist(n + 1);

    // Min-heap for Dijkstra: {distance, node}
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    pq.push({0, 1});
    dist[1].push(0);

    while (!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        // Skip if this path is not among the k smallest for this node
        if (dist[node].top() < currDist && (int)dist[node].size() == k)
            continue;

        for (auto &[next, wt] : adj[node]) {
            long long newDist = currDist + wt;

            // If less than k distances stored or this one is smaller than the largest
            if ((int)dist[next].size() < k || newDist < dist[next].top()) {
                dist[next].push(newDist);
                pq.push({newDist, next});
                if ((int)dist[next].size() > k)
                    dist[next].pop(); // Keep only k smallest distances
            }
        }
    }

    // Collect all distances from max-heap of destination node and sort ascending
    vector<long long> ans;
    while (!dist[n].empty()) {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }
    sort(ans.begin(), ans.end());

    for (auto &d : ans)
        cout << d << " ";
    cout << "\n";

    return 0;
}
