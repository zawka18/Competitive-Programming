#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    while(t--) 
    {
        long long a, b;
        cin >> a >> b;
        
        long long tb = b;
        int e = 0;
        while(tb % 2 == 0) 
        {
            tb /= 2;
            e++;
        }
 
        if(e == 0) 
        { 
            if(a % 2 == 0) cout << -1 << "\n";
            else cout << a*b + 1 << "\n";
            continue;
        }
 
        long long res = -1;
        if(a % 2 == 0) 
        {
            res = max(a + b, a*(b/2) + 2);
        } 
        else 
        {
            if(e == 1) res = -1;
            else res = max(a*2 + b/2, a*(b/2) + 2);
        }
        cout << res << "\n";
    }
}
