#include "bits/stdc++.h"
using namespace std;
#define ll long long
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t;
    cin>>t;
 
    while (t--)
    {
        multiset<int> dp;
        int n; cin>>n;
        dp.emplace(0);
 
        for(int i=0; i<n; i++)
        {
            int l,r;
            cin>>l>>r;
            auto it = dp.upper_bound(r);
            if(it!=dp.end())    dp.erase(it);
            dp.insert(l);
            cout<<(int)dp.size()-1<<' ';
        }
        cout<<'\n';
    }
 
 
    return 0;
}
