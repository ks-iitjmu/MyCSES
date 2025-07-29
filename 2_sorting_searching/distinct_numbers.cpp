// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef set<ll> sll;
#define ins insert

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    sll nums;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        nums.ins(temp);
    }
    cout << nums.size() << "\n";
    return 0;
}