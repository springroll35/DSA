#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e3+1;

class Graph {
    public:
    int m, n, s, t;
    int a[maxn][maxn];
    int visited[maxn], trace[maxn];
        void read() {
        	memset(a, 0, sizeof(a));
            cin >> n >> m >> s >> t;
            while(m--) {
            	int u, v;
            	cin >> u >> v;
            	a[u][v] = 1;
            }
        }
        
        void init() {
            for(int i = 1; i <= n; i++) {
                visited[i] = trace[i] = 0;
            }
        }
        
        void BFS(int u) {
            queue<int> q;
            visited[u] = 1;
            q.push(u);
            while(q.size()) {
                int v = q.front();
                q.pop();
                for(int i = 1; i <= n; i++) {
                    if (a[v][i] && visited[i] == 0) {
                        visited[i] = 1;
                        q.push(i);
                        trace[i] = v;
                    }
                }
            }
        }
        
        void findPath(int s, int t) {
            if (trace[t] == 0) {
                cout << -1 << endl;
            }
                else {
                	vector<int> ans;
                    ans.push_back(t);
                    int u = trace[t];
                    while(u != s) {
                        ans.push_back(u);
                        u = trace[u];
                    }
                    ans.push_back(s);
                    reverse(ans.begin(), ans.end());
                    for(auto x : ans) cout << x << ' ';
                    cout << endl;
                }
        }
};

void process() {
    Graph g;
    g.read();
    g.init();
    g.BFS(g.s);
    if (g.trace[g.t]) {
        g.findPath(g.s, g.t);
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