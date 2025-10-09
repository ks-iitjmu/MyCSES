#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

// Function to calculate a^b using binary exponentiation
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

ll findDigit(ll N)
{
    ll digits = 1;
    ll base = 9;

    // Step 1: Find which group contains the N-th digit
    while (N > digits * base)
    {
        N -= digits * base;
        base *= 10;
        digits++;
    }

    // Step 2: Find the actual number and the digit
    ll number = power(10, digits - 1) + (N - 1) / digits;
    ll index = (N - 1) % digits;

    string s = to_string(number);
    return s[index] - '0';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
        ll k;
        cin >> k;
        cout << findDigit(k) << "\n";
    }

    return 0;
}
