/*
Problem: Raab Game I
Category: Greedy / Simulation
Difficulty: Medium
Time Complexity: O(n^2)
Space Complexity: O(n)

Approach:
- Check if a + b <= n (feasible)
- Greedily assign wins for each player using largest vs smallest remaining cards
- Fill remaining cards arbitrarily to produce a valid game sequence
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n) {
            cout << "NO\n";
            continue;
        }

        vector<int> p1, p2;
        vector<int> remaining1, remaining2;

        // Initial card sets
        for(int i=1;i<=n;i++) remaining1.push_back(i);
        for(int i=1;i<=n;i++) remaining2.push_back(i);

        // Assign 'a' points to player 1
        for(int i=0;i<a;i++) {
            p1.push_back(n - i);          // largest cards of player 1
            p2.push_back(i + 1);          // smallest cards of player 2
            remaining1.erase(remove(remaining1.begin(), remaining1.end(), n - i), remaining1.end());
            remaining2.erase(remove(remaining2.begin(), remaining2.end(), i + 1), remaining2.end());
        }

        // Assign 'b' points to player 2
        for(int i=0;i<b;i++) {
            p1.push_back(remaining1[i]);          // smallest remaining cards of player1
            p2.push_back(n - i);                  // largest cards of player2
        }

        // Fill remaining cards arbitrarily
        int r1start = b;
        for(int i=r1start;i<remaining1.size();i++) {
            p1.push_back(remaining1[i]);
            p2.push_back(remaining2[i - b]);
        }

        cout << "YES\n";
        for(int x : p1) cout << x << " ";
        cout << "\n";
        for(int x : p2) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
