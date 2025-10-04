#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string x;
    int ans, suma=0;
    cin>>x;

    for(auto c : x)
    {
        if(c!='?')
            suma+=c-'0';
    }

    if(suma%3==0)
        ans=0;
    else
        ans=3-(suma%3);

    cout<<ans;

    return 0;
}