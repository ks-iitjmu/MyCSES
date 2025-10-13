#include <bits/stdc++.h>
using namespace std;

/*

Labyrinth(https://cses.fi/problemset/task/1193)

# Prerequisite:
-> Graph theory, Breadth First Search

# Main Idea:
-> We can start from the starting position and visit all the 4 direction one by one and when we reach 'B', we'll stop. But the main task is to find the 
   actual path. For tracking the path, we can backtrack the from the last node('B') to first node('A').

Solution:

1. Find the position of the 'A' and store  that in queue.
2. Start BFS from starting position and visit all the cell.
3. While processing if we reach our destination then backtrack and construct the path else we can't reach till the end.

Complexties:
1. Time Complexity: O(n * m)
2. Space Commplexity: O(n * m)
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    /// Helper function to verify indices
    std::function<bool(int, int)> is_valid_index = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x < n && y < m;
    };
    
    /// Given labyrinth map
    vector<string> labyrinth(n);
    /// Stores if the cell is visited or not, so that we don't visit the same cell twice.
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    /// Queue to perform DFS
    queue<pair<int, int>> q;
    /// Matrix to store the information that from which side we came. path[2][3] = 'L', means we came from (2, 4)
    vector<vector<char>> path(n, vector<char> (m));

    // These array for traversion to the L, R, D and U
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    char direction[] = {'D', 'R', 'U', 'L'};

    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                q.push({i, j});   
                vis[i][j] = true;
                break;
            }
        } 
    }
    bool is_path_exists = false;
    /// Index of destination
    int final_x, final_y;

    // BFS Algorithm
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!is_valid_index(nx, ny)) {
                continue;
            }

            // We didn't go to this cell. Note that we can't visit the cell which has '#'
            if (labyrinth[nx][ny] == '.' && !vis[nx][ny]) {
                vis[nx][ny] = true;  
                q.push({nx, ny});
                path[nx][ny] = direction[k]; // Store the information from where we came
            } else if (labyrinth[nx][ny] == 'B') {
                path[nx][ny] = direction[k];
                final_x = nx, final_y = ny; 
                is_path_exists = true;
                break;
            }
        }
        if (is_path_exists) {
            break;
        }
    }

    if (!is_path_exists) {
        cout << "NO\n";
        return 0;
    }

    // We need to construct the path
    string full_path = "";
    
    while (is_valid_index(final_x, final_y) && labyrinth[final_x][final_y] != 'A') {
        full_path += path[final_x][final_y];
        // Dependeing upon the direction, adjust the index. 
        // 'U' means we came from the down, so go down
        if (path[final_x][final_y] == 'U') {
            final_x += 1; 
        } else if (path[final_x][final_y] == 'D') {
            final_x -= 1; 
        } else if (path[final_x][final_y] == 'L') {
            final_y += 1;
        } else {
            final_y -= 1;
        }
    }
    // reverse the string as we came from the last
    reverse(full_path.begin(), full_path.end());
    cout << "YES\n" << full_path;
    return 0;       
}
