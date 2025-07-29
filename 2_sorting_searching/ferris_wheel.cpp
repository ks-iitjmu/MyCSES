// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define pb push_back
#define bg begin()
#define ed end()

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    cin >> n >> x;
    vll nums;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        nums.pb(temp);
    }
    sort(nums.bg, nums.ed);
    ll ans = 0;
    ll l = 0;
    ll N = nums.size();
    for (ll r = N - 1; r >= l; r--)
    {
        if (nums[l] + nums[r] <= x)
            l++;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}