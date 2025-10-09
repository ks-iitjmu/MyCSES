#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; 
    if (!(cin >> n)) return 0;
    unordered_map<ll, ll> freq;
    freq.reserve((size_t)2 * max(1LL, n));

    for (ll i = 0; i < n; ++i) {
        ll x; cin >> x;
        ++freq[x];
    }

    long long ans = 1;
    for (auto &kv : freq) {
        ans = (ans * ((kv.second + 1) % mod)) % mod;
    }
    ans = (ans - 1 + mod) % mod;  // remove empty subsequence

    cout << ans << '\n';
    return 0;
}
