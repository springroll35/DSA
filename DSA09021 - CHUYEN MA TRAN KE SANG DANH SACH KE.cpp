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
std::vector<std::vector<int> > ke;
int a[maxn][maxn];

void process() {
    memset(a, 0, sizeof(a));
    cin >> n;
    std::vector<int> tmp;
    for(int i = 0; i <= n; i++) ke.pb(tmp);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j]) {
                ke[i].pb(j);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(auto x : ke[i]) {
            cout << x << ' ';
        }
        cout << endl;
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