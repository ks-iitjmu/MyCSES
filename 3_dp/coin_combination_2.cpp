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
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    vll dp(x + 1, 0);
    dp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = c[i]; j <= x; j++)
        {
            dp[j] = (dp[j] + dp[j - c[i]]) % mod;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}
