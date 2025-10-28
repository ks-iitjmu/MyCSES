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

class BIT
{
    vector<int> tree;
    int n;

public:
    BIT(int size) : n(size), tree(size + 1, 0) {}

    void update(int idx, int delta)
    {
        for (; idx <= n; idx += idx & -idx)
            tree[idx] += delta;
    }

    int query(int idx)
    {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += tree[idx];
        return sum;
    }

    int range_query(int l, int r)
    {
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<Range> ranges(n);
    vector<int> y_coords;

    for (int i = 0; i < n; ++i)
    {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].index = i;
        y_coords.push_back(ranges[i].y);
    }

    // Coordinate compression for y values
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());

    map<int, int> compress;
    for (int i = 0; i < y_coords.size(); ++i)
        compress[y_coords[i]] = i + 1;

    // Update compressed y values
    for (int i = 0; i < n; ++i)
        ranges[i].y = compress[ranges[i].y];

    sort(ranges.begin(), ranges.end(), compareRanges);

    vector<int> contains(n, 0), is_contained(n, 0);

    // Count ranges contained by each range
    BIT bit1(y_coords.size());
    for (int i = n - 1; i >= 0; --i)
    {
        contains[ranges[i].index] = bit1.range_query(1, ranges[i].y);
        bit1.update(ranges[i].y, 1);
    }

    // Count ranges that contain each range
    BIT bit2(y_coords.size());
    for (int i = 0; i < n; ++i)
    {
        is_contained[ranges[i].index] = bit2.range_query(ranges[i].y, y_coords.size());
        bit2.update(ranges[i].y, 1);
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
