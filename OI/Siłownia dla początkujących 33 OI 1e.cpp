#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;

    while(n>=0)
    {
        if(n%3==0 || n%8==0) {cout<<"TAK"; return 0;}
        n-=8;
    }

    cout<<"NIE";

}
