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

int m, n, k;
std::vector<std::vector<int> > ke;
int vis[maxn], tt[maxn], pos[maxn];

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
    cin >> k >> n >> m;
    for(int i = 0; i <= n; i++) {
        vis[i] = tt[i] = 0;
    }
    vector<int> a(0);
    for(int i = 0; i <= n; i++) ke.pb(a);
    for(int i = 0; i < k; i++) cin >> pos[i];
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
    }
    for(int i = 0; i < k; i++) {
        DFS(pos[i]);
        for(int j = 1; j <= n; j++) {
            if (vis[j]) {
                tt[j]++;
                vis[j] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if (tt[i] == k) ans++;
    }
    cout << ans;
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}