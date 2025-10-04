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
        if(n==2){
           cout<<-1<<' '<<2<<'\n';  continue;
        }

        if(n%2==0)
        {
            for(int i=0; i<n-2; i+=2)    cout<<-1<<' '<<3<<' ';
            cout<<-1<<' '<<2<<' ';
        }
        else
        {
            for(int i=0; i<n-1; i+=2)    cout<<-1<<' '<<3<<' ';
            cout<<-1;
        }
        
        cout<<'\n';

    }

    return 0;
}
