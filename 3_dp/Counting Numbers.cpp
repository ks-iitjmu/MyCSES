#include <bits/stdc++.h>
using namespace std;
long long l_val, r_val; 
string s;
long long dp[25][2][20][2];

long long idk(int i, bool mx, int prev, bool leadingzero) {
    if (i == s.size())
        return 1;
    long long &ret = dp[i][mx][prev][leadingzero];
    if (~ret)
        return ret;
    
    ret = 0;
    int end = mx ? s[i] - '0' : 9;
    
    for (int j = 0; j <= end; ++j) {
        if (j == prev && !leadingzero)
            continue;
        
        ret += idk(i + 1, 
                   mx && (j == end), 
                   j, 
                   leadingzero && (j == 0));
    }
    return ret;
}

long long calculate(long long n) {
    if (n < 0) return 0;
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return idk(0, 1, 15, 1); 
}

void solve() {
    cin >> l_val >> r_val;
    
    long long ans_r = calculate(r_val);
    long long ans_l_minus_1 = calculate(l_val - 1);
    
    long long final_ans = ans_r - ans_l_minus_1;
    
    cout << final_ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}