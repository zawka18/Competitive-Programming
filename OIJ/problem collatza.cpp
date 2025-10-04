#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    ll val=102676904080084950;
    int kroki=1800;

    while(n!=kroki)
    {
        if(val%2==0)    val/=2;
        else    val=val*3+1;
        kroki--;
    }
    cout<<val;

    return 0;
}
