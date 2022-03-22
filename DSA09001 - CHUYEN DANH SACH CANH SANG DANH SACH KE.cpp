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

void process() {
    ke.clear();
    cin >> n >> m;
    vector<int> a(0);
    for(int i = 0; i <= n; i++) ke.pb(a);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(auto x : ke[i]) cout << x << ' '; 
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

    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}