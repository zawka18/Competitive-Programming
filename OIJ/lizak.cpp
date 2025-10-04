#include "bits/stdc++.h"
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> lizak(n);

    for (int i = 0; i < n; ++i) 
    {
        cin >> lizak[i];
    }

    unordered_map<int, int> freq; 
    int left = 0;
    int minLength = INT_MAX;

    for (int right = 0; right < n; ++right) 
    {
        freq[lizak[right]]++;

        while (freq[lizak[right]] >= 3)
        {
            minLength = min(minLength, right - left + 1);

            freq[lizak[left]]--;
            left++;
        }
    }

    if (minLength == INT_MAX) 
    {
        cout << "NIE" << endl;
    } 
    else 
    {
        cout << minLength << endl;
    }

    return 0;
}