// Kunal Sharma IIT Jammu


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define bg begin()
#define ed end()

struct Task {
    ll duration, deadline;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<Task> tasks(n);
    for (ll i = 0; i < n; i++)
        cin >> tasks[i].duration >> tasks[i].deadline;

    sort(tasks.bg, tasks.ed, [](const Task &t1, const Task &t2) {
        return t1.deadline < t2.deadline;
    });

    ll time = 0, reward = 0;
    for (ll i = 0; i < n; i++)
    {
        time += tasks[i].duration;
        reward += tasks[i].deadline - time;
    }

    cout << reward << "\n";

    return 0;
}
