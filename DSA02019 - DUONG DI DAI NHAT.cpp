#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 100;
const ll mod = 1e9+7;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

std::vector<std::vector<int> > ke;
int vis[maxn][maxn];
int m, n;
int ans;

void init() {
    ke.clear();
    ke.resize(maxn);
    memset(vis, 0, sizeof(vis));
    ans = INT_MIN;
}

void DFS(int u, int cnt) {
    //cout << u << ' ';
    //int cur = 0;
    ans = max(ans, cnt);
    for(auto v : ke[u]) {
        if(!vis[u][v]) {
            vis[u][v] = vis[v][u] = 1;
            DFS(v, cnt + 1);
            vis[u][v] = vis[v][u] = 0;
        }
    }
}

void process() {
    cin >> n >> m;
    init();
    while(m--) {
        int u, v;
        cin >> u >> v;
        u++; v++;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    for(int i = 1; i <= n; i++) {
        DFS(i, 0);
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