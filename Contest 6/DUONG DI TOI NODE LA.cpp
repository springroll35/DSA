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

int n;
vector<vector<int>> ke;
vector<string> ans;
bitset<maxn> vis;

void init() {
    ke.clear();
    ke.resize(n + 1);
    ans.clear();
    vis.reset();
}

void DFS(int u, string s) {
    if(ke[u].empty()) {
        ans.pb(s);
        return;
    }
    vis[u] = 1;
    for(auto v : ke[u]) {
        if(!vis[v]) {
            DFS(v, s + " " + to_string(v));
        }
    }
}

bool cmp(string x, string y) {
    int posx = x.find_last_of(" ");
    int posy = y.find_last_of(" ");
    return (stoi(x.substr(posx, maxn)) < stoi(y.substr(posy, maxn)));
}

void process() {
    cin >> n;
    init();
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
    }
    DFS(1, "1");
    sort(all(ans), cmp);
    for(auto x : ans) {
        cout << x << endl;
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