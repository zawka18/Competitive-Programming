#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ld long double

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll m,d,n; cin>>m>>d>>n;
    vector<ll> a(n);

    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.rbegin(), a.rend());
    if(a[0]<m-d) {cout<<0; return 0;}
    ll ktoram=0;
    while(ktoram+1<n && a[ktoram+1]>=m-d) ktoram++;

    ll akt=0;
    bool czy=false;
    for(ll i=0; i<n; i++)
    {
        if(2*(d-akt)+m-d<=a[ktoram]) {cout<<i+1-czy;return 0;}
        if(i==ktoram) {czy=true; continue;}
        if(d-akt>a[i]) {cout<<0;return 0;}

        akt+=(a[i]-(d-akt));
        if(akt>=m) {cout<<i+1-czy;return 0;}
        if(akt>d) akt=d;
    }

    if(2*(d-akt)+m-d<=a[ktoram]) {cout<<n; return 0;}
    cout<<0;




}
