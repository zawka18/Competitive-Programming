#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) 
    {
        int b, k, h;
        cin >> b >> k >> h;

        long long total_per_cycle = b + k;

        if (b > h) 
        {
            cout << "NO" << '\n';
            continue;
        }

        long long full = (h - b) / total_per_cycle; 

        long long total = full * total_per_cycle + b;

        if (total > h) 
        {
            cout << "NO" << '\n';
        } 
        else 
        {
            total += k; 
            if (total > h) 
            {
                cout << "YES" << '\n'; 
            }
            else 
            {
                cout << "NO" << '\n'; 
            }
        }
    }

    return 0;
}
