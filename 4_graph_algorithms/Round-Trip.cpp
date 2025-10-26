#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool isCycle(int v, int p)
{
    visited[v] = true;
    for (int child : adj[v])
    {
        if (child == p)
            continue; // Skip the parent node
        if (visited[child])
        {
            cycle_end = v;
            cycle_start = child;
            return true;
        }
        parent[child] = v;
        if (isCycle(child, v))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;
    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && isCycle(v, parent[v]))
            break;
    }

    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
        {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        cout << cycle.size() << '\n';
        for (int v : cycle)
        {
            cout << v + 1 << ' ';
        }
    }
    return 0;
}

//Time Complexity: O(n + m) where n is number of nodes and m is number of edges
//Space Complexity: O(n + m) for adjacency list and O(n) for visited and parent arrays

//Problem link: https://cses.fi/problemset/task/1669/