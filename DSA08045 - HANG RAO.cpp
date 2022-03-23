#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 3e3+5;
const ll mod = 1e9+7;
const int row[4] = {-1, 0, 1, 0};
const int col[4] = {0, -1, 0, 1};
typedef pair<int,int> ii;
 
int x[maxn], y[maxn];
int t[maxn];
int xz, yz;
char c[2*maxn][2*maxn];
stack<int> sx, sy;
int sz;

int compress(int a[maxn], int z) {
    memcpy(t, a, sizeof(t));
    sort(t, t + z);
    int sz = unique(t, t + z) - t;
    for (int i = 0; i < z; i++) {
        a[i] = (lower_bound(t, t + sz, a[i]) - t) * 2;
    }
    return sz * 2;
}

void put(int x, int y) {
    if (x < 0 || y < 0  || x >= xz || y >= yz) return;
    if (c[x][y] == 'X') return;
    sz += (c[x][y] == 'C');
    c[x][y] = 'X';
    sx.push(x);
    sy.push(y);
}

void dfs(int ux, int uy) {
    put(ux, uy);
    while (sx.size()) {
        int x = sx.top(); 
        sx.pop();
        int y = sy.top(); 
        sy.pop();
        for (int i = 0; i < 4; i++) {
            int kx = x + row[i];
            int ky = y + col[i];
            put(kx, ky);
        }
    }
}

void process() {
    int n, m;
    cin >> n >> m;
    int z = 0;
    x[z] = y[z] = -1e9; 
    z++;
    x[z] = y[z] = 1e9;
    z++;
    for (int i = 0; i < 2 * n; i++) {
        cin >> x[z] >> y[z]; 
        z++;
    }
    for (int i = 0; i < m; i++) {
        cin >> x[z] >> y[z]; 
        z++;
    }
    xz = compress(x, z);
    yz = compress(y, z);
    memset(c, '.', sizeof(c));
    for (int i = 0; i < n; i++) {
        int a = i * 2 + 2;
        int b = i * 2 + 3;
        int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            while (y1 <= y2) {
                c[x1][y1] = 'X';
                y1++;
            }
        } 
        else {
            if (x1 > x2) swap(x1, x2);
            while (x1 <= x2) {
                c[x1][y1] = 'X';
                x1++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a = i + 2 * n + 2;
        c[x[a]][y[a]] = 'C';
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a = i + 2 * n + 2;
        sz = 0;
        dfs(x[a], y[a]);
        ans = max(ans, sz);
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