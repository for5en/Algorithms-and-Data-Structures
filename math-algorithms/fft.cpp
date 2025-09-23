#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

double PI = acos(-1);

struct comp
{
    double re;
    double im;
};

comp mult(comp a, comp b)
{
    comp c;
    c.re = (a.re * b.re) - (a.im * b.im);
    c.im = (a.re * b.im) + (a.im * b.re);
    return c;
};

comp add(comp a, comp b)
{
    comp c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

comp sub(comp a, comp b)
{
    comp c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}

vector <comp> FFT(const vector <comp> &W, int n)
{
    if(n == 1)
    {
        vector <comp> y;

        comp w;
        w.re = W[0].re;
        w.im = W[0].im;
        y.pb(w);

        return y;
    }

    vector <comp> W0, W1;
    W0.clear();
    W1.clear();

    comp temp1, temp2;
    for(int i=0; i<n; i+=2)
    {
        temp1.re = W[i].re;
        temp1.im = W[i].im;
        temp2.re = W[i+1].re;
        temp2.im = W[i+1].im;
        W0.pb(temp1);
        W1.pb(temp2);
    }

    vector <comp> y0 = FFT(W0, n/2);
    vector <comp> y1 = FFT(W1, n/2);

    comp uni;
    uni.re = cos(2*PI / n);
    uni.im = -sin(2*PI / n);

    vector <comp> y(n);

    comp point;
    point.re = 1;
    point.im = 0;

    for(int i=0; i<n/2; i++)
    {
        y[i] = add(y0[i], mult(y1[i], point));
        y[i + n/2] = sub(y0[i], mult(y1[i], point));
        point = mult(point, uni);
    }

    return y;
}

vector <comp> IFFTn(const vector <comp> &W, int n)
{
    if(n == 1)
    {
        vector <comp> y;

        comp w;
        w.re = W[0].re;
        w.im = W[0].im;
        y.pb(w);

        return y;
    }

    vector <comp> W0, W1;
    W0.clear();
    W1.clear();

    comp temp1, temp2;
    for(int i=0; i<n; i+=2)
    {
        temp1.re = W[i].re;
        temp1.im = W[i].im;
        temp2.re = W[i+1].re;
        temp2.im = W[i+1].im;
        W0.pb(temp1);
        W1.pb(temp2);
    }

    vector <comp> y0 = IFFTn(W0, n/2);
    vector <comp> y1 = IFFTn(W1, n/2);

    comp uni;
    uni.re = cos(2*PI / n);
    uni.im = sin(2*PI / n);

    vector <comp> y(n);

    comp point;
    point.re = 1;
    point.im = 0;

    for(int i=0; i<n/2; i++)
    {
        y[i] = add(y0[i], mult(y1[i], point));
        y[i + n/2] = sub(y0[i], mult(y1[i], point));
        point = mult(point, uni);
    }

    return y;
}

vector <comp> IFFT(const vector <comp> &W, int n)
{
    vector <comp> Y = IFFTn(W, n);
    for(int i=0; i<n; i++)
    {
        Y[i].re /= n;
        Y[i].im /= n;
    }

    return Y;
}


vector <comp> multY(vector <comp> y1, vector <comp> y2, int n)
{
    vector <comp> y(n);
    for(int i=0; i<n; i++)
    {
        y[i] = mult(y1[i], y2[i]);
    }

    return y;
}

int nextP2(int x)
{
    int P2 = 1;
    while(P2 < x) P2 <<= 1;
    return P2;
}

int main()
{
    int m, k;
    double re, im;
    comp zero;
    zero.re = 0;
    zero.im = 0;

    cout << "Give size of the first polynomial: ";
    cin >> m;

    vector <comp> A(m);
    cout << "Give coefficients of the first polynomial ([re] [im]): \n";
    for(int i=0; i<m; i++)
    {
        cin >> re >> im;
        A[i].re = re;
        A[i].im = im;
    }

    cout << "\nGive size of the second polynomial: ";
    cin >> k;

    vector <comp> B(k);
    cout << "Give coefficients of the second polynomial ([re] [im]): \n";
    for(int i=0; i<k; i++)
    {
        cin >> re >> im;
        B[i].re = re;
        B[i].im = im;
    }

    int n = 2*nextP2(max(m, k));
    while(A.size() < n) A.pb(zero);
    while(B.size() < n) B.pb(zero);

    vector <comp> C = IFFT(multY(FFT(A, n), FFT(B, n), n), n);

    cout << "\nTheir product is: \n";
    for(int i=0; i<n; i++)
    {
        cout << fixed << setprecision(0) << C[i].re << " " << C[i].im << "\n";
    }

    return 0;
}
