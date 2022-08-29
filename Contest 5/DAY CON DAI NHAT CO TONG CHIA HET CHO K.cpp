#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(k) k.begin(), k.end()
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e4+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

void process() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int dp[n+1][k+1];
    for(int i = 0; i <= k; i++) dp[0][i] = -1e9;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        int x = a[i-1] % k;
        for(int j = 0; j < k; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][(j-x+k) % k] + 1);
        }
    }
    cout << dp[n][0] << endl;
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