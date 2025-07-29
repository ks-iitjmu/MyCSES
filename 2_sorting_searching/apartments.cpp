// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define pb push_back
#define bg begin()
#define ed end()

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    vll a, b;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        a.pb(t);
    }
    for (ll i = 0; i < m; i++)
    {
        ll t;
        cin >> t;
        b.pb(t);
    }
    sort(a.bg, a.ed);
    sort(b.bg, b.ed);
    ll cnt = 0, aptr = 0, bptr = 0;
    while (aptr < n)
    {
        while (bptr < m && b[bptr] < a[aptr] - k)
            bptr++;
        if (bptr < m && a[aptr] - k <= b[bptr] && b[bptr] <= a[aptr] + k)
        {
            cnt++;
            aptr++;
            bptr++;
        }
        else
            aptr++;
    }
    cout << cnt << "\n";
    return 0;
}