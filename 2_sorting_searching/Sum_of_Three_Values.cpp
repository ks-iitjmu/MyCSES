// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        ll target = x - a[i].first;
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            ll current_sum = a[left].first + a[right].first;
            if (current_sum == target) {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << endl;
                return;
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}