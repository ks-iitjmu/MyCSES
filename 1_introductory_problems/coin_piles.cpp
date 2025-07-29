// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll a, b;
        cin >> a >> b;
        if ((a + b) % 3 != 0 || a > 2 * b || b > 2 * a)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}