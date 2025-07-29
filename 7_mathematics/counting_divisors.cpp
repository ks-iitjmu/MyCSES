// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 1000001

ll d[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 1; i < MAX; i++)
        for (ll j = i; j < MAX; j += i)
            d[j]++;

    ll t;
    cin >> t;
    while (t--)
    {
        ll b;
        cin >> b;
        cout << d[b] << '\n';
    }
    return 0;
}
