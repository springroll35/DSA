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

int n;
vector<vector<int>> ke;
bitset<maxn> vis;
int ans;

void init() {
    ke.clear();
    ke.resize(n + 1);
    vis.reset();
    ans = 0;
}

void DFS(int u, int cnt) {
    ans = max(ans, cnt);
    vis[u] = 1;
    for(auto v : ke[u]) {
        if(!vis[v]) {
            DFS(v, cnt + 1);
        }
    }
}

void process() {
    cin >> n;
    init();
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
    }
    DFS(1, 0);
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