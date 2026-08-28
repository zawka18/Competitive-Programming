#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k; cin>>n>>k;
    ll zakres=sqrt(n)+1;

    vector<ll> ans(n+7,0);
    vector<vector<pair<ll,ll>>> male(zakres+1);

    for(ll i=0; i<k; i++)
    {
        ll a,l,d; cin>>a>>l>>d;

        if(d<=zakres)   male[d].push_back({a,l});
        else
        {
            ll o=a;
            for(ll j=0; j<l; j++)
            {
                ans[o]++;
                o+=d;
            }
        }
    }

    vector<ll> sp(n+zakres+7,0);

    for(ll i=1; i<=zakres; i++)
    {
        fill(sp.begin(), sp.end(), 0);
        for(auto &[x,y] : male[i])
        {
            sp[x]+=1;
            sp[x+y*i]-=1;
        }

        for(ll j=1; j<=n; j++)
        {
            if(j>i) sp[j]+=sp[j-i];
            ans[j]+=sp[j];
        }
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';

}
