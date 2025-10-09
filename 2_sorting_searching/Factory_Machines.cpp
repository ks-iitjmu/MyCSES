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

    ll n, t;
    cin >> n >> t;
    vll k(n);
    for (ll &x : k)
        cin >> x;

    ll left = 1, right = 1e18, ans = right;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        ll products = 0;
        for (ll i = 0; i < n; i++)
            products += mid / k[i];

        if (products >= t)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
