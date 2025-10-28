#include<bits/stdc++.h>
using namespace std;


/*

Company Queries II (https://cses.fi/problemset/task/1688)

# Prerequisite:
->  DP, Tree Algorithms, Binary Lifting

# Main Idea:
->  - Since we need to find the lowest common boss of two employee, which is essentially lowest common ancestor node of the both employee.
    - So we need to find LCA of two given node u and v for q queries.
    - For finding LCA of two nodes efficiently we will use technique called Binary Lifting.
    - The main idea is to store the (2^k)th ancestor of any node.
    - For following tree, (2^1)th ancestor of 4 is 1.
    1
   / \
  2   3
 /
4
    - We can precompute the ancestors in nlogn and then for finding LCA, we'll use the precomputed values to find the LCA.

- Resource link: https://cp-algorithms.com/graph/lca_binary_lifting.html

# Complexties:
->  1. Time Complexity: O(n * log(n) + q * log(n))
    2. Space Commplexity: O(n * log(n))

# Optimizations:
->  1. Space Optimization: Use jump pointers to reduce space to O(n)
       Link: https://codeforces.com/blog/entry/74847
    
    2. Euler Tour + RMQ: Reduce query time to O(1) with O(n log n) preprocessing
       Link: https://cp-algorithms.com/graph/rmq_linear.html
    
    3. Farach-Colton-Bender Algorithm: Achieve O(n) preprocessing + O(1) per query
       Link: https://cp-algorithms.com/graph/lca_farachcoltonbender.html

*/


int n, q;
vector<vector<int>> adj;
/// @brief Stores the 2^kth ancestor of any node. 
/// ancestor[u][k] = 2kth ancestor of node u
vector<vector<int>> ancestor; 

/// @brief Stores the depth of node u from the root node(here 1).
vector<int> depth;

void dfs(int node, int parent = -1, int current_depth = 0) {
    depth[node] = current_depth;
    for (int &child: adj[node]) {
        if (child != parent) {
            dfs(child, node, current_depth + 1);
        }
    }
}

/// @brief
/// For finding LCA of the two nodes, first we have to bring them in equal depth.
/// Suppose for two nodes u and v, depth[v] > depth[u] so we have to bring v to the same level as u. For that we will use our ancestor table
/// Then if the new v == u, then u is our ancestor, else we have to find a common node.
/// @return LCA of two given node u and v
int lca(int u, int v) {
    // keep always depth[v] > depth[u]
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    
    int diff = depth[v] - depth[u];
    int power = 0;
    
    // Bring v to the same level as u
    while (diff) {
        int bit = diff % 2;
        if (bit) {
            if (ancestor[v][power] == -1) {
                break;
            }
            v = ancestor[v][power];
        }
        if (v == -1) {
            break;
        }
        power++, diff >>= 1;
    }
    
    // After aligning depths, if v reached u, then u is the LCA
    /*
    Example:
            3     -> lca(3, 4) = 3 because 3 is an ancestor of 4
           / \
          1   5
         / 
        4 
    */
    if (v == u) {
        return v;
    }
    
    // Both nodes are at same depth but not the same node
    // Use binary search approach: try to jump by decreasing powers of 2
    // Jump both nodes up while their ancestors at that level are different
    // This ensures we stop just below the LCA
    /*
    Example:
            3        -> lca(7, 2) = 3
           / \          
          1   5         After alignment, u=2 and v=7 are at same depth
         /     \        We jump both up simultaneously until we reach nodes 1 and 5
        4       6       (which have the same parent 3)
       /         \      Then return ancestor[1][0] = 3
      2           7
    */
    for (int i = (int) log2(n) + 1; i >= 0; i--) {
        if (ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }

    // After the loop, both u and v are children of the LCA
    // So their immediate parent (2^0 ancestor) is the LCA
    return ancestor[u][0];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    ancestor.resize(n + 1, vector<int>((int) log2(n) + 2, -1));
    adj.resize(n + 1);
    depth.resize(n + 1, 0);
    
    for (int child = 2; child <= n; child++) {
        int parent;
        cin >> parent;
        adj[parent].push_back(child);
        // 2^0th ancestor of any node will be it's parent
        ancestor[child][0] = parent;
    }
    
    // Build the binary lifting table using dynamic programming
    // Time Complexity: O(n * log(n))
    /*
    -> To find the 2^k-th ancestor, we can jump twice by 2^(k-1)
    
    Example:
                1        To find 2^2-th (4th) ancestor of node 5:
               /         - First find 2^1-th (2nd) ancestor of 5 → node 3
              4          - Then find 2^1-th (2nd) ancestor of 3 → node 1
             /           So ancestor[5][2] = ancestor[ancestor[5][1]][1]
            3
           /             So: ancestor[node][k] = ancestor[ancestor[node][k-1]][k-1]
          2
         /
        5  
    */
    for (int node = 1; node <= n; node++) {
        for (int jump = 1; jump <= (int) log2(n) + 1; jump++) {
            if (ancestor[node][jump - 1] != -1) {
                ancestor[node][jump] = ancestor[ancestor[node][jump - 1]][jump - 1];
            }
        }
    }
    
    dfs(1);
    
    while (q--) {
        // process each query
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    
    return 0;
}