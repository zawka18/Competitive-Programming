#include "bits/stdc++.h"
#include "zerlib.h"
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




signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n=daj_n();

    vi ans(n+1);
    vi a;
    int a1=-1;
    bool czy=false;

    for(int i=1; i<n; i++)
    {
        ans[i]=suma(0,i);
        if(ans[i]==2) {a1=1; czy=true;}
        if(ans[i]==0) {a1=0; czy=true;}
    }

    if(!czy)
    {
        int x=suma(1,2);
        a1=(ans[1]+ans[2]-x)/2;
    }
    a.pb(a1);
    for(int i=1; i<n; i++) a.pb(ans[i]-a1);

    odpowiedz(a);

    

}