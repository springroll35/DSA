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

int cnt(int x, int y[], int n, std::vector<ll> d) {
    ll ans = 0;
    if(x == 0) return 0;
    if(x == 1) return d[0];
    ll pos = upper_bound(y, y+n, x) - y;
    ans += n - pos;
    ans += d[0] + d[1];
    if(x == 2) {
        ans -= d[3] + d[4];
    }
    if(x == 3) {
        ans += d[2];
    }
    return ans;

}

void process() {
    int m, n;
    cin >> m >> n;
    int a[m], b[n];
    std::vector<ll> d(5, 0);
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] < 5) d[b[i]]++;
    }
    sort(b, b+n);
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        ans += cnt(a[i], b, n, d);
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