#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int n, m;
int a, b, c;
vector <pair<int,int>> graph[1000];
int dist[1000];
priority_queue <pair<int,int>> pq;

void dijkstra(int x)
{
    for(int i=0; i<graph[x].size(); i++)
    {
        pq.push({-dist[x]-graph[x][i].ss, graph[x][i].ff});
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }

    fill(dist, dist+1000, 9999999);

    pq.push({0, 1});
    while(!pq.empty())
    {
        if(-pq.top().ff < dist[pq.top().ss])
        {
            dist[pq.top().ss] = -pq.top().ff;
            dijkstra(pq.top().ss);
        }
        pq.pop();
    }

    for(int i=1; i<=n; i++)
    {
        cout << i << ": " << dist[i] << "\n";
    }


    return 0;
}
