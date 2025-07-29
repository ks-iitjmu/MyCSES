// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef multiset<ll> msll;
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
    msll tops;
    for (ll x : a)
    {
        auto it = tops.upper_bound(x);
        if (it != tops.end())
            tops.erase(it);
        tops.insert(x);
    }
    cout << tops.size() << "\n";
    return 0;
}
