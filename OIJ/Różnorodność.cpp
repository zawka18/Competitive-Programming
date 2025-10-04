#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll last = LLONG_MIN; 
    int ans = 0;

    for (ll x : a) 
    {
        if (x - 1 > last) 
        {
            last = x - 1;
            ans++;
        } 
        else if (x > last) 
        {
            last = x;
            ans++;
        } 
        else if (x + 1 > last) 
        {
            last = x + 1;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}