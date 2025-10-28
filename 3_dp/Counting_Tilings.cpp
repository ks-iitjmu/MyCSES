#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
long long dp[1001][1024];

void generate_transitions(int col, int cur_mask, int row, int next_mask, long long ways) {
    if (row == n) {
        dp[col + 1][next_mask] = (dp[col + 1][next_mask] + ways) % MOD;
        return;
    }
    
    if (cur_mask & (1 << row)) {
        generate_transitions(col, cur_mask, row + 1, next_mask, ways);
    } else {
        if (row + 1 < n && !(cur_mask & (1 << (row + 1)))) {
            generate_transitions(col, cur_mask | (1 << row) | (1 << (row + 1)), row + 2, next_mask, ways);
        }
        
        generate_transitions(col, cur_mask | (1 << row), row + 1, next_mask | (1 << row), ways);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    if ((n * m) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for (int col = 0; col < m; col++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[col][mask] == 0) continue;
            generate_transitions(col, mask, 0, 0, dp[col][mask]);
        }
    }
    
    cout << dp[m][0] << endl;
    
    return 0;
}
