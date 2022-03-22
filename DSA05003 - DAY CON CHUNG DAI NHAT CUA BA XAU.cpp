#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 101;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

void process() {
    int m, n, p;
    cin >> m >> n >> p;
    string x, y, z;
    cin >> x >> y >> z;
    int dp[m+1][n+1][p+1];
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= p; k++) {
                if (i == 0 || j == 0 || k == 0) dp[i][j][k] = 0;
                else if (x[i-1] == y[j-1] && y[j-1] == z[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
            }
        }
    } 
    //cout << x << ' ' << y << ' ' << z;
    cout << dp[m][n][p] << endl;

    
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