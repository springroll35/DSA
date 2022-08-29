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
typedef pair<int,int> ii;

int m, n, u, v;
std::vector<std::vector<int> > ke;
int vis[maxn];

bool check(int x) {
    bitset<maxn> vis;
    vis[x] = 1;
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while(q.size()) {
        u = q.front();
        q.pop();
        for(auto i : ke[u]) {
            if(!vis[i]) {
                if(i == v) return 0;
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return 1;
}

void process() {
    ke.clear();
    cin >> n >> m >> u >> v;
    for(int i = 0; i <= n; i++) {
        vis[i] = 0;
    }
    vector<int> a(0);
    for(int i = 0; i <= n; i++) ke.pb(a);
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].pb(y);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(i == u || i == v) continue;
        ans += check(i);
    }
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