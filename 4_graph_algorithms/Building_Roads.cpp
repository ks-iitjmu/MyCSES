/*
Problem: Building Roads
Category: Graph Algorithms (Undirected Graph)
Difficulty: Medium
Time Complexity: O(n + m)
Space Complexity: O(n + m)

Approach:
Use graph traversal to find connected components. Pick one representative node from each
component; the minimum number of roads required to connect all components is (components - 1).
Connect the representatives in a simple chain: (rep[0], rep[1]), (rep[1], rep[2]), ...

Key Insights:
- Any connected component can be represented by any one of its vertices.
- Connecting k components requires exactly k-1 edges; connecting representatives in a chain
  achieves this minimum.
- Use iterative DFS (explicit stack) to avoid recursion-depth issues on large inputs.
- Handle edge cases: n = 1, m = 0, already connected graphs.

Notes:
- Nodes are 1-indexed (as per CSES problem statement).
- Fast I/O is used for competitive programming.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read number of cities (nodes) and existing roads (edges)
    int num_nodes, num_edges;
    if (!(cin >> num_nodes >> num_edges)) return 0;

    // Adjacency list for the undirected graph (1-indexed)
    vector<vector<int>> adjacency(num_nodes + 1);
    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        cin >> u >> v;
        // add both directions because graph is undirected
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    // visited[i] == true means node i has been visited in component discovery
    vector<char> visited(num_nodes + 1, false);
    // representatives: one node per connected component
    vector<int> representatives;
    representatives.reserve(num_nodes);

    // Iterative DFS function using an explicit stack to avoid recursion depth limits
    auto iterative_dfs = [&](int start) {
        // stack for DFS traversal
        std::stack<int> dfs_stack;
        dfs_stack.push(start);
        visited[start] = true;

        while (!dfs_stack.empty()) {
            int node = dfs_stack.top();
            dfs_stack.pop();

            // visit all neighbors
            for (int neighbor : adjacency[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    dfs_stack.push(neighbor);
                }
            }
        }
    };

    // Find connected components by scanning all nodes
    for (int node = 1; node <= num_nodes; ++node) {
        if (!visited[node]) {
            // node is a new component representative
            representatives.push_back(node);
            // mark all nodes in this component as visited
            iterative_dfs(node);
        }
    }

    // Number of components
    int component_count = static_cast<int>(representatives.size());

    // Minimum roads required to connect all components = components - 1
    int roads_to_add = max(0, component_count - 1);
    cout << roads_to_add << '\n';

    // Output the roads to add: connect consecutive representatives
    for (int i = 0; i + 1 < component_count; ++i) {
        cout << representatives[i] << ' ' << representatives[i + 1] << '\n';
    }

    return 0;
}
