#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,d,ans=0;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>d;
        if(d%10==0)
            d-=1;
        ans+=d/10;
    }

    cout<<ans;

    return 0;
}