#include "bits/stdc++.h"
using namespace std;
#define pi pair<int,int>
#define ll long long


const int MAXN = 500007;
vector<pi> graf1[MAXN];
bool visited[MAXN], odwiedzone[MAXN];   //odwiedzone do bfs1 i bfs2
int rodzina[MAXN], parentArr[MAXN];     //do jakiej spójnej należy dany wierzchołek, a parentArr to z jakiego wierzchołka przyszliśmy
vector<int> glowa(1);   //pierwszy wierzchołek ze spójnej
vector<int> zmiany;     //numer drogi do usunięcia
bool edgeUsed[MAXN];    //czy już jej nie usunęliśmy

void bfs1(int start, int rodzic)    //zwykły bfs z spójnymi składowymi
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    glowa.push_back(start);
    rodzina[start]=rodzic;
    while(!q.empty())
    {
        int v=q.front(); q.pop();
        for(auto [u,z] : graf1[v])
        {
            if(!visited[u])
            {
                rodzina[u]=rodzina[v];
                visited[u]=true;
                q.push(u);
            }
        }
    }
}

void bfs2(int start)    //drugi bfs
{
    queue<int> q;
    q.push(start);
    odwiedzone[start]=true;
    parentArr[start]=0;     //ten nie przyszedł z żadnego innego wierzchołka

    while(!q.empty())
    {
        int v=q.front(); q.pop();
        for(auto [u,z] : graf1[v])
        {
            if(!odwiedzone[u])  //jeśli nie odwiedzone to jak w zwykłym bfs
            {
                odwiedzone[u]=true;
                parentArr[u]=v;     //do wierzchołka u przyszliśmy z v
                q.push(u);
            }
            else
            {
                if(parentArr[v] != u && !edgeUsed[z])   //jeśli nie przyszliśmy do v z u i jeszcze nieusunęliśmy tej drogi
                {
                    zmiany.push_back(z);
                    edgeUsed[z] = true;
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i=1;i<n;i++) 
    {
        int a,b;
        cin>>a>>b;
        //dodajemy do grafu drogi, i to numer krawędzi
        graf1[a].push_back({b,i});
        graf1[b].push_back({a,i});
    }

    int rodzic=1;
    for(int i=1; i<=n; i++)     //spójne składowe
    {
        if(!visited[i]) 
        {
            bfs1(i,rodzic);
            rodzic++;
        }
    }

    cout<<rodzic-2<<'\n'; 

    for(int i=1; i<(int)glowa.size(); i++)
        bfs2(glowa[i]);

    int idx=0;
    for(int z : zmiany) 
    {
        if(idx+2 <= rodzic && idx+2 < (int)glowa.size())      cout<<z<<' '<<glowa[1]<<' '<<glowa[idx+2]<<'\n';
        idx++;
        if(idx >= rodzic-2) break;
    }

    return 0;
}