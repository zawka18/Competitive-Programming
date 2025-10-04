#include "bits/stdc++.h"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> liczby;
	int akt_liczba,i;
	
	for(i=0;i<3;++i){
		cin>>akt_liczba;
		liczby.push_back(akt_liczba);
	}
	
	sort(liczby.begin(),liczby.end());
	//025
	if(liczby[0]==0){
		if (liczby[1]==0){
			liczby[0]=liczby[2];
			liczby[2]=0;
		}
		else{
			liczby[0]=liczby[1];
			liczby[1]=0;
		}	
	}
	for(i=0;i<3;++i)
		cout<<liczby[i];
	
	
	
	return 0;
}