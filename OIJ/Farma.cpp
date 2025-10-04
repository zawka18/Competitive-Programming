#include "bits/stdc++.h"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int glowy,nogi,krowy=0,kury=0;
	
	cin>>glowy>>nogi;
	
	krowy=(nogi-2*glowy)/2;
	kury=(4*glowy-nogi)/2;
	
	cout<<kury<<' '<<krowy;
	
	/*
	tyle mają:
	krowy = (nogi - 2 glowy)/2
	kury = (4 glowy - nogi)/2
	
	
	równania:
	krowy + kury = glowy
	4 krowy + 2 kury = nogi
	
	kury = glowy - krowy
	krowy = glowy - kury
	
	4krowy + 2 glowy - 2 krowy = nogi
	
	nogi = 2 krowy + 2 glowy
	
	2 krowy = 2 glowy - nogi
	
	krowy = (nogi - 2 glowy)/2
	
	4 glowy - 4 kury + 2 kury = nogi
	4 glowy - 2 kury = nogi
	
	-2 kury = nogi - 4 glowy
	
	2 kury = 4 glowy - nogi
	kury = (4 glowy - nogi)/2
	
	*/
	return 0;
}