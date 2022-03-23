#include <bits/stdc++.h>

using namespace std;

#define fi "inp.inp"
#define ll long long

typedef pair<int,int> II;

const int maxn = 1005;
const ll mod = 1e9+7;

int n;
int a[maxn],dp[maxn];

void process() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int ans=0;
    for(int i=0;i<n;i++) {
        dp[i]=1;
        for(int j=0;j<i;j++) {
            if (a[j] <= a[i] && dp[i] < dp[j]+1) dp[i]=dp[j]+1;
        }
        ans=max(ans,dp[i]);
    }
    cout << n-ans << endl;
}

int main()
{
    //freopen(fi,"r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--) {
        process();
    }
    return 0;
}




