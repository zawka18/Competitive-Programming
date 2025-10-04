#include <bits/stdc++.h>
using namespace std;

int n;
int tab[400006];

bool CanPlusFit(int L)
{
    static int bad[400006];

    bad[0] = (tab[0] < L+1);
    for (int i = 1; i < n; i++)
    {
        bad[i] = bad[i-1] + (tab[i] < L+1);
    }

    for (int i = L; i+L < n; i++)
    {
        int left = i-L, right = i+L;
        int cntBad = bad[right] - (left > 0 ? bad[left-1] : 0);

        if (cntBad == 0 && tab[i] >= 2*L+1) return true;
    }
    return false;
}

int BinarySearch(int minR, int maxR)
{
    int l = minR, r = maxR;
    while (l+1 < r)
    {
        int mid = (l+r)/2;
        if (CanPlusFit(mid)) l = mid;
        else r = mid;
    }
    return CanPlusFit(r) ? r : l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) cin >> tab[i];

    cout << BinarySearch(0, n/2) << "\n";
}
