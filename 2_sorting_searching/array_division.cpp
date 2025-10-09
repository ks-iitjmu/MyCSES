// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll maxSum, int k, const vector<int>& a) {
    int subarraysNeeded = 1;
    ll currentSum = 0;

    for (int val : a) {
        if (currentSum + val > maxSum) {
            subarraysNeeded++;
            currentSum = val;
        } else {
            currentSum += val;
        }
    }
    return subarraysNeeded <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    ll low = 0;
    ll high = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        high += a[i];
        low = max(low, (ll)a[i]);
    }

    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, k, a)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}