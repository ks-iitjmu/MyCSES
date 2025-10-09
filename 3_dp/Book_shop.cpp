#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Function to find the maximum number of pages which we can
// have with cost <= X
ll solve(ll N, ll X, vector<ll> price, vector<ll> pages)
{
    // dp[] array such that dp[i] stores the maximum number
    // of pages we can buy such that the cost is at most i
    vector<ll> dp(X + 1, 0);

    // Iterate over all the books
    for (int i = 0; i < N; i++) {
        // Iterate over the cost from X to 0
        for (int C = X; C > 0; C--) {
            // Check if we can purchase the ith book
            if (price[i] > C)
                continue;
            // Update dp[C] if purchasing the ith book will
            // increase the total number of pages
            dp[C] = max(dp[C], pages[i] + dp[C - price[i]]);
        }
    }
    return dp[X];
}
int main()
{
    // Sample Input
    ll N = 4, X = 10;

    vector<ll> price = {4, 8, 5, 3};
    vector<ll> pages = {5, 12, 8, 1};

    cout << solve(N, X, price, pages) << endl;
}
