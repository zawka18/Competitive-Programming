#include "bits/stdc++.h"
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int domy;
    long long kombinacje = 0;
    cin >> domy;

    vector<int> cuksy(domy + 1);

    int liczba_parzystych_0 = 1;  
    int liczba_parzystych_1 = 0;

    int parzystosc = 0;

    for (int i = 1; i <= domy; ++i) 
    {
        cin >> cuksy[i];
        parzystosc = (parzystosc + cuksy[i] % 2) % 2; 
        
        if (parzystosc == 0) 
        {
            kombinacje += liczba_parzystych_0;
            liczba_parzystych_0++;
        } 
        else if (parzystosc == 1) 
        {
            kombinacje += liczba_parzystych_1;
            liczba_parzystych_1++;
        }
    }

    cout << kombinacje;

    return 0;
}