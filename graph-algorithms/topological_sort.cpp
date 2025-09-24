#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int n, m;
int a, b;
vector <int> graph[10005];
vector <int> topsort;
bitset <10005> visited;

void top_sort(int x)
{
    visited[x] = 1;
    for(int i=0; i<graph[x].size(); i++)
    {
        if(!visited[graph[x][i]]) top_sort(graph[x][i]);
    }
    topsort.pb(x);
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
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i]) top_sort(i);
    }

    cout << "Nodes sorted topologicaly:\n";
    for(int i=n-1; i>=0; i--)
    {
        cout << topsort[i] << " ";
    }



    return 0;
}
