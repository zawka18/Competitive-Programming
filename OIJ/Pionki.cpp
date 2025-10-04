#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define s second
#define f first


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    int x,y,razem=0;
    vector<int> X,Y,ileX,ileY;
    x=-1;
    y=-1;

    for(int i=0; i<n; i++)  cin>>a[i];

    for(int i=0; i<n; i++)  
    {
        int ile=0;
        for(int j=0; j<m; j++)
        {
            if(a[i][j]=='#')
            {    
                ile++;
                razem++;
            }
        }
        ileX.push_back(ile);
        x=max(x,ile);
    }
    //cout<<"XD"<<endl;

    for(int i=0; i<m; i++)  
    {
        int ile=0;
        for(int j=0; j<n; j++)
        {
            if(a[j][i]=='#')    ile++;
        }
        ileY.push_back(ile);
        y=max(y,ile);
    }
    //cout<<"XD"<<endl;

    for(int i=0; i<ileX.size(); i++)   
    {
        if(ileX[i]==x)  X.push_back(i);
    }
    //cout<<"XD"<<endl;
    for(int i=0; i<ileY.size(); i++)   
    {
        if(ileY[i]==y)  Y.push_back(i);
    }
    //cout<<"XD"<<endl;

    bool flag=false;
    for(int i=0; i<X.size(); i++)
    {
        for(int j=0; j<Y.size(); j++)
        {
            if(a[X[i]][Y[j]]=='#')
            {
                flag=true;
                break;
            }
        }
        if(flag==true)  break;
    }
    //cout<<"XD"<<endl;

    int ans=0;
    ans+=x;
    ans+=y;

    if(flag==true) 
    {
        ans-=2;
        ans+=(razem-x-y+1)*2;
    }
    else    ans+=(razem-x-y)*2;

    cout<<ans;




    
    
    return 0;
}