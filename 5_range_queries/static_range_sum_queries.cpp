/*
Problem: Static Range Sum Queries (sum of values in [a, b] for multiple queries)
Input:
- n (number of values), q (number of queries)
- array x[1..n]
- q lines of queries with integers a, b (1 <= a <= b <= n)
Output:
- For each query, print sum_{i=a..b} x[i]
Constraints:
- 1 <= n, q <= 2 * 10^5
- 1 <= x_i <= 1e9
Approach:
- Build 1-indexed prefix sums p where p[i] = sum of first i elements
- Answer each query in O(1): p[b] - p[a-1]
Notes:
- Use 64-bit integers (long long) for sums to handle up to ~2e14.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<long long> pref(n + 1, 0);
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
