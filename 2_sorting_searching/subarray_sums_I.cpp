// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    int left = 0;
    ll current_sum = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += a[right];

        while (current_sum > x && left <= right) {
            current_sum -= a[left];
            left++;
        }

        if (current_sum == x) {
            count++;
        }
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