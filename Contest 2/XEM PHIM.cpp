#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

void process() {
    int n, c;
    cin >> c >> n;
    int a[n+1];
    std::vector<std::vector<int> > dp(n+1, std::vector<int> (c+1, 0));
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= c; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i-1][j];
                if (a[i-1] <= j && dp[i-1][j-a[i-1]] + a[i-1] <= c) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-a[i-1]] + a[i-1]);
                }
            }
        }
    }
    cout << dp[n][c] << endl;
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}