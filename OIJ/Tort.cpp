#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,ans=0;
    cin>>n;
    vector<int> need(n+7),ma(n+7);

    for(int i=0; i<n; i++)
        cin>>need[i];
    for(int i=0; i<n; i++)
    {
        cin>>ma[i];
        if(ma[i]<need[i])
            ans++;
    }
    
    cout<<ans;

    return 0;
}