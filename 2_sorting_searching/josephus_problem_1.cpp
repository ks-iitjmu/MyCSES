// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin >> n;
    deque<int> dq;

    for (int i = 1; i <= n; ++i) 
        dq.push_back(i);
    
    vector<int> removed;
    removed.reserve(n);

    while (!dq.empty()) {
        // skip one (move front to back)
        int x = dq.front();
        dq.pop_front();
        dq.push_back(x);

        // remove next (the second)
        int y = dq.front();
        dq.pop_front();
        removed.push_back(y);
    }

    // print
    for (size_t i = 0; i < removed.size(); ++i) {
        if (i) cout << ' ';
        cout << removed[i];
    }

    return 0;
}