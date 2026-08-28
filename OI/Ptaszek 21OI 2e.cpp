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

    int n; cin>>n;
    vi d(n); for(int i=0; i<n; i++) cin>>d[i]; 
    int q; cin>>q;
    while(q--)
    {
        int x; cin>>x;
        vi dp(n);
        dp[n-1]=0;
        int cnt=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,d[n-1],n-1});
        while(cnt<x)
        {
            if(d[n-2-cnt]<=d[n-1]) dp[n-2-cnt]=1;
            else dp[n-2-cnt]=0;
            pq.push({dp[n-2-cnt],d[n-2-cnt],n-2-cnt});
            cnt++;
        }
        
        for(int i=n-2-cnt; i>=0; i--)
        {
            while(get<2>(pq.top())>i+x) pq.pop();
            auto [dpk,val,ind]=pq.top();
            dp[i]=dpk;
            if(val>=d[i]) dp[i]++;
            pq.push({dp[i],d[i],i});
        }

        //for(auto y : dp) cout<<y<<' ';
        //cout<<endl;

        cout<<dp[0]<<'\n';
    }

}