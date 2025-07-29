// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

ll b_exp(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << b_exp(a, b) << '\n';
    }
    return 0;
}
