// CSES 2169 - Nested Ranges Count
// Outputs: line 1 = how many ranges contain each range
//          line 2 = how many ranges each range contains

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Fenwick / BIT for prefix sums on 1..N
struct Fenwick {
    int n; vector<ll> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void reset(int m) { n=m; bit.assign(n+1,0); }
    void add(int idx, ll val){ for(; idx<=n; idx+=idx&-idx) bit[idx]+=val; }
    ll sum(int idx){ ll s=0; for(; idx>0; idx-=idx&-idx) s+=bit[idx]; return s; }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; 
    if(!(cin >> n)) return 0;

    struct R { ll l,r; int id; };
    vector<R> a(n);
    vector<ll> allR; allR.reserve(n);
    for(int i=0;i<n;i++){
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
        allR.push_back(a[i].r);
    }

    // sort by l asc, r desc
    sort(a.begin(), a.end(), [](const R& A, const R& B){
        if (A.l != B.l) return A.l < B.l;
        return A.r > B.r;
    });

    // coordinate-compress r
    sort(allR.begin(), allR.end());
    allR.erase(unique(allR.begin(), allR.end()), allR.end());
    auto ridx = [&](ll r){
        return int(lower_bound(allR.begin(), allR.end(), r) - allR.begin()) + 1; // 1-based
    };

    vector<ll> contain_me(n,0), i_contain(n,0); // answers in input order
    Fenwick fw((int)allR.size());

    // 1) how many contain me: sweep left -> right, count r >= r_i among seen
    fw.reset((int)allR.size());
    for(int i=0;i<n;i++){
        int ri = ridx(a[i].r);
        ll seen = i; // number of ranges already processed
        ll leq = fw.sum(ri-1); // those with r < r_i
        contain_me[a[i].id] = seen - leq; // r >= r_i
        fw.add(ri, 1);
    }

    // 2) how many I contain: sweep right -> left, count r <= r_i among to the right
fw.reset((int)allR.size());
for (int i = n - 1; i >= 0; i--) {
    int ri = ridx(a[i].r);
    // count how many future intervals have r <= r_i
    i_contain[a[i].id] = fw.sum(ri);
    // add current interval AFTER counting, so it won't count itself
    fw.add(ri, 1);
}

    // output
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << contain_me[i];
    }
    cout << '\n';
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << i_contain[i];
    }
    cout << '\n';
    return 0;
}