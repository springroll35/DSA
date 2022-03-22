#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int m,n;

void process() {
    cin >> m >> n;
    vector<int> p(m+1,0), q(n+1,0), r(m+n+1,0);
    for(int i = 0; i < m; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> q[i];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            r[i+j] += p[i]*q[j];
        }
    }
    for(int i = 0; i < m+n-1; i++) cout << r[i] << ' ';
    cout << endl;
    
    
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