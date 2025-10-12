// Problem: Grid Paths
// Category: Dynamic Programming / Combinatorics
// Language: C++
// Calculates the number of unique paths from top-left to bottom-right of a grid.

#include <bits/stdc++.h>
using namespace std;

long long gridPaths(int n, int m) {
    vector<vector<long long>> dp(n, vector<long long>(m, 0));

    // Base cases: first row and first column
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int j = 0; j < m; j++) dp[0][j] = 1;

    // Fill DP table using recurrence: dp[i][j] = dp[i-1][j] + dp[i][j-1]
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[n-1][m-1];
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << gridPaths(n, m) << endl;
    return 0;
}
