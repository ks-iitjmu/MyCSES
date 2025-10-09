// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<ll, int> prefix_sum;
    prefix_sum[0] = 1;

    ll count = 0;
    ll current_prefix_sum = 0;

    for (ll val : a) {
        current_prefix_sum += val;
        ll required = current_prefix_sum - x;

        if (prefix_sum.count(required)) {
            count += prefix_sum[required];
        }

        prefix_sum[current_prefix_sum]++;
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}