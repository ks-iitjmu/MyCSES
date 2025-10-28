#include <bits/stdc++.h>
using namespace std;
 
/*
  We want the lexicographically minimal string of length (2n-1) formed by
  moving from (0,0) to (n-1,n-1) on an n×n grid of letters, moving only Right or Down.
 
  We do a DP “by diagonals,” but avoid O(n^3) clearing.  Instead, we keep an
  integer array can_step[i][j], initialized to –1.  If can_step[i][j] == d, that
  means “cell (i,j) is reachable by a path whose prefix-string of length (d+1)
  is the lexicographically minimal possible among all paths to diagonal d.”
 
  - Initialize can_step[0][0] = 0 (diagonal 0).  answer[0] = grid[0][0].
  - For each diagonal d = 0..(2n-3):
      1) Scan all (i,j) with i+j = d and can_step[i][j] == d.  Look at their
         neighbors (i+1,j) and (i,j+1) if in bounds, and find the smallest letter
         among those neighbors. Call it bestChar.
      2) Set answer[d+1] = bestChar.
      3) Scan the same (i,j) again; for any neighbor whose letter == bestChar,
         set can_step[ni][nj] = d+1.  (Overwriting if it was < d+1; if it was
         already d+1, no harm.)  That marks exactly those cells on diagonal d+1
         that lie on a path with minimal prefix of length d+2.
  - After finishing d = 0..(2n-3), answer has length (2n-1).  Print it.
 
  Each diagonal has O(n) cells, and there are 2n-1 diagonals, so O(n^2) total.
*/
 
static int can_step[3000][3000];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
 
    if (n == 1) {
        // Only one cell
        cout << grid[0][0] << "\n";
        return 0;
    }
 
    // Initialize can_step to -1
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            can_step[i][j] = -1;
        }
    }
    // (0,0) is on diagonal 0
    can_step[0][0] = 0;
 
    string answer;
    answer.reserve(2*n - 1);
    answer.push_back(grid[0][0]);
 
    // Process diagonals d = 0,1,...,2n-3
    for(int d = 0; d < 2*n - 2; d++) {
        // Determine the range of i for which i+j = d and 0 <= i,j < n:
        int i_min = max(0, d - (n-1));
        int i_max = min(n-1, d);
 
        // 1) Find bestChar among all neighbors of (i,j) with can_step[i][j] == d
        char bestChar = 'Z' + 1;
        for(int i = i_min; i <= i_max; i++) {
            int j = d - i;
            if (can_step[i][j] != d) continue;
            if (i + 1 < n) {
                char c = grid[i+1][j];
                if (c < bestChar) bestChar = c;
            }
            if (j + 1 < n) {
                char c = grid[i][j+1];
                if (c < bestChar) bestChar = c;
            }
        }
 
        answer.push_back(bestChar);
 
        // 2) Mark can_step[ni][nj] = d+1 for any neighbor whose letter == bestChar
        for(int i = i_min; i <= i_max; i++) {
            int j = d - i;
            if (can_step[i][j] != d) continue;
            if (i + 1 < n && grid[i+1][j] == bestChar) {
                can_step[i+1][j] = d + 1;
            }
            if (j + 1 < n && grid[i][j+1] == bestChar) {
                can_step[i][j+1] = d + 1;
            }
        }
    }
 
    cout << answer << "\n";
    return 0;
}