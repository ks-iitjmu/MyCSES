#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

class BIT {
    vector<long long> bit;
    int n;

public:
    BIT(int size) {
        n = size;
        bit.assign(n + 2, 0);
    }

    void update(int idx, long long val) {
        while (idx <= n) {
            bit[idx] = (bit[idx] + val) % mod;
            idx += idx & -idx;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        while (idx > 0) {
            sum = (sum + bit[idx]) % mod;
            idx -= idx & -idx;
        }
        return sum;
    }
};

int countIncreasingSubsequences(vector<int>& arr) {
    int n = arr.size();

    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    for (int &x : arr) {
        x = lower_bound(sortedArr.begin(), sortedArr.end(), x) - sortedArr.begin() + 1;
    }

    BIT bit(n);
    for (int i = 0; i < n; i++) {
        long long cnt = (bit.query(arr[i] - 1) + 1) % mod;
        bit.update(arr[i], cnt);
    }

    return bit.query(n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countIncreasingSubsequences(arr) << endl;
    
    return 0;
}