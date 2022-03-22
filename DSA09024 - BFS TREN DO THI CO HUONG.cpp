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

int m, n, s;
std::vector<std::vector<int> > ke;
int vis[maxn];

void BFS(int u) {
    queue<int> q;
    vis[u] = 1;
    q.push(u);
    cout << u << ' ';
    while(q.size()) {
        int v = q.front();
        q.pop();
        for(auto it : ke[v]) {
            if (!vis[it]) {
                cout << it << ' ';
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

void process() {
    ke.clear();
    cin >> n >> m >> s;
    for(int i = 0; i <= n; i++) {
        vis[i] = 0;
    }
    vector<int> a(0);
    for(int i = 0; i <= n; i++) ke.pb(a);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
    }
    BFS(s);
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