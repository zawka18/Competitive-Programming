#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> apply_op(const vector<int>& a) 
{
    int n = a.size();
    vector<int> cnt(n+1, 0);
    for (int v : a) if (0 <= v && v <= n) cnt[v]++;
    int mex = 0;
    while (mex <= n && cnt[mex] > 0) ++mex;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        int v = a[i];
        if (v < 0 || v > n) {
            b[i] = mex; 
        } else if (cnt[v] == 1 && v < mex) {
            b[i] = v;
        } else {
            b[i] = mex;
        }
    }
    return b;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (k == 0) {
            long long s = 0;
            for (int v : a) s += v;
            cout << s << '\n';
            continue;
        }
        auto a1 = apply_op(a);
        if (k == 1) {
            long long s = 0;
            for (int v : a1) s += v;
            cout << s << '\n';
            continue;
        }
        auto a2 = apply_op(a1);
        if (k == 2) {
            long long s = 0;
            for (int v : a2) s += v;
            cout << s << '\n';
            continue;
        }
        auto a3 = apply_op(a2);
        long long s = 0;
        if (k % 2 == 0) {
            for (int v : a2) s += v;
        } else {
            for (int v : a3) s += v;
        }
        cout << s << '\n';
    }
    return 0;
}
