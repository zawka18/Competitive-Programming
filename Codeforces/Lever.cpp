#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
const int maxi=10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int tab1[maxi];
        int tab2[maxi];

        for(int i=0; i<n; i++)  cin>>tab1[i];
        for(int i=0; i<n; i++)  cin>>tab2[i];

        int ans=1;

        for(int i=0; i<n; i++)  ans+=max(0,tab1[i]-tab2[i]);

        cout<<ans<<'\n';
    }

    return 0;
}
