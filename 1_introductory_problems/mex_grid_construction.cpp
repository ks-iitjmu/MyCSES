// Problem: Mex Grid Construction
// Category: Introductory Problems
// Difficulty: Medium
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

// Approach:
// The grid[i][j] is filled with the XOR of row and column indices (i ^ j).
// This ensures that the mex condition holds: each cell has the smallest 
// non-negative integer not appearing to the left in the row or above in the column.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // Construct and print the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (i ^ j) << " ";
        }
        cout << "\n";
    }

    return 0;
}