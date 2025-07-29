// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define bg begin()
#define ed end()

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
    sort(a.bg, a.ed);

    ll target = 1;
    for (ll x : a)
    {
        if (x > target)
            break;
        target += x;
    }
    cout << target << "\n";
    return 0;
}
