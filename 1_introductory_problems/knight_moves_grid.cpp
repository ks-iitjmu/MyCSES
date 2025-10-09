/*
Problem: Knight Moves Grid
Category: Introductory Problems
Difficulty: Easy
Time Complexity: O(n²)
Space Complexity: O(n²)

Approach:
BFS (Breadth-First Search) from the top-left corner (0,0) to find minimum
number of moves for a knight to reach (0,0) from every position on the board.

Key Insights:
- Knight has 8 possible moves in L-shape pattern
- BFS guarantees shortest path (minimum moves)
- Each cell stores minimum distance to reach (0,0)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    // Knight moves: 8 possible directions
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    // Distance matrix to store minimum moves
    vector<vector<int>> dist(n, vector<int>(n, -1));
    
    // BFS from top-left corner (0, 0)
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // Try all 8 knight moves
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // Check if new position is valid and not visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    // Print the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}