// Kunal Sharma IIT Jammu

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  if (!(cin >> n >> k))
    return 0;
  vector<pair<int, int>> movies(n);
  for (int i = 0; i < n; i++)
    cin >> movies[i].first >> movies[i].second;

  sort(movies.begin(), movies.end(), [](const pair<int, int> &a, const pair<int, int> &b)
       { return a.second < b.second; });

  multiset<int> endTimes;

  int total = 0;

  for (const auto &p : movies)
  {
    int start = p.first;
    int finish = p.second;

    auto it = endTimes.upper_bound(start);
    if (it == endTimes.begin())
    {

      if ((int)endTimes.size() < k)
      {
        endTimes.insert(finish);
        total++;
      }
    }
    else
    {

      --it;
      endTimes.erase(it);
      endTimes.insert(finish);
      total++;
    }
  }

  cout << total << "\n";

  return 0;
}
