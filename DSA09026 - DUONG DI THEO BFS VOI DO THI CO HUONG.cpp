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

int m, n, s, t;
std::vector<std::vector<int> > ke;
int vis[maxn], trace[maxn];

void BFS(int u) {
    queue<int> q;
    vis[u] = 1;
    q.push(u);
    while(q.size()) {
        int v = q.front();
        q.pop();
        for(auto it : ke[v]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
                trace[it] = v;
            }
        }
    }
}

void findPath(int s, int t) {
    std::vector<int> ans;
    if (trace[t] == 0) {
        cout << -1 << endl;
    }
    else {
        ans.pb(t);
        int u = trace[t];
        while(u != s) {
            ans.pb(u);
            u = trace[u];
        }
        ans.pb(s);
        reverse(all(ans));
        for(auto x : ans) cout << x << ' ';
        cout << endl;
    }
}
        
void process() {
    ke.clear();
    cin >> n >> m >> s >> t;
    for(int i = 0; i <= n; i++) {
        vis[i] = trace[i] = 0;
    }
    vector<int> a(0);
    for(int i = 0; i <= n; i++) ke.pb(a);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
    }
    BFS(s);
    findPath(s, t);
    cout << endl;
    
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