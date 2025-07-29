// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

ll mod_mul(ll a, ll b)
{
    return a % mod * (b % mod) % mod;
}

ll mod_sum(ll a, ll b)
{
    return (a + b) % mod;
}

ll sum_range(ll l, ll r)
{
    ll cnt = r - l + 1;
    return mod_mul((l + r) % mod, cnt % mod) * 500000004 % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll ans = 0;

    for (ll i = 1, last; i <= n; i = last + 1)
    {
        ll q = n / i;
        last = n / q;
        ll s = sum_range(i, last);
        ans = mod_sum(ans, mod_mul(s, q));
    }

    cout << ans << '\n';
    return 0;
}
