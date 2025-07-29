// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxX = 1e6;
const ll mod = 1e9 + 7;
ll n, dp[maxX + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dp[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= 6 && i - j >= 0; j++)
        {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}