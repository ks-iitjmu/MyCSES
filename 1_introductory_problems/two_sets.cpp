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
    if (n % 4 == 1 || n % 4 == 2)
        cout << "NO" << "\n";
    else if (n % 4 == 3)
    {
        cout << "YES" << "\n";
        cout << n / 2 << "\n";
        for (int i = 2; i <= n / 2; i += 2)
            cout << i << " " << n - i << " ";
        cout << n << "\n"
             << n / 2 + 1 << "\n";
        for (int i = 1; i <= n / 2; i += 2)
            cout << i << " " << n - i << " ";
    }
    else
    {
        cout << "YES" << "\n";
        cout << n / 2 << "\n";
        for (int i = 2; i <= n / 2; i += 2)
            cout << i << " " << n - i + 1 << " ";
        cout << n / 2 << "\n";
        for (int i = 1; i <= n / 2; i += 2)
            cout << i << " " << n - i + 1 << " ";
    }
    return 0;
}