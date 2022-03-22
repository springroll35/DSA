#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 105;
const ll mod = 1e9+7;
const int row[4] = {-1, 0, 1, 0};
const int col[4] = {0, -1, 0, 1};
typedef pair<int,int> ii;

int n, m;
std::vector<std::vector<int> > ke;
std::vector<std::vector<int> > vis(100 , vector<int>(100, 0));
int ok;

void init() {
    ke.clear();
    ke.resize(105);
    ok = 0;
}

void DFS(int u, set<int> s, vector<vector<int> > vis) {
    s.insert(u);
    if(s.size() == n) {
        ok = 1;
    }
    for(auto v : ke[u]) {
        if(!vis[u][v] && !vis[v][u]) {
            vis[u][v] = vis[v][u] = 1;
            DFS(v, s, vis);
        }
    }
}

void process() {
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    for(int i = 1; i <= n; i++) {
        DFS(i, set<int> (), vis);
    }
    cout << ok << endl;


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