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
    for(ll k = 1; k<=n; k++){
        cout << (1 + (k-1)*(k-2)/2)*(k-1)*(k+4) << "\n";
    }
    return 0;
}