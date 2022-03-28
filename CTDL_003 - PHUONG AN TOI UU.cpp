#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 105;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n, v;
int a[maxn], c[maxn];
std::vector<std::vector<int> > dp;
std::vector<int> ans;

void trace(int n, int v) {
    if (n == 0) return;
    if(dp[n][v] == dp[n-1][v]) {
        trace(n-1, v);
    }
    else {
        trace(n-1, v-a[n]);
        ans[n-1] = 1;
    }
}

void process() {
    cin >> n >> v;
    dp.resize(n+1, std::vector<int> (v+1, 0));
    ans.resize(n, 0);
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= v; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i-1][j];
                if (a[i] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]] + c[i]);
                }
            }
        }
    }
    cout << dp[n][v] << endl;
    trace(n, v);
    for(auto x : ans) {
        cout << x << ' ';
    }
    
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