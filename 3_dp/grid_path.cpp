#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll solve(vector<string>& grid, ll N)
{
    // dp[][] array such that dp[i][j] stores the number of
    // ways to reach cell(i, j) from cell(0, 0)
    vector<vector<ll> > dp(N, vector<ll>(N, 0));


    // Finding the number of ways for the first column
    for (int i = 0; i < N; i++) {
        if (grid[i][0] == '*')
            break;
        dp[i][0] = 1;
    }

    // Finding the number of ways for the first row
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == '*')
            break;
        dp[0][j] = 1;
    }

    // Finding the number of ways for the remaining grid
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            // If the cell is blocked, then move to the next
            // cell
            if (grid[i][j] == '*')
                continue;

            // The number of ways to reach cell(i, j) =
            // number of ways to reach cell (i-1,j) + number
            // of ways to reach cell(i,j-1)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    
      // Return the number of ways to reach the last cell of the grid
    return dp[N - 1][N -1];
}

int main()
{
      // Sample Input
    ll N = 4;
    vector<string> grid = {"....", ".*..", "...*", "*..."};
  
    cout << solve(grid, N) << "\n";
}
