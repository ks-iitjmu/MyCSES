// Problem: Distinct Values Subarrays II
// Category: Sorting and Searching
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach:
// Use a sliding window [l, r] to maintain at most k distinct elements.
// Track frequencies using a hash map.
// Expand r, and when distinct elements exceed k, move l forward.
// For each r, add (r - l + 1) to the answer (all valid subarrays ending at r).

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    unordered_map<int, int> freq;
    int left = 0;
    int distinct = 0;

    for (int right = 0; right < n; right++) {
        if (freq[a[right]] == 0) distinct++;
        freq[a[right]]++;

        while (distinct > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0) distinct--;
            left++;
        }

        ans += (right - left + 1);
    }

    cout << ans << "\n";
    return 0;
}
