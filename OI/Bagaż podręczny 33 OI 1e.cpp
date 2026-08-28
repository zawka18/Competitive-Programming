#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    ll mina=INT_MAX, minb=INT_MAX, minc=INT_MAX;
    for(int i=0; i<n; i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        vector<ll> akt(3);
        akt[0]=a;   akt[1]=b;   akt[2]=c;
        sort(akt.begin(),akt.end());
        mina=min(mina,akt[0]);
        minb=min(minb,akt[1]);
        minc=min(minc,akt[2]);
    }
    cout<<mina*minb*minc;

}
