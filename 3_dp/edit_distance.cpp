#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    if (!(cin >> s)) return 0;
    if (!(cin >> t)) return 0;

    int n = (int)s.size();
    int m = (int)t.size();

    vector<int> prev(m + 1), cur(m + 1);
    for (int j = 0; j <= m; j++) prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        cur[0] = i;
        for (int j = 1; j <= m; j++)
        {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            cur[j] = min({ prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + cost });
        }
        swap(prev, cur);
    }

    cout << prev[m] << "\n";
    return 0;
}
