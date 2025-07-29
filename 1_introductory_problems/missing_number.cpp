// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll s = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ll temp;
        cin >> temp;
        s = s + temp;
    }
    cout << n * (n + 1) / 2 - s << "\n";
    return 0;
}