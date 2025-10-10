#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
	cin >> n;

	vector<int> subsequence;
	for (int i = 0; i < n; i++){
		int value;
		cin >> value;
		
		int index = lower_bound(subsequence.begin(), subsequence.end(), value) - subsequence.begin();
		if(index == subsequence.size()) {
		  subsequence.push_back(value);
		} 
		else {
		  subsequence[index] = value;
		}
	}

	cout << subsequence.size() << endl;
    
    return 0;
}