#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

string s,p;
int KMPNext[1005];

void kmp(string str)
{
    int dl = str.size();
    int j = -1;

    KMPNext[0] = -1;

    for(int i=1; i<=dl; i++)
    {
        while((j>-1) && (str[j]!=str[i-1])) j = KMPNext[j];
        j++;

        KMPNext[i] = j;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    kmp(s);

    for(int i=1; i<=s.size(); i++) cout << KMPNext[i] << " ";



    return 0;
}
