#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of non-adjacent elements
int maxNonAdjacentSum(vector<int>& nums) {
    int n = nums.size();

    // Edge cases
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // incl = max sum including current element
    // excl = max sum excluding current element
    int incl = nums[0];
    int excl = 0;

    for (int i = 1; i < n; i++) {
        int new_excl = max(incl, excl); // maximum till previous element
        incl = excl + nums[i];          // include current element
        excl = new_excl;                // update exclude
    }

    // Final answer is the max of incl and excl
    return max(incl, excl);
}

int main() {
    vector<int> nums1 = {3, 2, 7, 10};
    vector<int> nums2 = {3, 2, 5, 10, 7};

    cout << "Example 1 Output: " << maxNonAdjacentSum(nums1) << endl; // 13
    cout << "Example 2 Output: " << maxNonAdjacentSum(nums2) << endl; // 15

    return 0;
}
