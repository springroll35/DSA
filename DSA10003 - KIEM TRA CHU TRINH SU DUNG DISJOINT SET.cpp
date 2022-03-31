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
std::vector<ii> edges;
int par[maxn];
int m, n;

void init() {
    ke.clear();
    ke.resize(maxn);
    edges.clear();
    for(int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int find(int u) {
    if(par[u] == u) 
        return u;
    par[u] = find(par[u]);
    return par[u];
}

void Union(int u, int v) {
    int x = find(u);
    int y = find(v);
    par[u] = v;
}

void process() {
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.pb({u, v});
    }
    for(auto it : edges) {
        
            int x = find(it.fi);
            int y = find(it.sc);
            if(x == y) {
                cout << "YES" << endl;
                return;
            }
            else 
                Union(x, y);
    }
    cout << "NO" << endl;
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