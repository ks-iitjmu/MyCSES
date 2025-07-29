// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_set<ll> usll;
typedef vector<ll> vll;
#define er erase
#define ins insert
#define cnt count

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    usll s;
    ll ans = 0, l = 0;
    for (ll r = 0; r < n; r++)
    {
        while (s.cnt(a[r]))
        {
            s.er(a[l]);
            l++;
        }
        s.ins(a[r]);
        ans += (r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
