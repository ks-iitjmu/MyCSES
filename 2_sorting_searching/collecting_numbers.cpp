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
    ll n;
    cin >> n;
    vll x(n);
    for (ll &v : x)
        cin >> v;
    vll pos(n + 1);
    for (ll i = 0; i < n; i++)
    {
        pos[x[i]] = i;
    }
    ll rounds = 1;
    ll last = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (pos[i] > last)
        {
            last = pos[i];
        }
        else
        {
            rounds++;
            last = pos[i];
        }
    }
    cout << rounds << "\n";
    return 0;
}
