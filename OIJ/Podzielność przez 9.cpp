#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string n;
    cin>>n;
    int suma=0;
    for(int i=0; i<(int)n.size(); i++)
        suma+=n[i]-'0';

    int ile1=9-suma%9,ile2=suma%9;
    string m="";

    for(int i=0; i<(int)n.size(); i++)
    {
        if(n[i]-'0'+ile1<10)
        {
            m+=(char)n[i]+ile1;
            for(int j=i+1; j<n.size(); j++) m+=n[j];
            break;
        }
        else if(n[i]-'0'-ile2>=0)
        {
            m+=(char)n[i]-ile2;
            for(int j=i+1; j<n.size(); j++) m+=n[j];
            break;
        }
        else    m+=n[i];
    }

    cout<<m;


    return 0;
}
