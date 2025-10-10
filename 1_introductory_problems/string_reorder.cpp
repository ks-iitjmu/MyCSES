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

    // Check feasibility
    int maxFreq = *max_element(freq.begin(), freq.end());
    if (maxFreq > (n + 1) / 2) {
        cout << -1 << "\n";
        return 0;
    }

    string ans;
    ans.reserve(n);
    char prev = '#';

    for (int i = 0; i < n; ++i) {
        char pick = 0;

        for (int c = 0; c < 26; ++c) {
            if (freq[c] == 0) continue;
            char ch = 'A' + c;
            if (ch == prev) continue;

            // Try placing this character and check if the rest is possible
            freq[c]--;
            int remaining = n - i - 1;
            int maxLeft = *max_element(freq.begin(), freq.end());
            if (maxLeft <= (remaining + 1) / 2) {
                pick = ch;
                break;
            }
            freq[c]++; // backtrack if not valid
        }

        if (!pick) {
            cout << -1 << "\n";
            return 0;
        }

        ans.push_back(pick);
        prev = pick;
        freq[pick - 'A']--;
    }

    cout << ans << "\n";
    return 0;
}
