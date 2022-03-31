#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 35;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

void process() {
    int n;
    cin >> n;
    int dp[n][n];
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp[0][i] = x;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j+1];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << '[';
        for(int j = 0; j < n-i-1; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << dp[i][n-i-1] << ']' << endl;
    }
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