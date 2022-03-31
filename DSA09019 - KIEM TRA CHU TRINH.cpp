#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

std::vector<std::vector<int> > ke;
int vis[maxn];
int m, n;
bool ok;

void init() {
    ke.clear();
    ke.resize(maxn);
    memset(vis, 0, sizeof (vis));
    ok = false;
}

void DFS(int u, int pre) {
    vis[u] = 1;
    for(auto v : ke[u]) {
        if(!vis[v]) {
            DFS(v, u);
        }
        else if(vis[v] && v != pre) {
            ok = true;
        }
    }
}

void process() {
    cin >> n >> m;
    init();
    while(m--) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            DFS(i, i);
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();
    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}