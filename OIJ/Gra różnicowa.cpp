#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,p,akt,ans=0;

    cin>>n>>p;

    vector<int> a(p+7);

    for(int i=0; i<n; i++)
    {
        cin>>akt;
        a[akt%p]++;
    }

    for(int i=0; i<p;i++)
    {
        if(a[i]==1)
            ans++;
    }

    cout<<ans<<'\n';
    

    return 0;
}