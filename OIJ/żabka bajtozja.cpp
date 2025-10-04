#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3+7;

vector<int> graph[MAX_N];
vector<bool> visited(MAX_N, false);

int n, p;
long long s;
vector<pair<long long,long long>> stones;

void bfs(int start) 
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) 
    {
        int v = q.front(); q.pop();

        for (int u : graph[v]) 
        {
            if (!visited[u]) 
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> s;

    stones.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> stones[i].first >> stones[i].second;
    }

    for (int i = 0; i < n; i++) {

        for (int j = i+1; j < n; j++) 
        {
            long long dx = stones[i].first - stones[j].first;
            long long dy = stones[i].second - stones[j].second;

            if (dx*dx + dy*dy <= s*s) 
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    bfs(p-1); 

    double max_dist = 0.0;
    long long x0 = stones[p-1].first;
    long long y0 = stones[p-1].second;

    for (int i = 0; i < n; i++) 
    {
        if (visited[i]) 
        {
            long long dx = stones[i].first - x0;
            long long dy = stones[i].second - y0;
            double dist = sqrt((double)dx*dx + (double)dy*dy);
            if (dist > max_dist) max_dist = dist;
        }
    }

    cout << fixed << setprecision(3) << max_dist+s << "\n";

    return 0;
}
