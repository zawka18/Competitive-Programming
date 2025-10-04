#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin>>t;

    while(t--)
    {
        vector<int> ile(10,0);
        int n,mini=INT_MAX,a;

        cin>>n;

        for(int i=1; i<=n; i++)
        {
            cin>>a;
            ile[a]++;
            if (ile[0] >= 3 && ile[2] >= 2 && ile[1] >= 1 && ile[3] >= 1 && ile[5] >= 1)
                mini=min(mini,i);
        }

        if(mini==INT_MAX)
            cout<<0;
        else
            cout<<mini;
        cout<<'\n';

    }

    return 0;
}
