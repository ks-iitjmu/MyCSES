#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

ll aPowBMod(ll base, ll exp)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 != 0)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i].first >> values[i].second;
    }

    ll numOfDivisors = 1;
    ll numOfDivisors_exp = 1;
    bool is_tao_even = false;
    for (auto &pr : values)
    {
        ll exp = pr.second;
        if((exp+1) % 2 == 0) is_tao_even = true;
        numOfDivisors = (numOfDivisors * (exp + 1)) % mod;
        numOfDivisors_exp = (numOfDivisors_exp * (exp + 1)) % (mod-1);
    }

    ll sum = 1;
    for (auto &[p, e] : values)
    {
        ll num = (aPowBMod(p, e + 1) - 1 + mod) % mod; // To prevent negative, if aPowBMod(p, e+1) == 0
        ll dem_inv = aPowBMod(p - 1, mod - 2);
        ll complete = (num * dem_inv) % mod;
        sum = (sum * complete) % mod;
    }

    ll half_tao = 1;
    if(is_tao_even){
        bool flag = false;
        for(auto &pr : values){
            ll exp = pr.second;
            if(!flag && (exp+1) % 2 ==0){
                exp/=2;
                flag = true;
            }
            half_tao = (half_tao * (exp+1)) % (mod-1);
        }
    }

    ll prod = 1;
    ll final_exp;
    for (auto &[p, e] : values)
    {
        if (e % 2 == 0)
        {
            ll e_half =e / 2;
            final_exp = (e_half * numOfDivisors_exp) % (mod - 1);
        }
        else
        {
            ll e_mod = e % (mod-1);
            final_exp = (half_tao * e_mod) % (mod - 1);
        }
        ll term = aPowBMod(p, final_exp);
        prod = (prod * term) % mod;
    }

    cout<<numOfDivisors<<" "<<sum<<" "<<prod<<'\n';

    return 0;
}