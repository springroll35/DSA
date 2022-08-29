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

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

struct Edge
{
    int s, e, w;
};


int m, n, s;
vector<Edge> edges;

void init() {
    edges.clear();
    edges.resize(m);
}

bool FordBellman(int s) {
    vector<int> dis(n+1, 1e9);
    dis[s] = 0;
    for(int i = 1; i < n; i++) {
        for(auto edge : edges) {
            int u = edge.s;
            int v = edge.e;
            int w = edge.w;
            if(dis[u] != 1e9 && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }
    for(auto edge : edges) {
        int u = edge.s;
        int v = edge.e;
        int w = edge.w;
        if(dis[u] != 1e9 && dis[v] > dis[u] + w) {
            return 0;
        }
    }
    return 1;
}

void process() {
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge x;
        x.s = u;
        x.e = v;
        x.w = w;
        edges.pb(x);
    }
    for(int i = 1; i <= n; i++) {
        if(!FordBellman(i)) {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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