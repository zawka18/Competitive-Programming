#include "bits/stdc++.h"
using namespace std;

//debug
#define dbg(a) cout << a << endl

//rozne
using ll = long long;
using ull = unsigned long long;
using ld = long double;

//skroty
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

//pary
using pii = pair<int,int>;
using pll = pair<long long, long long>;
using pcc = pair<char,char>;
using pss = pair<string,string>;
using pci = pair<char,int>;
using pic = pair<int,char>;

//mapy
using mii = map<int,int>;
using mll = map<long long, long long>;
using mcc = map<char,char>;
using mss = map<string,string>;
using mci = map<char,int>;
using mic = map<int,char>;

//vectory
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;

//sorty
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

//stale
constexpr int MOD=1e9+7;
constexpr int mod=998244353;
constexpr int MAXN=1e3+3;
constexpr int LOG=16;
constexpr int baza=1<<18;

//#define int long long

vvi g;
vi dp;
int ans=0;
void dfs(int v, int ost)
{
    for(auto u : g[v])
    {
        if(u==ost) continue;
        dfs(u,v);
    }
    int max1=0,max2=0;
    for(auto u : g[v])
    {
        if(u==ost) continue;
        if(dp[u]>max2) max2=dp[u];
        if(max2>max1) swap(max1,max2);
    }
    int cand=max1+max2+(int)g[v].size()-2;
    dp[v]=max1+(int)g[v].size()-2;
    if(max1==0) dp[v]++;
    if(max2==0) cand++;
    ans=max(cand,ans);
    //cout<<v<<' '<<dp[v]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    g.resize(n+1); dp.resize(n+1,0);

    for(int i=0; i<n-1; i++)
    {
        int a,b; cin>>a>>b;
        g[a].pb(b); g[b].pb(a);
    }
    if(n==2) {cout<<0; return 0;}
    dfs(1,0);
    cout<<ans<<'\n';

}