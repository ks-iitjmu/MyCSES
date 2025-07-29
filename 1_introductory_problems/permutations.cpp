// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    if (n == 1)
        cout << 1 << "\n";
    else if (n <= 3)
    {
        cout << "NO SOLUTION" << "\n";
    }
    else
    {
        for (ll i = 2; i <= n; i = i + 2)
        {
            cout << i << " ";
        }
        for (ll i = 1; i <= n; i = i + 2)
        {
            cout << i << " ";
        }
    }
    return 0;
}