// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef map<ll, ll> umll;

const ll mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vll a(n);
    for (ll &x : a)
        cin >> x;
    vll dp(n + 1);
    dp[0] = 1;
    umll last;
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = (dp[i - 1] * 2) % mod;
        if (last.count(a[i - 1]))
        {
            ll j = last[a[i - 1]];
            dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
        }
        last[a[i - 1]] = i;
    }
    cout << (dp[n] - 1 + mod) % mod << "\n";
    return 0;
}
