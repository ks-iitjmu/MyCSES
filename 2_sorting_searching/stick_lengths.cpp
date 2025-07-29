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
    ll n;
    cin >> n;
    vll num;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        num.pb(t);
    }
    sort(num.bg, num.ed);
    ll val = num[n / 2];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans = ans + abs(num[i] - val);
    }
    cout << ans << "\n";
    return 0;
}