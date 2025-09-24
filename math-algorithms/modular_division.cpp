#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

//  1 = a^(p-1) mod p  -->  a^(-1) = a^(p-2) mod p

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

ll modular_division(ll a, ll b, ll mod)
{
    // a / b = a * b^(-1) = a * b^(p-2) mod p
    return (a * (fast_exp(b, mod-2, mod)) % mod);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, mod; // modulo needs to be prime

    cin >> a >> b >> mod;
    cout << a << " / " << b << " is congruent to " << modular_division(a, b, mod) << " modulo " << mod;



    return 0;
}
