#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
#define pi pair<int,int>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,poprzedni;
    int maxi=0;
    cin>>n;
    string a;
    cin>>a;

    int j=a.size()-1;
    while(j>=0)
    {
        if(a[j]=='X')
        {
            poprzedni=n-j;
            maxi=max(maxi,poprzedni);
            break;
        }
        j--;
    }

    for(int i=j-1; i>=0; i--)
    {
        if(a[i]=='X')
        {
            maxi=max(n-i,poprzedni+2);
            poprzedni=maxi;
        }
    }

    cout<<maxi;


    return 0;
}