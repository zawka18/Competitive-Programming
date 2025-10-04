#include "bits/stdc++.h"
using namespace std;

vector<int> rozmiar;
vector<int> programy;


int bin(int low, int high, int x)
{
    while(low<high)
    {
        int mid=(low+high)/2;

        if(rozmiar[mid]<x)
            low=mid+1;
        else
            high=mid;
    }
    return low;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ost, n, m,akt,ile=0;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>akt;
        programy.push_back(akt);
    }

    cin>>m;

    for(int i=0; i<m; i++)
    {
        cin>>akt;
        rozmiar.push_back(akt);
    }

    sort(rozmiar.begin(),rozmiar.end());
    sort(programy.begin(),programy.end());

    ost=0;
    for(int i=0; i<n; i++)
    {
    	ost=bin(ost,m,programy[i]);
    	if(ost<m)
    	{
    		ile++;
    		ost++;
    	}
    	else
    		break;
    }

    cout<<ile;




    return 0;
}