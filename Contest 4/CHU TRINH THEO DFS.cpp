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
typedef pair<ii, int> iii;

std::vector<std::vector<int> > ke;
vector<int> ans;
int vis[maxn];
int m, n;

void init() {
    ke.clear();
    ke.resize(maxn);
    ans.clear();
    memset(vis, 0, sizeof (vis));
}

void DFS(int u, int pre, vector<int> a) {
    vis[u] = 1;
    for(auto v : ke[u]) {
        if(v != pre) {
            if(v == 1) {
                if(ans.empty()) {
                    ans = a;
                    ans.pb(v);
                }
            }
            else if(!vis[v]) {
                a.pb(v);
                DFS(v, u, a);
                a.pop_back();
            }
        }
    }
}

void process() {
    cin >> n >> m;
    init();
    while(m--) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    for(int i = 1; i <= n; i++) {
        sort(all(ke[i]));
    }
    DFS(1, 1, vector<int>(1, 1));
    if(ans.size()) {
        for(auto x : ans) cout << x << ' ';
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
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