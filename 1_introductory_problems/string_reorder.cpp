// Problem: String Reorder
// Category: Introductory Problems
// Difficulty: Medium
// Time Complexity: O(n)
// Memory Complexity: O(n)

// Approach:
// 1. Count the frequency of each character (A–Z).
// 2. Check feasibility: if any character count > (n + 1) / 2 → print -1.
// 3. Use a greedy method:
//    - At each step, choose the lexicographically smallest valid character 
//      (not equal to the previous one) that still has remaining occurrences.
// 4. Continue until the string is fully built or impossible.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;

    int maxFreq = *max_element(freq.begin(), freq.end());
    if (maxFreq > (n + 1) / 2) {
        cout << -1 << "\n";
        return 0;
    }

    string result;
    char prev = '#'; // last used character

    // Using a simple greedy loop
    for (int i = 0; i < n; i++) {
        // Find the smallest possible character that can be used
        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0) continue;
            char c = 'A' + j;

            // Skip if same as previous
            if (c == prev) continue;

            // Try choosing this char and see if it's valid for remaining positions
            freq[j]--;
            // Check if it's still possible to fill rest
            int remaining = n - i - 1;
            int maxLeft = *max_element(freq.begin(), freq.end());
            if (maxLeft <= (remaining + 1) / 2) {
                result += c;
                prev = c;
                break;
            } else {
                freq[j]++; // undo
            }
        }
    }

    if ((int)result.size() != n) cout << -1 << "\n";
    else cout << result << "\n";

    return 0;
}
