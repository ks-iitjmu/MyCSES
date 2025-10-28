#include <bits/stdc++.h>
using namespace std;

string path;
bool visited[7][7];
int ans = 0;

void solve(int r, int c, int step) {
    if (r == 6 && c == 0) {
        if (step == 48) ans++;
        return;
    }
    
    if (step == 48) return;
    
    bool u = (r > 0 && !visited[r-1][c]);
    bool d = (r < 6 && !visited[r+1][c]);
    bool l = (c > 0 && !visited[r][c-1]);
    bool rr = (c < 6 && !visited[r][c+1]);
    
    if ((l && rr) && (!u && !d)) return;
    if ((u && d) && (!l && !rr)) return;
    
    char dir = path[step];
    
    if (dir != '?') {
        if (dir == 'U' && !u) return;
        if (dir == 'D' && !d) return;
        if (dir == 'L' && !l) return;
        if (dir == 'R' && !rr) return;
    }
    
    if ((dir == 'D' || dir == '?') && d) {
        visited[r+1][c] = true;
        solve(r+1, c, step+1);
        visited[r+1][c] = false;
    }
    
    if ((dir == 'U' || dir == '?') && u) {
        visited[r-1][c] = true;
        solve(r-1, c, step+1);
        visited[r-1][c] = false;
    }
    
    if ((dir == 'L' || dir == '?') && l) {
        visited[r][c-1] = true;
        solve(r, c-1, step+1);
        visited[r][c-1] = false;
    }
    
    if ((dir == 'R' || dir == '?') && rr) {
        visited[r][c+1] = true;
        solve(r, c+1, step+1);
        visited[r][c+1] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> path;
    
    memset(visited, false, sizeof(visited));
    visited[0][0] = true;
    solve(0, 0, 0);
    
    cout << ans << endl;
    
    return 0;
}
