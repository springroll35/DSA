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

const int maxn = 505;
const ll mod = 1e9+7;
const int rol[4] = {-1, 0, 0, 1};
const int col[4] = {0, -1, 1, 0};
typedef pair<int,int> ii;

int m, n;
int a[maxn][maxn], vis[maxn][maxn];

struct Data {
    bool operator() (pair<ii, int> x, pair<ii, int> y) {
        return x.sc > y.sc;
    }
};

void init() {
    memset(vis, 0, sizeof(vis));
}

void process() {
    cin >> m >> n;
    init();
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }

    priority_queue<pair<ii, int>, vector<pair<ii, int>>, Data> q;
    q.push({{1, 1}, a[1][1]});
    vis[1][1] = 1;
    while(q.size()) {
        ii uv = q.top().fi;
        int w = q.top().sc;
        q.pop();
        if(uv.fi == m && uv.sc == n) {
            cout << w << endl;
            return;
        }
        vis[uv.fi][uv.sc] = 1;
        for(int i = 0; i < 4; i++) {
            int x = uv.fi + rol[i];
            int y = uv.sc + col[i];
            if(x >= 1 && y >= 1 && x <= m && y <= n && !vis[x][y]) {
                vis[x][y] = 1;
                q.push({{x, y}, w + a[x][y]});
            }
        }

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