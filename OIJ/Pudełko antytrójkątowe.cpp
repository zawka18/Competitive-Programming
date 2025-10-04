#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M;   
    cin >> N >> M;
    vector<int> cnt(M+1, 0);
    for(int i=0; i<N; i++)
    {
        int a; cin >> a;
        cnt[a]++;
    }
    
    vector<int> vals;
    for(int i=1; i<=M; i++) if(cnt[i]>0) vals.push_back(i);
    
    int K = (int)vals.size();
    if(K==0)
    {
        cout << 0 << "\n";
        return 0;
    }
    
    vector<int> val(K+1, 0);
    for(int i=1; i<=K; i++) val[i] = vals[i-1];
    
    vector<vector<ll>> dp(K+1, vector<ll>(K+1, 0));
    
    for(int i=1; i<=K; i++)
    {
        if(cnt[val[i]] >= 1) dp[0][i] = 1;
        if(cnt[val[i]] >= 2) dp[i][i] = 1;
    }
    
    for(int i=1; i<=K; i++)
    {
        vector<ll> pref(i+1, 0);
        pref[0] = dp[0][i];
        for(int j=1; j<=i; j++) pref[j] = pref[j-1] + dp[j][i];
        
        int ub = 0;
        for(int j=i+1; j<=K; j++)
        {
            int need = val[j] - val[i];
            while(ub+1 <= i && val[ub+1] <= need) ub++;
            if(ub >= 0) dp[i][j] += pref[ub];
        }
    }
    
    ll total = 0;
    for(int i=1; i<=K; i++)
    {
        for(int j=0; j<=i; j++) total += dp[j][i];
    }
    
    ll ans = (ll) total;
    cout << ans << "\n";
    return 0;
}
