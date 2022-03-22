#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn=1e6+1;
ll a[maxn],b[maxn],c[maxn];
int m,n,k;

void process()
{
    vector<ll> v;
    v.clear();
    cin>>m>>n>>k;
    for(int i=0; i<m; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<k; i++) cin >> c[i];
    //sort(a+1,a+m+1);
    //sort(b+1,b+n+1);
    //sort(c+1,c+k+1);
    int x=0,y=0,z=0;
    while(x < m && y < n && z < k)
    {
        if (a[x] == b[y] && b[y] == c[z])
        {
            v.push_back(a[x]);
            x++;
            y++;
            z++;
        }
        else if (a[x] < b[y]) x++;
        else if (b[y] < c[z]) y++;
        else z++;
    }
    if (v.empty()) cout << "-1\n";
    else
    {
        for(ll x : v) cout << x << " ";
        cout << endl;
    }



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--)
    {
        process();
    }
    return 0;
}



