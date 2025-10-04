#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; 
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        map<pair<int,int>, pair<int,int>> counts;

        auto getPair = [&](int r) {
            int a = r;
            int b = (int)((k - r) % k);
            if (a > b) swap(a, b);
            return make_pair(a, b);
        };

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            int r = x % k;
            counts[getPair(r)].first++;
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            int r = x % k;
            counts[getPair(r)].second++;
        }

        bool ok = true;
        for (auto &[key, val] : counts) {
            if (val.first != val.second) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
