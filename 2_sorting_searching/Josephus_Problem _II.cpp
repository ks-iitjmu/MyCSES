// Kunal Sharma IIT Jammu


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define bg begin()
#define ed end()

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;

    set<ll> circle;
    for (ll i = 1; i <= n; i++)
        circle.insert(i);

    vector<ll> result;
    auto it = circle.bg;

    while (!circle.empty())
    {
        ll sz = circle.size();
        ll skip = k % sz;

        for (ll i = 0; i < skip; i++)
        {
            it++;
            if (it == circle.ed)
                it = circle.bg;
        }

        result.push_back(*it);
        it = circle.erase(it); 
        if (it == circle.ed)
            it = circle.bg;
    }

    for (ll x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}
