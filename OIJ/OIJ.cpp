#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string x,oij="";
    int ile=0;

    cin>>x;

    for(int i=0; i<x.size(); i++)
    {
        if(oij=="" && x[i]=='o')
            oij+='o';
        else if(oij=="o" && x[i]=='i')
            oij+='i';
        else if(oij=="oi" && x[i]=='j')
        {
            oij="";
            ile++;
        }

    }

    if(ile==0)
        cout<<"NIE"<<'\n';
    else
        cout<<ile<<'\n';

    return 0;
}