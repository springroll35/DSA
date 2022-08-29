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
std::vector<std::vector<int> > ke;
int vis[maxn];
int ans;

void BFS(int u) {
    queue<int> q;
    vis[u] = ans;
    q.push(u);
    while(q.size()) {
        int v = q.front();
        q.pop();
        for(auto it : ke[v]) {
            if (!vis[it]) {
                vis[it] = ans;
                q.push(it);
            }
        }
    }
}

void process() {
    ke.clear();
    int x;
    cin >> n >> m >> x;
    for(int i = 0; i <= n; i++) {
        vis[i] = 0;
    }
    vector<int> a(0);
    for (int i=0; i<=n; i++) ke.push_back(a);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    ans = 0;
    for(int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans++;
            BFS(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] != vis[x]) cout << i << endl;
    }
    if(ans == 1) cout << 0;
    
}

int main() {
    

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}