#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));
    std::vector<std::vector<long long>> sum(n, std::vector<long long>(n, 0));

    // Pre-compute sums of all sub-arrays
    for (int i = 0; i < n; ++i) {
        sum[i][i] = arr[i];
        for (int j = i + 1; j < n; ++j) {
            sum[i][j] = sum[i][j - 1] + arr[j];
        }
    }

    // Base case: length 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = arr[i];
    }

    // Fill the DP table for lengths from 2 to n
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            
            long long score_from_left = sum[i][j] - dp[i+1][j];
            long long score_from_right = sum[i][j] - dp[i][j-1];

            dp[i][j] = std::max(score_from_left, score_from_right);
        }
    }

    std::cout << dp[0][n - 1] << std::endl;

    return 0;
}
