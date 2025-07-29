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
    ll ans = 0;
    while (n > 0)
    {
        n = n / 5;
        ans = ans + n;
    }
    cout << ans << "\n";
    return 0;
}