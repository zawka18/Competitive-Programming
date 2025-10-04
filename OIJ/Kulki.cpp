#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
#define pi pair<int, int>

ll licz(string a, string b, char c)
{
    int n=a.size();
    vector<pi> kulki;
    for(int i=0; i<n; i++)
    {
        if(a[i]==c) kulki.push_back({i,0});
        if(b[i]==c) kulki.push_back({i,1});
    }

    ll ans=0;

    for(int i=0; i<n; i++)
    {
        ans+=abs(kulki[i].first-i);
        ans+=kulki[i].second;
    }

    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,ans=0;
    string a,b;
    cin>>n;
    cin>>a>>b;

    cout<<min(licz(a,b,'C'),licz(a,b,'B'));


    return 0;
}