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

int m, n;
std::vector<std::vector<int> > ke;
int vis[maxn];

void DFS(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for(auto v : ke[u]) {
        if (!vis[v]) {
            DFS(v);            
        }
    }
}

void process() {
    ke.clear();
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        vis[i] = 0;
    }
    vector<int> a(0);
    for (int i=0; i<=n; i++) ke.push_back(a);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
    }
    int ans = 0;
    // DFS tung dinh, neu trong cac dinh con lai khong thuoc 1 tplt voi dinh dang xet
    // => do thi ko lien thong manh
    for(int i = 1; i <= n; i++) {
        DFS(i);
        for(int j = 1; j <= n; j++) {
            if (!vis[j]) {
                cout << "NO" << endl;
                return;
            }
        }
        memset(vis, 0, sizeof(vis));
    }
    cout << "YES" << endl;
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