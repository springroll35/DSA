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
bitset<maxn> vis;
std::vector<std::vector<int> > ke;

void init() {
    ke.clear();
    ke.resize(n + 1);
    vis.reset();
}

void DFS(int u) {
    vis[u] = 1;
    for(auto v : ke[u]) {
        if(!vis[v]) {
            DFS(v);
        }
    }
}

bool isConnected() {
    int i;
    for(i = 1; i <= n; i++) {
        if (ke[i].size()) {
            break;
        }
    }
    if (i == n) return true;
    DFS(i);
    for(int i = 1; i <= n; i++) {
        if (!vis[i] && ke[i].size()) return false;
    }
    return true;

}

int check() {
    if(!isConnected()) return 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if (ke[i].size() & 1) {
            cnt++;
        }
    }
    if(cnt > 2) return 0;
    return (cnt) ? 1 : 2;

}

void process() {
    cin >> n >> m;
    init();
    while(m--) {
        int u , v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    cout << check() << endl;
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