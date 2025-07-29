// Kunal Sharma IIT Jammu
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 2e5 + 1;

int N, a[maxN], b[maxN], dp[2 * maxN];
struct Movie
{
    int t, id, type;
} movies[2 * maxN];
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
        movies[2 * i] = {a[i], i, 0};
        movies[2 * i + 1] = {b[i], i, 1};
    }

    sort(movies, movies + 2 * N, [](Movie A, Movie B)
         { return A.t == B.t ? A.id < B.id : A.t < B.t; });

    for (int i = 0; i < 2 * N; i++)
        mp[movies[i].t] = i;

    for (int i = 0; i < 2 * N; i++)
    {
        if (movies[i].type == 0)
            dp[i] = (i > 0 ? dp[i - 1] : 0);
        else
            dp[i] = max((i > 0 ? dp[i - 1] : 0), dp[mp[a[movies[i].id]]] + 1);
    }

    cout << dp[2 * N - 1] << '\n';
    return 0;
}
