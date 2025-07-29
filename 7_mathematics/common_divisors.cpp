// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 1000001

ll freq[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        freq[x]++;
    }
    for (ll g = MAX - 1; g >= 1; g--)
    {
        ll cnt = 0;
        for (ll j = g; j < MAX; j += g)
            cnt += freq[j];
        if (cnt >= 2)
        {
            cout << g << '\n';
            return 0;
        }
    }
    return 0;
}
