#include "bits/stdc++.h"

using namespace std; 
const int max_n=2*1e5+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) 
    {
        int n, x;
        cin >> n >> x;

        vector<int> moc(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> moc[i];
        }

        sort(moc.begin(), moc.end(), greater<int>());

        int kombi = 0;
        int g = 0;
        
        while (g < n) 
        {
            int count = 0; 
            int min_skill = moc[g]; 
            int current_strength = 0;

            while (g < n && current_strength < x) 
            {
                count++; 
                current_strength = count * moc[g];
                g++;
            }

            if (current_strength >= x) 
            {
                kombi++;
            }
        }

        cout << kombi << '\n';
    }

    return 0;
}
