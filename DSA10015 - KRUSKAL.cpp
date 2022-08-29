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

const int maxn = 1e4+5;
const ll mod = 1e9+7;
const int row[4] = {1, -1, 0, 0};
const int col[4] = {0, 0, 1, -1};
typedef pair<int, int> ii;

struct Edge
{
    int u, v, w;
    Edge(int a, int b, int c) {
        this->u = a;
        this->v = b;
        this->w = c;
    }
};

int m, n;
int par[maxn];
vector<Edge> edges;

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

int find(int u) {
    if (par[u] == -1) return u;
    par[u] = find(par[u]);
    return par[u];
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    par[v] = u;
    return 1;
}

void init() {
    edges.clear();
    memset(par, -1, sizeof(par));
}

void process() {
    init();
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb(Edge(u, v, w));
    }
    int ans = 0;
    sort(edges.begin(), edges.end(), cmp);
    for (auto edge : edges) {
        if (!Union(edge.u, edge.v)) continue;
        ans += edge.w;
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