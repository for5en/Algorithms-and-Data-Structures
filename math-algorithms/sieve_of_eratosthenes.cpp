#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

void sieve(int n, bool* primes)
{
    primes[1] = 1;
    for(int i=2; i<=n; i++)
    {
        if(!primes[i])
        {
            for(int j=2*i; j<=n; j+=i)
            {
                primes[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    bool primes[n+5];
    fill(primes, primes + n + 5, 0);
    sieve(n, primes);

    cout << "Primes from 1 to " << n << ":\n";
    for(int i=1; i<=n; i++)
    {
        if(!primes[i]) cout << i << ", ";
    }


    return 0;
}
