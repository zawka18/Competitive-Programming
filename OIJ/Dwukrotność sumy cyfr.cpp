#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second

const int MAXN= 500;
const int B = 60;

int f(long long x)
{
    int suma=0;
    while(x>0)
    {
        suma+=x%10;
        x/=10;
    }

    return suma*2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,x;
    cin>>n>>x;

    vector<vector<int>> jp(B, vector<int>(MAXN));

    for(int i=0; i<MAXN; i++)   jp[0][i]=f(i);
    
    for(int i=1; i<B; i++)
    {
        for(int j=0; j<MAXN; j++)
        {
            jp[i][j]=jp[i-1][jp[i-1][j]];
        }
    }

    if(n==1)    
    {
        cout<<x<<'\n';
        return 0;
    }

    ll ans=f(x);
    n-=2;        
    for(int b=0; b<B; b++)
    {
        if(n & (1LL<<b))  ans=jp[b][ans];
    }
    cout<<ans;

    return 0;
}
