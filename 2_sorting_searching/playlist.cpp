// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef set<ll> sll;
typedef vector<ll> vll;

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
    sll seen;
    ll l = 0, res = 0;
    for (ll r = 0; r < n; r++)
    {
        while (seen.count(a[r]))
        {
            seen.erase(a[l++]);
        }
        seen.insert(a[r]);
        res = max(res, r - l + 1);
    }
    cout << res << "\n";
    return 0;
}
