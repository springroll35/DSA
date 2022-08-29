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
    string s, x;
    cin >> s >> x;
    s = " " + s;
    x = " " + x;
    int m = s.length(), n = x.length();
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if (s[i] == x[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[m-1][n-1] << endl;

    
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