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
    vll t(n);
    ll sum = 0, max_time = 0;
    for (ll &x : t)
    {
        cin >> x;
        sum += x;
        max_time = max(max_time, x);
    }

    cout << max(sum, 2 * max_time) << "\n";

    return 0;

}
