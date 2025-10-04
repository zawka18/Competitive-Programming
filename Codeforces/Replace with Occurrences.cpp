#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; 
    if(!(cin >> t)) return 0;
    
    while(t--) 
    {
        int n; cin >> n;
        vi b(n+1);
        for(int i=1;i<=n;i++) cin >> b[i];
        vector<vi> pos(n+1);
        for(int i=1;i<=n;i++) pos[b[i]].push_back(i);
        vi a(n+1, -1);
        bool ok = true;
        int label = 1;
        for(int k=1;k<=n;k++)
        {
            int cnt = (int)pos[k].size();
            if(cnt==0) continue;
            if(cnt % k != 0) { ok = false; break; }
            for(int i=0;i<cnt;i++)
            {
                a[pos[k][i]] = label;
                if((i+1) % k == 0) label++;
            }
        }
        if(!ok) 
        {
            cout << -1 << '\n';
        } 
        else 
        {
            for(int i=1;i<=n;i++)
            {
                if(i>1) cout << ' ';
                cout << a[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
