#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

const ll maxSize = 1000000;
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

    ll n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans = fact[a];
        ans = ans * invFact[b] % mod;
        ans = ans * invFact[a - b] % mod;
        cout<<ans<<'\n';
    }

    return 0;
}