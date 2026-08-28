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

    int n,m; cin>>n>>m;
    vi t(n),p(m);
    for(int i=0; i<n; i++) cin>>t[i];
    for(int i=0; i<m; i++) cin>>p[i];

    int ans=INT_MAX;

    for(int i=0; i<m; i++)
    {
        int akt=0;
        deque<int> dq;
        for(int j=0; j<m; j++)
        {
            dq.push_back(p[(j+i)%m]);
            if(p[(j+i)%m]!=t[j]) akt++;
        }
        ans=min(ans,akt);
        int g=m;
        while(g<n)
        {
            int x=dq.front();
            dq.pop_front();
            if(x!=t[g-m]) akt--;

            dq.push_back(x);
            if(x!=t[g]) akt++;

            g++;
            ans=min(ans,akt);
        }
    }

    cout<<ans<<'\n';

}
