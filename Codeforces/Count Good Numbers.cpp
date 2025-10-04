#include "bits/stdc++.h"

using namespace std;

long long lcm(long long a, long long b) 
{
    return a / __gcd(a, b) * b;
}

long long count_good(long long n) 
{
    vector<int> primes = {2, 3, 5, 7};
    long long total = n;

    for (int mask = 1; mask < (1 << 4); ++mask) 
    {
        long long l = 1;
        for (int i = 0; i < 4; ++i) 
        {
            if (mask & (1 << i)) 
            {
                l = lcm(l, primes[i]);
            }
        }
        long long ile = n / l;
        int bits = __builtin_popcount(mask);
        if (bits % 2 == 1) 
            total -= ile;
        else total += ile;
    }

    return total;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) 
    {
        long long l, r;
        cin >> l >> r;
        cout << count_good(r) - count_good(l - 1) << '\n';
    }
    return 0;
}
