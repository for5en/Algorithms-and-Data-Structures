#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int n, m;
int a, b, c;
vector <pair<int, int>> graph[1000]; // not used

vector <pair<int, pair<int, int>>> v;
int ans;
int siz[1000];
int par[1000];

int Find(int x)
{
    if(x == par[x]) return x;
    return (par[x] = Find(par[x]));
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(siz[x] > siz[y]) swap(x,y);
    par[x] = y;
    siz[y] += siz[x];
}

void reset()
{
    for(int i=0; i<1000; i++)
    {
        par[i] = i;
        siz[i] = 1;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    reset();
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        graph[a].pb({b, c});
        graph[b].pb({a, c});
        v.pb({c, {a, b}});
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++)
    {
        if(Find(v[i].ss.ff) != Find(v[i].ss.ss))
        {
            Union(v[i].ss.ff, v[i].ss.ss);
            ans += v[i].ff;
        }
    }

    cout << "MST cost: " << ans;




    return 0;
}
