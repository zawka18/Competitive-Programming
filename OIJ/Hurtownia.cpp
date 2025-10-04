#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<char,int> towar;
    int n, akt;
    char rodzaj;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>rodzaj>>akt;
        towar[rodzaj]+=akt;
    }

    for(const auto& pair : towar)
    {
        cout<<pair.first<<' '<<pair.second<<'\n';
    }


    return 0;
}