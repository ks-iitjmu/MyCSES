#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int l , r;
string s;
long long dp[25][2][20][2];
 
long long idk(int i , bool mx , int prev , bool leadingzero) {
    if(i == s.size())
        return 1;
    long long &ret = dp[i][mx][prev][leadingzero];
    if(~ret)
        return ret;
    ret = 0;
    int end = mx ? s[i] - '0' : 9;
    for (int j = 0; j <= end; ++j) {
        if(j == prev && !leadingzero)
            continue;
        ret += idk(i + 1 , mx && (j == end) , j , leadingzero && (j == 0));
    }
    return ret;
}
 
void solve() {
    cin >> l >> r;
    memset(dp , -1 , sizeof dp);
    s = to_string(r);
    long long ans = idk(0 , 1 , 15 , 1);
    memset(dp , -1 , sizeof dp);
    s = to_string(l - 1);
    ans -= idk(0 , 1 , 15 , 1);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

