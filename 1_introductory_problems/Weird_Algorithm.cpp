
#include <bits/stdc++.h>
#define ll long long int
​
using namespace std;
int main()
{
    ll N = 13;
    while (N != 1) {
        cout << N << " ";
        // If N is odd, then multiply it by 3 and add 1
        if (N & 1LL)
            N = N * 3 + 1;
        // If N is even, divide it by 2
        else
            N /= 2;
    }
    cout << 1;
}
