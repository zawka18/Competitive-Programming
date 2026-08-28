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

    ll n,k; int c; cin>>n>>k>>c;
    ll n1=n;
    vll dziel;

    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0) {dziel.pb(i);}
        while(n%i==0) n/=i;
    }
    if(n>1) dziel.pb(n);

    ll low=1,high=1e18;
    while(low<high)
    {
        ll mid=(low+high)/2;
        ll cnt=mid;
        
        for(int i=1; i<(1<<dziel.size()); i++)
        {
            ll akt=1;
            ll ile=0;
            for(int j=0; j<dziel.size(); j++)
            {
                if(i&(1<<j))
                {
                    akt*=dziel[j];
                    ile++;
                }
            }
            if(ile%2==1) cnt-=mid/akt;
            else cnt+=mid/akt;
        }

        if(cnt<k) low=mid+1;
        else high=mid;
    }

    int ile=0;

    while(ile<c)
    {
        bool flag=true;

 
        if(__gcd(low,n1)==1) {cout<<low<<' '; ile++;}
        low++;
    }

    
}