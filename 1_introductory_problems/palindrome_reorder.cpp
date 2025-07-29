// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    str s;
    cin >> s;
    ll f[26] = {0};
    ll n = s.size();
    ll odd = -1;
    for (int i = 0; i < n; i++)
        f[(int)(s[i] - 'A')]++;
    for (ll i = 0; i < 26; i++)
    {
        if (f[i] & 1)
        {
            if (f[i] & 1)
            {
                if (odd != -1)
                {
                    cout << "NO SOLUTION\n";
                    return 0;
                }
                else
                {
                    odd = i;
                }
            }
        }
    }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < f[i] / 2; j++)
            cout << (char)(i + 'A');
    if (odd != -1)
        cout << (char)(odd + 'A');
    for (int i = 25; i >= 0; i--)
        for (int j = 0; j < f[i] / 2; j++)
            cout << (char)(i + 'A');
    return 0;
}