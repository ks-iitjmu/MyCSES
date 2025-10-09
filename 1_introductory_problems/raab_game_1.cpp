#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n,a,b;
    cin >> n >> a >> b;

    if((a+b) > n){
        cout << "NO" << endl;
        return;
    }

    if((a + b) > 0 && (a == 0 || b == 0)){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    ll draws = n - (a+b);
    ll sz = n - draws;
    for(int i = (b+1); i<= sz;i++){
        cout << i<< " ";
    }
    for(int i = 1; i<=b; i++){
        cout << i << " ";
    }
    for(int i = sz + 1; i<= n; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i<=n; i++){
        cout << i << " ";
    }
    cout << endl;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // ------ Start Code ------
    ll T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}