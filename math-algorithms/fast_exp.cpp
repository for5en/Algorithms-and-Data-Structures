#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

ll fast_exp(ll a, ll b, ll mod)
{
    ll ans = 1;

    while(b > 0)
    {
        if(b%2) ans *= a;
        a *= a;
        b /= 2;

        a %= mod;
        ans %= mod;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, mod;
    cin >> a >> b >> mod;
    cout << a << "^" << b << " mod " << mod << " equals: " << fast_exp(a, b, mod);


    return 0;
}
