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
typedef pair<int,int> ii;

void process() {
    int m, n;
    cin >> m >> n;
    vector<vector<ll>> dp(m+1, vector<ll>(n+1, 1));
    for(int i = m-1; ~i; i--) {
        for(int j = n-1; ~j; j--) {
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }
    }
    cout << dp[0][0] << endl;

    
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