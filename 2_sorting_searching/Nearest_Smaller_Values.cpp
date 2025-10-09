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

    ll n;
    cin >> n;
    vll a(n);
    for (ll &x : a)
        cin >> x;

    stack<ll> s; // stores indices
    vll res(n);
    for (ll i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            res[i] = 0;
        else
            res[i] = s.top() + 1; // +1 for 1-based position
        s.push(i);
    }

    for (ll x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}
