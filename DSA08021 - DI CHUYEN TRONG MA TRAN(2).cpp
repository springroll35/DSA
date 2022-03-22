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
    int a[m][n], vis[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j], vis[i][j] = 0;
    }
    queue<iii> q;
    q.push({{0, 0}, 0});
    while(q.size()) {
        iii x = q.front();
        q.pop();
        if(x.fi.fi == m-1 && x.fi.sc == n-1) {
            cout << x.sc << endl;
            return; 
        }
        ii kx = {x.fi.fi + a[x.fi.fi][x.fi.sc], x.fi.sc};
        ii ky = {x.fi.fi, x.fi.sc + a[x.fi.fi][x.fi.sc]};
        int w = x.sc;
        if(isValid(kx.fi, kx.sc) && vis[kx.fi][kx.sc] == 0) {
            vis[kx.fi][kx.sc] = 1;
            q.push({kx, w+1});
        }
        if(isValid(ky.fi, ky.sc) && vis[ky.fi][ky.sc] == 0) {
            vis[ky.fi][ky.sc] = 1;
            q.push({ky, w+1});
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