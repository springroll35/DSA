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

const int maxn = 505;
const ll mod = 1e9+7;
const int row[4] = {1, -1, 0, 0};
const int col[4] = {0, 0, 1, -1};
const char c[4] = {'U', 'L', 'R', 'D'};
typedef pair<int,int> ii;

int m, n;
char a[maxn][maxn];
bool vis[501][501];
ii s, e;
bool ok;

void DFS(int u, int v, int cnt, char ch) {
	vis[u][v] = true;
	if (u == e.fi && v == e.sc && cnt <= 3) {
		ok = true;
		return;
	}
	if (cnt > 3 || a[u][v] == 'T') {
		vis[u][v] = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x = u + row[i];
        int y = v + col[i];
		if (x >= 0 && x < m && y >= 0 && y < m && a[x][y] != '*' && !vis[x][y]) {
			if (c[i] != ch)
				DFS(x, y, cnt + 1, c[i]);
			else DFS(x, y, cnt, c[i]);
		}
	}
	vis[u][v] = false;
}

void process() {
    cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') s = {i, j};
			if (a[i][j] == 'T') e = {i, j};
		}
	ok = false;
	memset(vis, false, sizeof(vis));
    DFS(s.fi, s.sc, 0, ' ');
    cout << (ok ? "YES" : "NO") << endl;
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