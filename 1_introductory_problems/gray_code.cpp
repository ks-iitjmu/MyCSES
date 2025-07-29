// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define bffs __builtin_ffs

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N;
    ll m = 16;
    bool b[m + 1] = {false};
    cin >> N;
    for (int i = N; i > 0; i--)
        cout << b[i];
    cout << '\n';
    for (int i = 1; i < (1 << N); i++)
    {
        int LSB = bffs(i);
        b[LSB] ^= 1;
        for (int i = N; i > 0; i--)
            cout << b[i];
        cout << '\n';
    }
    return 0;
}
