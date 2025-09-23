#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

void mat_mult(int a[2][2], int b[2][2])
{
    int temp[2][2];
    temp[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    temp[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    temp[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    temp[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    a[0][0] = temp[0][0];
    a[1][0] = temp[1][0];
    a[0][1] = temp[0][1];
    a[1][1] = temp[1][1];
}

int fast_fib(int n)
{
    int ans[2][2] = {{1, 0}, {0, 1}};
    int mat[2][2] = {{1, 1}, {1, 0}};

    while(n > 0)
    {
        if(n % 2)
        {
            mat_mult(ans, mat);
        }

        mat_mult(mat, mat);
        n /= 2;
    }

    return ans[0][1];
}

int main()
{
    int n;
    cin >> n;
    cout << n << "-th Fibonacci number is: " << fast_fib(n);


    return 0;
}
