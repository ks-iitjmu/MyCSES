#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Use long long for sums due to large values and constraints (up to 2*10^5 * 10^9)
typedef long long ll;

// Structure to store the four necessary values for each segment
struct Node {
    ll total_sum;
    ll max_prefix_sum;
    ll max_suffix_sum;
    ll max_subarray_sum;

    Node() : total_sum(0), max_prefix_sum(0), max_suffix_sum(0), max_subarray_sum(0) {}
};

// Global array to store the Segment Tree
vector<Node> tree;
vector<ll> arr;
int N;

// ----------------------------------------------------------------------
// 1. Merge Function
// ----------------------------------------------------------------------

// Function to merge two child nodes into a parent node
Node merge(const Node& left, const Node& right) {
    Node parent;

    // 1. Total Sum: Simple addition
    parent.total_sum = left.total_sum + right.total_sum;

    // 2. Max Prefix Sum:
    // It's either the prefix of the left child, OR
    // the total sum of the left child plus the prefix of the right child.
    parent.max_prefix_sum = max(left.max_prefix_sum, left.total_sum + right.max_prefix_sum);

    // 3. Max Suffix Sum:
    // It's either the suffix of the right child, OR
    // the total sum of the right child plus the suffix of the left child.
    parent.max_suffix_sum = max(right.max_suffix_sum, right.total_sum + left.max_suffix_sum);

    // 4. Max Subarray Sum:
    // It can be:
    // a) Max subarray sum of the left child.
    // b) Max subarray sum of the right child.
    // c) Max suffix of the left child + Max prefix of the right child (crossing the boundary).
    parent.max_subarray_sum = max({
        left.max_subarray_sum,
        right.max_subarray_sum,
        left.max_suffix_sum + right.max_prefix_sum
    });

    // We must allow empty subarrays (sum 0)
    parent.max_prefix_sum = max(0LL, parent.max_prefix_sum);
    parent.max_suffix_sum = max(0LL, parent.max_suffix_sum);
    parent.max_subarray_sum = max(0LL, parent.max_subarray_sum);
    
    return parent;
}

// ----------------------------------------------------------------------
// 2. Build Function
// ----------------------------------------------------------------------

// Function to build the Segment Tree recursively
void build(int node, int start, int end) {
    if (start == end) {
        // Leaf node: stores the array element's value
        ll val = arr[start];
        tree[node].total_sum = val;
        
        // Since empty subarrays are allowed (sum 0), take max(0, val)
        tree[node].max_prefix_sum = max(0LL, val);
        tree[node].max_suffix_sum = max(0LL, val);
        tree[node].max_subarray_sum = max(0LL, val);
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

// ----------------------------------------------------------------------
// 3. Update Function
// ----------------------------------------------------------------------

// Function to update the value at index idx
void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        // Base case: Reached the leaf node
        arr[idx] = val; // Update the actual array (optional, but good practice)
        tree[node].total_sum = val;
        
        // Update the max values based on the new single element
        tree[node].max_prefix_sum = max(0LL, val);
        tree[node].max_suffix_sum = max(0LL, val);
        tree[node].max_subarray_sum = max(0LL, val);
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            // Update in the left child
            update(2 * node, start, mid, idx, val);
        } else {
            // Update in the right child
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        // Merge the results back up the tree
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

// ----------------------------------------------------------------------
// Main Function
// ----------------------------------------------------------------------

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> N >> m;

    arr.resize(N + 1); // Array size N, using 1-based indexing for simplicity
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    // A segment tree for N elements typically needs 4*N space.
    tree.resize(4 * N + 1);

    // Build the initial Segment Tree
    build(1, 1, N);

    // Process updates
    for (int i = 0; i < m; ++i) {
        int k;
        ll x;
        cin >> k >> x;

        // Perform the update
        update(1, 1, N, k, x);

        // The maximum subarray sum is always stored at the root of the tree (node 1)
        cout << tree[1].max_subarray_sum << "\n";
    }

    return 0;
}
