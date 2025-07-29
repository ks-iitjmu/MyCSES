// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> cpl;
typedef vector<cpl> vpll;
#define pb push_back
#define bg begin()
#define ed end()
#define fs first
#define se second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vpll cust;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        cust.pb({a, 1});
        cust.pb({b, -1});
    }

    sort(cust.bg, cust.ed, [](const cpl &A, const cpl &B)
         {
        if (A.fs == B.fs)
            return A.se < B.se;
        return A.fs < B.fs; });

    ll ans = 0, cur = 0;
    for (auto i : cust)
    {
        cur += i.se;
        ans = max(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}
