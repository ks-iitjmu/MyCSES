// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define PB push_back

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vi output;
    output.PB(n);
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            output.PB(n / 2);
            n = n / 2;
        }
        else
        {
            output.PB(n * 3 + 1);
            n = n * 3 + 1;
        }
    }
    for (auto i : output)
    {
        cout << i << " ";
    }
    return 0;
}