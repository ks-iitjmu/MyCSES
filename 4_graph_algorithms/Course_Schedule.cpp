#include <bits/stdc++.h>
using namespace std;
/*
Course Schedule / Topological Sorting Problem

Prerequisite:
Graph theory, Topological sorting, Kahn’s Algorithm (BFS-based approach).

Main Idea:
We are given a set of courses and prerequisite relationships (a → b), meaning
you must complete course 'a' before course 'b'. This forms a Directed Graph.
The task is to determine a valid order of completing all courses — a Topological Order.

Solution:
1. Represent courses as graph nodes (1...n) and prerequisites as directed edges.
2. Compute indegree[] for each node (number of prerequisites).
3. Push all nodes with indegree = 0 (no prerequisites) into a queue.
4. Repeatedly remove a node from the queue:
   - Add it to the result order.
   - Reduce the indegree of all its neighbors by 1.
   - If a neighbor’s indegree becomes 0, push it into the queue.
5. If all nodes are processed → we found a valid order.
   If not → there exists a cycle, and it's IMPOSSIBLE to finish all courses.

Why It Works:
Kahn’s Algorithm ensures that each course is taken only when all its prerequisites are done.
If a cycle exists (mutual dependencies), some nodes will never reach indegree 0.

Complexity:
Time  : O(n + m)   — we visit each node and edge once.
Memory: O(n + m)   — for adjacency list and indegree array.

Alternative:
A DFS-based topological sort can also be used with recursion and a stack,
but Kahn’s Algorithm (BFS) is iterative and cycle-detection-friendly.
*/

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Adjacency list representation of the graph
    // adj[a] will store all nodes b such that there is an edge a -> b
    vector<vector<int>> adj(n + 1);

    // indegree[i] = number of prerequisites (incoming edges) for course i
    vector<int> indegree(n + 1, 0);

    // Reading m prerequisite relations
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);  // a must come before b
        indegree[b]++;        // increase indegree of b
    }

    // Queue to store all courses with no prerequisites (indegree = 0)
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i); // can be taken first
    }

    // This will store the valid topological order
    vector<int> order;

    // Process nodes with no incoming edges
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        // Reduce indegree of all neighbors (courses depending on u)
        for (int v : adj[u]) {
            indegree[v]--;
            // If indegree becomes 0, it can now be taken
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // If we couldn't include all courses, there’s a cycle → impossible to finish all
    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        // Print valid topological order
        for (int x : order)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
