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

    map<ll, pair<int, int>> sums;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll current_sum = a[i] + a[j];
            ll required = x - current_sum;

            if (sums.count(required)) {
                pair<int, int> p = sums[required];
                cout << p.first << " " << p.second << " " << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
        for (int k = 0; k < i; ++k) {
            sums[a[k] + a[i]] = {k + 1, i + 1};
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}