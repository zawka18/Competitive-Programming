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

vector<vector<pii>> g;
vvi odwr;
vi postorder;
vector<bool> vis,used;
vi spojna;
vector<char> ans;
int cnt=1;

void dfs(int v)
{
    vis[v]=true;
    for(auto [u,nr] : g[v])
    {
        if(used[abs(nr)]) continue;
        used[abs(nr)]=true;
        if(vis[u])
        {
            if(nr<0)
            {
                nr*=-1;
                ans[nr]='<';
            }
            else ans[nr]='>';
        }
        else if(!vis[u])
        {
            if(nr<0)
            {
                nr*=-1;
                ans[nr]='<';
            }
            else ans[nr]='>';
            dfs(u);
        }
    }
    postorder.pb(v);
}

void scc(int v, int nr)
{
    spojna[v]=nr;
    for(auto u : odwr[v])
    {
        if(spojna[u]==0) scc(u,nr);
    }
}


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    g.resize(n+1); odwr.resize(n+1); vis.resize(n+1); spojna.resize(n+1); ans.resize(m+1); used.resize(m+1);
    vector<pii> kraw(m+1);

    for(int i=1; i<=m; i++)
    {
        int a,b; cin>>a>>b;
        g[a].pb({b,i});
        g[b].pb({a,-1*i});
        kraw[i]={a,b};
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i]) dfs(i);
    }
    for(int i=1; i<=m; i++)
    {
        if(ans[i]=='<') odwr[kraw[i].ff].pb(kraw[i].ss);
        else odwr[kraw[i].ss].pb(kraw[i].ff);
    } 

    int akt=1;
    for(int i=postorder.size()-1; i>=0; i--)
    {
        if(spojna[postorder[i]]==0) {scc(postorder[i],akt); akt++;}
    }
    cout<<akt-1<<'\n';
    for(int i=1; i<=m; i++) cout<<ans[i]; 


}