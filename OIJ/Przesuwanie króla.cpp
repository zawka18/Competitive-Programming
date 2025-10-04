#include "bits/stdc++.h"
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char x, celx;
    int y, cely;

    cin >> x >> y >> celx >> cely;
    
    int mini = max(abs(celx - x), abs(cely - y));
    cout << mini << '\n'; 
    

    while (x != celx || y != cely)
    {
        if (x < celx && y < cely) 
        {
            cout << "NE "; 
            x++;
            y++;
        }

        else if (x < celx && y > cely) 
        {
            cout << "SE ";
            x++;
            y--;
        }

        else if (x > celx && y < cely) 
        {
            cout << "NW ";
            x--;
            y++;
        }
        
        else if (x > celx && y > cely) 
        {
            cout << "SW ";
            x--;
            y--;
        }
        
        else if (x < celx) 
        {
            cout << "E ";
            x++;
        }
        
        else if (x > celx)
        {
            cout << "W ";
            x--;
        }
        
        else if (y < cely) 
        {
            cout << "N "; 
            y++;
        }
        
        else if (y > cely) 
        {
            cout << "S ";
            y--;
        }
    }

    return 0;
}
