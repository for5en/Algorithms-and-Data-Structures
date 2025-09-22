#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int n, m;
int a, b;

vector <int> graph[1000];
bitset <1000> visited;

void dfs(int x)
{
    visited[x] = 1;
    for(int i=0; i<graph[x].size(); i++)
    {
        if(!visited[graph[x][i]]) dfs(graph[x][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m; // number of nodes and vertices

    for(int i=0; i<n; i++)
    {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs(1);


    return 0;
}
