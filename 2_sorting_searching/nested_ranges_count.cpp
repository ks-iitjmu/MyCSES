#include <bits/stdc++.h>
using namespace std;

struct Range {
    int left, right, index;
};

class BIT {
    int n;
    vector<int> tree;
public:
    BIT(int size) : n(size), tree(size + 1, 0) {}
    
    void update(int idx, int val) {
        for (int i = idx; i <= n; i += i & (-i)) {
            tree[i] += val;
        }
    }
    
    int query(int idx) {
        int sum = 0;
        for (int i = idx; i > 0; i -= i & (-i)) {
            sum += tree[i];
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<Range> ranges(n);
    vector<int> allCoords;
    
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].left >> ranges[i].right;
        ranges[i].index = i;
        allCoords.push_back(ranges[i].right);
    }
    
    // Coordinate compression for right endpoints
    sort(allCoords.begin(), allCoords.end());
    allCoords.erase(unique(allCoords.begin(), allCoords.end()), allCoords.end());
    
    map<int, int> compress;
    for (int i = 0; i < allCoords.size(); i++) {
        compress[allCoords[i]] = i + 1;
    }
    
    vector<int> contains(n), containedBy(n);
    
    // Sort: by left ascending, then by right descending
    sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) {
        if (a.left != b.left) return a.left < b.left;
        return a.right > b.right;
    });
    
    // Count how many ranges each range contains
    // When processing left to right with sorted ranges:
    // - All previously seen ranges have left <= current left
    // - If a previous range has right <= current right, it's contained by current
    BIT bit1(allCoords.size());
    for (int i = 0; i < n; i++) {
        int compRight = compress[ranges[i].right];
        // Count ranges with right endpoint <= current right
        contains[ranges[i].index] = bit1.query(compRight);
        bit1.update(compRight, 1);
    }
    
    // Count how many ranges contain each range
    // Process in reverse order:
    // - All previously seen ranges (from right) have left >= current left
    // - If a previous range has right >= current right, it contains current
    BIT bit2(allCoords.size());
    for (int i = n - 1; i >= 0; i--) {
        int compRight = compress[ranges[i].right];
        // Count ranges with right endpoint >= current right
        containedBy[ranges[i].index] = bit2.query(allCoords.size()) - bit2.query(compRight - 1);
        bit2.update(compRight, 1);
    }
    
    // Output results
    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < n; i++) {
        cout << containedBy[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
