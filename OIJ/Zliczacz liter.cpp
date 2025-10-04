#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<char, int> litery; 
    int ile_zdan;
    string akt;


    for(char c = 'a'; c <= 'z'; c++) {
        litery[c] = 0; 
    }

    for(char c = 'A'; c <= 'Z'; c++) 
    {
        litery[c] = 0; 
    }


    cin >> ile_zdan;


    for(int i = 0; i < ile_zdan; i++) 
    {
        while (cin >> akt) 
        { 
            for (char c : akt) 
            {
                if (c == ' ') 
                	continue;
                	
                ++litery[c]; 
            }
        }
    }

    for(char c = 'a'; c <= 'z'; c++) 
    {
        if(litery[c] > 0) 
        {
            cout << c << ' ' << litery[c] << "\n";  
        }
    }


    for(char c = 'A'; c <= 'Z'; c++) 
    {
        if(litery[c] > 0) 
        {
            cout << c << ' ' << litery[c] << "\n";  
        }
    }

    return 0;
}