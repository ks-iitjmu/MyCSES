#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007
pair<int,int> tree[1000000];

void build(int ind, int low, int high) {
    if (low == high) {
        tree[ind] = {1, low + 1};
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    tree[ind] = {tree[2 * ind + 1].first + tree[2 * ind + 2].first, -1};
}

void query(int ind, int x) {
    tree[ind].first--;
    if (tree[ind].second != -1) {
        cout << tree[ind].second << ' ';
        return;
    }
    if (tree[2 * ind + 1].first >= x)
        query(2 * ind + 1, x);
    else
        query(2 * ind + 2, x - tree[2 * ind + 1].first);
}

void solve() {
    int n, k;
    cin >> n >> k;
    build(0, 0, n - 1);
    int x = k + 1;
    for (int i = 0; i < n; i++) {
        x %= (n - i);
        if (x == 0) x = n - i;
        query(0, x);
        x += k;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

