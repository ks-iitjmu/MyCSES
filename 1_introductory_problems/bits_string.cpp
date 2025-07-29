// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans << 1) % mod;
    }
    cout << ans % mod << "\n";
    return 0;
}