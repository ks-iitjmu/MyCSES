// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define pb push_back

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vll num;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        num.pb(t);
    }
    ll ans = LONG_LONG_MAX;
    for (ll i = 0; i < (1 << n); i++)
    {
        ll a = 0;
        ll b = 0;
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
                a += num[j];
            else
                b += num[j];
        }
        ans = min(ans, abs(a - b));
    }
    cout << ans << "\n";
    return 0;
}