#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll k;
    int przerwa;
    string x,nowy="";

    cin>>x;
    cin>>k;

    przerwa=k%x.size();


    for(int i=przerwa; i<x.size(); i++)
        nowy+=x[i];

    for(int i=0; i<przerwa; i++)
        nowy+=x[i];

    cout<<nowy<<'\n';


    return 0;
}