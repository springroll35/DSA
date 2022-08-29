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
const int row[4] = {1, -1, 0, 0};
const int col[4] = {0, 0, 1, -1};
typedef pair<int, int> ii;

struct Edge
{
    int u, v;
    double w;
    Edge(int a, int b, double c) {
        this->u = a;
        this->v = b;
        this->w = c;
    }
};

int n;
int par[maxn];
pair<double, double> a[maxn];
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

double distance(pair<double, double> x, pair<double, double> y) {
    pair<double, double> dis = {y.fi - x.fi, y.sc - x.sc};
    return sqrt(dis.fi * dis.fi + dis.sc * dis.sc);
}
void process() {
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].fi >> a[i].sc;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            edges.pb(Edge(i+1, j+1, distance(a[i], a[j])));
        }
    }
    double ans = 0.0;
    sort(edges.begin(), edges.end(), cmp);
    for (auto edge : edges) {
        if (!Union(edge.u, edge.v)) continue;
        ans += edge.w;
    }
    cout << setprecision(6) << fixed << ans << endl;

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