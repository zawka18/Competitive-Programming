#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll liczba_elementow, krok, liczba;
    cin >> liczba_elementow >> krok;
    set<ll> obecne;

    for (int i = 0; i < liczba_elementow; i++) 
    {
        cin >> liczba;
        obecne.insert(liczba);
    }

    ll i = krok;
    while (true) 
    {
        if (obecne.find(i) == obecne.end()) 
        {
            cout << i;
            break;
        }
        i += krok; 
    }

    return 0;
}