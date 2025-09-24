#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int n, m;
int a, b;
vector <int> graph[10005];
bitset <10005> visited;
queue <int> q;

void bfs(int x)
{
    visited[x] = 1;
    q.push(x);

    while(!q.empty())
    {
        for(int i=0; i<graph[q.front()].size(); i++)
        {
            if(!visited[graph[q.front()][i]])
            {
                q.push(graph[q.front()][i]);
                visited[graph[q.front()][i]] = 1;
            }
        }
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bfs(1);

    return 0;
}
