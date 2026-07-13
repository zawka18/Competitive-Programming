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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<string> a(n);
    for(int i=0; i<n ;i++) cin>>a[i];
    vvi g(26);
    vi sw(26);

    for(int i=1; i<n; i++)
    {
        bool czy=true;
        for(int j=0; j<a[i-1].size() && j<a[i].size(); j++)
        {
            if(a[i][j]!=a[i-1][j]) 
            {
                //cout<<a[i-1][j]-'a'<<' '<<a[i][j]-'a'<<endl;
                g[a[i-1][j]-'a'].pb(a[i][j]-'a');
                sw[a[i][j]-'a']++;
                czy=false;
                break;
            }
        }
        if(czy && a[i-1].size()>a[i].size()) {cout<<"Impossible"<<'\n'; return 0;}
        
    }

    queue<int> q;
    bool czy=true;
    vi posort;
    for(int i=0; i<26; i++)
    {
        if(sw[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int v=q.front();
        posort.pb(v);
        q.pop();

        for(auto u : g[v])
        {
            sw[u]--;
            if(sw[u]==0) q.push(u);
        }
    }

    if(posort.size()!=26) {cout<<"Impossible"; return 0;}

    for(auto x : posort) cout<<char(x+'a');

}