// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define PB push_back

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vll num;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        num.PB(temp);
    }
    int i = 0;
    int j = 1;
    ll ans = 0;
    while (j < n)
    {
        if (num[i] > num[j])
        {
            ans = ans + num[i] - num[j];
            num[j] = num[i];
        }
        i++;
        j++;
    }
    cout << ans << "\n";
    return 0;
}