#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int m, n, s;
vector<vector<ii> > ke;
int dis[maxn], par[maxn];

void init() {
    ke.clear();
    ke.resize(n+1);
    for(int i = 1; i <= n; i++) {
    	dis[i] = 1e9;
    	par[i] = 0;
    }
}

void dijkstra(int s) {
    priority_queue<ii, vector<ii>, greater<ii> > q;
    dis[s] = 0;
    q.push({s, 0});
    while(q.size()) {
        int u = q.top().fi;
        int w = q.top().sc;
        q.pop();
        for(auto it : ke[u]) {
            int v = it.fi;
            int c = it.sc;
            if(dis[v] > w + c) {
                dis[v] = w + c;
                par[v] = u; 
                q.push({v, dis[v]});
            }
        }
    }
}

void process() {
    cin >> n >> m >> s;
    init();
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].pb({v, w});
        ke[v].pb({u, w});
    }
    dijkstra(s);
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
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