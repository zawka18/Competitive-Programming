#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());

        int koniec = n;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > c)
            {
                koniec = i;
                break;
            }
        }

        for (int i = koniec - 1; i >= 0; i--) 
        {
            if(a[i] <= c)
            {
                a[i] = 0;
                for(int j = 0; j < koniec; j++)
                {
                    if(a[j] < c)
                        a[j] *= 2;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)  
            if(a[i] > c)  
                ans++;

        cout << ans << '\n';
    }
    return 0;
}
