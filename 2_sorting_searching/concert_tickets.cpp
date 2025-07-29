// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef multiset<ll> msll;
#define ins insert
#define lb lower_bound
#define er erase

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    msll p;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll h;
        cin >> h;
        p.ins(-h);
    }
    for (int i = 0; i < m; i++)
    {
        ll t;
        cin >> t;
        if (p.lb(-t) == p.end())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << -*p.lb(-t) << "\n";
            p.er(p.lb(-t));
        }
    }
    return 0;
}