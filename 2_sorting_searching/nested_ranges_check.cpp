// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct range
{
    int left, right, index;
    bool operator<(const range &other) const
    {
        if (left == other.left)
            return right > other.right;
        return left < other.left;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool> contains(n);
    for (int indx = 0; indx < n; indx++)
    {
        cin >> ranges[indx].left;
        cin >> ranges[indx].right;
        ranges[indx].index = indx;
    }
    sort(ranges.begin(), ranges.end());

    int maxend = 0;
    for (int i = 0; i < n; i++)
    {
        if (ranges[i].right <= maxend)
            contained[ranges[i].index] = true;
        maxend = max(maxend, ranges[i].right);
    }

    int minend = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (ranges[i].right >= minend)
            contains[ranges[i].index] = true;
        minend = min(minend, ranges[i].right);
    }

    for (int i = 0; i < n; i++)
    {
        cout << contains[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << contained[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
