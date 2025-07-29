// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxX = 1000000;
const ll inf = LONG_LONG_MAX;
ll n, x, c, dp[maxX + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    fill(dp + 1, dp + x + 1, inf);
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        for (int j = 0; j <= x - c; j++)
            if (dp[j] != inf)
                dp[j + c] = min(dp[j + c], dp[j] + 1);
    }
    dp[x] == inf ? cout << -1 << "\n" : cout << dp[x] << "\n";
    return 0;
}