#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define vi vector<int>
#define pii pair<int,int>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin>>n;
    map<int,int> m;
    int ans=0;
    vector<pii> odp;
    int ost=1;

    for(int i=0; i<n; i++)
    {
        int a;  cin>>a;
        m[a]++;
        if(m[a]==2)
        {
            odp.push_back({ost,i+1});
            ost=i+2;
            m.clear();
            ans++;
        }
    }

    if(ans==0) {cout<<-1; return 0;}
    else
    {
        cout<<ans<<'\n';
        odp[ans-1].second=n;
        for(auto [x,y] : odp)
        {
            cout<<x<<' '<<y<<'\n';
        }
    }
    return 0;
}
