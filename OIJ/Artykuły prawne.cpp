#include "bits/stdc++.h"
using namespace std;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

	int n,i=0;
	char znak;
	cin>>n;
	
	for(i=n; i>26; i-=26){
		cout<<'z';
	}
	
	znak=i+'a'-1;
	cout<<znak;
	
	
	return 0;
}