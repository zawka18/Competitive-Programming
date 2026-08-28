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


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k; cin>>n>>k;
    set<pll> sub; vll a(n); 
    for(int i=0; i<n; i++) {cin>>a[i]; sub.insert({a[i],i+1});}
    vector<vector<pll>> ans(n+1);
    int ktory=1;
    while(!sub.empty())
    {
        if(sub.size()==1)
        {
            auto [maly,ind1]=*sub.begin();
            if(maly>k) {cout<<"NIE"<<'\n'; return 0;}
            ans[ktory].pb({ind1,maly}); sub.erase(sub.begin());

            ktory++; continue;
        }

        auto [maly, ind1]=*sub.begin();
        auto [duzy, ind2]=*sub.rbegin();

        sub.erase(sub.begin()); sub.erase(prev(sub.end()));
        if(maly>k) {cout<<"NIE"; return 0;}

        if(duzy<=k)
        {
            if(maly+duzy<=k)
            {
                ans[ktory].pb({ind1,maly});
                ans[ktory].pb({ind2,duzy});
            }
            else
            {
                ll ile=k-maly;
                ans[ktory].pb({ind1,maly});
                ans[ktory].pb({ind2,ile});
                if(duzy-ile>0) sub.insert({duzy-ile,ind2});
            }
            ktory++;
            continue;
        }

        if(maly<k)
        {
            ll ile=k-maly;
            ans[ktory].pb({ind1,maly});
            ans[ktory].pb({ind2,ile});
            if(duzy-ile>0) sub.insert({duzy-ile,ind2});
        }
        else
        {
            ans[ktory].pb({ind1,maly});
            sub.insert({duzy,ind2});
        }

        ktory++;
    }
    
    cout<<"TAK"<<'\n';

    for(int i=1; i<=n; i++)
    {
        cout<<ans[i].size()<<' ';
        for(auto [x,y] : ans[i]) cout<<x<<' '<<y<<' ';
        cout<<'\n';
    }

    
}