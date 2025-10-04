#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> liczby;
    int n,akt;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>akt;
        liczby.push_back(akt);
    }

    sort(liczby.begin(), liczby.end());

    int wynik=0;
    int g=0;

    for(int o=0; o<n; o++)
    {
        while(g<n && liczby[o]+liczby[o+1]>liczby[g])
            g++;
        wynik=max(wynik,g-o);
    }

    cout<<wynik;


    return 0;
}