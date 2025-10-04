#include "bits/stdc++.h"
using namespace std;

vector<int> l(26);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin>>n;


    for(int i=0; i<(int)n.size(); i++)  l[n[i]-'A']++;

    if(l['O'-'A']>=1 && l['I'-'A']>=1 && l['J'-'A']>=1) cout<<'T';
    else cout<<'N';

    if(l['E'-'A']>=1 && l['J'-'A']>=1 && l['O'-'A']>=1 && l['I'-'A']>=1) cout<<'T';
    else cout<<'N';

    if(l['I'-'A']>=2 && l['O'-'A']>=1) cout<<'T';
    else cout<<'N';



    return 0;
}
