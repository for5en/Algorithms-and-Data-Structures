#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int n, m;
int a, b;
vector <int> graph[1000];
vector <int> Tgraph[1000];
vector <int> toporder;
bitset <1000> visited;

int num;
int scc[1000];
vector <int> sccv[1000];

void topsort(int x)
{
    visited[x] = 1;
    for(int i=0; i<graph[x].size(); i++)
    {
        if(!visited[graph[x][i]]) topsort(graph[x][i]);
    }
    toporder.pb(x);
}

void kosaraju(int x)
{
    scc[x] = num;
    sccv[num].pb(x);
    for(int i=0; i<Tgraph[x].size(); i++)
    {
        if(scc[Tgraph[x][i]] == 0) kosaraju(Tgraph[x][i]);
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
        cin >> a >> b; // a -> b
        graph[a].pb(b);
        Tgraph[b].pb(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i]) topsort(i);
    }

    for(int i=toporder.size()-1; i>=0; i--)
    {
        if(scc[toporder[i]] == 0)
        {
            num++;
            kosaraju(toporder[i]);
        }
    }

    cout << "\nNumber of SCCs: " << num << "\n";
    for(int i=1; i<=n; i++)
    {
        cout << "SCC of " << i << " is: " << scc[i] << "\n";
    }

    cout << "\nAll SCCs:";
    for(int i=1; i<=num; i++)
    {
        cout << "\n" << i << ": ";
        for(int j=0; j<sccv[i].size(); j++) cout << sccv[i][j] << " ";
    }


    return 0;
}
