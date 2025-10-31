#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

ll removal(ll n, ll k)
{
    if (n == 1)
        return 1;
    if (k <= (n / 2))
        return 2 * k; // evens

    // odds
    ll temp_n = (n + 1) / 2;
    ll temp_k = k - (n / 2);

    ll x = removal(temp_n, temp_k);
    if (n % 2 == 0)
        return 2 * x - 1;
    else
    {
        if (x == 1)
            return n;
        return 2 * x - 3;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll q;
    cin >> q;
    while (q--)
    {
        ll n, k;
        cin >> n >> k;
        cout << removal(n, k) << '\n';
    }

    return 0;
}