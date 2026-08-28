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
constexpr int MAXN=1e6+3;
constexpr int LOG=16;
constexpr int baza=1<<18;

//#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vi a(n); for(int i=0; i<n; i++) cin>>a[i];
    vvi ind(MAXN); for(int i=0; i<n; i++) ind[a[i]].pb(i);
    int t; cin>>t;
    while(t--)
    {
        int m; cin>>m;
        int akt=-1;
        bool flag=true;

        for(int i=0; i<m; i++)
        {
            int x; cin>>x;
            if(!flag) continue;
            if(ind[x].size()==0) {cout<<"NIE"<<'\n'; flag=false; continue;}
            int low=0,high=ind[x].size()-1;
            while(low<high)
            {
                int mid=(low+high)/2;
                if(ind[x][mid]<=akt) low=mid+1;
                else high=mid;
                //cout<<low<<endl;
            }
            if(ind[x][low]<=akt) {cout<<"NIE"<<'\n'; flag=false; continue;}
            akt=ind[x][low];
        }
        if(!flag) continue;
        cout<<"TAK"<<'\n';
    }

}