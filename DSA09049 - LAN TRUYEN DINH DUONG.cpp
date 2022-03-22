#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 2e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int m, n, k;
std::vector<std::vector<int> > ke;
int vis[maxn];
std::vector<ll> pre(maxn, -1), nut(maxn, -1);

ll build(int u) {
    if (pre[u] > -1) return pre[u]; 
    if (ke[u].empty()) {
        return pre[u] = 1;
    }
    pre[u] = 0;
    for(auto v : ke[u]) {
        ll x = build(v);
        pre[u] += x;
    }
    pre[u]++;
    return pre[u];
}

ll getVal(int u) {
    if (nut[u] > -1) return nut[u]; 
    if (ke[u].empty()) {
        return nut[u] = 1;
    }
    nut[u] = 0;
    for(auto v : ke[u]) {
        nut[u] += getVal(v);
        nut[u] += pre[v];
    }
    nut[u]++;
    return nut[u];
}

void process() {
    cin >> n;
    vector<int> a(0);
    for(int i = 0; i <= n; i++) ke.pb(a);
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        ke[u].pb(i);
    }
    build(1);
    for(int i = 1; i <= n; i++) {
        cout << getVal(i) << ' ';
    }
    
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