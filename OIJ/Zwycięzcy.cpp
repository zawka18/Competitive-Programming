#include "bits/stdc++.h"
using namespace std;

bool compare(const pair<char,int>& a, const pair<char,int>& b)
{
    if(a.second!=b.second)
        return a.second>b.second;

    else
        return a.first<b.first;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<char, int>> zawodnicy;
    int n, akt;
    cin >> n;

    if(n>0)
        {
        n += 65;
        for (char c = 'A'; c < (char)n; c++)
        {
            cin >> akt;
            zawodnicy.push_back({c, akt});
        }

        sort(zawodnicy.begin(),zawodnicy.end(), compare);
        
        int maxi=zawodnicy[0].second;
        int i=0;
        
        while(zawodnicy[i].second==maxi)
        {
            cout<<zawodnicy[i].first;
            i++;
        }
    }

    return 0;
}