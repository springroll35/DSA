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
const int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
//const int row[4] = {-1, 0, 0, 1};
//const int col[4] = {0, -1, 1, 0};

int m, n;
std::vector<std::vector<int> > ke;
char a[maxn][maxn];
int vis[maxn][maxn];

bool isValid(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m) && a[x][y] == 'W';
}

void BFS(int x ,int y) {
    queue<ii> q;
    vis[x][y] = 1;
    q.push(ii(x, y));
    while(q.size()) {
        ii k = q.front();
        q.pop();
        for(int i = 0; i < 8; i++) {
            int u = k.fi + row[i];
            int v = k.sc + col[i];
            if (isValid(u, v) && !vis[u][v]) {
                vis[u][v] = 1;
                q.push(ii(u, v));
            }
        }
    }
}

void process() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> a[i][j], vis[i][j] = 0;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (a[i][j] == 'W' && !vis[i][j]) {
                ans++;
                //vis[i][j] = 1;
                BFS(i, j);
            }
        }
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

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}