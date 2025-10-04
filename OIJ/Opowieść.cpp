#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string a;
    cin>>a;
    unordered_map<char,int> m;
    int ans=0;

    for(int i=0; i<n; i++)
    {
        m[a[i]]++;
        if(m[(char)a[i]+32]>0 || m[(char)a[i]-32]>0)    ans++;
    }

    cout << ans << '\n';
    return 0;
}
