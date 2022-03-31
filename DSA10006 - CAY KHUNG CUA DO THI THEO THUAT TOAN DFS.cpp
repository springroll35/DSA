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
std::vector<ii> ans;
int vis[maxn];
int m, n, s;

void init() {
    ke.clear();
    ke.resize(maxn);
    memset(vis, 0, sizeof(vis));
    ans.clear();
}

void DFS(int u) {
    vis[u] = 1;
    for(auto v : ke[u]) {
        if(!vis[v]) {
            ans.pb({u, v});
            DFS(v);
        }
    }
}

void process() {
    cin >> n >> m >> s;
    init();
    while(m--) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    DFS(s);
    if(ans.size() == n-1) {
        for(auto x : ans)
            cout << x.fi << ' ' << x.sc << endl;
    }
    else cout << -1 << endl;
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