#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Function to print all the possible sums
void solve(vector<ll>& coins, ll N)
{
    // Find the maximum value which we can make using all
    // the coins
    ll sum = accumulate(coins.begin(), coins.end(), 0LL);

    // dp[][] array such that dp[i][j] = true if it is
    // possible to construct sum j using i coins
    vector<vector<bool> > dp(N + 1,
                             vector<bool>(sum + 1, false));
    dp[0][0] = true;

    // Iterate over all the coins
    for (int i = 1; i <= N; i++) {
        // Iterate over all the sums
        for (int j = 0; j <= sum; j++) {
            // If it is possible to construct sum j using
            // (i-1) coins, then mark dp[i][j] = true
            dp[i][j] = dp[i - 1][j];
            // If it is possible to construct sum (j -
            // coins[i]) using (i - 1) coins, then mark
            // dp[i][j] = true
            if (j >= coins[i - 1]
                && dp[i - 1][j - coins[i - 1]]) {
                dp[i][j] = true;
            }
        }
    }

    // vector to store all the sums which are possible to
    // construct using all the coins
    vector<int> possibleSums;

    // Store all the possible sums from 1 to sum which are
    // possible to construct
    for (int j = 1; j <= sum; j++) {
        if (dp[N][j]) {
            possibleSums.push_back(j);
        }
    }

    // Print the number of possible sums
    cout << possibleSums.size() << endl;
    // Print all the possible sums
    for (int i = 0; i < possibleSums.size(); i++)
        cout << possibleSums[i] << " ";
    cout << endl;
}

int main()
{
    // Sample Input
    ll N = 4;

    vector<ll> coins = { 4, 2, 5, 2 };
    solve(coins, N);
}
