#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int ile=0, a, ost=0;

    for(int i=0; i<n; i++)
    {
        cin>>a;
        if(ile%2==1)
        {
            if(a<ost)
                ile++;
            ost=a;
        }
        else
        {
        if(a>ost)
            ile++;
        ost=a;
        }
    }

    cout<<ile;


    return(0);
}