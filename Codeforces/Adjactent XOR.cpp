#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define ll long long
#define ld long double
#define f first
#define s second

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<ull> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        if (a[n-1] != b[n-1]) {
            cout << "NO\n";
            continue;
        }

        vector<char> used(n, 0);
        bool ok = true;

        for (int i = 0; i < n-1 && ok; ++i) {
            if (a[i] == b[i]) continue;
            ull need = a[i] ^ b[i];

            ull cur = 0;
            int found = -1;
            for (int r = i+1; r < n; ++r) {
                cur ^= a[r];
                if (cur == need) { found = r; break; }
            }
            if (found == -1) { ok = false; break; }

            for (int j = found-1; j >= i+1; --j) {
                if (used[j]) continue;
                a[j] ^= a[j+1];
                used[j] = 1;
            }

            if (used[i]) { ok = false; break; }
            a[i] ^= a[i+1];
            used[i] = 1;
        }

        if (!ok) { cout << "NO\n"; continue; }
        if (a == b) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
