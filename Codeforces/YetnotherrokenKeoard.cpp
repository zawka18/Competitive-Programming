#include "bits/stdc++.h"
using namespace std;
#define ll long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        string world;
        cin>>world;

        stack<int> capitals, smalls;
        unordered_map<int, bool> deleted;

        for(int i=0; i<world.size(); ++i){
            if(world[i]=='b'){
                deleted[i]=true;
                if(!smalls.empty()){
                    deleted[smalls.top()]=true;
                    smalls.pop();
                }

            }
            else if(world[i]=='B'){
                deleted[i]=true;
                if(!capitals.empty()){
                    deleted[capitals.top()]=true;
                    capitals.pop();
                }
            }
            else if('a'<=world[i] && world[i]<='z'){
                smalls.push(i);
            }
            else if('A'<=world[i] && world[i]<='Z'){
                capitals.push(i);
            }
        }

        for(int i=0; i<world.size(); ++i){
            if(!deleted[i]){
                cout<<world[i];
            }
        }
        cout<<endl;

    }



    return 0;
}