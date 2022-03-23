#include <bits/stdc++.h>

using namespace std;

#define fi "inp.inp"
#define ll long long

typedef pair<int,int> II;

const int maxn = 1005;
const ll mod = 1e9+7;

int n,k;
ll dp[maxn][maxn];

ll C(int n, int k) {
    if (k == 0 || k == n) return 1;
    for(int i = 0; i <= k; i++) {
        for(int j = i; j <= n; j++) {
            if (i == 0 || i == j) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % mod;
        }
    }
    return dp[k][n] % mod;
}

void process() {
    cin >> n >> k;
    cout << C(n, k) << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}