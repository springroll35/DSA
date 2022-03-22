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
const int row[6] = {-1, 0, 0, 1, 0, 0};
const int col[6] = {0, -1, 1, 0, 0, 0};
const int height[6] = {0, 0, 0, 0, -1, 1};
typedef pair<int,int> ii;

int m, n, p;

struct Node {
    int x, y, z;
};

bool isVald(int x, int y, int z) {
    return (x >= 0 && y >= 0 && z >= 0 && x < m && y < n && z < p);
}

void process() {
    cin >> m >> n >> p;
    int dp[m][n][p];
    Node s, e;
    for(int i = 0; i < m; i++) {
        cin.ignore();
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < p; k++) {
                char x;
                cin >> x;
                if(x == 'S') {
                    s.x = i;
                    s.y = j;
                    s.z = k;
                }
                if(x == 'E') {
                    e.x = i;
                    e.y = j;
                    e.z = k;
                }
                if(x == '#') dp[i][j][k] = -1;
                else dp[i][j][k] = 0;
            }
        }
    }

    queue<Node> q;
    q.push(s);
    while(q.size()) {
        Node u = q.front();
        q.pop();
        if(u.x == e.x && u.y == e.y && u.z == e.z) break;
        for(int i = 0; i < 6; i++) {
            Node k;
            k.x = u.x + row[i];
            k.y = u.y + col[i];
            k.z = u.z + height[i];
            if(!isVald(k.x, k.y, k.z)) continue;
            if(dp[k.x][k.y][k.z] == -1 || dp[k.x][k.y][k.z] > 0) continue;
            dp[k.x][k.y][k.z] = dp[u.x][u.y][u.z] + 1;
            q.push(k);
        }
    }
    cout << (dp[e.x][e.y][e.z] == 0 ? -1 : dp[e.x][e.y][e.z]) << endl;
    //cout << 1 << endl;

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