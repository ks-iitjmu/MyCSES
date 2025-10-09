/*
Problem: Raab Game I
Category: Greedy / Simulation
Difficulty: Medium
Time Complexity: O(n)
Space Complexity: O(n)

Approach:
- Check if a + b <= n (feasible)
- Construct two sequences where player 1 wins exactly 'a' rounds and player 2 wins exactly 'b' rounds
- Each player must use cards 1 to n exactly once
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

        cout << "YES\n";
        
        vector<int> p1(n), p2(n);
        vector<bool> used1(n+1, false), used2(n+1, false);
        
        // First a rounds: player 1 wins
        for(int i = 0; i < a; i++) {
            p1[i] = n - i;         // P1 gets largest cards
            p2[i] = i + 1;         // P2 gets smallest cards  
            used1[n - i] = true;
            used2[i + 1] = true;
        }
        
        // Next b rounds: player 2 wins
        for(int i = 0; i < b; i++) {
            p1[a + i] = a + 1 + i;     // P1 gets next smallest available
            p2[a + i] = n - a - i;     // P2 gets next largest available
            used1[a + 1 + i] = true;
            used2[n - a - i] = true;
        }
        
        // Fill remaining rounds with unused cards (these will be draws)
        vector<int> remaining1, remaining2;
        for(int i = 1; i <= n; i++) {
            if(!used1[i]) remaining1.push_back(i);
            if(!used2[i]) remaining2.push_back(i);
        }
        
        for(int i = a + b; i < n; i++) {
            p1[i] = remaining1[i - a - b];
            p2[i] = remaining2[i - a - b];
        }
        
        // Output player 1's sequence
        for(int i = 0; i < n; i++) {
            cout << p1[i];
            if(i < n-1) cout << " ";
        }
        cout << "\n";
        
        // Output player 2's sequence  
        for(int i = 0; i < n; i++) {
            cout << p2[i];
            if(i < n-1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
