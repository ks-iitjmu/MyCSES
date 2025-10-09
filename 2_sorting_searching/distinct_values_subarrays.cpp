/*
Problem: Distinct Values Subarrays II
Category: Sliding Window / Two Pointers
Difficulty: Medium
Time Complexity: O(n)
Space Complexity: O(k)

Approach:
- Use a sliding window with two pointers.
- Maintain at most k distinct elements in the window.
- Count all subarrays ending at each right pointer position.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<long long, int> freq;
    long long ans = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        freq[arr[r]]++;
        while (freq.size() > k) {
            freq[arr[l]]--;
            if (freq[arr[l]] == 0) freq.erase(arr[l]);
            l++;
        }
        ans += (r - l + 1);
    }

    cout << ans << "\n";
    return 0;
}
