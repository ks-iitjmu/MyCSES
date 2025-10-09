/*
Problem: Static Range Sum Queries
Category: Range Queries
Difficulty: Medium
Time Complexity: O(n + q)
Space Complexity: O(n)

Approach:
- Build a 1-indexed prefix sum array `pref` where pref[i] = sum of first i elements
- Answer each query in O(1) using: sum(a..b) = pref[b] - pref[a-1]

Key Insights:
- Use long long for sums to handle large numbers (~2e14)
- 1-indexed array simplifies query computation
- Efficient for large n, q (up to 2*10^5)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> pref(n + 1, 0);  // 1-indexed prefix sums
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (pref[b] - pref[a - 1]) << '\n';
    }

    return 0;
}
