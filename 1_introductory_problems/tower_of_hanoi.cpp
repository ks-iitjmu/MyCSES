// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void mov(ll f, ll t, ll d)
{
    if (d == 1)
    {
        cout << f << " " << t << "\n";
        return;
    }
    ll o = 6 - f - t;
    mov(f, o, d - 1);
    cout << f << " " << t << "\n";
    mov(o, t, d - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    mov(1, 3, n);
    return 0;
}