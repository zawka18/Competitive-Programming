#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll sp(int x)
{
    return(ll)x*(x+1)/2;
}

ll cala_suma(int a, int b)
{
    return(sp(b)-sp(a-1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,start,meta;

    cin>>n>>k>>start>>meta;

    int lista_1= start+(n-k);

    if(lista_1>n)
        lista_1-=n;
    
    int lista_2= meta+(n-k);
    if(lista_2>n)
        lista_2-=n;

    if(lista_1<=lista_2)
        cout<<cala_suma(lista_1,lista_2)<<'\n';
    else
        cout<<cala_suma(lista_1,n)+sp(lista_2)<<'\n';


    return 0;
}