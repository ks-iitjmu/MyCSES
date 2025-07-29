// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef set<string> ss;
typedef vector<char> vc;
typedef string str;
#define bg begin()
#define ed end()
#define np next_permutation
#define ins insert

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    str s;
    ss ans;
    cin >> s;
    ans.ins(s);
    ll n = s.size();
    sort(s.bg, s.ed);
    ans.ins(s);
    while (np(s.bg, s.ed))
    {
        ans.ins(str(s.bg, s.ed));
    }
    cout << ans.size() << "\n";
    for (str i : ans)
    {
        cout << i << "\n";
    }
    return 0;
}