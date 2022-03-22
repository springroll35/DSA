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
int num[maxn], low[maxn], par[maxn], timer;
std::vector<std::vector<int> > ke;
std::vector<ii> ans;

void DFS(int u) {
    timer++;
    num[u] = low[u] = timer;
    bool maybe_cut_vertex = false;
    int child = 0;
    for(auto v : ke[u]) {
        if (num[v] == 0) {
            child++;
            par[v] = u;
            DFS(v);
            if(low[v] >= num[v]) {
                if (u < v) {
                   ans.pb({u, v});
                }
                else {
                    ans.pb({v, u});
                }
            }
            if(low[v] >= num[u]) {
                maybe_cut_vertex = true;
            }
            low[u] = min(low[u], low[v]);
        }
        else if (v != par[u]) {
            low[u] = min(low[u], num[v]);
        }
    }
    /*if(par[u] == 0) {
        if (child > 1) {
            ans.insert(u);
        }
    }
    else if(maybe_cut_vertex) {
        ans.insert(u);
    } */
}

void init() {
    ke.clear();
    ans.clear();
    ke.resize(n + 5);
    timer = 0;
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(par, 0, sizeof(par));
}


void process() {
    cin >> n >> m;
    init();
    //vector<int> tmp(0);
    //for(int i = 0; i <= n; i++) ke.pb(tmp);
    while(m--) {
        int u , v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    for(int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            DFS(i);
        }
    }
    sort(all(ans));
    for(auto x : ans) {
        cout << x.fi << ' ' << x.sc << ' ';
    }
    //for(int i = 1; i <= n; i++) {
        //cout << num[i] << ' ' << low[i] << endl;
    //}
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