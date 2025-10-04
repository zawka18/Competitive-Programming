#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,l;
    ll razem=0;
    cin>>n>>l;
    
    vector<char> opis(l);
    for(int i=0;i<l; i++)
        cin>>opis[i];

    vector<int> nawoz(n+1,0);
    for(int i=0; i<n; i++)
    {
        cin>>nawoz[i];
        razem+=nawoz[i];
    }
    
    sort(opis.begin(),opis.end());
    
    for(int i=0; i<l; i++)
    {
        if(opis[i]=='D')
        {
            if(razem>0)
                razem--;
            else 
            {
                cout<<"NIE";
                return 0;
            }
        }

        else
        {
            if(nawoz[opis[i]-49]>0)
            {
                nawoz[opis[i]-49]--;
                razem--;
            }
            else 
            {
                cout<<"NIE";
                return 0;
            }
        }
    }

    cout<<"TAK";
    return 0;
}