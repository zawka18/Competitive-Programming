#include <bits/stdc++.h>
using namespace std;

long long znajdzK(long long ktora, long long maks, long long baza)
{
    long long licznik = 1;
    long long aktualna = 0;
    bool dopuszczZera = false;

    while (true)
    {
        for (int d = dopuszczZera ? 0 : 1; d <= 9; ++d)
        {
            long long nowa = aktualna * 10 + d;
            if (licznik == ktora)
                return nowa;

            long long mozliwosci = (baza - 1) / 9 + min(baza, max(0LL, maks - nowa * baza + 1));
            if (licznik + mozliwosci > ktora)
            {
                aktualna = nowa;
                baza /= 10;
                dopuszczZera = true;
                ktora -= licznik;
                licznik = 1;
                break;
            }
            licznik += mozliwosci;
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int podzadanie = 4;
    if (argc > 1) podzadanie = stoi(argv[1]);

    int n;
    cin >> n;

    if (podzadanie == 1) if (!(n <= 200)) exit(1);
    if (podzadanie == 3) if (!(n == 1)) exit(1);

    vector<pair<string, long long>> dane(n);
    vector<long long> prefixy(n);

    for (int i = 0; i < n; ++i)
    {
        string nazwa;
        long long ile;
        cin >> nazwa >> ile;

        if (podzadanie == 1) if (!(nazwa.size() <= 20)) exit(1);
        if (podzadanie <= 2) if (!(ile < 1000)) exit(1);

        dane[i] = {nazwa, ile};
    }

    sort(dane.begin(), dane.end());

    long long suma = 0;
    for (int i = 0; i < n; ++i)
    {
        suma += dane[i].second;
        prefixy[i] = suma;
    }

    int q;
    cin >> q;

    while (q--)
    {
        long long k;
        cin >> k;

        auto it = lower_bound(prefixy.begin(), prefixy.end(), k);
        if (it == prefixy.end())
        {
            cout << "NIE\n";
        }
        else
        {
            int idx = it - prefixy.begin();
            long long podstawa = 1;
            while (podstawa * 10 <= dane[idx].second) podstawa *= 10;

            long long lokalK = k - (idx == 0 ? 0 : prefixy[idx - 1]);
            cout << dane[idx].first << znajdzK(lokalK, dane[idx].second, podstawa) << "\n";
        }
    }

    return 0;
}