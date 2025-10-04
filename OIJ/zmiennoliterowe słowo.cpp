#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string napis;
    int ile=0;

    cin>>napis;

    for(int i=1; i<napis.size(); i++)
    {
        if(napis[i]==napis[i-1])
            ile+=1;
    }   

    cout<<ile;
    
    return 0;
}