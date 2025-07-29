// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef map<ll, ll> mll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, s;
    cin >> n >> s;
    mll mp;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        ll c = s - t;
        if (mp.count(c))
        {
            cout << mp[c] + 1 << " " << i + 1 << "\n";
            return 0;
        }
        mp[t] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
