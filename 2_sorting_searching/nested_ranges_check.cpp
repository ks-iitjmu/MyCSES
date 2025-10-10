// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

struct Range
{
    int x, y, index;
};

bool compareRanges(const Range &a, const Range &b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x < b.x;
}

void solve()
{
    int n;
    cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end(), compareRanges);

    vector<int> contains(n, 0), is_contained(n, 0);

    int max_end = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ranges[i].y <= max_end)
            is_contained[ranges[i].index] = 1;
        max_end = max(max_end, ranges[i].y);
    }

    int min_end = 2e9;
    for (int i = n - 1; i >= 0; --i)
    {
        if (ranges[i].y >= min_end)
            contains[ranges[i].index] = 1;
        min_end = min(min_end, ranges[i].y);
    }

    for (int i = 0; i < n; ++i)
        cout << contains[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
    for (int i = 0; i < n; ++i)
        cout << is_contained[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}