#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n , dp[62626];
 
void solve() {
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if(sum & 1)
        return void(cout << 0 << endl);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (long long j = sum / 2; j >= i; --j) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }
    cout << dp[sum / 2] << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

