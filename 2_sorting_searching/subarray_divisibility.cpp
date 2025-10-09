// CSES 1662: Subarray Divisibility
// Counts subarrays with sum % n == 0 using prefix remainders.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007  // (not used here, kept to match repo template)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    if (!(cin >> n)) return 0;

    vector<ll> freq(n, 0);
    // freq[r] = how many prefix sums had remainder r so far
    // Start with empty prefix remainder 0 to count subarrays starting at index 1
    freq[0] = 1;

    ll pref = 0;
    ll ans = 0;

    for (ll i = 0; i < n; ++i) {
        ll x; 
        cin >> x;
        pref += x;

        ll r = pref % n;
        if (r < 0) r += n;   // normalize for negative values

        ans += freq[r];     // each earlier same remainder forms a valid subarray
        ++freq[r];
    }

    cout << ans << '\n';
    return 0;
}