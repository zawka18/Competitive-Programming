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
constexpr int baza=1<<20;

//#define int long long
vvi g,odwr;
vi postorder;
vi spojna;
vi rozmiar;
vector<bool> visited;

void dfs(int v)
{
    visited[v]=true;

    for(auto u : g[v])
    {
        if(!visited[u]) dfs(u);
    }
    postorder.pb(v);
}

void scc(int v, int nr)
{
    spojna[v]=nr;
    for(int u : odwr[v])
    {
        if(spojna[u]==0) scc(u,nr);
    }
}




signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    g.resize(n+1); odwr.resize(n+1); visited.resize(n+1); spojna.resize(n+1);
    vector<pii> kraw;

    for(int i=0; i<m; i++)
    {
        int a,b; cin>>a>>b;
        kraw.pb({a,b});
        g[a].pb(b);
        odwr[b].pb(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i]) dfs(i);
    }

    int akt=1;

    for(int i=postorder.size()-1; i>=0; i--)
    {
        if(spojna[postorder[i]]==0)
        {
            scc(postorder[i],akt);
            akt++;
        }
    }

    rozmiar.resize(akt+1,0);

    vvi nowy(n+1);
    vi sw(n+1);

    for(auto [a,b] : kraw)
    {
        if(spojna[a]!=spojna[b]) {nowy[spojna[a]].pb(spojna[b]); sw[spojna[b]]++;}
    }
    
    for(int i=1; i<=n; i++) rozmiar[spojna[i]]++;

    queue<int> q;
    vi posort;
    for(int i=1; i<akt; i++)
    {
        if(sw[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int v=q.front();
        posort.pb(v);
        q.pop();

        for(auto u : nowy[v])
        {
            sw[u]--;
            if(sw[u]==0) q.push(u);
        }
    }

    vi dp(akt,0);
    for(int i=posort.size()-1; i>=0; i--)
    {
        dp[posort[i]]=rozmiar[posort[i]]-1;

        for(auto u : nowy[posort[i]]) dp[posort[i]]+=dp[u]+1;
    }

    for(int i=1; i<=n; i++) cout<<dp[spojna[i]]<<'\n';


    

}