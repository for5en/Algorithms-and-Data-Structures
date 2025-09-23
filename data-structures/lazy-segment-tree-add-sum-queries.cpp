#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int q, a, b, c;
char t;
const int n = 1<<10;
int tree[2*n], lazy[2*n];

void push(int w, int n)
{
    lazy[w*2] += lazy[w];
    lazy[w*2+1] += lazy[w];
    tree[w*2] += lazy[w]*n/2;
    tree[w*2+1] += lazy[w]*n/2;
    lazy[w] = 0;
}

int query(int w, int x, int y, int b, int e)
{
    if(b >= x && e <= y) return tree[w];

    int sum = 0;
    int m = (b + e) / 2;

    push(w, e-b+1);

    if(x <= m) sum += query(w*2, x, y, b, m);
    if(m < y) sum += query(w*2+1, x, y, m+1, e);

    return sum;
}

void add(int w, int x, int y, int b, int e, int v)
{
    if(b >= x && e <= y)
    {
        lazy[w] += v;
        tree[w] += v*(e-b+1);
        return;
    }

    int m = (b + e) / 2;

    push(w, e-b+1);

    if(x <= m) add(w*2, x, y, b, m, v);
    if(m < y) add(w*2+1, x, y, m+1, e, v);

    tree[w] = tree[w*2] + tree[w*2+1] + lazy[w]*(e-b+1);
}

int main()
{
    cin >> q;
    for(int i=0; i<q; i++)
    {
        cin >> t;
        if(t == 'q')
        {
            cin >> a >> b; // sum query from a to b
            cout << query(1, a, b, 1, n) << "\n";
        }
        else if(t == 'a')
        {
            cin >> a >> b >> c; // add c to a, a+1, ..., b
            add(1, a, b, 1, n, c);
        }
    }


    return 0;
}
