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
vector<ll> f(2);

void pre()
{
    f[0]=0; f[1]=1;
    int last=1;
    while(f[last]+f[last-1]<=1e18)
    {
        f.pb(f[last]+f[last-1]);
        last++;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    pre();
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        int ans=0;
        while(n>0)
        {
            auto it=lower_bound(all(f),n);
            if(it==f.end()) n=abs(n-f.back());
            else n=min(abs(n-(*it)),abs(n-(*(it-1))));
            ans++;
        }
        cout<<ans<<'\n';
    }

    
}