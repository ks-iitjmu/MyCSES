/*
Problem: Sum of Three Values
Category: Array / Two Pointers
Difficulty: Medium
Time Complexity: O(n^2)
Space Complexity: O(n)

Approach:
- Sort array while keeping original indices.
- For each element, use two pointers to find a pair whose sum equals target-x.
- Output original positions if found.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1; // store original position
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n-2; i++) {
        long long target = x - arr[i].first;
        int l = i+1, r = n-1;
        while (l < r) {
            long long sum = arr[l].first + arr[r].first;
            if (sum == target) {
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << "\n";
                return 0;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

