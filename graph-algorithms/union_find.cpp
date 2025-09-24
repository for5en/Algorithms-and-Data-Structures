#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int n;
int a, b;
int par[10005];
int siz[10005];

int q;
char c;

void reset(int n)
{
    for(int i=1; i<=n; i++)
    {
        par[i] = i;
        siz[i] = 1;
    }
}

int Find(int x)
{
    if(x == par[x]) return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(siz[x] < siz[y]) swap(x, y);

    siz[x] += siz[y];
    par[y] = x;
}

int main()
{
    cin >> n >> q; // n - number of ?nodes?, q - number of operations
    reset(n);

    for(int i=0; i<q; i++)
    {
        cin >> c; // F - Find, U - Union
        if(c == 'F')
        {
            cin >> a;
            cout << "Parent of " << a << " is: " << Find(a) << "\n";
        }
        else if(c == 'U')
        {
            cin >> a >> b;
            Union(a, b);
        }
    }

    return 0;
}
