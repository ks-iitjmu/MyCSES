#include <bits/stdc++.h>
using namespace std;

/*

Counting Rooms problem

Prerequisite:

Graph theory, Disjoint Set Union (DSU) / Union-Find, 2D grid traversal.

Main Idea:

Model each floor cell as a node and connect adjacent floor cells (up, down, left, right) using DSU. Each connected component of floor cells represents one room.

Solution:

1. Treat the grid as a graph where each `.` (floor) is a node.
2. Use DSU to unite adjacent floor cells that share a border.
3. After processing all cells, count the number of unique DSU parents among floor cells.
4. The number of unique roots = total number of rooms.

Optimization Trick:
Instead of running DFS/BFS for each unvisited cell, DSU efficiently merges connected components in near O(α(N)) time. Using `iota()` for initialization simplifies the DSU setup.
*/

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0); // Initialize each node's parent to itself (i.e., parent[i] = i)
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    DSU dsu(n * m);

    auto idx = [&](int i, int j) { return i * m + j; };
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // Union adjacent floor cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                for (auto &d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '.') {
                        dsu.unite(idx(i, j), idx(ni, nj));
                    }
                }
            }
        }
    }

    // Count distinct roots (rooms)
    unordered_set<int> rooms;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                rooms.insert(dsu.find(idx(i, j)));
            }
        }
    }

    cout << rooms.size() << "\n";
    return 0;
}
