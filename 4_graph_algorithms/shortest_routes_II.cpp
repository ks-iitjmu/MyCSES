#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

Shortest Routes II (https://cses.fi/problemset/task/1672)

# Prerequisite:
-> Graph theory, Floyd-Warshall Algorithm

# Main Idea:
-> As we need to find the shortest route from node u to node v for q queries. We can see that n <= 500, so n^3 <= 1.25e8, so we can use 
   Floyd-Warshall algorithm to find all pair shortest path. 

More on Floyd-Warshall : https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html, https://www.geeksforgeeks.org/dsa/floyd-warshall-algorithm-dist-16/

# Solution:

1. Initialise dist matrix with dimesion (n + 1) * (n + 1)
2. Mark dist[u][u] = 0
3. Apply Floyd-Warshall's algorithm

# Complexties:
1. Time Complexity: O(n^3 + q)
2. Space Commplexity: O(n * n)
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    
  
    /// dist -> stores distance from u -> v, if path doesn't exist then the value will be LLONG_MAX
    vector<vector<ll>> dist(n + 1, vector<ll> (n + 1, LLONG_MAX));

    while (m--) {
        int u, v;
        ll weight;
        cin >> u >> v >> weight;

        // update the distance
        dist[u][v] = min(weight, dist[u][v]);
        dist[v][u] = min(weight, dist[v][u]);
    }
 
    for (int i = 1; i <= n; i++) {
        // from i -> i, the distance will be zero
        dist[i][i] = 0;
    }
 
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if (j == k || (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX)) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == LLONG_MAX) {
            cout << -1 << "\n";
        } else {
            cout << dist[u][v] << "\n";
        }
    }

    return 0;       
}
