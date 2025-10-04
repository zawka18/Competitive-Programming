#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string os;
    int k;
    vector<int> sp;     //wszystkie ind ciezarowek

    cin >> os >> k;

    for(int i = 0; i < os.size(); i++)
    {
        if(os[i] == 'X')
            sp.push_back(i); 
    }

    double mini = INT_MAX; 

    for(int i = 0; i <= sp.size() - k; i++)
    {
        double dist = sp[i + k - 1] - sp[i];
        if(dist < mini)
        {
            mini = dist; 
        }
    }

    cout << mini / 2; 

    return 0;
}
