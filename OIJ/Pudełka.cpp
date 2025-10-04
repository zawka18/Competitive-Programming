#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    unordered_map<int,int> cnt;
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        int b;
        cin >> b;
        cnt[b]++;
        ans = max(ans, cnt[b]);
    }

    cout << ans << '\n';
    return 0;
}
