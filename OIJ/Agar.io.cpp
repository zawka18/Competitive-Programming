#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin >> n;
    vector<long long> Komorki(n);
    long long MAX = -1;

    for (int i = 0; i < n; ++i) 
    {
        cin >> Komorki[i];
        if (Komorki[i] > MAX)   MAX = Komorki[i];

    }

    sort(Komorki.begin(), Komorki.end());
    long long mass = 2;
    int ops = 0;

    priority_queue<long long> Masses;

    while (MAX > mass) 
    {
        for (int i = 0; i < (int)Komorki.size(); ++i) 
        {
            if (Komorki[i] < mass) 
            {
                Masses.push(Komorki[i]);
                Komorki.erase(Komorki.begin() + i);
                --i;
            } 
            else 
            {
                break;
            }
        }
        ops++;
        if (Masses.empty()) 
        {
            cout << "NIE";
            return 0;
        }
        mass += Masses.top();
        Masses.pop();
    }

    cout << ops;
}
