#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define INF 1000000000000
using namespace std;

// function to find number of possible arrays that satisfy
// the description
ll getans(vector<ll>& arr, ll N, ll M,
        vector<vector<ll> >& dp)
{
    // Iterate over all indices from 0 to N - 1
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            // If we are at the first index and the value is
            // unknown
            if (arr[i] == 0) {
                // There is only one way to put any value at
                // the first index
                for (int val = 1; val <= M; val++)
                    dp[i][val] = 1;
            }
            else {
                // If we are at the first index and the
                // value is fixed, there is only one way to
                // put the value arr[0] at 0th index
                dp[i][arr[i]] = 1;
            }
        }
        else {
            // If we are not at the first index and the
            // value is unknown, then for each val from 1 to
            // M, the number of ways to put val are equal to
            // the number of ways we can put val-1, val,
            // val+1 at the previous index
            if (arr[i] == 0) {
                for (int val = 1; val <= M; val++) {
                    dp[i][val] = (dp[i - 1][val - 1]
                                + dp[i - 1][val]
                                + dp[i - 1][val + 1])
                                % mod;
                }
            }
            // If we are not at the first index and the
            // value is known, then the number of ways to
            // put arr[i] are equal to the number of ways we
            // can put arr[i]-1, arr[i], arr[i]+1 at the
            // previous index
            else {
                dp[i][arr[i]] = (dp[i - 1][arr[i] - 1]
                                + dp[i - 1][arr[i]]
                                + dp[i - 1][arr[i] + 1]) % mod;
            }
        }
    }

    // Variable to store the final answer
    ll ans = 0;

    // Sum the number of ways of putting any value in the
    // last index to get the final answer
    for (int val = 1; val <= M; val++) {
        ans = (ans + dp[N - 1][val]) % mod;
    }

    return ans;
}
int main()
{
    // Sample Input
    ll N = 3, M = 5;
    vector<ll> arr = {2, 0, 2};

    // dp[][] array such that dp[i][j] stores the number of
    // arrays that have arr[i] = j
    vector<vector<ll> > dp(N, vector<ll>(M + 2, 0));
    cout << getans(arr, N, M, dp) << endl;
}
