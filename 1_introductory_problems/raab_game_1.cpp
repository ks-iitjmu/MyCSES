// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef set<ll> ssll;
#define pb push_back
#define er erase
#define ins insert
#define cnt count
#define up upper_bound
#define lb lower_bound
#define bg begin()
#define ed end()

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        if (a + b > n)
        {
            cout << "NO\n";
            continue;
        }
        vll p1(n);
        for (ll i = 0; i < n; i++)
            p1[i] = i + 1;
        ssll s;
        for (ll i = 1; i <= n; i++)
            s.ins(i);
        vll p2(n, 0);
        ll remB = b;
        for (ll i = 0; i < n && remB > 0; i++)
        {
            auto it = s.up(p1[i]);
            if (it != s.ed)
            {
                p2[i] = *it;
                s.er(it);
                remB--;
            }
        }
        if (remB > 0)
        {
            cout << "NO\n";
            continue;
        }
        ll remA = a;
        for (ll i = n - 1; i >= 0 && remA > 0; i--)
        {
            if (p2[i] != 0)
                continue;
            auto it = s.lb(p1[i]);
            if (it != s.bg)
            {
                --it;
                if (*it < p1[i])
                {
                    p2[i] = *it;
                    s.er(it);
                    remA--;
                }
            }
        }
        if (remA > 0)
        {
            cout << "NO\n";
            continue;
        }
        for (ll i = 0; i < n; i++)
        {
            if (p2[i] != 0)
                continue;
            auto it_eq = s.find(p1[i]);
            if (it_eq != s.ed)
            {
                p2[i] = *it_eq;
                s.er(it_eq);
            }
            else
            {
                auto it_any = s.bg;
                p2[i] = *it_any;
                s.er(it_any);
            }
        }
        cout << "YES\n";
        for (ll i = 0; i < n; i++)
            cout << p1[i] << ' ';
        cout << '\n';
        for (ll i = 0; i < n; i++)
            cout << p2[i] << ' ';
        cout << '\n';
    }
    return 0;
}
