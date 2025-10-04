#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string karty;
    cin>>karty;
    unordered_map<char,int> ile;

    for(auto karta : karty)
    {
        ile[karta]++;
    }

    int c2=0,c3=0,c4=0;

    for(auto &rodzaj : ile)
    {
        if(rodzaj.second==2)   
            c2++;
        else if(rodzaj.second==3)
            c3++;
        else if(rodzaj.second==4)
            c4++;
    }

    while(c4>0)
    {
        if(c2<c3)
        {
            c4--;
            c2+=2;
        }
        else
        {
            c4--;
            c3++;
        }
    }

    while(c3>c2)
    {
        c3--;
        c2++;
    }

    cout<<min(c3,c2);

    return 0;
}