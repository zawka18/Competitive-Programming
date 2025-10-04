#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vec vector
const int MAXN=1e6+7;
vec<int> a(MAXN);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m=INT_MAX;
    cin>>n;
    //cout<<"XD";

    for(int i=0; i<n; i++)
    {
        int akt;
        cin>>akt;
        if(akt>MAXN)    continue;
        a[akt]++;
    }
    //cout<<"XD";

    for(int i=0; i<MAXN; i++)
    {
        if(m==0)
        {
            cout<<i;
            return 0;
        }
        else
        {
            m=min(m,a[i]+1);
        }
        m--;
    }

    return 0;
}