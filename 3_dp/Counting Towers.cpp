#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int MAXN = 1e6;
    vector<long long> dpA(MAXN + 1), dpB(MAXN + 1);
    dpA[1] = dpB[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        dpA[i] = (2 * dpA[i - 1] + dpB[i - 1]) % MOD;
        dpB[i] = (dpA[i - 1] + 4 * dpB[i - 1]) % MOD;
    }

    while (t--) {
        int n;
        cin >> n;
        cout << (dpA[n] + dpB[n]) % MOD << "\n";
    }
}
