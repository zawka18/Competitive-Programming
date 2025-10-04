#include "bits/stdc++.h"
using namespace std;

void cbrt(int &n)
{
    
    while(n>0)
    {
    	int pierwiastek=cbrt((int)n);
    	
        for(int i=0; i<pierwiastek; i++)
            cout<<"O";
            
        for(int i=0; i<pierwiastek; i++)
            cout<<"I";
            
        for(int i=0; i<pierwiastek; i++)
            cout<<"J";
            
        cout<<"E";
        
        n-=pierwiastek*pierwiastek*pierwiastek;
    }
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;

    cin>>n;

    cbrt(n);
    
    return 0;
}