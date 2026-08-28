#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //cout<<"XDDD";

    ll n,a,b,c; cin>>n>>a>>b>>c;

    vector<ll> dp(n+3,0);
    dp[1]=a;

    //cout<<"XDDD";
    for(ll i=2; i<=n; i++)
    {
        ll mini=LLONG_MAX;
        for(ll j=1; j<i; j++)
        {
            mini=min(mini,dp[j]+dp[i-j]+b);
            if(i%j==0 && j!=1)
            {
                mini=min(mini,dp[j]+dp[i/j]+c);
            }
        }
        dp[i]=mini;
    }
    //cout<<"XDDD";

    for(int i=1; i<=n; i++) cout<<dp[i]<<' ';


}
