// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vll a(n), pos(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    ll rounds = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
            rounds++;
    }
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        --x;
        --y;
        ll v1 = a[x], v2 = a[y];
        set<ll> affected = {v1, v2};
        for (ll d = -1; d <= 1; d++)
        {
            if (v1 + d >= 1 && v1 + d <= n)
                affected.insert(v1 + d);
            if (v2 + d >= 1 && v2 + d <= n)
                affected.insert(v2 + d);
        }
        for (ll val : affected)
        {
            if (val > 1 && pos[val] < pos[val - 1])
                rounds--;
        }
        swap(a[x], a[y]);
        pos[a[x]] = x;
        pos[a[y]] = y;
        for (ll val : affected)
        {
            if (val > 1 && pos[val] < pos[val - 1])
                rounds++;
        }

        cout << rounds << "\n";
    }

    return 0;
}
