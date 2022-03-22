#include <bits/stdc++.h>

using namespace std;

#define ll long long

typedef pair<int,int> II;

const int maxn = 1e6+5;

int n;
ll a[maxn];

void process() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i]+=abs(a[i]);
    }
    ll ans=-1e18;
    ll sum=0;
    for(int i=0;i<n;i++) {
        sum=max(a[i],sum+a[i]);
        ans=max(ans,sum);
    }
    cout << ans << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    return 0;
}





