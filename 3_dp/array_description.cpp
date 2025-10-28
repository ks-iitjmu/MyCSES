#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));
    
    if (x[0] == 0) {
        for (int v = 1; v <= m; v++) {
            dp[0][v] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        if (x[i] == 0) {
            for (int v = 1; v <= m; v++) {
                for (int prev = max(1, v - 1); prev <= min(m, v + 1); prev++) {
                    dp[i][v] = (dp[i][v] + dp[i-1][prev]) % MOD;
                }
            }
        } else {
            int v = x[i];
            for (int prev = max(1, v - 1); prev <= min(m, v + 1); prev++) {
                dp[i][v] = (dp[i][v] + dp[i-1][prev]) % MOD;
            }
        }
    }
    
    long long result = 0;
    for (int v = 1; v <= m; v++) {
        result = (result + dp[n-1][v]) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}
