#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

const ll maxSize = 2000000;
ll fact[maxSize + 1];
ll invFact[maxSize + 1];

ll apowbmod(ll base, ll exp)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

void preFact()
{
    fact[0] = 1;
    for (int i = 1; i <= maxSize; i++)
    {
        fact[i] = (fact[i - 1] * (i)) % mod;
    }
}

void preInvFact()
{
    invFact[maxSize] = apowbmod(fact[maxSize], mod - 2);
    for (int i = maxSize - 1; i >= 0; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preFact();
    preInvFact();

    ll apples, children;
    cin >> children >> apples;
    ll ans = fact[apples + children - 1];
    ans = ans * invFact[children - 1] % mod;
    ans = ans * invFact[apples] % mod;
    cout << ans << '\n';

    return 0;
}