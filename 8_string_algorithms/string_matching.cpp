/*
Given a string and a pattern, your task is to count the number of positions 
where the pattern occurs in the string.

Input: The first input line has a string of length n, and the second input line has a pattern of length m. 
Both of them consist of characters a–z.


Output: Print one integer: the number of occurrences.
Constraints : 1 <= n,m <= 10^6

Example
Input: saippuakauppias
pp

Output:
2


given below is the solution for this problem

*/

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define pp pair<ll,ll>
#define ll int
#define True 1
#define gcd __gcd
#define range(i,a,b,c) for(ll i=a;i<b;i+=c)
#define int long long
#define lb lower_bound
#define ub upper_bound
#define False 0
#define prmap(m) {for(auto i: m) cout<<(i.fi)<<": "<<i.sec<<"  "; print("")}
#define maxa(p,q) *max_element(p,q)
#define mina(p,q) *min_element(p,q)
#define pq priority_queue<int>
#define all(v) v.begin(),v.end()
#define len(p) p.size()
#define append pb
#define foi(p,n) for(int i=p;i<n;i++)
#define ini(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define fi first
#define sec second
#define mp make_pair
#define tc while(t--)
#define N ((ll)800009)
#define gtc(a,b) cout<<"Case #"<<a<<": "<<b<<endl;
#define va(n) vector<ar<ll,n>>
#define fo(n) for(int i=0;i<n;i++)
#define rev(n) for(int i=n-1;i>=0;i--)
#define foj(m,n) for(int j=m;j<n;j++)
#define ar array
#define vp vector<pair<int,int>>
#define vc vector<int>
#define print(p) cout<<p<<"\n";
#define pr(p) cout<<p<<" ";
#define pr2(p,q) cout<<p<<" "<<q<<endl;
#define pr3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl;
#define pr4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
#define pra(a) {for(auto i: a) cout<<i<<" "; cout<<endl;}
#define prm(a) {for(auto i: a) pra(i) cout<<endl;}
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define isvalid(i,j,n,m) (1<=i and i<=n and 1<=j and j<=m)
#define gh fflush(stdout)
#define why {print("LOL") return 0;}
using namespace std;
 
 
ll n,t,k,maxn,x,y,flag=0,l1,r1,l2,r2,parity[2]={0,0},ok,need,c=0,m;
ll mod=1e9+7,INF=1e18,MAX=5e5;
 
string s,p;
 
vc computeZ(string& s)
{
	ll n=len(s);
	vc z(n+1,0);
	ll l=0,r=0;
	foi(1,n)
    {
		if(i<r)	z[i]=min(r-i,z[i-l]);
		while(i+z[i]<n and s[z[i]]==s[i+z[i]]) z[i]++;
		if(i+z[i]>r) l=i,r=i+z[i];
	}
	return z;
}
 

signed main()
{
    fio
    t=1;
    ll uu=t;
    tc
    {
        cin>>s>>p;
        string ps=p+"$"+s;
        vc z=computeZ(ps);
        ll ans=0,m=len(p);
        foi(m+1,len(ps)) if(z[i]>=m) ans++;
        print(ans)
    }
    return 0;
}