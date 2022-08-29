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
typedef pair<ii, int> iii;

int m, n;

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < m && y < n;
}

void process() {
    cin >> m >> n;
    int a[m][n], dp[m][n], vis[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j], dp[i][j] = 0, vis[i][j] = 0;
    }
    queue<ii> q;
    q.push({0, 0});
    while(q.size()) {
        ii x = q.front();
        q.pop();
        if(x.fi == m-1 && x.sc == n-1) {
            cout << dp[m-1][n-1] << endl;
            return; 
        }
        ii kx = {x.fi + a[x.fi][x.sc], x.sc};
        ii ky = {x.fi, x.sc + a[x.fi][x.sc]};
        int w = dp[x.fi][x.sc];
        if(isValid(kx.fi, kx.sc) && !vis[kx.fi][kx.sc]) {
            dp[kx.fi][kx.sc] = w+1;
            vis[kx.fi][kx.sc] = 1;
            q.push(kx);
        }
        if(isValid(ky.fi, ky.sc) && !vis[ky.fi][ky.sc]) {
            dp[ky.fi][ky.sc] = w+1;
            vis[ky.fi][ky.sc] = 1;
            q.push(ky);
        }
    }
    cout << -1 << endl;

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