#include "bits/stdc++.h"
using namespace std;

const int MAX_N = 1007;

int n, m;
vector<vector<char>> talerz(MAX_N, vector<char>(MAX_N));
vector<vector<int>> sp(MAX_N, vector<int>(MAX_N, 0));

bool sprawdz(int rozmiar)
{
    vector<vector<int>> ciastka(MAX_N, vector<int>(MAX_N, 0));

    for (int i = 1; i + rozmiar - 1 <= n; i++)
    {
        for (int j = 1; j + rozmiar - 1 <= m; j++)
        {
            int suma = sp[i + rozmiar - 1][j + rozmiar - 1]- sp[i + rozmiar - 1][j - 1]- sp[i - 1][j + rozmiar - 1]+ sp[i - 1][j - 1];
            
            if (suma == rozmiar * rozmiar)
            {
                ciastka[i][j] += 1;
                ciastka[i + rozmiar][j] -= 1;
                ciastka[i][j + rozmiar] -= 1;
                ciastka[i + rozmiar][j + rozmiar] += 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ciastka[i][j] += ciastka[i - 1][j] + ciastka[i][j - 1] - ciastka[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (talerz[i - 1][j - 1] == '#' && ciastka[i][j] <= 0)
                return false;
            if (talerz[i - 1][j - 1] == '.' && ciastka[i][j] > 0)
                return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> talerz[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int wartosc = (talerz[i - 1][j - 1] == '#') ? 1 : 0;
            sp[i][j] = wartosc + sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];
        }
    }

    int low = 1, high = min(n, m), result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sprawdz(mid))
        {
            result = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    cout << result << "\n";
    return 0;
}
