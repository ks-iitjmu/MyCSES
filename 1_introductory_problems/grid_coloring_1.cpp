// Problem: Grid Coloring I
// Category: Introductory Problems
// Difficulty: Medium
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Approach:
// We will iterate through each cell of the grid and assign it the first
// available color that is different from its top and left neighbors.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++)
    cin >> grid[i];

  vector<char> colors = {'A', 'B', 'C', 'D'};
  vector<string> result = grid; // To store new grid

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (char c : colors) {
        if (c != grid[i][j] && (i == 0 || c != result[i - 1][j]) &&
            (j == 0 || c != result[i][j - 1])) {
          result[i][j] = c;
          break;
        }
      }
    }
  }

  // Print the final grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << result[i][j];
    cout << "\n";
  }

  return 0;
}