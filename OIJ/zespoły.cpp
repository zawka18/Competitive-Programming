#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,akt;
    vector<int> moc;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>akt;
        moc.push_back(akt);
    }

    sort(moc.begin(), moc.end());

    int ile=0;
    for(int i=0; i+2<n; i++)
    {
        if(abs(moc[i]-moc[i+2])<=1)
        {
            ile++;
            i+=2;
            
        }
    }

    cout<<ile<<'\n';


    return 0;
}