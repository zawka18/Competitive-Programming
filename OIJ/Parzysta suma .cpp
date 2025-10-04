#include "bits/stdc++.h"                                                        
using namespace std;                                                            
int main(){                                                                     
ios_base::sync_with_stdio(0);                                                   
cin.tie(0);                                                                     
cout.tie(0);                                                                    
    int n,akt_liczba,i;                                                         

    long long suma=0;                                                           
    vector<int> liczby;                                                         
    cin>>n;                                                                     
                                                                                
    for(i=0;i<n; ++i){                                                          
        cin>>akt_liczba;                                                        
        liczby.push_back(akt_liczba);                                           
        suma+=akt_liczba;                                                       
    }                                                                           
    if(suma%2==0){                                                              
        cout<<suma<<endl;                                                       
        return 0;                                                               
    }                                                                           
    sort(liczby.begin(),liczby.end());                                          
    for(i=0; i<n; ++i){                                                         
        if (liczby[i]%2!=0){                                                    
            suma-=liczby[i];                                                    
            cout<<suma;                                                         
            return 0;                                                           
        }                                                                       
    }                                                                           
                                                                                
                                                                                
return 0;                                                                       
}