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
typedef pair<ii, int> iii;

void process() {
    int m, n;
    cin >> m >> n;
    int a[m], b[n];
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a+m);
    sort(b, b+n);
    set<int> s, s1;
    for(int i = 0; i < m; i++) {
        s.insert(a[i]);
    }
    for(int i = 0; i < n; i++) {
        if(s.find(b[i]) != s.end()) {
            s1.insert(b[i]);
        }
    }
    for(int i = 0; i < n; i++) {
        s.insert(b[i]);
    }
    for(auto x : s) cout << x << ' ';
    cout << endl;
    for(auto x : s1) cout << x << ' ';
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