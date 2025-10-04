#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
#define pi pair<int,int>
const int MAXN=1e6+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> k(n),r(n);

    for(int i=0; i<n; i++)  cin>>k[i];
    for(int i=0; i<n; i++)  cin>>r[i];
    
    if(n==1)
    {
        cout<<k[0]<<r[0];
        return 0;
    }

    sort(k.begin(),k.end());
    sort(r.begin(),r.end());

    ll ans=0;
    for(int i=0; i<n; i++)
    {
        ll a=k[i];
        ll b=r[r.size()-i-1];
        for(int i=1; i<MAXN; i*=10)
        {
            if(b<i)
            {
                //cout<<a*i+b<<endl;
                ans+=a*i+b;
                break;
            }
        }
    }

    cout<<ans<<'\n';


    return 0;
}