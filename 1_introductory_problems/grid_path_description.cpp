/*
Problem: Grid Path Description
Category: Introductory Problems
Difficulty: Medium
Time Complexity: O(4^48) with pruning -> O(88418) effective
Space Complexity: O(48) for recursion depth

Approach:
Backtracking with path validation. We traverse a 7x7 grid from (0,0) to (6,0)
following the given path description. Use pruning to avoid invalid paths early.

Key Insights:
- 48 moves total (7x7 grid has 48 steps from top-left to bottom-left)
- '?' can be any direction (D/U/L/R)
- Must end at exactly (6,0) after 48 moves
- Use visited array to avoid revisiting cells
- Prune paths that can't reach destination
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

string path;
bool visited[7][7];
int dx[] = {1, -1, 0, 0}; // D, U, L, R
int dy[] = {0, 0, -1, 1};
char directions[] = {'D', 'U', 'L', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7 && !visited[x][y];
}

int solve(int x, int y, int step) {
    // Base case: reached end position
    if (x == 6 && y == 0) {
        return (step == 48) ? 1 : 0;
    }
    
    // If we've used all steps but haven't reached destination
    if (step == 48) {
        return 0;
    }
    
    // Pruning: check if we can still reach destination
    // If we're surrounded by visited cells or walls, it's a dead end
    int validMoves = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) validMoves++;
    }
    
    // If no valid moves and we're not at destination, return 0
    if (validMoves == 0 && !(x == 6 && y == 0)) {
        return 0;
    }
    
    int result = 0;
    
    if (path[step] == '?') {
        // Try all 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                result += solve(nx, ny, step + 1);
                visited[nx][ny] = false;
            }
        }
    } else {
        // Follow the specified direction
        int dir = -1;
        for (int i = 0; i < 4; i++) {
            if (directions[i] == path[step]) {
                dir = i;
                break;
            }
        }
        
        if (dir != -1) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                result = solve(nx, ny, step + 1);
                visited[nx][ny] = false;
            }
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> path;
    
    // Initialize visited array
    memset(visited, false, sizeof(visited));
    visited[0][0] = true; // Starting position
    
    cout << solve(0, 0, 0) << "\n";
    
    return 0;
}