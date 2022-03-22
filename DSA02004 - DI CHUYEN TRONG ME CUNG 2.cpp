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
const int row[] = {-1, 0, 0, 1};
const int col[] = {0, -1, 1, 0};
const string ch[] = {"U", "L", "R", "D"};
typedef pair<int,int> ii;

int n;
int a[maxn][maxn];
vector<string> ans;

bool isValid(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < n) && a[x][y];
}

void Try(int x, int y, string s) {
    if (x == n-1 && y == n-1) {
        ans.pb(s);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int u = x+row[i];
        int v = y+col[i];
        if (isValid(u, v)) {
            a[u][v] = 0;
            Try(u, v, s+ch[i]);
            a[u][v] = 1;
        }
    }

}


void process() {
    ans.clear();
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    if (a[0][0]) {
        a[0][0] = 0;
        Try(0, 0, "");
    }
    if (ans.size()) {
        sort(all(ans));
        for(auto x : ans) cout << x << ' ';
        cout << endl;
    }
    else cout << "-1" << endl;
    
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