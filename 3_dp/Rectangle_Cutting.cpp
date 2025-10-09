#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Function to find the minimum number of moves required to
// cut a rectangle of A X B into squares
ll solve(ll A, ll B)
{
    // dp[][] table such that dp[i][j] stores the minimum
    // number of cuts required to cut a rectangle of size (i
    // X j) into squares
    vector<vector<int> > dp(A + 1, vector<int>(B + 1, 1e9));
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            // If the rectangle is already a square, then 0
            // cuts are required
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                // Iterate over all the possible cuts we can
                // make horizontally
                for (int k = 1; k < j; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[i][k] + dp[i][j - k] + 1);
                }
                // Iterate over all the possible cuts we can
                // make vertically
                for (int k = 1; k < i; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }
    // Return the minimum  number of cuts required to cut a
    // rectangle of size (A X B) into squares
    return dp[A][B];
}

int main()
{
    // Sample Input
    int A = 3, B = 5;
  
    cout << solve(A, B) << "\n";
}
