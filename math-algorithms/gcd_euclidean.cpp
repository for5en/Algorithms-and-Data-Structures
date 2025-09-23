#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int gcd(int x, int y)
{
    if(x > y) swap(x, y);
    while(x != 0)
    {
        y %= x;
        swap(x, y);
    }

    return y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;
    cout << "GCD of " << x << " and " << y << " equals: " << gcd(x, y);

    return 0;
}
