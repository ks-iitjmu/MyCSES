// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef vector<ll> vll;
#define er erase
#define ins insert
#define cnt count

ll ans = 0;
vs board(8);
bool col[8], diag1[15], diag2[15];

void solve(ll r)
{
    if (r == 8)
    {
        ans++;
        return;
    }
    for (ll c = 0; c < 8; c++)
    {
        if (board[r][c] == '*')
            continue;
        if (col[c] || diag1[r + c] || diag2[r - c + 7])
            continue;
        col[c] = diag1[r + c] = diag2[r - c + 7] = 1;
        solve(r + 1);
        col[c] = diag1[r + c] = diag2[r - c + 7] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 0; i < 8; i++)
        cin >> board[i];
    solve(0);
    cout << ans << '\n';
    return 0;
}
