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
std::vector<std::vector<int> > ke;
int vis[maxn][maxn];

void process() {
    ke.clear();
    memset(vis, 0, sizeof(vis));
    cin >> n;
    cin.ignore();
    vector<int> a(0);
    for(int i = 0; i <= n; i++) ke.pb(a);
    for(int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        s += ' ';
        int x = 0;
        for(int j = 0; j < s.length(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                x = x*10 + (s[j] - '0');
            }
            else {
                vis[i][x] = vis[x][i] = 1;
                x = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if (vis[i][j]) {
                cout << i << ' ' << j << endl;
            }
        }
    }
    
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