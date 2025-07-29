// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define mod 1000000007

ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll f(ll n)
{
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ans = ans * i % mod;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    str s;
    cin >> s;
    ll h[26] = {0};
    ll n = s.size();
    for (ll i = 0; i < n; i++)
    {
        h[s[i] - 'a']++;
    }
    ll ans = f(n);
    for (ll i = 0; i < 26; i++)
    {
        if (h[i] > 0)
        {
            ans = ans * power(f(h[i]), mod - 2) % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}
