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

const int maxn = 1e4+1;
const ll mod = 1e9+7;
const int row[4] = {1, -1, 0, 0};
const int col[4] = {0, 0, 1, -1};
typedef pair<int,int> ii;

struct Node
{
    int x, y, d;
};


void process() {
    int m, n;
    cin >> m >> n;
    int a[m+1][n+1];
    queue<Node> q;
    Node s;
    s.d = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) {
                s.x = i;
                s.y = j;
                q.push(s);
            }
        }
    }

    int ans = 0;
    while(q.size()) {
        Node u = q.front();
        q.pop();
        ans = max(ans, u.d);
        for(int i = 0; i < 4; i++) {
            Node v;
            v.x = u.x + row[i];
            v.y = u.y + col[i];
            if(v.x >= 1 && v.y >= 1 && v.x <= m && v.y <= n && a[v.x][v.y] == 1) {
                v.d = u.d + 1;
                a[v.x][v.y] = 2; // da thanh cay con
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                ans = -1;
                break;
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

    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}