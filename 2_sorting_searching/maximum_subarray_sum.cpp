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
    vll num(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    ll m = num[0];
    ll r = num[0];
    for (ll i = 1; i < n; i++)
    {
        m = max(num[i], m + num[i]);
        r = max(r, m);
    }
    cout << r << "\n";
    return 0;
}
