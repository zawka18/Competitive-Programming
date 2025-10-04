#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vi vector<int>

vi f(int x)
{
    vi male,duze;
    for(int i=1; i<sqrt(x)+1; i++)
    {
        if(x%i==0)
        {
            male.push_back(i);
            if(i*i!=x)  duze.push_back(x/i);
        }
    }

    vi dzielniki=male;

    for(int i=(int)duze.size()-1; i>=0; i--) dzielniki.push_back(duze[i]);
    return dzielniki;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll a,b,c,d; cin>>a>>b>>c>>d;
    ll szuk=c*d;

    vi C=f(c);
    vi D=f(d);

    for(int i=0; i<(int)C.size(); i++)
    {
        for(int j=0; j<(int)D.size(); j++)
        {
            ll x=1LL*C[i]*D[j];
            ll y=szuk/x;
            if(x<=a && y<=b || y<=a && x<=b)    {cout<<"TAK";   return 0;}
        }
    }
    

    cout << "NIE";
    return 0;
}
