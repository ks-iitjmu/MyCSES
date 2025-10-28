#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    if (grid[0][0] == '*' || grid[n-1][n-1] == '*') {
        cout << 0 << endl;
        return 0;
    }
    
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
            
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    
    cout << dp[n-1][n-1] << endl;
    
    return 0;
}
