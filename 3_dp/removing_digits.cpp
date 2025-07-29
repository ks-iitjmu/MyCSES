// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vll dp(n + 1, LONG_LONG_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int d = i;
        while (d > 0)
        {
            if (d % 10 != 0)
                dp[i] = min(dp[i], dp[i - (d % 10)] + 1);
            d /= 10;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}