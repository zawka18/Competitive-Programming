#include "bits/stdc++.h"
using namespace std;

vector<long long> liczby_silne, silnie;

int bin1(int low, int high, long long x) 
{
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (liczby_silne[mid] >= x)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int bin2(int low, int high, long long x) 
{
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (liczby_silne[mid] > x)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long silnia = 1, i = 1;

    while (silnia <= 10000000000000) 
    {
        silnia *= i;
        silnie.push_back(silnia);
        i++;
    }

    for (int mask = 1; mask < (1 << silnie.size()); mask++) 
    {
        long long suma = 0;
        for (int j = 0; j < silnie.size(); j++) 
        {
            if (mask & (1 << j)) 
            {
                suma += silnie[j];
            }
        }
        liczby_silne.push_back(suma);
    }

    sort(liczby_silne.begin(), liczby_silne.end());


    vector<long long> prefix_sum(liczby_silne.size(), 0);
    prefix_sum[0] = liczby_silne[0];
    for (int i = 1; i < liczby_silne.size(); i++) 
    {
        prefix_sum[i] = prefix_sum[i - 1] + liczby_silne[i];
    }

    int ile_pyt;
    cin >> ile_pyt;

    long long suma, start, meta;
    while (ile_pyt--) 
    {
        suma = 0;
        cin >> start >> meta;

        int low = bin1(0, liczby_silne.size(), start);
        int high = bin2(0, liczby_silne.size(), meta);

        if (low < high) 
        {
            suma = prefix_sum[high - 1] - (low > 0 ? prefix_sum[low - 1] : 0);
        }

        cout << suma << endl;
    }

    return 0;
}