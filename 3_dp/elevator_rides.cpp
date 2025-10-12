#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll x;
    if (!(cin >> n >> x)) return 0;
    vector<ll> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    int m = 1 << n;
    const int INF = n + 1;
    vector<pair<int,ll>> dp(m, {INF, 0});
    dp[0] = {1, 0};

    for (int mask = 0; mask < m; mask++)
    {
        auto [rides, last] = dp[mask];
        if (rides == INF) continue;
        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1 << i)))
            {
                int nmask = mask | (1 << i);
                pair<int,ll> cand;
                if (last + w[i] <= x) cand = {rides, last + w[i]};
                else cand = {rides + 1, w[i]};
                if (cand.first < dp[nmask].first || (cand.first == dp[nmask].first && cand.second < dp[nmask].second))
                    dp[nmask] = cand;
            }
        }
    }

    cout << dp[m - 1].first << "\n";
    return 0;
}
