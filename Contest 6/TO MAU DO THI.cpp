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

const int maxn = 105;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int m, n, k;
int a[maxn][maxn], vis[maxn];

bool cmp(ii x, ii y) {
    return x.sc > y.sc;
}

void process() {
    vector<ii> v;
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    cin >> n >> m >> k;
    while(m--) {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        for(int j = 1; j <= n; j++) tmp += a[i][j];
        v.pb({i, tmp});
    }
    int cnt = 0;
    sort(all(v), cmp);
    for(auto x : v) {
        int u = x.fi;
        if(vis[u]) continue;
        vis[u] = 1;
        cnt++;
        for(int i = 1; i <= n; i++) {
            if(a[u][i] == 0) {
                vis[i] = 1;
            }
        }
    }
    cout << (cnt <= k ? "YES" : "NO") << endl;
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