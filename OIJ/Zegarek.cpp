#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h,m,s;

    cin>>h>>m>>s;

    s++;
    if(s==60)
    {
        s=0;
        m++;
        if(m==60)
        {
            m=0;
            h++;
            if(h==24)
                h=0;
        }
    }

    if(h<10)
        cout<<0;
    cout<<h<<':';

    if(m<10)
        cout<<0;
    cout<<m<<':';

    if(s<10)
        cout<<0;
    cout<<s;

    cout<<'\n';

    return 0;
}