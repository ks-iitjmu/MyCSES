// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007


void multiply(ll a[2][2], ll b[2][2])
{
    ll x = (a[0][0] * b[0][0] % mod + a[0][1] * b[1][0] % mod) % mod;
    ll y = (a[0][0] * b[0][1] % mod + a[0][1] * b[1][1] % mod) % mod;
    ll z = (a[1][0] * b[0][0] % mod + a[1][1] * b[1][0] % mod) % mod;
    ll w = (a[1][0] * b[0][1] % mod + a[1][1] * b[1][1] % mod) % mod;

    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = w;
}


void matrix_pow(ll mat[2][2], ll n)
{
    ll res[2][2] = {{1, 0}, {0, 1}};
    while (n)
    {
        if (n & 1)
            multiply(res, mat);
        multiply(mat, mat);
        n >>= 1;
    }
   
    mat[0][0] = res[0][0];
    mat[0][1] = res[0][1];
    mat[1][0] = res[1][0];
    mat[1][1] = res[1][1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    ll fib[2][2] = {{1, 1}, {1, 0}};
    matrix_pow(fib, n - 1);

    cout << fib[0][0] << '\n';
    return 0;
}
