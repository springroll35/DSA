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
ll a[maxn];

bool check(ll x, ll a[]) {
    for(int i = 0; i < n; i++) {
        if (a[i] / x == a[i] / (x+1)) return false;
    }
    return true;
}

void process() {
    vector<ll> u,v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        u.pb(a[i]);
    }
    sort(all(u));
    v = u;
    for(ll i = u[0]; i > 0; i--) {
        if (check(i, a)) {
            for (int j = 0; j < n; j++) {
                v[j] = a[j] / (i+1) + 1;
            }
            break;
        }
    }
    ll ans = 0;
    for(auto x : v) ans += x;
    cout << ans;

   
    
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