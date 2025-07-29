// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    str s;
    cin >> s;
    int i = 0;
    int j = 1;
    int rep = 1;
    int ans = 1;
    int n = s.size();
    while (j <= n)
    {
        if (s[i] == s[j])
        {
            rep = rep + 1;
            ans = max(ans, rep);
            i++;
            j++;
        }
        else
        {
            rep = 1;
            i++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}
