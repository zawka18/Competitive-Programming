#include <bits/stdc++.h>
using namespace std;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<string> an(n);

    for (int i = 0; i < n; i++)
    {
        cin >> an[i];
    }

    sort(an.begin(), an.end());

    vector<vector<int>> counts(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        for (char c : an[i])
        {
            counts[i][c - 'a']++;
        }
    }

    vector<int> group(n, -1);
    int group_id = 0;

    for (int i = 0; i < n; i++)
    {
        if (group[i] == -1)
        {
            group[i] = group_id;
            for (int j = i + 1; j < n; j++)
            {
                if (group[j] == -1 && counts[i] == counts[j])
                {
                    group[j] = group_id;
                }
            }
            group_id++;
        }
    }

    vector<vector<string>> grouped(group_id);

    for (int i = 0; i < n; i++)
    {
        grouped[group[i]].push_back(an[i]);
    }

    for (auto &grp : grouped)
    {
        sort(grp.begin(), grp.end());
        grp.erase(unique(grp.begin(), grp.end()), grp.end());
    }

    sort(grouped.begin(), grouped.end(), [](const vector<string> &a, const vector<string> &b)
    {
        return a[0] < b[0];
    });

    for (auto &grp : grouped)
    {
        for (auto &s : grp)
        {
            cout << s << ' ';
        }
        cout << '\n';
    }

    return 0;
}
