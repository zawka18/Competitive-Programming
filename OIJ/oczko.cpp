#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    int ile=0;
    int maxi=-1;
    vector<int> win;

    for(int j=1; j<=n; j++)
    {
        string a;
        cin>>a;
        int as=0;
        int suma=0;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]=='A')   as++;
            else if(a[i]=='T')  suma+=10;
            else if(a[i]=='J')  suma+=10;
            else if(a[i]=='Q')  suma+=10;
            else if(a[i]=='K')  suma+=10;
            else    suma+=int(a[i])-48;
        }
        suma+=as;
        if(as > 0 && suma + 10 <= 21) suma += 10;

        if(suma==maxi)
        {  
            ile++;
            win.push_back(j);
        }

        if(suma<=21 && suma>maxi)
        {
            maxi=suma;
            ile=1;
            win.clear();
            win.push_back(j);
        }
    }

    if(maxi==-1)    cout<<0;
    else
    {
        cout<<ile<<'\n';
        for(int i=0; i<win.size(); i++)     cout<<win[i]<<' ';
    }

    return 0;
}