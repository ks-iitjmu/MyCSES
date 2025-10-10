#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    if (!(cin >> n)) return 0;

    struct Cust
    {
        ll a, b;
        int idx;
    };

    vector<Cust> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].a >> v[i].b;
        v[i].idx = i;
    }

    sort(v.begin(), v.end(), [](const Cust &x, const Cust &y)
    {
        if (x.a != y.a) return x.a < y.a;
        return x.b < y.b;
    });

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> busy;
    vector<int> free_rooms;
    vector<int> ans(n, -1);
    int next_room_id = 0;
    int max_rooms_used = 0;

    for (const auto &c : v)
    {
        ll arrival = c.a;
        ll depart  = c.b;

        while (!busy.empty() && busy.top().first < arrival)
        {
            free_rooms.push_back(busy.top().second);
            busy.pop();
        }

        int room_id;
        if (!free_rooms.empty())
        {
            room_id = free_rooms.back();
            free_rooms.pop_back();
        }
        else
        {
            next_room_id++;
            room_id = next_room_id;
            max_rooms_used = max(max_rooms_used, next_room_id);
        }

        ans[c.idx] = room_id;
        busy.push({depart, room_id});
    }

    cout << max_rooms_used << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
