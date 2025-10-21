#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

/*

Christmas Party(https://cses.fi/problemset/task/1717/)

# Prerequisite:
-> Basic Combinatorics, Derangement, Principal of Inclusion-Exclusion

# Main Idea:
-> Here the task is to find the number of ways of distributing the gifts such that the owner of that gift should not get the gift.
   We can change the problem statement slightly, that is we have n elements and we need to arrange each element in such that the ith 
   element should not come to the ith position. We need to find number of such arrangements.
-> This is classic problem of derangements. That is we need to find dearrangment of n.
1) We can use PIE to find such arrangements, 
number of derangements with n elements = number of all permutation - number of all permutation where ith element is at ith index
                                         = n! - N
Using PIE, N comes out to be:, N = summation from (k = 1 to k = n) { (-1)^(k + 1) * n! / k! }
See this link for detail: https://brilliant.org/wiki/derangements/

2) Recurrence relation
-> The recurrance relation is :
D[n] = (n - 1)(D[n - 1] + D[n - 2])
See coding part.

Solution:

1. Initialise the array with n + 1 elements
2. Specify base cases, i.e., D[0] = 1, D[1] = 0
3. Use recurrance relation to fill the values.

Complexties:
1. Time Complexity: O(n)
2. Space Commplexity: O(n)

Optimization:
We can optimize space complextiy from O(n) -> O(1). Since we only need D[i - 1] and D[i - 2], so we can keep the variables for that.
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    /// D[i] -> Number of derangement of i elements
    vector<long long> D(n + 1, 0);

    // base case, since number of deranging 0 elements will be one, but number of dearranging 1 element will be 0.
    D[0] = 1;

    for (int i = 2; i <= n; i++) {
        /*  We can place ith element to all positions excluding it's own position. Hence i - 1 choices
            Now let's assume that we placed it to kth position, now there are two cases:
            1. The kth element placed to the ith position, i.e., both were swaped, then there are exaclty i - 2 elements 
               which needs to be dearranged, hence D[i - 2].
            2. The kth element is placed other than the ith position, then there are exactly i - 1 element which needs to be dearranged.
               Hence D[i - 1]  
            Combining both gives us following recurrence relation
        */
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % mod;
    }

    cout << D[n] << "\n";

    return 0;       
}
