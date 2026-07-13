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

    int t; cin>>t;
    
    while(t--)
    {
        int n; cin>>n;
        vi a(n);
        int suma=0;
        for(int i=0; i<n; i++) {cin>>a[i]; suma+=a[i];}

        if(suma-n>1) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
        
    }
}