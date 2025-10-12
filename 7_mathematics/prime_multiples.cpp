#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> primes(k);
    for (int i = 0; i < k; i++)
    {
        cin >> primes[i];
    }

    ll ans = 0;

    for (int i = 1; i < (1 << k); i++)
    {
        ll prod = 1LL;
        for (int j = 0; j < k; j++)
        {
            if ((i >> j) & 1)
            {
                if (primes[j] > n / prod)
                {
                    prod = n + 1;
                    break;
                }
                prod *= primes[j];
            }
        }
        if (prod > n)
        {
            continue;
        }

        int set_size = __builtin_popcount(i);
        if (set_size % 2 == 0)
            ans -= n / prod;
        else
            ans += n / prod;
    }

    cout << ans << '\n';

    return 0;
}