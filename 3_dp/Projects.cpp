#include <bits/stdc++.h>
using namespace std;

struct Project
{
    long long start, end, reward;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Project> projects(n);

    for (int i = 0; i < n; i++)
    {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), [](Project &a, Project &b)
            { return a.end < b.end; });
    vector<long long> ends;
    for (auto &p : projects)
        ends.push_back(p.end);

    vector<long long> dp(n); // dp[i] = max reward till project i

    for (int i = 0; i < n; i++)
    {
        long long take = projects[i].reward;
        int lastEnd = upper_bound(ends.begin(), ends.end(), projects[i].start - 1) - ends.begin() - 1;

        if (lastEnd >= 0)
            take += dp[lastEnd];

        long long notTake = (i > 0 ? dp[i - 1] : 0);

        dp[i] = max(notTake, take);
    }

    cout << dp[n - 1] << "\n";
    return 0;
}

//Time Complexity: O(n log n) due to sorting and binary search
//Space Complexity: O(n) for dp and ends arrays

//Problem link: https://cses.fi/problemset/task/1140/
