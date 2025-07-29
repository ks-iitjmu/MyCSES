// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef set<ll> sll;
typedef multiset<ll> msll;
#define rbg rbegin()
#define up upper_bound
#define ins insert
#define er erase

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x, n;
    cin >> x >> n;
    sll l;
    msll s;
    l.ins(x);
    l.ins(0);
    s.ins(x);
    for (ll i = 0; i < n; i++)
    {
        ll pos;
        cin >> pos;
        auto u = l.up(pos);
        auto lo = prev(u);
        s.er(s.find(*u - *lo));
        s.ins(pos - *lo);
        s.ins(*u - pos);
        l.ins(pos);
        cout << *s.rbg << " ";
    }
    cout << "\n";
    return 0;
}