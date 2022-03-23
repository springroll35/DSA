#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e3+1;
const ll mod = 1e9+7;
const int row[6] = {-1, 0, 0, 1, 0, 0};
const int col[6] = {0, -1, 1, 0, 0, 0};
const int height[6] = {0, 0, 0, 0, -1, 1};
typedef pair<int,int> ii;

void process() {
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    int dp[m][n];
    for(int i = 0; i < m; i++) {
        dp[i][0] = a[i][0];
    }
    for(int i = 0; i < n; i++) {
        dp[0][i] = a[0][i];
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(a[i][j]) {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

    
    
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