#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e4+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n;
ll a[5][maxn];
bool dd[20];
ll dp[maxn][1 << 5];

int getBit(int x, int y) {
    return ((x >> y) & 1);
}

void process() {
    cin >> n;
    ll ans = -1e18;
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            ans = max(ans, a[i][j]);
        }
    }
    if(ans <= 0) {
        cout << ans << endl;
        return;
    }
    memset(dd, 0, sizeof(dd));
    for(int x = 0; x < (1 << 4); x++) {
        dd[x] = 1; 
        for(int i = 0; i < 4; i++) {
            if(getBit(x, i) && getBit(x, i+1)) {
                dd[x] = 0;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int x = 0; x < (1 << 4); x++) {
            dp[i][x] = -1e18;
            if(dd[x]) {
                int sum = 0;
                for(int j = 0; j < 4; j++) {
                    if(getBit(x,j)) sum += a[j][i];
                }
                for(int j = 0; j < (1 << 4); j++) {
                    if(dd[j] && ((x & j) == 0)) {
                        dp[i][x] = max(dp[i][x], dp[i-1][j] + sum);
                    }
                }
            }
            ans = max(ans, dp[i][x]);
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