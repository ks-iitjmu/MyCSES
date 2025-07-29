// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    cin >> n >> x;
    vll c(n);
    vll dp(x + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    dp[0] = 1;
    for (ll i = 0; i <= x; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i - c[j] < 0)
                continue;
            dp[i] += dp[i - c[j]];
            dp[i] = dp[i] % mod;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}