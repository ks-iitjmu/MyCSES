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
        ll y, x;
        cin >> y >> x;
        if (y > x)
        {
            if (y % 2)
                cout << (y - 1) * (y - 1) + x << "\n";
            else
                cout << y * y - x + 1 << "\n";
        }
        else
        {
            if (x % 2)
                cout << x * x - y + 1 << "\n";
            else
                cout << (x - 1) * (x - 1) + y << "\n";
        }
    }
    return 0;
}