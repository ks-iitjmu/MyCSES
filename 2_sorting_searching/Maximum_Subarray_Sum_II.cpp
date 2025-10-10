// Kunal Sharma IIT Jammu

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;

  vector<long long> x(n + 1, 0), prefix(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> x[i];
    prefix[i] = prefix[i - 1] + x[i];
  }

  multiset<long long> window;
  long long ans = LLONG_MIN;

  for (int i = a; i <= n; i++)
  {

    window.insert(prefix[i - a]);

    if (i - b - 1 >= 0)
      window.erase(window.find(prefix[i - b - 1]));

    long long min_prefix = *window.begin();

    ans = max(ans, prefix[i] - min_prefix);
  }

  cout << ans << "\n";
  return 0;
}
