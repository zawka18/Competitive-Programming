#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while(q--)
    {
        string s;
        cin >> s;
        vector<int> ile(26);

        for(char c : s)
            ile[c - 'A']++;

        for(char c : {'T', 'F', 'N'})
        {
            while(ile[c - 'A']--)
                cout << c;
        }

        for(int i = 0; i < 26; i++)
        {
            char c = 'A' + i;
            if(c != 'T' && c != 'F' && c != 'N')
            {
                while(ile[i]--)
                    cout << c;
            }
        }
        cout << '\n';
    }
    return 0;
}
