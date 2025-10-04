#include "bits/stdc++.h"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,akt_liczba,i;
	long long operacje=0;
	vector<int> ilosc_liczb;
	
	ilosc_liczb.resize(1000001,0);
	
	cin>>n;
	vector<int> ciag(n);
	
	 for (int i = 0; i < n; ++i) {
        cin >> ciag[i];
        ++ilosc_liczb[ciag[i]];
	}
	
	for(i=1000000; i>0; --i){
		while(ilosc_liczb[i]>1){
			--ilosc_liczb[i];
			++ilosc_liczb[i-1];
			++operacje;
		}
	}
	cout<<operacje;
	return 0;
}