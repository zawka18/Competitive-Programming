#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,m,snieg;
    cin>>n>>m;
    vector<string> rys(n+7);

    for(int i=0; i<n; i++)
    {
        cin>>rys[i];
    }

    for(int j=0; j<m; j++)
    {
        snieg=0;
        for(int i=0; i<n; i++)
        {
            if(rys[i][j]=='*')
            {
                snieg++;
                rys[i][j]='.';
            }
            if(rys[i][j]=='#')
            {
                for(int o=1; o<=snieg; o++)
                {
                    rys[i-o][j]='*';
                }
                snieg=0;
            }
        }
    }
    
    for(int i=0; i<n; i++)
        cout<<rys[i]<<'\n';


    return 0;
}