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
int in[maxn], in2[maxn];
std::vector<std::vector<int> > ke, ke2;

void init() {
    ke.clear();
    ke.resize(n + 1);
    ke2.clear();
    ke2.resize(n + 1);
    for(int i = 0; i <= maxn; i++) {
        in[i] = in2[i] = 0;
    }
    vis.reset();
}

void DFS(int u, std::vector<std::vector<int> > &ke) {
    vis[u] = 1;
    for(auto v : ke[u]) {
        if(!vis[v]) {
            DFS(v, ke);
        }
    }
}

bool isStronglyConnected() {
    vis.reset();
    int k;
    for(k = 1; k <= n; k++) {
        if (ke[k].size()) {
            break;
        }
    }
    DFS(k, ke);
    for(int i = 1; i <= n; i++) {
        if (!vis[i] && ke[i].size()) return false;
    }
    vis.reset();
    DFS(k, ke2);
    for(int i = 1; i <= n; i++) {
        if (!vis[i] && ke2[i].size()) return false;
    }
    return true;

}

int check() {
    if(!isStronglyConnected()) return 0;
    for(int i = 1; i <= n; i++) {
        if (ke[i].size() != in[i]) return 0;
    }
    return 1;

}

void process() {
    cin >> n >> m;
    init();
    while(m--) {
        int u , v;
        cin >> u >> v;
        ke[u].pb(v);
        in[v]++;
    }
    for(int i = 1; i <= n; i++) {
        for(auto v : ke[i]) {
            ke2[v].pb(i);
            in2[i]++;
        }
    }
    cout << check() << endl;
    //cout << 1;
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